#include <iostream>
#include <string>
#include <map>
#include <vector>

class StudentDetails {
private:
    std::string name;
    std::string gender;
    std::string email;
    std::string phoneNumber;

public:
    StudentDetails() = default;

    StudentDetails(const std::string& name, const std::string& gender, const std::string& email, const std::string& phoneNumber)
        : name(name), gender(gender), email(email), phoneNumber(phoneNumber) {}

    void setName(const std::string& name) {
        this->name = name;
    }

    void setGender(const std::string& gender) {
        this->gender = gender;
    }
    void setEmail(const std::string& email) {
        this->email = email;
    }
    void setPhoneNumber(const std::string& phoneNumber) {
        this->phoneNumber = phoneNumber;
    }

    std::string getName() const {
        return name;
    }

    std::string getGender() const {
        return gender;
    }

    std::string getEmail() const {
        return email;
    }

    std::string getPhoneNumber() const {
        return phoneNumber;
    }
};

struct Course {
    std::string courseName;
    int marks;
};

// Function to input course details
Course inputCourseDetails() {
    Course course;
    std::string courseName;

    std::cout << "Enter course name: ";
    std::cin.ignore(); // Clear the newline character left in the input buffer
    std::getline(std::cin, courseName);
    course.courseName = courseName;

    std::cout << "Enter marks for " << courseName << ": ";
    std::cin >> course.marks;

    return course;
}

int main() {
    std::map<std::string, StudentDetails> students;
    std::map<std::string, std::vector<Course>> studentCourses;

    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        std::string id;
        std::cout << "Enter student ID: ";
        std::cin >> id;

        std::string name, gender, email, phoneNumber;
        std::cout << "Enter student name: ";
        std::cin.ignore(); // Clear the newline character left in the input buffer
        std::getline(std::cin, name);
        std::cout << "Enter student gender: ";
        std::cin >> gender;
        std::cout << "Enter student email: ";
        std::cin >> email;
        std::cout << "Enter student phoneNumber: ";
        std::cin >> phoneNumber;

        students[id] = StudentDetails(name, gender, email, phoneNumber);

        int numCourses;
        std::cout << "Enter the number of courses for student " << id << ": ";
        std::cin >> numCourses;

        for (int j = 0; j < numCourses; j++) {
            studentCourses[id].push_back(inputCourseDetails());
        }
    }

    std::string studentIDToAccess;
    std::cout << "Enter a student ID to access details: ";
    std::cin >> studentIDToAccess;

    if (students.find(studentIDToAccess) != students.end()) {
        std::cout << "Name of student " << studentIDToAccess << ": " << students[studentIDToAccess].getName() << std::endl;

        if (studentCourses.find(studentIDToAccess) != studentCourses.end()) {
            std::vector<Course>& courses = studentCourses[studentIDToAccess];

            std::cout << "Course details for student " << studentIDToAccess << ":\n";
            for (const Course& course : courses) {
                std::cout << "Course: " << course.courseName << ", Marks: " << course.marks << std::endl;
            }

            // Allow editing course details
            std::cout << "Do you want to edit course details? (Y/N): ";
            char choice;
            std::cin >> choice;

            if (choice == 'Y' || choice == 'y') {
                for (Course& course : courses) {
                    Course editedCourse = inputCourseDetails();
                    course = editedCourse; // Update the course details
                }
            }
        }
    } else {
        std::cout << "Student not found." << std::endl;
    }

    return 0;
}
