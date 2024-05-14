#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>

class Student {
public:
    Student(const std::string& username);
    std::vector<double> getGrades() const;
    std::vector<bool> getAttendance() const;
    void registerGrade(double grade);
    void registerAttendance(bool attended);
private:
    std::string username;
    std::vector<double> grades;
    std::vector<bool> attendance;
};

#endif
