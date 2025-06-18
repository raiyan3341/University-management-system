// university_classes.cpp
// Defines the implementations for Student, Department, Faculty, Course,
// Book, Library, FoodItem, Cafeteria, and University classes.

#include "university_classes.h" // Include the header with class declarations
#include <iomanip>              // Required for std::fixed and std::setprecision

// --- Helper Functions Implementations ---

void clearInputBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string getStringInput(const std::string &prompt)
{
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

int getIntegerInput(const std::string &prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail())
        {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            clearInputBuffer();
        }
        else
        {
            clearInputBuffer();
            return value;
        }
    }
}

// --- Class Implementations ---

// Student Class
Student::Student(std::string id, std::string n, std::string dob,
                 std::string addr, std::string phone, std::string mail,
                 std::string dept, double gpa,
                 std::string hscR, std::string sscR)
    : studentID(id), name(n), dateOfBirth(dob), address(addr),
      phoneNumber(phone), email(mail), departmentEnrolled(dept), CGPA(gpa),
      hscResult(hscR), sscResult(sscR) {}

std::string Student::getStudentID() const { return studentID; }
std::string Student::getName() const { return name; }
std::string Student::getDateOfBirth() const { return dateOfBirth; }
std::string Student::getAddress() const { return address; }
std::string Student::getPhoneNumber() const { return phoneNumber; }
std::string Student::getEmail() const { return email; }
std::string Student::getDepartment() const { return departmentEnrolled; }
double Student::getCGPA() const { return CGPA; }
const std::vector<std::string> &Student::getEnrolledCourseIDs() const { return enrolledCourseIDs; }
std::string Student::getHSCResult() const { return hscResult; }
std::string Student::getSSCResult() const { return sscResult; }

void Student::setCGPA(double gpa) { CGPA = gpa; }

void Student::enrollCourse(const std::string &courseID)
{
    bool alreadyEnrolled = false;
    for (const std::string &id : enrolledCourseIDs)
    {
        if (id == courseID)
        {
            alreadyEnrolled = true;
            break;
        }
    }
    if (!alreadyEnrolled)
    {
        enrolledCourseIDs.push_back(courseID);
    }
}

