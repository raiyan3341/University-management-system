// university_classes.h
// Defines the declarations for Student, Department, Faculty, Course, and University classes.

#ifndef UNIVERSITY_CLASSES_H
#define UNIVERSITY_CLASSES_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::find_if and std::transform
#include <limits>    // For std::numeric_limits

// These helpers are common and can be declared here to be accessible by multiple classes/files.
void clearInputBuffer();
std::string getStringInput(const std::string &prompt);
int getIntegerInput(const std::string &prompt);

// --- Class Declarations ---

class Book
{
private:
    std::string bookID;
    std::string title;
    std::string author;
    std::string genre;
    bool isAvailable; // true if available, false if borrowed

public:
    Book(std::string id = "", std::string t = "", std::string auth = "",
         std::string g = "", bool available = true);

    std::string getBookID() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getGenre() const;
    bool getAvailability() const;

    void setAvailability(bool available);
    void displayBookInfo() const;
};

// New: Library Class
class Library
{
private:
    std::vector<Book> books;

public:
    void addBook(const Book &book);
    void displayAllBooks() const;
    void searchBookByTitle() const;
    void searchBookByAuthor() const;
    void searchBookByGenre() const;
    // Add functions for borrowing/returning if desired later
};

// New: FoodItem Class
class FoodItem
{
private:
    std::string itemID;
    std::string name;
    double price;
    std::string category; // e.g., "Main Course", "Snack", "Beverage"

public:
    FoodItem(std::string id = "", std::string n = "", double p = 0.0, std::string cat = "");

    std::string getItemID() const;
    std::string getName() const;
    double getPrice() const;
    std::string getCategory() const;

    void displayFoodItemInfo() const;
};

// New: Cafeteria Class
class Cafeteria
{
private:
    std::vector<FoodItem> menuItems;

public:
    void addMenuItem(const FoodItem &item);
    void displayAllMenuItems() const;
    void searchMenuItemByName() const;
    void searchMenuItemByCategory() const;
    // Add functions for ordering/payment if desired later
};

class Student
{
private:
    std::string studentID;
    std::string name;
    std::string dateOfBirth;
    std::string address;
    std::string phoneNumber;
    std::string email;
    std::string departmentEnrolled;
    std::vector<std::string> enrolledCourseIDs;
    double CGPA;
    std::string hscResult;
    std::string sscResult;

public:
    Student(std::string id = "", std::string n = "", std::string dob = "",
            std::string addr = "", std::string phone = "", std::string mail = "",
            std::string dept = "", double gpa = 0.0,
            std::string hscR = "", std::string sscR = "");

    std::string getStudentID() const;
    std::string getName() const;
    std::string getDateOfBirth() const;
    std::string getAddress() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
    std::string getDepartment() const; // Ensure this is available
    double getCGPA() const;
    const std::vector<std::string> &getEnrolledCourseIDs() const;
    std::string getHSCResult() const;
    std::string getSSCResult() const;

    void setCGPA(double gpa);
    void enrollCourse(const std::string &courseID);
    void displayStudentInfo() const;
};

class Department
{
private:
    std::string departmentID;
    std::string name;
    std::string headOfDepartment;
    int totalFacultyCount;
    int totalStudentCount;

public:
    Department(std::string id = "", std::string n = "", std::string hod = "",
               int facultyCount = 0, int studentCount = 0);

    std::string getDepartmentID() const;
    std::string getName() const; // Ensure this is available
    std::string getHeadOfDepartment() const;
    int getTotalFacultyCount() const;
    int getTotalStudentCount() const;

    void setHeadOfDepartment(const std::string &hod);
    void incrementFacultyCount();
    void decrementFacultyCount();
    void incrementStudentCount();
    void decrementStudentCount();
    void displayDepartmentInfo() const;
};

class Faculty
{
private:
    std::string facultyID;
    std::string name;
    std::string departmentAssigned;
    std::string designation;
    std::string email;
    std::vector<std::string> coursesTaughtIDs;

public:
    Faculty(std::string id = "", std::string n = "", std::string dept = "",
            std::string desig = "", std::string mail = "");

    std::string getFacultyID() const;
    std::string getName() const;
    std::string getDepartment() const; // Ensure this is available
    std::string getDesignation() const;
    std::string getEmail() const;
    const std::vector<std::string> &getCoursesTaughtIDs() const;

    void assignCourse(const std::string &courseID);
    void displayFacultyInfo() const;
};

class Course
{
private:
    std::string courseID;
    std::string title;
    std::string departmentOffering;
    int credits;
    std::string courseDescription;

public:
    Course(std::string id = "", std::string t = "", std::string dept = "",
           int c = 0, std::string desc = "");

    std::string getCourseID() const;
    std::string getTitle() const;
    std::string getDepartmentOffering() const;
    int getCredits() const;
    std::string getCourseDescription() const;

    void displayCourseInfo() const;
};

// In university_classes.h, inside the University class
class University
{
private:
    std::vector<Student> students;
    std::vector<Department> departments;
    std::vector<Faculty> faculties;
    std::vector<Course> courses;
    Library universityLibrary;
    Cafeteria universityCafeteria;

    void loadInitialData();

public:
    // Methods for each management type
    void addAdmission();
    void addStudent();
    void displayAllStudents() const; // Modified to ask for department
    void searchStudent() const;
    void enrollStudentInCourse();

    void addDepartment();
    void displayAllDepartments() const;
    void searchDepartment() const;

    void addFaculty();
    void displayAllFaculties() const;
    void searchFaculty() const;
    void assignCourseToFaculty();

    void addCourse();
    void displayAllCourses() const;
    void searchCourse() const;

    void manageLibrary();
    void displayLibraryMenu() const;

    void manageCafeteria(); // New function to handle cafeteria menu and operations
    void displayCafeteriaMenu() const;

    // Main program flow
    void displayMainMenu() const;
    void displayAdmissionMenu() const;
    void displayStudentMenu() const;
    void displayDepartmentMenu() const;
    void displayFacultyMenu() const;
    void displayCourseMenu() const;
    void run(); // Defined in university_management_main.cpp
};

#endif // UNIVERSITY_CLASSES_H
