#ifndef UNIVERSITY_CLASSES_H
#define UNIVERSITY_CLASSES_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

void clearInputBuffer();
string getStringInput(const string &prompt);
int getIntegerInput(const string &prompt);

// --- Class Declarations ---

class Book
{
private:
    string bookID;
    string title;
    string author;
    string genre;
    bool isAvailable;

public:
    Book(string id = "", string t = "", string auth = "",
         string g = "", bool available = true);

    string getBookID() const;
    string getTitle() const;
    string getAuthor() const;
    string getGenre() const;
    bool getAvailability() const;

    void setAvailability(bool available);
    void displayBookInfo() const;
};

// New: Library Class
class Library
{
private:
    vector<Book> books;

public:
    void addBook(const Book &book);
    void displayAllBooks() const;
    void searchBookByTitle() const;
    void searchBookByAuthor() const;
    void searchBookByGenre() const;
};

// New: FoodItem Class
class FoodItem
{
private:
    string itemID;
    string name;
    double price;
    string category;

public:
    FoodItem(string id = "", string n = "", double p = 0.0, string cat = "");
    string getItemID() const;
    string getName() const;
    double getPrice() const;
    string getCategory() const;

    void displayFoodItemInfo() const;
};

// New: Cafeteria Class
class Cafeteria
{
private:
    vector<FoodItem> menuItems;

public:
    void addMenuItem(const FoodItem &item);
    void displayAllMenuItems() const;
    void searchMenuItemByName() const;
    void searchMenuItemByCategory() const;
};

class Student
{
private:
    string studentID;
    string name;
    string dateOfBirth;
    string address;
    string phoneNumber;
    string email;
    string departmentEnrolled;
    vector<string> enrolledCourseIDs;
    double CGPA;
    string hscResult;
    string sscResult;

public:
    Student(string id = "", string n = "", string dob = "",
            string addr = "", string phone = "", string mail = "",
            string dept = "", double gpa = 0.0,
            string hscR = "", string sscR = "");

    string getStudentID() const;
    string getName() const;
    string getDateOfBirth() const;
    string getAddress() const;
    string getPhoneNumber() const;
    string getEmail() const;
    string getDepartment() const;
    double getCGPA() const;
    const vector<string> &getEnrolledCourseIDs() const;
    string getHSCResult() const;
    string getSSCResult() const;

    void setCGPA(double gpa);
    void enrollCourse(const string &courseID);
    void displayStudentInfo() const;
};

class Department
{
private:
    string departmentID;
    string name;
    string headOfDepartment;
    int totalFacultyCount;
    int totalStudentCount;

public:
    Department(string id = "", string n = "", string hod = "",
    int facultyCount = 0, int studentCount = 0);

    string getDepartmentID() const;
    string getName() const;
    string getHeadOfDepartment() const;
    int getTotalFacultyCount() const;
    int getTotalStudentCount() const;

    void setHeadOfDepartment(const string &hod);
    void incrementFacultyCount();
    void decrementFacultyCount();
    void incrementStudentCount();
    void decrementStudentCount();
    void displayDepartmentInfo() const;
};

class Faculty
{
private:
    string facultyID;
    string name;
    string departmentAssigned;
    string designation;
    string email;
    vector<string> coursesTaughtIDs;

public:
    Faculty(string id = "", string n = "", string dept = "",
            string desig = "", string mail = "");

    string getFacultyID() const;
    string getName() const;
    string getDepartment() const;
    string getDesignation() const;
    string getEmail() const;
    const vector<string> &getCoursesTaughtIDs() const;

    void assignCourse(const string &courseID);
    void displayFacultyInfo() const;
};

class Course
{
private:
    string courseID;
    string title;
    string departmentOffering;
    int credits;
    string courseDescription;

public:
    Course(string id = "", string t = "", string dept = "",
           int c = 0, string desc = "");

    string getCourseID() const;
    string getTitle() const;
    string getDepartmentOffering() const;
    int getCredits() const;
    string getCourseDescription() const;

    void displayCourseInfo() const;
};


class University
{
private:
    vector<Student> students;
    vector<Department> departments;
    vector<Faculty> faculties;
    vector<Course> courses;
    Library universityLibrary;
    Cafeteria universityCafeteria;

    void loadInitialData();

public:
    void addAdmission();
    void addStudent();
    void displayAllStudents() const;
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

    void manageCafeteria();
    void displayCafeteriaMenu() const;

    // Main program flow
    void displayMainMenu() const;
    void displayAdmissionMenu() const;
    void displayStudentMenu() const;
    void displayDepartmentMenu() const;
    void displayFacultyMenu() const;
    void displayCourseMenu() const;
    void run();
};

#endif
