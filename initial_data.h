// initial_data.h
// Declares the function to populate hardcoded initial data.

#ifndef INITIAL_DATA_H
#define INITIAL_DATA_H

#include "university_classes.h" // Include this to get class declarations (Book, Library, FoodItem, Cafeteria, etc.)
#include <vector> // Ensure vector is included if not already by university_classes.h
#include <string> // Ensure string is included

using namespace std; // Added for easier access to standard library components

// Function to populate initial hardcoded data into the vectors
// Note: The parameters for populateHardcodedData remain the same for backward compatibility
// but the actual population of Library and Cafeteria will happen via their specific functions.
void populateHardcodedData(
    vector<Student>& students,
    vector<Department>& departments,
    vector<Faculty>& faculties,
    vector<Course>& courses,
    // The following parameters are kept for compatibility but might not be directly used
    // for initial enrollments/assignments within this specific populate function.
    // They are primarily for the main University::loadInitialData to handle
    // complex assignments after all basic data is loaded.
    const vector<Course>& availableCourses, // To help with initial enrollments/assignments
    const vector<Faculty>& availableFaculties // To help with initial assignments
);

// New: Function to populate hardcoded/random book data into a Library object
void populateLibraryData(Library& library);

// New: Function to populate hardcoded/random cafeteria menu data into a Cafeteria object
void populateCafeteriaData(Cafeteria& cafeteria);

#endif // INITIAL_DATA_H
