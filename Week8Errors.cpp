#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int age;

public:
    Student(const std::string& studentName, int studentAge)
        : name(studentName), age(studentAge) {
    }

    void printInfo() const {
        std::cout << "Student: " << name << ", Age: " << age << std::endl;
    }
};

class Course {
private:
    std:string title;
    Student student;

public:
    Course(const std::string& courseTitle, const Student& enrolledStudent)
        : title(courseTitle), student(enrolledStudent) {
    }

    void showCourse() const {
        std::cout << "Course: " << title << std::endl;
        student.printInfo();
    }
};

int main() {
    Student s1("Alice", "20");
    Course c1("Algorithms", s1);

    c1.showCourse();

    return 0;
}