// university_classes.cpp
// Defines the implementations for Student, Department, Faculty, Course,
// Book, Library, FoodItem, Cafeteria, and University classes.

#include "university_classes.h"
#include <iomanip>
#include <algorithm>
#include <limits>
using namespace std;

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string getStringInput(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

int getIntegerInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            clearInputBuffer();
        } else {
            clearInputBuffer();
            return value;
        }
    }
}


// Student Class
Student::Student(string id, string n, string dob,
                 string addr, string phone, string mail,
                 string dept, double gpa,
                 string hscR, string sscR)
    : studentID(id), name(n), dateOfBirth(dob), address(addr),
      phoneNumber(phone), email(mail), departmentEnrolled(dept), CGPA(gpa),
      hscResult(hscR), sscResult(sscR) {}

string Student::getStudentID() const { return studentID; }
string Student::getName() const { return name; }
string Student::getDateOfBirth() const { return dateOfBirth; }
string Student::getAddress() const { return address; }
string Student::getPhoneNumber() const { return phoneNumber; }
string Student::getEmail() const { return email; }
string Student::getDepartment() const { return departmentEnrolled; }
double Student::getCGPA() const { return CGPA; }
const vector<string>& Student::getEnrolledCourseIDs() const { return enrolledCourseIDs; }
string Student::getHSCResult() const { return hscResult; }
string Student::getSSCResult() const { return sscResult; }

void Student::setCGPA(double gpa) { CGPA = gpa; }

void Student::enrollCourse(const string& courseID) {
    bool alreadyEnrolled = false;
    for (const string& id : enrolledCourseIDs) {
        if (id == courseID) {
            alreadyEnrolled = true;
            break;
        }
    }
    if (!alreadyEnrolled) {
        enrolledCourseIDs.push_back(courseID);
    }
}

