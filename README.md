# Adv_Student_Report_Card
📘 Advanced Student Report Card System

📌 Overview

The Advanced Student Report Card System is a C-based console application designed to manage and generate student academic records efficiently.
It allows creating, updating, deleting, and viewing student report cards with advanced features such as GPA calculation, grade analytics, data validation, improved file handling, and secure input mechanisms.

This project is ideal for college mini-projects, file handling practice, and beginner-to-intermediate C programming learning.


The Advanced Student Report Card System is a feature-rich C console application designed to manage student academic records professionally.
It supports:

Multiple subject marks

Attendance tracking

Total, average & percentage calculation

Automatic grade assignment

Data storage using file handling

Update & delete operations

Student ranking system

Clean and user-friendly console UI

This project is ideal for college mini-projects, assignments, and resume projects.

🚀 Key Features
✅ 1. Add Student Record

Stores complete student information:

Student ID

Name

Marks for 5 subjects

Attendance (%)

It automatically computes:

Total marks

Average

Percentage

Grade

✅ 2. Display All Students

Shows a formatted table with:

ID, Name

Each subject’s marks

Total & Percentage

Grade

Attendance

✅ 3. Search Student by ID

Displays a detailed report card:

Marks breakdown

Grade & percentage

Attendance

Remarks

✅ 4. Update Student Record

Allows modifying:

Student name

Marks

Attendance

System recalculates totals & grades automatically.

✅ 5. Delete Student Record

Deletes a student permanently from the database file.

✅ 6. Ranking System

Automatically sorts students by percentage and displays:

Rank

Student Name

Percentage

Grade

✅ 7. File Handling (Permanent Storage)

All student data is stored in:

students.dat


Even after closing the program, records remain safe.

✅ 8. Input Validation

Prevents invalid data like:

Negative marks

Marks above 100

Attendance > 100

Duplicate student IDs

✅ 9. Remarks System

Based on percentage:

Excellent

Very Good

Good

Average

Needs Improvement

🛠 Technologies Used

C Programming (Structured & Modular)

File Handling with Binary Files

Structures

Console UI

📂 Project Structure
/AdvancedStudentReportCard
   ├── reportcard.c          # Main source code
   ├── students.dat          # Auto-generated database file
   ├── README.md             # Documentation
   ├── sample-output.txt     # Optional
   └── screenshots/          # Optional

📌 Grade Calculation Logic
Percentage	Grade
90–100	A+
80–89	A
70–79	B
60–69	C
50–59	D
< 50	F
📌 Remarks Logic
Grade	Remarks
A+	Excellent Performance
A	Very Good
B	Good
C	Average
D	Needs Improvement
F	Fail – Needs Support
▶️ How to Run
Windows / Linux / Mac
gcc reportcard.c -o reportcard
./reportcard

📘 Sample Output
===========================================
      ADVANCED STUDENT REPORT CARD SYSTEM
===========================================
1. Add Student
2. Display All Students
3. Search Student by ID
4. Update Student
5. Delete Student
6. Rank List
7. Exit
Enter your choice: 1

Enter Student ID: 101
Enter Name: Mahi
Enter Marks in 5 Subjects: 87 92 78 89 90
Enter Attendance (%): 95
✔ Student Added Successfully!


📄 License

This project is free to use for educational purposes.

👤 Author : Mahesh Babu Baswani
