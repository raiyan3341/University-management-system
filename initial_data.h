// initial_data.h
// Declares the function to populate hardcoded initial data.

#ifndef INITIAL_DATA_H
#define INITIAL_DATA_H
#include "university_classes.h" 
#include <vector>
#include <string>
using namespace std;

void populateHardcodedData(
    vector<Student>& students,
    vector<Department>& departments,
    vector<Faculty>& faculties,
    vector<Course>& courses,
    
    const vector<Course>& availableCourses,
    const vector<Faculty>& availableFaculties);


void populateLibraryData(Library& library);
void populateCafeteriaData(Cafeteria& cafeteria);
#endif
