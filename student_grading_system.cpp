#include <iostream>
#include <vector>
#include <iomanip> // for formatting output
#include <algorithm> // for std::find_if

using namespace std;

// Define structures for Student, Course, and Grade
struct Student {
    int id;
    string name;
};

struct Course {
    int code;
    string title;
};

struct Grade {
    int studentID;
    int courseCode;
    double assignmentScore;
    double examScore;
};

// Function declarations
void displayMenu();
void addStudent(vector<Student> &students);
void addCourse(vector<Course> &courses);
void recordGrade(vector<Student> &students, vector<Course> &courses, vector<Grade> &grades);
void displayGrades(vector<Student> &students,vector<Course> &courses, vector<Grade> &grades);

// Function to find a student by ID
vector<Student>::iterator findStudentByID(vector<Student> &students, int studentID) {
    vector<Student>::iterator studentIter;
    for (studentIter = students.begin(); studentIter != students.end(); ++studentIter) {
        if (studentIter->id == studentID) {
        // Student found
            return studentIter;
        }
    }

    if (studentIter == students.end()) {
        cout << "Error: Student not found.\n";
    }
    return studentIter;
}

// Function to find a course by code
vector<Course>::iterator findCourseByCode(vector<Course> &courses, int courseCode) {
    vector<Course>::iterator courseIter;

    for(courseIter = courses.begin(); courseIter!= courses.end(); ++courseIter){
        if(courseIter->code == courseCode){
            return courseIter;
        }
    }
    if (courseIter == courses.end()) {
        cout << "Error: Course not found.\n";
    }
    return courseIter;
}

int main() {
    vector<Student> students;
    vector<Course> courses;
    vector<Grade> grades;

    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                addCourse(courses);
                break;
            case 3:
                recordGrade(students, courses, grades);
                break;
            case 4:
                displayGrades(students, courses, grades);
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "\nStudent Grading System\n";
    cout << "1. Add Student\n";
    cout << "2. Add Course\n";
    cout << "3. Record Grade\n";
    cout << "4. Display Grades\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

void addStudent(vector<Student> &students) {
    Student newStudent;
    cout << "Enter student ID: ";
    cin >> newStudent.id;
    cout << "Enter student name: ";
    cin.ignore(); // Ignore newline character
    getline(cin, newStudent.name);

    students.push_back(newStudent);
    cout << "Student added successfully.\n";
}

void addCourse(vector<Course> &courses) {
    Course newCourse;
    cout << "Enter course code: ";
    cin >> newCourse.code;
    cout << "Enter course title: ";
    cin.ignore(); // Ignore newline character
    getline(cin, newCourse.title);

    courses.push_back(newCourse);
    cout << "Course added successfully.\n";
}

void recordGrade(vector<Student> &students, vector<Course> &courses, vector<Grade> &grades) {
    Grade newGrade;
    cout << "Enter student ID: ";
    cin >> newGrade.studentID;

    // Check if the entered student ID is valid
    auto studentIter = findStudentByID(students, newGrade.studentID);
    if (studentIter == students.end()) {
        cout << "Error: Student not found.\n";
        return;
    }

    cout << "Enter course code: ";
    cin >> newGrade.courseCode;

    // Check if the entered course code is valid
    auto courseIter = findCourseByCode(courses, newGrade.courseCode);
    if (courseIter == courses.end()) {
        cout << "Error: Course not found.\n";
        return;
    }

    cout << "Enter assignment score: ";
    cin >> newGrade.assignmentScore;
    cout << "Enter exam score: ";
    cin >> newGrade.examScore;

    grades.push_back(newGrade);
    cout << "Grade recorded successfully.\n";
}

void displayGrades(vector<Student> &students,vector<Course> &courses, vector<Grade> &grades) {
    if (grades.empty()) {
        cout << "No grades recorded yet.\n";
        return;
    }

    cout << "Student ID | Student Name | Course Code | Course Title | Assignment Score | Exam Score | Final Grade\n";
    cout << "---------------------------------------------------------------------------------------------\n";

    for (const auto &grade : grades) {
        auto student = findStudentByID(students, grade.studentID);
        auto course = findCourseByCode(courses, grade.courseCode);

        double finalGrade = 0.4 * grade.assignmentScore + 0.6 * grade.examScore;

        cout << setw(10) << grade.studentID << " | " << setw(12) << student->name << " | "
             << setw(11) << grade.courseCode << " | " << setw(12) << course->title << " | "
             << setw(17) << grade.assignmentScore << " | " << setw(9) << grade.examScore << " | "
             << setw(11) << finalGrade << "\n";
    }
}
