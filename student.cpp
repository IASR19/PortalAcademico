#include "student.h"

Student::Student(const std::string& username) : username(username) {}

std::vector<double> Student::getGrades() const {
    return grades;
}

std::vector<bool> Student::getAttendance() const {
    return attendance;
}

void Student::registerGrade(double grade) {
    grades.push_back(grade);
}

void Student::registerAttendance(bool attended) {
    attendance.push_back(attended);
}
