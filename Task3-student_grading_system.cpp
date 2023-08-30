#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    double grade;
};

int main() {
    vector<Student> studentData;

    while (true) {
        string name;
        cout << "Enter student name (or 'exit' to finish): ";
        getline(cin, name);

        if (name == "exit") {
            break;
        }

        double grade;
        cout << "Enter grade for " << name << ": ";
        cin >> grade;
        cin.ignore();  // Clear the newline character from the buffer

        studentData.push_back({name, grade});
    }

    if (studentData.empty()) {
        cout << "No data entered." << endl;
        return 0;
    }

    double totalGrades = 0.0;
    for (const auto& student : studentData) {
        totalGrades += student.grade;
    }
    double averageGrade = totalGrades / studentData.size();

    sort(studentData.begin(), studentData.end(), [](const Student& a, const Student& b) {
        return a.grade < b.grade;
    });

    const Student& lowest = studentData.front();
    const Student& highest = studentData.back();

    cout << "Average grade: " << averageGrade << endl;
    cout << "Lowest grade: " << lowest.name << " = " << lowest.grade << endl;
    cout << "Highest grade: " << highest.name << " = " << highest.grade << endl;

    return 0;
}
