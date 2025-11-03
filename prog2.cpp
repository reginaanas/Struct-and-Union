#include <iostream>
#include <string>
using namespace std;

const int ARRAY_SIZE = 20;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

struct studentList {
    studentType students_array[ARRAY_SIZE];  
    int listLength;                      
};

void readStudentData(studentList& sList);
void assignGrades(studentList& sList);
int findHighestScore(const studentList& sList);
void printHighestScorers(const studentList& sList, int highestScore);
void displayAllStudents(const studentList& sList);
void processStudents(); 

int main() {
    processStudents(); 
    return 0;
}

void processStudents() {
    studentList sList;  
    sList.listLength = ARRAY_SIZE; 
    cout << "Enter 20 student data";
    readStudentData(sList);
    assignGrades(sList);
    int highestScore = findHighestScore(sList);

    cout << "\nAll Students:\n";
    displayAllStudents(sList);

    cout << "\nStudent(s) with the highest score (" << highestScore << "):\n";
    printHighestScorers(sList, highestScore);
}

void readStudentData(studentList& sList) {
    cout << "\nEnter student data (FirstName LastName Score):\n";
    for (int i = 0; i < sList.listLength; i++) {
        cout << "Student #" << i + 1 << ": ";
        cin >> sList.students_array[i].studentFName >> sList.students_array[i].studentLName >> sList.students_array[i].testScore;
    }
}

void assignGrades(studentList& sList) {
    for (int i = 0; i < sList.listLength; i++) {
        int score = sList.students_array[i].testScore;
        if (score >= 90)
            sList.students_array[i].grade = 'A';
        else if (score >= 80)
            sList.students_array[i].grade = 'B';
        else if (score >= 70)
            sList.students_array[i].grade = 'C';
        else if (score >= 60)
            sList.students_array[i].grade = 'D';
        else
            sList.students_array[i].grade = 'F';
    }
}

int findHighestScore(const studentList& sList) {
    int highest = sList.students_array[0].testScore;
    for (int i = 1; i < sList.listLength; i++) {
        if (sList.students_array[i].testScore > highest)
            highest = sList.students_array[i].testScore;
    }
    return highest;
}

void displayStudentInfo(const studentType& student) {
    cout << student.studentLName << ", " << student.studentFName << endl;
    cout << "Score: " << student.testScore << endl;
    cout << "Grade: " << student.grade << endl << endl;
}

void displayAllStudents(const studentList& sList) {
    for (int i = 0; i < sList.listLength; i++) {
        displayStudentInfo(sList.students_array[i]);
    }
}

void printHighestScorers(const studentList& sList, int highestScore) {
    for (int i = 0; i < sList.listLength; i++) {
        if (sList.students_array[i].testScore == highestScore)
            displayStudentInfo(sList.students_array[i]);
    }
}