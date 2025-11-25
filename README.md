# Adv_Student_Report_Card
📘 Advanced Student Report Card System
📌 Overview

The Advanced Student Report Card System is a C-based console application designed to manage and generate student academic records efficiently.
It allows creating, updating, deleting, and viewing student report cards with advanced features such as GPA calculation, grade analytics, data validation, improved file handling, and secure input mechanisms.

This project is ideal for college mini-projects, file handling practice, and beginner-to-intermediate C programming learning.

✨ Features (Advanced)
🧑‍🎓 Student Management

Add new student records

Update existing student details

Delete student records

Search student by roll number

View complete student list

View a single student's report

📊 Academic Performance

Auto-calculated Total Marks

Weighted Percentage

CGPA / GPA Calculation

Auto Grade Assignment (A+, A, B+, B, C, D, F)

Supports 5 or 6 subjects

Subject-by-subject breakdown

📂 File Handling (Persistent Data)

Stores all student records in a .dat file

Uses binary file handling for faster and safer operations

Prevents corruption and duplication

🔒 Input Safety & Validation

Overflow-safe integer input

Restricted marks range (0–100)

Roll number uniqueness check

Error-handling for invalid input

📈 Analytics (Optional Add-on)

Highest & lowest scorer

Class average

Subject-wise average

Top 3 rank list

🧪 Technologies Used

C Programming

File Handling (Binary Mode)

Structures

Functions / Modular Code

Dynamic Validation

Formatted Console UI

📁 Project Structure
/Student-Report-Card-System
│── student.c        → Main program file
│── student.dat      → Auto-generated database file
│── README.md        → Documentation
└── Makefile (optional)

🚀 How to Run
Using GCC
gcc student.c -o student
./student

Windows (MinGW)
gcc student.c -o student.exe
student.exe

📜 Grading Structure
Percentage	Grade
90–100	A+
80–89	A
70–79	B+
60–69	B
50–59	C
40–49	D
< 40	F



📄 License

This project is free to use for educational purposes.

👤 Author : Mahesh Babu Baswani
