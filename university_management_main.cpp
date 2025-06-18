// university_management_main.cpp
// Main program file for the University Management System.

#include "university_classes.h" // Include the header with University class definition
#include "initial_data.h"       // Include the header with data population function declarations

void University::loadInitialData() {

    populateHardcodedData(students, departments, faculties, courses,
                          std::vector<Course>(), std::vector<Faculty>());
    populateLibraryData(universityLibrary);
    populateCafeteriaData(universityCafeteria);
}

void University::run()
{
    loadInitialData(); // Load all initial data at startup

    int choice;
    do
    {
        displayMainMenu();
        choice = getIntegerInput("Enter your choice: ");

        switch (choice)
        {
        case 1: // Admission Management
            int admissionChoice;
            do
            {
                displayAdmissionMenu();
                admissionChoice = getIntegerInput("Enter your choice: ");
                switch (admissionChoice)
                {
                case 1:
                    addAdmission();
                    break;
                case 0:
                    std::cout << "Returning to Main Menu..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
                }
            } while (admissionChoice != 0);
            break;
        case 2: // Student Management
            int studentChoice;
            do
            {
                displayStudentMenu();
                studentChoice = getIntegerInput("Enter your choice: ");
                switch (studentChoice)
                {
                case 1:
                    addStudent();
                    break;
                case 2:
                    displayAllStudents();
                    break;
                case 3:
                    searchStudent();
                    break;
                case 4:
                    enrollStudentInCourse();
                    break;
                case 0:
                    std::cout << "Returning to Main Menu..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
                }
            } while (studentChoice != 0);
            break;
        case 3: // Department Management
            int departmentChoice;
            do
            {
                displayDepartmentMenu();
                departmentChoice = getIntegerInput("Enter your choice: ");
                switch (departmentChoice)
                {
                case 1:
                    addDepartment();
                    break;
                case 2:
                    displayAllDepartments();
                    break;
                case 3:
                    searchDepartment();
                    break;
                case 0:
                    std::cout << "Returning to Main Menu..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
                }
            } while (departmentChoice != 0);
            break;
        case 4: // Faculty Management
            int facultyChoice;
            do
            {
                displayFacultyMenu();
                facultyChoice = getIntegerInput("Enter your choice: ");
                switch (facultyChoice)
                {
                case 1:
                    addFaculty();
                    break;
                case 2:
                    displayAllFaculties();
                    break;
                case 3:
                    searchFaculty();
                    break;
                case 4:
                    assignCourseToFaculty();
                    break;
                case 0:
                    std::cout << "Returning to Main Menu..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
                }
            } while (facultyChoice != 0);
            break;
        case 5: // Course Management
            int courseChoice;
            do
            {
                displayCourseMenu();
                courseChoice = getIntegerInput("Enter your choice: ");
                switch (courseChoice)
                {
                case 1:
                    addCourse();
                    break;
                case 2:
                    displayAllCourses();
                    break;
                case 3:
                    searchCourse();
                    break;
                case 0:
                    std::cout << "Returning to Main Menu..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
                }
            } while (courseChoice != 0);
            break;
        case 6:              
            manageLibrary(); 
            break;
        case 7:                
            manageCafeteria(); 
            break;
        case 0:
            std::cout << "Exiting University Management System. Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (choice != 0);
}


int main()
{
    University myUniversity;
    myUniversity.run();
    return 0;
}