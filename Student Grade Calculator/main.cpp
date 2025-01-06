#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// Structure to store student details
struct Student {
    string name;
    int rollNumber;
    vector<int> marks;
    int totalMarks;
    float percentage;
    char grade;
};

// Function to calculate grade
char calculateGrade(float percentage) {
    if (percentage >= 90) return 'A+';
    else if (percentage >= 80) return 'A';
    else if (percentage >= 70) return 'B';
    else if (percentage >= 60) return 'C';
    else return 'F';
}

// Function to input student data
Student inputStudentData(const vector<string>& subjects) {
    Student student;
    cout << "\nEnter Student Name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;

    student.totalMarks = 0;
    student.marks.resize(subjects.size());
    for (size_t i = 0; i < subjects.size(); i++) {
        do {
            cout << "Enter marks for " << subjects[i] << ": ";
            cin >> student.marks[i];
            if (student.marks[i] < 0 || student.marks[i] > 100)
                cout << "Invalid marks! Please enter a value between 0 and 100.\n";
        } while (student.marks[i] < 0 || student.marks[i] > 100);
        student.totalMarks += student.marks[i];
    }
    student.percentage = (float)student.totalMarks / subjects.size();
    student.grade = calculateGrade(student.percentage);

    return student;
}

// Function to display student data
void displayStudentData(const Student& student) {
    cout << "\nStudent Name: " << student.name;
    cout << "\nRoll Number: " << student.rollNumber;
    cout << "\nTotal Marks: " << student.totalMarks;
    cout << "\nPercentage: " << fixed << setprecision(2) << student.percentage << "%";
    cout << "\nGrade: " << student.grade << endl;
}

// Function to save student data to a file
void saveStudentDataToFile(const vector<Student>& students) {
    ofstream outFile("StudentGrades.txt", ios::app);
    if (outFile.is_open()) {
        for (const auto& student : students) {
            outFile << "Student Name: " << student.name << "\n";
            outFile << "Roll Number: " << student.rollNumber << "\n";
            outFile << "Total Marks: " << student.totalMarks << "\n";
            outFile << "Percentage: " << fixed << setprecision(2) << student.percentage << "%\n";
            outFile << "Grade: " << student.grade << "\n";
            outFile << "-----------------------------------\n";
        }
        outFile.close();
        cout << "Data saved to StudentGrades.txt\n";
    } else {
        cout << "Error opening file to save data.\n";
    }
}

// Function to load and display data from a file
void loadStudentDataFromFile() {
    ifstream inFile("StudentGrades.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "No existing data found.\n";
    }
}

// Main menu function
void menu() {
    vector<Student> students;
    vector<string> subjects;
    int choice;

    do {
        cout << "\n--- Student Grade Calculator ---";
        cout << "\n1. Add Student Data";
        cout << "\n2. View All Records";
        cout << "\n3. Save Data to File";
        cout << "\n4. Load Data from File";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (subjects.empty()) {
                    int numSubjects;
                    cout << "Enter the number of subjects: ";
                    cin >> numSubjects;
                    subjects.resize(numSubjects);
                    for (int i = 0; i < numSubjects; i++) {
                        cout << "Enter name of Subject " << i + 1 << ": ";
                        cin >> subjects[i];
                    }
                }
                students.push_back(inputStudentData(subjects));
                break;
            }
            case 2:
                for (const auto& student : students) {
                    displayStudentData(student);
                }
                break;
            case 3:
                saveStudentDataToFile(students);
                break;
            case 4:
                loadStudentDataFromFile();
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);
}

// Main function
int main() {
    menu();
    return 0;
}