void Student::displayStudentInfo() const {
    cout << "\n--- Student Details ---" << endl;
    cout << "Student ID: " << studentID << endl;
    cout << "Name: " << name << endl;
    cout << "Date of Birth: " << dateOfBirth << endl;
    cout << "Address: " << address << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Email: " << email << endl;
    cout << "Department: " << departmentEnrolled << endl;
    cout << "HSC Result: " << hscResult << endl;
    cout << "SSC Result: " << sscResult << endl;
    cout << "CGPA: " << CGPA << endl;
    cout << "Enrolled Courses: ";
    if (enrolledCourseIDs.empty()) {
        cout << "None" << endl;
    } else {
        for (const string& courseID : enrolledCourseIDs) {
            cout << courseID << " ";
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
}

// Department Class
Department::Department(string id, string n, string hod,
                       int facultyCount, int studentCount)
    : departmentID(id), name(n), headOfDepartment(hod),
      totalFacultyCount(facultyCount), totalStudentCount(studentCount) {}

string Department::getDepartmentID() const { return departmentID; }
string Department::getName() const { return name; }
string Department::getHeadOfDepartment() const { return headOfDepartment; }
int Department::getTotalFacultyCount() const { return totalFacultyCount; }
int Department::getTotalStudentCount() const { return totalStudentCount; }

void Department::setHeadOfDepartment(const string& hod) { headOfDepartment = hod; }
void Department::incrementFacultyCount() { totalFacultyCount++; }
void Department::decrementFacultyCount() { if (totalFacultyCount > 0) totalFacultyCount--; }
void Department::incrementStudentCount() { totalStudentCount++; }
void Department::decrementStudentCount() { if (totalStudentCount > 0) totalStudentCount--; }

void Department::displayDepartmentInfo() const {
    cout << "\n--- Department Details ---" << endl;
    cout << "Department ID: " << departmentID << endl;
    cout << "Name: " << name << endl;
    cout << "Head of Department: " << headOfDepartment << endl;
    cout << "Total Faculty: " << totalFacultyCount << endl;
    cout << "Total Students: " << totalStudentCount << endl;
    cout << "--------------------------" << endl;
}

// Faculty Class
Faculty::Faculty(string id, string n, string dept,
                 string desig, string mail)
    : facultyID(id), name(n), departmentAssigned(dept),
      designation(desig), email(mail) {}

string Faculty::getFacultyID() const { return facultyID; }
string Faculty::getName() const { return name; }
string Faculty::getDepartment() const { return departmentAssigned; }
string Faculty::getDesignation() const { return designation; }
string Faculty::getEmail() const { return email; }
const vector<string>& Faculty::getCoursesTaughtIDs() const { return coursesTaughtIDs; }

void Faculty::assignCourse(const string& courseID) {
    bool alreadyAssigned = false;
    for (const string& id : coursesTaughtIDs) {
        if (id == courseID) {
            alreadyAssigned = true;
            break;
        }
    }
    if (!alreadyAssigned) {
        coursesTaughtIDs.push_back(courseID);
    }
}

void Faculty::displayFacultyInfo() const {
    cout << "\n--- Faculty Details ---" << endl;
    cout << "Faculty ID: " << facultyID << endl;
    cout << "Name: " << name << endl;
    cout << "Department: " << departmentAssigned << endl;
    cout << "Designation: " << designation << endl;
    cout << "Email: " << email << endl;
    cout << "Courses Taught: ";
    if (coursesTaughtIDs.empty()) {
        cout << "None" << endl;
    } else {
        for (const string& courseID : coursesTaughtIDs) {
            cout << courseID << " ";
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
}

// Course Class
Course::Course(string id, string t, string dept,
               int c, string desc)
    : courseID(id), title(t), departmentOffering(dept),
      credits(c), courseDescription(desc) {}

string Course::getCourseID() const { return courseID; }
string Course::getTitle() const { return title; }
string Course::getDepartmentOffering() const { return departmentOffering; }
int Course::getCredits() const { return credits; }
string Course::getCourseDescription() const { return courseDescription; }

void Course::displayCourseInfo() const {
    cout << "\n--- Course Details ---" << endl;
    cout << "Course ID: " << courseID << endl;
    cout << "Title: " << title << endl;
    cout << "Department: " << departmentOffering << endl;
    cout << "Credits: " << credits << endl;
    cout << "Description: " << courseDescription << endl;
    cout << "----------------------" << endl;
}

// --- New Class Implementations ---

// Book Class Implementations
Book::Book(string id, string t, string auth, string g, bool available)
    : bookID(id), title(t), author(auth), genre(g), isAvailable(available) {}

string Book::getBookID() const { return bookID; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getGenre() const { return genre; }
bool Book::getAvailability() const { return isAvailable; }

void Book::setAvailability(bool available) { isAvailable = available; }

void Book::displayBookInfo() const {
    cout << "  ID: " << bookID
              << ", Title: \"" << title << "\""
              << ", Author: " << author
              << ", Genre: " << genre
              << ", Status: " << (isAvailable ? "Available" : "Borrowed") << endl;
}

// Library Class Implementations
void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::displayAllBooks() const {
    if (books.empty()) {
        cout << "\nNo books in the library yet." << endl;
        return;
    }
    cout << "\n--- All Books in Library ---" << endl;
    for (const auto& book : books) {
        book.displayBookInfo();
    }
    cout << "----------------------------" << endl;
}

void Library::searchBookByTitle() const {
    string searchTerm = getStringInput("Enter Book Title to search: ");
    bool found = false;
    cout << "\n--- Search Results (Books by Title) ---" << endl;
    string searchTermLower = searchTerm;
    transform(searchTermLower.begin(), searchTermLower.end(), searchTermLower.begin(), ::tolower);

    for (const auto& book : books) {
        string bookTitleLower = book.getTitle();
        transform(bookTitleLower.begin(), bookTitleLower.end(), bookTitleLower.begin(), ::tolower);
        if (bookTitleLower.find(searchTermLower) != string::npos) {
            book.displayBookInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No book found with '" << searchTerm << "' in its title." << endl;
    }
    cout << "---------------------------------------" << endl;
}

void Library::searchBookByAuthor() const {
    string searchTerm = getStringInput("Enter Author Name to search: ");
    bool found = false;
    cout << "\n--- Search Results (Books by Author) ---" << endl;
    string searchTermLower = searchTerm;
    transform(searchTermLower.begin(), searchTermLower.end(), searchTermLower.begin(), ::tolower);

    for (const auto& book : books) {
        string authorNameLower = book.getAuthor();
        transform(authorNameLower.begin(), authorNameLower.end(), authorNameLower.begin(), ::tolower);
        if (authorNameLower.find(searchTermLower) != string::npos) {
            book.displayBookInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No book found by author '" << searchTerm << "'." << endl;
    }
    cout << "----------------------------------------" << endl;
}

void Library::searchBookByGenre() const {
    string searchTerm = getStringInput("Enter Genre to search (e.g., Fiction, Science, History): ");
    bool found = false;
    cout << "\n--- Search Results (Books by Genre) ---" << endl;
    string searchTermLower = searchTerm;
    transform(searchTermLower.begin(), searchTermLower.end(), searchTermLower.begin(), ::tolower);

    for (const auto& book : books) {
        string genreLower = book.getGenre();
        transform(genreLower.begin(), genreLower.end(), genreLower.begin(), ::tolower);
        if (genreLower.find(searchTermLower) != string::npos) {
            book.displayBookInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No book found in genre '" << searchTerm << "'." << endl;
    }
    cout << "---------------------------------------" << endl;
}

// FoodItem Class Implementations
FoodItem::FoodItem(string id, string n, double p, string cat)
    : itemID(id), name(n), price(p), category(cat) {}

string FoodItem::getItemID() const { return itemID; }
string FoodItem::getName() const { return name; }
double FoodItem::getPrice() const { return price; }
string FoodItem::getCategory() const { return category; }

void FoodItem::displayFoodItemInfo() const {
    cout << "  ID: " << itemID
              << ", Name: " << name
              << ", Price: " << fixed << setprecision(2) << price << " BDT"
              << ", Category: " << category << endl;
}

// Cafeteria Class Implementations
void Cafeteria::addMenuItem(const FoodItem& item) {
    menuItems.push_back(item);
}

void Cafeteria::displayAllMenuItems() const {
    if (menuItems.empty()) {
        cout << "\nNo food items in the cafeteria menu yet." << endl;
        return;
    }
    cout << "\n--- All Cafeteria Menu Items ---" << endl;
    for (const auto& item : menuItems) {
        item.displayFoodItemInfo();
    }
    cout << "--------------------------------" << endl;
}

void Cafeteria::searchMenuItemByName() const {
    string searchTerm = getStringInput("Enter Food Item Name to search: ");
    bool found = false;
    cout << "\n--- Search Results (Food Items by Name) ---" << endl;
    string searchTermLower = searchTerm;
    transform(searchTermLower.begin(), searchTermLower.end(), searchTermLower.begin(), ::tolower);

    for (const auto& item : menuItems) {
        string itemNameLower = item.getName();
        transform(itemNameLower.begin(), itemNameLower.end(), itemNameLower.begin(), ::tolower);
        if (itemNameLower.find(searchTermLower) != string::npos) {
            item.displayFoodItemInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No food item found with '" << searchTerm << "' in its name." << endl;
    }
    cout << "------------------------------------------" << endl;
}

void Cafeteria::searchMenuItemByCategory() const {
    string searchTerm = getStringInput("Enter Category to search (e.g., Main Course, Snack, Beverage): ");
    bool found = false;
    cout << "\n--- Search Results (Food Items by Category) ---" << endl;
    string searchTermLower = searchTerm;
    transform(searchTermLower.begin(), searchTermLower.end(), searchTermLower.begin(), ::tolower);

    for (const auto& item : menuItems) {
        string categoryLower = item.getCategory();
        transform(categoryLower.begin(), categoryLower.end(), categoryLower.begin(), ::tolower);
        if (categoryLower.find(searchTermLower) != string::npos) {
            item.displayFoodItemInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No food item found in category '" << searchTerm << "'." << endl;
    }
    cout << "---------------------------------------------" << endl;
}

// University Class Method Implementations (excluding loadInitialData and run)
void University::addAdmission() {
    cout << "\n--- Submit Admission Application ---" << endl;
    string studentName = getStringInput("Enter Student Name: ");
    string studentID = getStringInput("Enter Student ID: ");
    string phoneNumber = getStringInput("Enter Phone Number: ");
    string address = getStringInput("Enter Address: ");
    string email = getStringInput("Enter Email: ");
    string hscResult = getStringInput("Enter HSC Result (e.g., 5.00): ");
    string sscResult = getStringInput("Enter SSC Result (e.g., 4.50): ");
    string departmentChoice = getStringInput("Enter Preferred Department (e.g., Computer Science and Engineering, Electrical and Electronic Engineering, Bangla, English, Textile): ");

    cout << "\nAdmission submitted successfully!" << endl;
}

void University::addStudent() {
    cout << "\n--- Add New Student ---" << endl;
    string id = getStringInput("Enter Student ID: ");

    for (const auto& s : students) {
        if (s.getStudentID() == id) {
            cout << "Error: Student with this ID already exists." << endl;
            return;
        }
    }

    string name = getStringInput("Enter Name: ");
    string dob = getStringInput("Enter Date of Birth (DD-MM-YYYY): ");
    string address = getStringInput("Enter Address: ");
    string phone = getStringInput("Enter Phone Number: ");
    string email = getStringInput("Enter Email: ");
    string department = getStringInput("Enter Enrolled Department (e.g., Computer Science and Engineering, Electrical and Electronic Engineering, Bangla, English, Textile): ");
    string hscResult = getStringInput("Enter HSC Result (e.g., 5.00): ");
    string sscResult = getStringInput("Enter SSC Result (e.g., 4.50): ");
    double cgpa = 0.0;

    students.emplace_back(id, name, dob, address, phone, email, department, cgpa, hscResult, sscResult);
    cout << "Student added successfully!" << endl;

    auto it_dept = find_if(departments.begin(), departments.end(),
                                [&](const Department& d){ return d.getName() == department; });
    if (it_dept != departments.end()) {
        it_dept->incrementStudentCount();
    } else {
        cout << "Warning: Department '" << department << "' not found. Student count not updated." << endl;
    }
}

// --- UPDATED displayAllStudents() ---
void University::displayAllStudents() const {
    string deptName = getStringInput("Enter Department Name to display students from : ");

    // Convert input department name to lowercase for case-insensitive comparison
    string deptNameLower = deptName;
    transform(deptNameLower.begin(), deptNameLower.end(), deptNameLower.begin(), ::tolower);

    bool departmentFound = false;
    for (const auto& d : departments) {
        string currentDeptNameLower = d.getName();
        transform(currentDeptNameLower.begin(), currentDeptNameLower.end(), currentDeptNameLower.begin(), ::tolower);
        if (currentDeptNameLower == deptNameLower) {
            departmentFound = true;
            break;
        }
    }

    if (!departmentFound) {
        cout << "Error: Department '" << deptName << "' not found." << endl;
        return;
    }

    bool foundStudents = false;
    cout << "\n--- All Students in " << deptName << " Department ---" << endl;
    for (const auto& student : students) {
        // Convert student's department name to lowercase for comparison
        string studentDeptLower = student.getDepartment();
        transform(studentDeptLower.begin(), studentDeptLower.end(), studentDeptLower.begin(), ::tolower);

        if (studentDeptLower == deptNameLower) {
            student.displayStudentInfo();
            foundStudents = true;
        }
    }
    if (!foundStudents) {
        cout << "No students registered in " << deptName << " yet." << endl;
    }
    cout << "---------------------------------------" << endl;
}

void University::searchStudent() const {
    string studentID = getStringInput("Enter Student ID: ");
    string departmentName = getStringInput("Enter Student's Department: ");
    bool found = false;
    cout << "\n--- Search Results (Students) ---" << endl;
    for (const auto& student : students) {
        if (student.getStudentID() == studentID && student.getDepartment() == departmentName) {
            student.displayStudentInfo();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No student found matching this ID and Department." << endl;
    }
}

void University::enrollStudentInCourse() {
    string studentID = getStringInput("Enter Student ID to enroll in a course: ");
    auto it_student = find_if(students.begin(), students.end(),
                                   [&](const Student& s){ return s.getStudentID() == studentID; });

    if (it_student != students.end()) {
        string courseID = getStringInput("Enter Course ID to enroll: ");
        auto it_course = find_if(courses.begin(), courses.end(),
                                       [&](const Course& c){ return c.getCourseID() == courseID; });

        if (it_course != courses.end()) {
            if (it_student->getDepartment() == it_course->getDepartmentOffering()) {
                it_student->enrollCourse(courseID);
                cout << "Student '" << it_student->getName() << "' successfully enrolled in course '" << it_course->getTitle() << "'." << endl;
            } else {
                cout << "Error: Course '" << it_course->getTitle() << "' belongs to a different department than student '" << it_student->getName() << "'." << endl;
            }
        } else {
            cout << "Error: Course with ID '" << courseID << "' not found." << endl;
        }
    } else {
        cout << "Error: Student with ID '" << studentID << "' not found." << endl;
    }
}

void University::addDepartment() {
    cout << "\n--- Add New Department ---" << endl;
    string id = getStringInput("Enter Department ID (e.g., CSE001): ");

    for (const auto& d : departments) {
        if (d.getDepartmentID() == id) {
            cout << "Error: Department with this ID already exists." << endl;
            return;
        }
    }

    string name = getStringInput("Enter Department Name (e.g., Computer Science and Engineering, Bangla, English, Textile, Electrical and Electronic Engineering): ");

    string nameLower = name;
    transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
    for (const auto& d : departments) {
        string existingNameLower = d.getName();
        transform(existingNameLower.begin(), existingNameLower.end(), existingNameLower.begin(), ::tolower);
        if (existingNameLower == nameLower) {
            cout << "Error: Department with this name already exists." << endl;
            return;
        }
    }

    string hod = getStringInput("Enter Head of Department's Name: ");

    departments.emplace_back(id, name, hod);
    cout << "Department added successfully!" << endl;
}

void University::displayAllDepartments() const {
    if (departments.empty()) {
        cout << "\nNo departments registered yet." << endl;
        return;
    }
    cout << "\n--- All Registered Departments ---" << endl;
    for (const auto& department : departments) {
        department.displayDepartmentInfo();
    }
}

void University::searchDepartment() const {
    string searchTerm = getStringInput("Enter Department ID or Name to search: ");
    bool found = false;
    cout << "\n--- Search Results (Departments) ---" << endl;
    for (const auto& department : departments) {
        string deptNameLower = department.getName();
        transform(deptNameLower.begin(), deptNameLower.end(), deptNameLower.begin(), ::tolower);
        string searchTermLower = searchTerm;
        transform(searchTermLower.begin(), searchTermLower.end(), searchTermLower.begin(), ::tolower);

        if (department.getDepartmentID() == searchTerm || deptNameLower.find(searchTermLower) != string::npos) {
            department.displayDepartmentInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No department found matching the search term." << endl;
    }
}

void University::addFaculty() {
    cout << "\n--- Add New Faculty ---" << endl;
    string id = getStringInput("Enter Faculty ID: ");

    for (const auto& f : faculties) {
        if (f.getFacultyID() == id) {
            cout << "Error: Faculty with this ID already exists." << endl;
            return;
        }
    }

    string name = getStringInput("Enter Name: ");
    string department = getStringInput("Enter Assigned Department (e.g., Computer Science and Engineering, Electrical and Electronic Engineering, Bangla, English, Textile): ");

    auto it_dept = find_if(departments.begin(), departments.end(),
                                [&](const Department& d){ return d.getName() == department; });
    if (it_dept == departments.end()) {
        cout << "Error: Department '" << department << "' does not exist. Please add the department first." << endl;
        return;
    }

    string designation = getStringInput("Enter Designation (e.g., Professor, Lecturer): ");
    string email = getStringInput("Enter Email: ");

    faculties.emplace_back(id, name, department, designation, email);
    cout << "Faculty added successfully!" << endl;

    it_dept->incrementFacultyCount();
}

// --- UPDATED displayAllFaculties() ---
void University::displayAllFaculties() const {
    string deptName = getStringInput("Enter Department Name to display faculties from : ");
    string deptNameLower = deptName;
    transform(deptNameLower.begin(), deptNameLower.end(), deptNameLower.begin(), ::tolower);

    bool departmentFound = false;
    for (const auto& d : departments) {
        string currentDeptNameLower = d.getName();
        transform(currentDeptNameLower.begin(), currentDeptNameLower.end(), currentDeptNameLower.begin(), ::tolower);
        if (currentDeptNameLower == deptNameLower) {
            departmentFound = true;
            break;
        }
    }

    if (!departmentFound) {
        cout << "Error: Department '" << deptName << "' not found." << endl;
        return;
    }

    bool foundFaculties = false;
    cout << "\n--- All Faculties in " << deptName << " Department ---" << endl;
    for (const auto& faculty : faculties) {
        string facultyDeptLower = faculty.getDepartment();
        transform(facultyDeptLower.begin(), facultyDeptLower.end(), facultyDeptLower.begin(), ::tolower);

        if (facultyDeptLower == deptNameLower) {
            faculty.displayFacultyInfo();
            foundFaculties = true;
        }
    }
    if (!foundFaculties) {
        cout << "No faculties registered in " << deptName << " yet." << endl;
    }
    cout << "---------------------------------------" << endl;
}

void University::searchFaculty() const {
    string facultyName = getStringInput("Enter Faculty Name: ");
    string departmentName = getStringInput("Enter Faculty's Department: ");
    bool found = false;
    cout << "\n--- Search Results (Faculties) ---" << endl;

    string facultyNameLower = facultyName;
    transform(facultyNameLower.begin(), facultyNameLower.end(), facultyNameLower.begin(), ::tolower);
    string departmentNameLower = departmentName;
    transform(departmentNameLower.begin(), departmentNameLower.end(), departmentNameLower.begin(), ::tolower);

    for (const auto& faculty : faculties) {
        string currentFacultyNameLower = faculty.getName();
        transform(currentFacultyNameLower.begin(), currentFacultyNameLower.end(), currentFacultyNameLower.begin(), ::tolower);
        string currentDepartmentNameLower = faculty.getDepartment();
        transform(currentDepartmentNameLower.begin(), currentDepartmentNameLower.end(), currentDepartmentNameLower.begin(), ::tolower);

        if (currentFacultyNameLower.find(facultyNameLower) != string::npos &&
            currentDepartmentNameLower.find(departmentNameLower) != string::npos) {
            faculty.displayFacultyInfo();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No faculty found matching this name and department." << endl;
    }
}

void University::assignCourseToFaculty() {
    string facultyID = getStringInput("Enter Faculty ID to assign a course: ");
    auto it_faculty = find_if(faculties.begin(), faculties.end(),
                                   [&](const Faculty& f){ return f.getFacultyID() == facultyID; });

    if (it_faculty != faculties.end()) {
        string courseID = getStringInput("Enter Course ID to assign: ");
        auto it_course = find_if(courses.begin(), courses.end(),
                                       [&](const Course& c){ return c.getCourseID() == courseID; });

        if (it_course != courses.end()) {
            if (it_faculty->getDepartment() == it_course->getDepartmentOffering()) {
                it_faculty->assignCourse(courseID);
                cout << "Course '" << it_course->getTitle() << "' successfully assigned to faculty '" << it_faculty->getName() << "'." << endl;
            } else {
                cout << "Error: Course '" << it_course->getTitle() << "' belongs to a different department than faculty '" << it_faculty->getName() << "'." << endl;
            }
        } else {
            cout << "Error: Course with ID '" << courseID << "' not found." << endl;
        }
    } else {
        cout << "Error: Faculty with ID '" << facultyID << "' not found." << endl;
    }
}

void University::addCourse() {
    cout << "\n--- Add New Course ---" << endl;
    string id = getStringInput("Enter Course ID (e.g., CSC101): ");

    for (const auto& c : courses) {
        if (c.getCourseID() == id) {
            cout << "Error: Course with this ID already exists." << endl;
            return;
        }
    }

    string title = getStringInput("Enter Course Title: ");
    string department = getStringInput("Enter Department Offering Course (e.g., Computer Science and Engineering, Electrical and Electronic Engineering, Bangla, English, Textile): ");

    auto it_dept = find_if(departments.begin(), departments.end(),
                                [&](const Department& d){ return d.getName() == department; });
    if (it_dept == departments.end()) {
        cout << "Error: Department '" << department << "' does not exist. Please add the department first." << endl;
        return;
    }

    int credits = getIntegerInput("Enter Credits for the course: ");
    string description = getStringInput("Enter Course Description: ");

    courses.emplace_back(id, title, department, credits, description);
    cout << "Course added successfully!" << endl;
}

void University::displayAllCourses() const {
    if (courses.empty()) {
        cout << "\nNo courses registered yet." << endl;
        return;
    }
    cout << "\n--- All Registered Courses ---" << endl;
    for (const auto& course : courses) {
        course.displayCourseInfo();
    }
}

void University::searchCourse() const {
    string searchTerm = getStringInput("Enter Course ID or Title to search: ");
    bool found = false;
    cout << "\n--- Search Results (Courses) ---" << endl;
    for (const auto& course : courses) {
        string courseTitleLower = course.getTitle();
        transform(courseTitleLower.begin(), courseTitleLower.end(), courseTitleLower.begin(), ::tolower);
        string searchTermLower = searchTerm;
        transform(searchTermLower.begin(), searchTermLower.end(), searchTermLower.begin(), ::tolower);

        if (course.getCourseID() == searchTerm || courseTitleLower.find(searchTermLower) != string::npos) {
            course.displayCourseInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No course found matching the search term." << endl;
    }
}

// Library Management
void University::displayLibraryMenu() const {
    cout << "\n--- Library Management ---" << endl;
    cout << "1. Display All Books" << endl;
    cout << "2. Search Book by Title" << endl;
    cout << "3. Search Book by Author" << endl;
    cout << "4. Search Book by Genre" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "--------------------------" << endl;
}

void University::manageLibrary() {
    int libraryChoice;
    do {
        displayLibraryMenu();
        libraryChoice = getIntegerInput("Enter your choice: ");
        switch (libraryChoice) {
        case 1:
            universityLibrary.displayAllBooks();
            break;
        case 2:
            universityLibrary.searchBookByTitle();
            break;
        case 3:
            universityLibrary.searchBookByAuthor();
            break;
        case 4:
            universityLibrary.searchBookByGenre();
            break;
        case 0:
            cout << "Returning to Main Menu..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (libraryChoice != 0);
}

// Cafeteria Management
void University::displayCafeteriaMenu() const {
    cout << "\n--- Cafeteria Management ---" << endl;
    cout << "1. Display All Menu Items" << endl;
    cout << "2. Search Menu Item by Name" << endl;
    cout << "3. Search Menu Item by Category" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "----------------------------" << endl;
}

void University::manageCafeteria() {
    int cafeteriaChoice;
    do {
        displayCafeteriaMenu();
        cafeteriaChoice = getIntegerInput("Enter your choice: ");
        switch (cafeteriaChoice) {
        case 1:
            universityCafeteria.displayAllMenuItems();
            break;
        case 2:
            universityCafeteria.searchMenuItemByName();
            break;
        case 3:
            universityCafeteria.searchMenuItemByCategory();
            break;
        case 0:
            cout << "Returning to Main Menu..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (cafeteriaChoice != 0);
}

void University::displayMainMenu() const {
    cout << "\n===== University Management System =====" << endl;
    cout << "1. Admission Management" << endl;
    cout << "2. Student Management" << endl;
    cout << "3. Department Management" << endl;
    cout << "4. Faculty Management" << endl;
    cout << "5. Course Management" << endl;
    cout << "6. Library Management" << endl;
    cout << "7. Cafeteria Management" << endl;
    cout << "0. Exit" << endl;
    cout << "========================================" << endl;
}

void University::displayAdmissionMenu() const {
    cout << "\n--- Admission Management ---" << endl;
    cout << "1. Submit New Admission Application" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "--------------------------" << endl;
}

void University::displayStudentMenu() const {
    cout << "\n--- Student Management ---" << endl;
    cout << "1. Add New Student" << endl;
    cout << "2. Display All Students " << endl;
    cout << "3. Search Student by ID and Department" << endl;
    cout << "4. Enroll Student in Course" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "--------------------------" << endl;
}

void University::displayDepartmentMenu() const {
    cout << "\n--- Department Management ---" << endl;
    cout << "1. Add New Department" << endl;
    cout << "2. Display All Departments" << endl;
    cout << "3. Search Department" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "-----------------------------" << endl;
}

void University::displayFacultyMenu() const {
    cout << "\n--- Faculty Management ---" << endl;
    cout << "1. Add New Faculty" << endl;
    cout << "2. Display All Faculties " << endl;
    cout << "3. Search Faculty by Name and Department" << endl;
    cout << "4. Assign Course to Faculty" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "--------------------------" << endl;
}

void University::displayCourseMenu() const {
    cout << "\n--- Course Management ---" << endl;
    cout << "1. Add New Course" << endl;
    cout << "2. Display All Courses" << endl;
    cout << "3. Search Course" << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "-------------------------" << endl;
}
