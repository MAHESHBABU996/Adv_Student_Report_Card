#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define SUBJECTS 5
#define DATA_FILE "students.dat"

struct Student {
    int roll;
    char name[MAX_NAME];
    float marks[SUBJECTS];
    float total;
    float percent;
    char grade;
};

static void flushInput(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

static int readInt(const char *prompt) {
    int val;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &val) == 1) {
            flushInput();
            return val;
        } else {
            printf("Invalid input. Please enter an integer.\n");
            flushInput();
        }
    }
}

static float readFloat(const char *prompt) {
    float val;
    while (1) {
        printf("%s", prompt);
        if (scanf("%f", &val) == 1) {
            flushInput();
            return val;
        } else {
            printf("Invalid input. Please enter a number.\n");
            flushInput();
        }
    }
}

static void calculate(struct Student *s) {
    s->total = 0.0f;
    for (int i = 0; i < SUBJECTS; ++i)
        s->total += s->marks[i];
    s->percent = s->total / SUBJECTS;

    if (s->percent >= 90.0f) s->grade = 'A';
    else if (s->percent >= 75.0f) s->grade = 'B';
    else if (s->percent >= 60.0f) s->grade = 'C';
    else if (s->percent >= 45.0f) s->grade = 'D';
    else s->grade = 'F';
}

void addStudent(void) {
    struct Student s;
    FILE *fp = fopen(DATA_FILE, "ab");
    if (!fp) {
        perror("Error opening data file for writing");
        return;
    }

    s.roll = readInt("\nEnter Roll Number: ");

    printf("Enter Name: ");
    if (fgets(s.name, sizeof(s.name), stdin) == NULL) {
        s.name[0] = '\0';
    } else {
        /* remove trailing newline */
        s.name[strcspn(s.name, "\n")] = '\0';
    }

    for (int i = 0; i < SUBJECTS; ++i) {
        char prompt[64];
        snprintf(prompt, sizeof(prompt), "Enter marks for Subject %d: ", i + 1);
        s.marks[i] = readFloat(prompt);
        if (s.marks[i] < 0.0f) {
            printf("Negative marks not allowed. Setting to 0.\n");
            s.marks[i] = 0.0f;
        }
    }

    calculate(&s);

    if (fwrite(&s, sizeof(s), 1, fp) != 1) {
        perror("Error writing record");
    } else {
        printf("\nStudent Record Added Successfully!\n");
    }

    fclose(fp);
}

void displayAll(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    if (!fp) {
        printf("\nNo data found (file does not exist).\n");
        return;
    }

    struct Student s;
    int count = 0;
    printf("\n------------------- ALL STUDENTS -------------------\n");
    while (fread(&s, sizeof(s), 1, fp) == 1) {
        printf("\nRoll      : %d\n", s.roll);
        printf("Name      : %s\n", s.name);
        printf("Total     : %.2f\n", s.total);
        printf("Percent   : %.2f\n", s.percent);
        printf("Grade     : %c\n", s.grade);
        ++count;
    }

    if (count == 0)
        printf("\nNo records found.\n");

    fclose(fp);
}

void searchStudent(void) {
    int roll = readInt("\nEnter Roll Number to Search: ");
    FILE *fp = fopen(DATA_FILE, "rb");
    if (!fp) {
        printf("No data found.\n");
        return;
    }

    struct Student s;
    int found = 0;
    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.roll == roll) {
            printf("\n----- Student Found -----\n");
            printf("Roll     : %d\n", s.roll);
            printf("Name     : %s\n", s.name);
            for (int i = 0; i < SUBJECTS; ++i)
                printf("Subject %d: %.2f\n", i + 1, s.marks[i]);
            printf("Total    : %.2f\n", s.total);
            printf("Percent  : %.2f\n", s.percent);
            printf("Grade    : %c\n", s.grade);
            found = 1;
            break;
        }
    }
    if (!found) printf("\nStudent Not Found!\n");
    fclose(fp);
}

void deleteStudent(void) {
    int roll = readInt("\nEnter Roll Number to Delete: ");
    FILE *fp = fopen(DATA_FILE, "rb");
    if (!fp) {
        printf("No data found.\n");
        return;
    }
    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        perror("Error creating temporary file");
        fclose(fp);
        return;
    }

    struct Student s;
    int found = 0;
    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.roll == roll) {
            found = 1;
            continue; /* skip writing this record */
        }
        fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        remove(DATA_FILE);
        rename("temp.dat", DATA_FILE);
        printf("\nRecord Deleted Successfully!\n");
    } else {
        remove("temp.dat");
        printf("\nRecord Not Found!\n");
    }
}

void updateStudent(void) {
    int roll = readInt("\nEnter Roll Number to Update Marks: ");
    FILE *fp = fopen(DATA_FILE, "rb+");
    if (!fp) {
        printf("No data found.\n");
        return;
    }

    struct Student s;
    int found = 0;
    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.roll == roll) {
            printf("\nEnter New Marks for %s (Roll %d):\n", s.name, s.roll);
            for (int i = 0; i < SUBJECTS; ++i) {
                char prompt[64];
                snprintf(prompt, sizeof(prompt), "Subject %d: ", i + 1);
                s.marks[i] = readFloat(prompt);
                if (s.marks[i] < 0.0f) {
                    printf("Negative marks not allowed. Setting to 0.\n");
                    s.marks[i] = 0.0f;
                }
            }
            calculate(&s);
            /* move file pointer back one record and overwrite */
            fseek(fp, -((long)sizeof(s)), SEEK_CUR);
            if (fwrite(&s, sizeof(s), 1, fp) != 1) {
                perror("Error writing updated record");
            } else {
                printf("\nRecord Updated Successfully!\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) printf("\nStudent Not Found!\n");
    fclose(fp);
}

void classTopper(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    if (!fp) {
        printf("No data found.\n");
        return;
    }

    struct Student s;
    struct Student top;
    int found = 0;

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (!found || s.percent > top.percent) {
            top = s;
            found = 1;
        }
    }
    fclose(fp);

    if (!found) {
        printf("\nNo records to determine topper.\n");
        return;
    }

    printf("\n----- CLASS TOPPER -----\n");
    printf("Roll   : %d\n", top.roll);
    printf("Name   : %s\n", top.name);
    printf("Percent: %.2f\n", top.percent);
    printf("Grade  : %c\n", top.grade);
}

int main(void) {
    int choice;

    while (1) {
        printf("\n==================== STUDENT REPORT CARD SYSTEM ====================\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll\n");
        printf("4. Update Student Marks\n");
        printf("5. Delete Student\n");
        printf("6. Show Class Topper\n");
        printf("7. Exit\n");
        printf("====================================================================\n");
        choice = readInt("Enter Your Choice: ");

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: classTopper(); break;
            case 7:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid Choice! Try again.\n");
        }
    }
}