void Student::displayStudentInfo() const
{
    std::cout << "\n--- Student Details ---" << std::endl;
    std::cout << "Student ID: " << studentID << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Date of Birth: " << dateOfBirth << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Department: " << departmentEnrolled << std::endl;
    std::cout << "HSC Result: " << hscResult << std::endl;
    std::cout << "SSC Result: " << sscResult << std::endl;
    std::cout << "CGPA: " << CGPA << std::endl;
    std::cout << "Enrolled Courses: ";
    if (enrolledCourseIDs.empty())
    {
        std::cout << "None" << std::endl;
    }
    else
    {
        for (const std::string &courseID : enrolledCourseIDs)
        {
            std::cout << courseID << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------" << std::endl;
}

// Department Class
Department::Department(std::string id, std::string n, std::string hod,
                       int facultyCount, int studentCount)
    : departmentID(id), name(n), headOfDepartment(hod),
      totalFacultyCount(facultyCount), totalStudentCount(studentCount) {}

std::string Department::getDepartmentID() const { return departmentID; }
std::string Department::getName() const { return name; }
std::string Department::getHeadOfDepartment() const { return headOfDepartment; }
int Department::getTotalFacultyCount() const { return totalFacultyCount; }
int Department::getTotalStudentCount() const { return totalStudentCount; }

void Department::setHeadOfDepartment(const std::string &hod) { headOfDepartment = hod; }
void Department::incrementFacultyCount() { totalFacultyCount++; }
void Department::decrementFacultyCount()
{
    if (totalFacultyCount > 0)
        totalFacultyCount--;
}
void Department::incrementStudentCount() { totalStudentCount++; }
void Department::decrementStudentCount()
{
    if (totalStudentCount > 0)
        totalStudentCount--;
}

void Department::displayDepartmentInfo() const
{
    std::cout << "\n--- Department Details ---" << std::endl;
    std::cout << "Department ID: " << departmentID << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Head of Department: " << headOfDepartment << std::endl;
    std::cout << "Total Faculty: " << totalFacultyCount << std::endl;
    std::cout << "Total Students: " << totalStudentCount << std::endl;
    std::cout << "--------------------------" << std::endl;
}

// Faculty Class
Faculty::Faculty(std::string id, std::string n, std::string dept,
                 std::string desig, std::string mail)
    : facultyID(id), name(n), departmentAssigned(dept),
      designation(desig), email(mail) {}

std::string Faculty::getFacultyID() const { return facultyID; }
std::string Faculty::getName() const { return name; }
std::string Faculty::getDepartment() const { return departmentAssigned; }
std::string Faculty::getDesignation() const { return designation; }
std::string Faculty::getEmail() const { return email; }
const std::vector<std::string> &Faculty::getCoursesTaughtIDs() const { return coursesTaughtIDs; }

void Faculty::assignCourse(const std::string &courseID)
{
    bool alreadyAssigned = false;
    for (const std::string &id : coursesTaughtIDs)
    {
        if (id == courseID)
        {
            alreadyAssigned = true;
            break;
        }
    }
    if (!alreadyAssigned)
    {
        coursesTaughtIDs.push_back(courseID);
    }
}

void Faculty::displayFacultyInfo() const
{
    std::cout << "\n--- Faculty Details ---" << std::endl;
    std::cout << "Faculty ID: " << facultyID << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Department: " << departmentAssigned << std::endl;
    std::cout << "Designation: " << designation << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Courses Taught: ";
    if (coursesTaughtIDs.empty())
    {
        std::cout << "None" << std::endl;
    }
    else
    {
        for (const std::string &courseID : coursesTaughtIDs)
        {
            std::cout << courseID << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------" << std::endl;
}

// Course Class
Course::Course(std::string id, std::string t, std::string dept,
               int c, std::string desc)
    : courseID(id), title(t), departmentOffering(dept),
      credits(c), courseDescription(desc) {}

std::string Course::getCourseID() const { return courseID; }
std::string Course::getTitle() const { return title; }
std::string Course::getDepartmentOffering() const { return departmentOffering; }
int Course::getCredits() const { return credits; }
std::string Course::getCourseDescription() const { return courseDescription; }

void Course::displayCourseInfo() const
{
    std::cout << "\n--- Course Details ---" << std::endl;
    std::cout << "Course ID: " << courseID << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Department: " << departmentOffering << std::endl;
    std::cout << "Credits: " << credits << std::endl;
    std::cout << "Description: " << courseDescription << std::endl;
    std::cout << "----------------------" << std::endl;
}

// --- New Class Implementations ---

// Book Class Implementations
Book::Book(std::string id, std::string t, std::string auth, std::string g, bool available)
    : bookID(id), title(t), author(auth), genre(g), isAvailable(available) {}

std::string Book::getBookID() const { return bookID; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getGenre() const { return genre; }
bool Book::getAvailability() const { return isAvailable; }

void Book::setAvailability(bool available) { isAvailable = available; }

void Book::displayBookInfo() const
{
    std::cout << "  ID: " << bookID
              << ", Title: \"" << title << "\""
              << ", Author: " << author
              << ", Genre: " << genre
              << ", Status: " << (isAvailable ? "Available" : "Borrowed") << std::endl;
}

// Library Class Implementations
void Library::addBook(const Book &book)
{
    books.push_back(book);
}

void Library::displayAllBooks() const
{
    if (books.empty())
    {
        std::cout << "\nNo books in the library yet." << std::endl;
        return;
    }
    std::cout << "\n--- All Books in Library ---" << std::endl;
    for (const auto &book : books)
    {
        book.displayBookInfo();
    }
    std::cout << "----------------------------" << std::endl;
}

void Library::searchBookByTitle() const
{
    std::string searchTerm = getStringInput("Enter Book Title to search: ");
    bool found = false;
    std::cout << "\n--- Search Results (Books by Title) ---" << std::endl;
    std::string searchTermLower = searchTerm;
    std::transform(searchTermLower.begin(), searchTermLower.end(), searchTermLower.begin(), ::tolower);

    for (const auto &book : books)
    {
        std::string bookTitleLower = book.getTitle();
        std::transform(bookTitleLower.begin(), bookTitleLower.end(), bookTitleLower.begin(), ::tolower);
        if (bookTitleLower.find(searchTermLower) != std::string::npos)
        {
            book.displayBookInfo();
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "No book found with '" << searchTerm << "' in its title." << std::endl;
    }
    std::cout << "---------------------------------------" << std::endl;
}

void Library::searchBookByAuthor() const
{
    std::string searchTerm = getStringInput("Enter Author Name to search: ");
    bool found = false;
    std::cout << "\n--- Search Results (Books by Author) ---" << std::endl;
    std::string searchTermLower = searchTerm;
    std::transform(searchTermLower.begin(), searchTermLower.end(), searchTermLower.begin(), ::tolower);

    for (const auto &book : books)
    {
        std::string authorNameLower = book.getAuthor();
        std::transform(authorNameLower.begin(), authorNameLower.end(), authorNameLower.begin(), ::tolower);
        if (authorNameLower.find(searchTermLower) != std::string::npos)
        {
            book.displayBookInfo();
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "No book found by author '" << searchTerm << "'." << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
}

void Library::searchBookByGenre() const
{
    std::string searchTerm = getStringInput("Enter Genre to search (e.g., Fiction, Science, History): ");
    bool found = false;
    std::cout << "\n--- Search Results (Books by Genre) ---" << std::endl;
    std::string searchTermLower = searchTerm;
    std::transform(searchTermLower.begin(), searchTermLower.end(), searchTermLower.begin(), ::tolower);

    for (const auto &book : books)
    {
        std::string genreLower = book.getGenre();
        std::transform(genreLower.begin(), genreLower.end(), genreLower.begin(), ::tolower);
        if (genreLower.find(searchTermLower) != std::string::npos)
        {
            book.displayBookInfo();
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "No book found in genre '" << searchTerm << "'." << std::endl;
    }
    std::cout << "---------------------------------------" << std::endl;
}

// FoodItem Class Implementations
FoodItem::FoodItem(std::string id, std::string n, double p, std::string cat)
    : itemID(id), name(n), price(p), category(cat) {}

std::string FoodItem::getItemID() const { return itemID; }
std::string FoodItem::getName() const { return name; }
double FoodItem::getPrice() const { return price; }
std::string FoodItem::getCategory() const { return category; }

void FoodItem::displayFoodItemInfo() const
{
    std::cout << "  ID: " << itemID
              << ", Name: " << name
              << ", Price: " << std::fixed << std::setprecision(2) << price << " BDT"
              << ", Category: " << category << std::endl;
}

// Cafeteria Class Implementations
void Cafeteria::addMenuItem(const FoodItem &item)
{
    menuItems.push_back(item);
}

void Cafeteria::displayAllMenuItems() const
{
    if (menuItems.empty())
    {
        std::cout << "\nNo food items in the cafeteria menu yet." << std::endl;
        return;
    }
    std::cout << "\n--- All Cafeteria Menu Items ---" << std::endl;
    for (const auto &item : menuItems)
    {
        item.displayFoodItemInfo();
    }
    std::cout << "--------------------------------" << std::endl;
}

void Cafeteria::searchMenuItemByName() const
{
    std::string searchTerm = getStringInput("Enter Food Item Name to search: ");
    bool found = false;
    std::cout << "\n--- Search Results (Food Items by Name) ---" << std::endl;
    std::string searchTermLower = searchTerm;
    std::transform(searchTermLower.begin(), searchTermLower.end(), searchTermLower.begin(), ::tolower);

    for (const auto &item : menuItems)
    {
        std::string itemNameLower = item.getName();
        std::transform(itemNameLower.begin(), itemNameLower.end(), itemNameLower.begin(), ::tolower);
        if (itemNameLower.find(searchTermLower) != std::string::npos)
        {
            item.displayFoodItemInfo();
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "No food item found with '" << searchTerm << "' in its name." << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;
}

void Cafeteria::searchMenuItemByCategory() const
{
    std::string searchTerm = getStringInput("Enter Category to search (e.g., Main Course, Snack, Beverage): ");
    bool found = false;
    std::cout << "\n--- Search Results (Food Items by Category) ---" << std::endl;
    std::string searchTermLower = searchTerm;
    std::transform(searchTermLower.begin(), searchTermLower.end(), searchTermLower.begin(), ::tolower);

    for (const auto &item : menuItems)
    {
        std::string categoryLower = item.getCategory();
        std::transform(categoryLower.begin(), categoryLower.end(), categoryLower.begin(), ::tolower);
        if (categoryLower.find(searchTermLower) != std::string::npos)
        {
            item.displayFoodItemInfo();
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "No food item found in category '" << searchTerm << "'." << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
}

// University Class Method Implementations (excluding loadInitialData and run)
void University::addAdmission()
{
    std::cout << "\n--- Submit Admission Application ---" << std::endl;
    std::string studentName = getStringInput("Enter Student Name: ");
    std::string studentID = getStringInput("Enter Student ID: ");
    std::string phoneNumber = getStringInput("Enter Phone Number: ");
    std::string address = getStringInput("Enter Address: ");
    std::string email = getStringInput("Enter Email: ");
    std::string hscResult = getStringInput("Enter HSC Result (e.g., 5.00): ");
    std::string sscResult = getStringInput("Enter SSC Result (e.g., 4.50): ");
    std::string departmentChoice = getStringInput("Enter Preferred Department (e.g., Computer Science and Engineering, Electrical and Electronic Engineering, Bangla, English, Textile): ");

    std::cout << "\nAdmission submitted successfully!" << std::endl;
}

void University::addStudent()
{
    std::cout << "\n--- Add New Student ---" << std::endl;
    std::string id = getStringInput("Enter Student ID: ");

    for (const auto &s : students)
    {
        if (s.getStudentID() == id)
        {
            std::cout << "Error: Student with this ID already exists." << std::endl;
            return;
        }
    }

    std::string name = getStringInput("Enter Name: ");
    std::string dob = getStringInput("Enter Date of Birth (DD-MM-YYYY): ");
    std::string address = getStringInput("Enter Address: ");
    std::string phone = getStringInput("Enter Phone Number: ");
    std::string email = getStringInput("Enter Email: ");
    std::string department = getStringInput("Enter Enrolled Department (e.g., Computer Science and Engineering, Electrical and Electronic Engineering, Bangla, English, Textile): ");
    std::string hscResult = getStringInput("Enter HSC Result (e.g., 5.00): ");
    std::string sscResult = getStringInput("Enter SSC Result (e.g., 4.50): ");
    double cgpa = 0.0;

    students.emplace_back(id, name, dob, address, phone, email, department, cgpa, hscResult, sscResult);
    std::cout << "Student added successfully!" << std::endl;

    auto it_dept = std::find_if(departments.begin(), departments.end(),
                                [&](const Department &d)
                                { return d.getName() == department; });
    if (it_dept != departments.end())
    {
        it_dept->incrementStudentCount();
    }
    else
    {
        std::cout << "Warning: Department '" << department << "' not found. Student count not updated." << std::endl;
    }
}

void University::displayAllStudents() const
{
    if (students.empty())
    {
        std::cout << "\nNo students registered yet." << std::endl;
        return;
    }
    std::cout << "\n--- All Registered Students ---" << std::endl;
    for (const auto &student : students)
    {
        student.displayStudentInfo();
    }
}

void University::searchStudent() const
{
    std::string studentID = getStringInput("Enter Student ID: ");
    std::string departmentName = getStringInput("Enter Student's Department: ");
    bool found = false;
    std::cout << "\n--- Search Results (Students) ---" << std::endl;
    for (const auto &student : students)
    {
        if (student.getStudentID() == studentID && student.getDepartment() == departmentName)
        {
            student.displayStudentInfo();
            found = true;
            break;
        }
    }
    if (!found)
    {
        std::cout << "No student found matching this ID and Department." << std::endl;
    }
}

void University::enrollStudentInCourse()
{
    std::string studentID = getStringInput("Enter Student ID to enroll in a course: ");
    auto it_student = std::find_if(students.begin(), students.end(),
                                   [&](const Student &s)
                                   { return s.getStudentID() == studentID; });

    if (it_student != students.end())
    {
        std::string courseID = getStringInput("Enter Course ID to enroll: ");
        auto it_course = std::find_if(courses.begin(), courses.end(),
                                      [&](const Course &c)
                                      { return c.getCourseID() == courseID; });

        if (it_course != courses.end())
        {
            if (it_student->getDepartment() == it_course->getDepartmentOffering())
            {
                it_student->enrollCourse(courseID);
                std::cout << "Student '" << it_student->getName() << "' successfully enrolled in course '" << it_course->getTitle() << "'." << std::endl;
            }
            else
            {
                std::cout << "Error: Course '" << it_course->getTitle() << "' belongs to a different department than student '" << it_student->getName() << "'." << std::endl;
            }
        }
        else
        {
            std::cout << "Error: Course with ID '" << courseID << "' not found." << std::endl;
        }
    }
    else
    {
        std::cout << "Error: Student with ID '" << studentID << "' not found." << std::endl;
    }
}

void University::addDepartment()
{
    std::cout << "\n--- Add New Department ---" << std::endl;
    std::string id = getStringInput("Enter Department ID (e.g., CSE001): ");

    for (const auto &d : departments)
    {
        if (d.getDepartmentID() == id)
        {
            std::cout << "Error: Department with this ID already exists." << std::endl;
            return;
        }
    }

    std::string name = getStringInput("Enter Department Name (e.g., Computer Science and Engineering, Bangla, English, Textile, Electrical and Electronic Engineering): ");

    std::string nameLower = name;
    std::transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
    for (const auto &d : departments)
    {
        std::string existingNameLower = d.getName();
        std::transform(existingNameLower.begin(), existingNameLower.end(), existingNameLower.begin(), ::tolower);
        if (existingNameLower == nameLower)
        {
            std::cout << "Error: Department with this name already exists." << std::endl;
            return;
        }
    }

    std::string hod = getStringInput("Enter Head of Department's Name: ");

    departments.emplace_back(id, name, hod);
    std::cout << "Department added successfully!" << std::endl;
}

void University::displayAllDepartments() const
{
    if (departments.empty())
    {
        std::cout << "\nNo departments registered yet." << std::endl;
        return;
    }
    std::cout << "\n--- All Registered Departments ---" << std::endl;
    for (const auto &department : departments)
    {
        department.displayDepartmentInfo();
    }
}

void University::searchDepartment() const
{
    std::string searchTerm = getStringInput("Enter Department ID or Name to search: ");
    bool found = false;
    std::cout << "\n--- Search Results (Departments) ---" << std::endl;
    for (const auto &department : departments)
    {
        std::string deptNameLower = department.getName();
        std::transform(deptNameLower.begin(), deptNameLower.end(), deptNameLower.begin(), ::tolower);
        std::string searchTermLower = searchTerm;
        std::transform(searchTermLower.begin(), searchTermLower.end(), searchTermLower.begin(), ::tolower);

        if (department.getDepartmentID() == searchTerm || deptNameLower.find(searchTermLower) != std::string::npos)
        {
            department.displayDepartmentInfo();
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "No department found matching the search term." << std::endl;
    }
}

void University::addFaculty()
{
    std::cout << "\n--- Add New Faculty ---" << std::endl;
    std::string id = getStringInput("Enter Faculty ID: ");

    for (const auto &f : faculties)
    {
        if (f.getFacultyID() == id)
        {
            std::cout << "Error: Faculty with this ID already exists." << std::endl;
            return;
        }
    }

    std::string name = getStringInput("Enter Name: ");
    std::string department = getStringInput("Enter Assigned Department (e.g., Computer Science and Engineering, Electrical and Electronic Engineering, Bangla, English, Textile): ");

    auto it_dept = std::find_if(departments.begin(), departments.end(),
                                [&](const Department &d)
                                { return d.getName() == department; });
    if (it_dept == departments.end())
    {
        std::cout << "Error: Department '" << department << "' does not exist. Please add the department first." << std::endl;
        return;
    }

    std::string designation = getStringInput("Enter Designation (e.g., Professor, Lecturer): ");
    std::string email = getStringInput("Enter Email: ");

    faculties.emplace_back(id, name, department, designation, email);
    std::cout << "Faculty added successfully!" << std::endl;

    it_dept->incrementFacultyCount();
}

void University::displayAllFaculties() const
{
    if (faculties.empty())
    {
        std::cout << "\nNo faculties registered yet." << std::endl;
        return;
    }
    std::cout << "\n--- All Registered Faculties ---" << std::endl;
    for (const auto &faculty : faculties)
    {
        faculty.displayFacultyInfo();
    }
}

void University::searchFaculty() const
{
    std::string facultyName = getStringInput("Enter Faculty Name: ");
    std::string departmentName = getStringInput("Enter Faculty's Department: ");
    bool found = false;
    std::cout << "\n--- Search Results (Faculties) ---" << std::endl;

    std::string facultyNameLower = facultyName;
    std::transform(facultyNameLower.begin(), facultyNameLower.end(), facultyNameLower.begin(), ::tolower);
    std::string departmentNameLower = departmentName;
    std::transform(departmentNameLower.begin(), departmentNameLower.end(), departmentNameLower.begin(), ::tolower);

    for (const auto &faculty : faculties)
    {
        std::string currentFacultyNameLower = faculty.getName();
        std::transform(currentFacultyNameLower.begin(), currentFacultyNameLower.end(), currentFacultyNameLower.begin(), ::tolower);
        std::string currentDepartmentNameLower = faculty.getDepartment();
        std::transform(currentDepartmentNameLower.begin(), currentDepartmentNameLower.end(), currentDepartmentNameLower.begin(), ::tolower);

        if (currentFacultyNameLower.find(facultyNameLower) != std::string::npos &&
            currentDepartmentNameLower.find(departmentNameLower) != std::string::npos)
        {
            faculty.displayFacultyInfo();
            found = true;
            break;
        }
    }
    if (!found)
    {
        std::cout << "No faculty found matching this name and department." << std::endl;
    }
}

void University::assignCourseToFaculty()
{
    std::string facultyID = getStringInput("Enter Faculty ID to assign a course: ");
    auto it_faculty = std::find_if(faculties.begin(), faculties.end(),
                                   [&](const Faculty &f)
                                   { return f.getFacultyID() == facultyID; });

    if (it_faculty != faculties.end())
    {
        std::string courseID = getStringInput("Enter Course ID to assign: ");
        auto it_course = std::find_if(courses.begin(), courses.end(),
                                      [&](const Course &c)
                                      { return c.getCourseID() == courseID; });

        if (it_course != courses.end())
        {
            if (it_faculty->getDepartment() == it_course->getDepartmentOffering())
            {
                it_faculty->assignCourse(courseID);
                std::cout << "Course '" << it_course->getTitle() << "' successfully assigned to faculty '" << it_faculty->getName() << "'." << std::endl;
            }
            else
            {
                std::cout << "Error: Course '" << it_course->getTitle() << "' belongs to a different department than faculty '" << it_faculty->getName() << "'." << std::endl;
            }
        }
        else
        {
            std::cout << "Error: Course with ID '" << courseID << "' not found." << std::endl;
        }
    }
    else
    {
        std::cout << "Error: Faculty with ID '" << facultyID << "' not found." << std::endl;
    }
}

void University::addCourse()
{
    std::cout << "\n--- Add New Course ---" << std::endl;
    std::string id = getStringInput("Enter Course ID (e.g., CSC101): ");

    for (const auto &c : courses)
    {
        if (c.getCourseID() == id)
        {
            std::cout << "Error: Course with this ID already exists." << std::endl;
            return;
        }
    }

    std::string title = getStringInput("Enter Course Title: ");
    std::string department = getStringInput("Enter Department Offering Course (e.g., Computer Science and Engineering, Electrical and Electronic Engineering, Bangla, English, Textile): ");

    auto it_dept = std::find_if(departments.begin(), departments.end(),
                                [&](const Department &d)
                                { return d.getName() == department; });
    if (it_dept == departments.end())
    {
        std::cout << "Error: Department '" << department << "' does not exist. Please add the department first." << std::endl;
        return;
    }

    int credits = getIntegerInput("Enter Credits for the course: ");
    std::string description = getStringInput("Enter Course Description: ");

    courses.emplace_back(id, title, department, credits, description);
    std::cout << "Course added successfully!" << std::endl;
}

void University::displayAllCourses() const
{
    if (courses.empty())
    {
        std::cout << "\nNo courses registered yet." << std::endl;
        return;
    }
    std::cout << "\n--- All Registered Courses ---" << std::endl;
    for (const auto &course : courses)
    {
        course.displayCourseInfo();
    }
}

void University::searchCourse() const
{
    std::string searchTerm = getStringInput("Enter Course ID or Title to search: ");
    bool found = false;
    std::cout << "\n--- Search Results (Courses) ---" << std::endl;
    for (const auto &course : courses)
    {
        std::string courseTitleLower = course.getTitle();
        std::transform(courseTitleLower.begin(), courseTitleLower.end(), courseTitleLower.begin(), ::tolower);
        std::string searchTermLower = searchTerm;
        std::transform(searchTermLower.begin(), searchTermLower.end(), searchTermLower.begin(), ::tolower);

        if (course.getCourseID() == searchTerm || courseTitleLower.find(searchTermLower) != std::string::npos)
        {
            course.displayCourseInfo();
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "No course found matching the search term." << std::endl;
    }
}

// --- New University Class Method Implementations ---

// Library Management
void University::displayLibraryMenu() const
{
    std::cout << "\n--- Library Management ---" << std::endl;
    std::cout << "1. Display All Books" << std::endl;
    std::cout << "2. Search Book by Title" << std::endl;
    std::cout << "3. Search Book by Author" << std::endl;
    std::cout << "4. Search Book by Genre" << std::endl;
    std::cout << "0. Back to Main Menu" << std::endl;
    std::cout << "--------------------------" << std::endl;
}

void University::manageLibrary()
{
    int libraryChoice;
    do
    {
        displayLibraryMenu();
        libraryChoice = getIntegerInput("Enter your choice: ");
        switch (libraryChoice)
        {
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
            std::cout << "Returning to Main Menu..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (libraryChoice != 0);
}

// Cafeteria Management
void University::displayCafeteriaMenu() const
{
    std::cout << "\n--- Cafeteria Management ---" << std::endl;
    std::cout << "1. Display All Menu Items" << std::endl;
    std::cout << "2. Search Menu Item by Name" << std::endl;
    std::cout << "3. Search Menu Item by Category" << std::endl;
    std::cout << "0. Back to Main Menu" << std::endl;
    std::cout << "----------------------------" << std::endl;
}

void University::manageCafeteria()
{
    int cafeteriaChoice;
    do
    {
        displayCafeteriaMenu();
        cafeteriaChoice = getIntegerInput("Enter your choice: ");
        switch (cafeteriaChoice)
        {
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
            std::cout << "Returning to Main Menu..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (cafeteriaChoice != 0);
}

void University::displayMainMenu() const
{
    std::cout << "\n===== University Management System =====" << std::endl;
    std::cout << "1. Admission Management" << std::endl;
    std::cout << "2. Student Management" << std::endl;
    std::cout << "3. Department Management" << std::endl;
    std::cout << "4. Faculty Management" << std::endl;
    std::cout << "5. Course Management" << std::endl;
    // New Options
    std::cout << "6. Library Management" << std::endl;   // New
    std::cout << "7. Cafeteria Management" << std::endl; // New
    std::cout << "0. Exit" << std::endl;
    std::cout << "========================================" << std::endl;
}

void University::displayAdmissionMenu() const
{
    std::cout << "\n--- Admission Management ---" << std::endl;
    std::cout << "1. Submit New Admission Application" << std::endl;
    std::cout << "0. Back to Main Menu" << std::endl;
    std::cout << "--------------------------" << std::endl;
}

void University::displayStudentMenu() const
{
    std::cout << "\n--- Student Management ---" << std::endl;
    std::cout << "1. Add New Student" << std::endl;
    std::cout << "2. Display All Students" << std::endl;
    std::cout << "3. Search Student by ID and Department" << std::endl;
    std::cout << "4. Enroll Student in Course" << std::endl;
    std::cout << "0. Back to Main Menu" << std::endl;
    std::cout << "--------------------------" << std::endl;
}

void University::displayDepartmentMenu() const
{
    std::cout << "\n--- Department Management ---" << std::endl;
    std::cout << "1. Add New Department" << std::endl;
    std::cout << "2. Display All Departments" << std::endl;
    std::cout << "3. Search Department" << std::endl;
    std::cout << "0. Back to Main Menu" << std::endl;
    std::cout << "-----------------------------" << std::endl;
}

void University::displayFacultyMenu() const
{
    std::cout << "\n--- Faculty Management ---" << std::endl;
    std::cout << "1. Add New Faculty" << std::endl;
    std::cout << "2. Display All Faculties" << std::endl;
    std::cout << "3. Search Faculty by Name and Department" << std::endl;
    std::cout << "4. Assign Course to Faculty" << std::endl;
    std::cout << "0. Back to Main Menu" << std::endl;
    std::cout << "--------------------------" << std::endl;
}

void University::displayCourseMenu() const
{
    std::cout << "\n--- Course Management ---" << std::endl;
    std::cout << "1. Add New Course" << std::endl;
    std::cout << "2. Display All Courses" << std::endl;
    std::cout << "3. Search Course" << std::endl;
    std::cout << "0. Back to Main Menu" << std::endl;
    std::cout << "-------------------------" << std::endl;
}
