// initial_data.h
// Declares the function to populate hardcoded initial data.

#ifndef INITIAL_DATA_H
#define INITIAL_DATA_H

#include "university_classes.h" // Include this to get class declarations (Book, Library, FoodItem, Cafeteria, etc.)

// Function to populate initial hardcoded data into the vectors
// Note: The parameters for populateHardcodedData remain the same for backward compatibility
// but the actual population of Library and Cafeteria will happen via their specific functions.
void populateHardcodedData(
    std::vector<Student>& students,
    std::vector<Department>& departments,
    std::vector<Faculty>& faculties,
    std::vector<Course>& courses,
    // The following parameters are kept for compatibility but might not be directly used
    // for initial enrollments/assignments within this specific populate function.
    // They are primarily for the main University::loadInitialData to handle
    // complex assignments after all basic data is loaded.
    const std::vector<Course>& availableCourses, // To help with initial enrollments/assignments
    const std::vector<Faculty>& availableFaculties // To help with initial assignments
);

// New: Function to populate hardcoded/random book data into a Library object
void populateLibraryData(Library& library);

// New: Function to populate hardcoded/random cafeteria menu data into a Cafeteria object
void populateCafeteriaData(Cafeteria& cafeteria);

#endif // INITIAL_DATA_H
