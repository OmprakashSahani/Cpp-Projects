# Student-Grade-Calculator
The Student Grade Calculator program allows users to input student data, calculate their grades based on marks, and store/display the results.

Student Grade Calculator
Overview:
The Student Grade Calculator program allows users to input student data, calculate their grades based on marks, and store/display the results. 
The program supports operations such as adding student data, viewing all records, saving data to a file, and loading data from a file.

Features:
1. Input student details including name, roll number, and marks for multiple subjects.
2. Calculate the total marks, percentage, and grade based on predefined thresholds.
3. Display student data in a user-friendly format.
4. Save student data to a file (StudentGrades.txt).
5. Load and view student data from the file.

Grade Calculation:
Grades are assigned based on the following percentage ranges:
A+: 90% and above

A: 80% to 89%

B: 70% to 79%

C: 60% to 69%

F: Below 60%

Requirements:
C++ compiler (C++11 or higher recommended).

How to Use:
1. Start the Program: Compile and run the program. You will be presented with a menu of options.

2. Add Student Data:

Select option 1.

Enter the number of subjects and their names.

Input the student's name, roll number, and marks for each subject. Marks should be between 0 and 100.

The program will calculate and display the total marks, percentage, and grade.

3. View All Records:

Select option 2 to display all the entered student data.

4. Save Data to File:

Select option 3 to save the student data to a file called StudentGrades.txt. The data will be appended to the file.

5. Load Data from File:

Select option 4 to load and display previously saved student data from the file.

6. Exit:

Select option 5 to exit the program.

File Structure:

StudentGrades.txt: This text file is used to store and retrieve student data.

Example:

Adding Student Data:

Enter the number of subjects: 3

Enter name of Subject 1: Math

Enter name of Subject 2: Science

Enter name of Subject 3: History


Enter Student Name: John Doe

Enter Roll Number: 101

Enter marks for Math: 85

Enter marks for Science: 90

Enter marks for History: 88


Student Name: John Doe

Roll Number: 101

Total Marks: 263

Percentage: 87.67%

Grade: A


Viewing All Records

Student Name: John Doe

Roll Number: 101

Total Marks: 263

Percentage: 87.67%

Grade: A


Saving and Loading Data

Saved data will be stored in StudentGrades.txt and can be loaded back into the program.

License

This project is open source and can be modified or distributed freely.
