// initial_data.cpp
// Defines the implementation of the function to populate hardcoded initial data.

#include "initial_data.h" // Include the header with the function declaration
#include "university_classes.h" // Include university_classes.h to get access to the class definitions

// For random data generation
#include <random>
#include <chrono> // For seeding the random number generator
#include <iomanip> // For std::setprecision with prices

// --- New: Populate Library Data ---
void populateLibraryData(Library& library) {
    // Seed the random number generator
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

    std::vector<std::string> genres = {"Fiction", "Science", "History", "Fantasy", "Biography",
                                       "Thriller", "Mystery", "Romance", "Poetry", "Self-Help"};
    std::vector<std::string> authors = {"Author A", "Author B", "Author C", "Author D", "Author E",
                                        "Author F", "Author G", "Author H", "Author I", "Author J"};
    std::vector<std::string> adjectives = {"The", "A", "Great", "Mysterious", "Lost", "Silent", "Hidden", "Bright"};
    std::vector<std::string> nouns = {"Book", "Journey", "Secret", "World", "Adventure", "Life", "Stars", "Forest", "City", "Dreams"};

    std::uniform_int_distribution<int> genre_dist(0, genres.size() - 1);
    std::uniform_int_distribution<int> author_dist(0, authors.size() - 1);
    std::uniform_int_distribution<int> adj_dist(0, adjectives.size() - 1);
    std::uniform_int_distribution<int> noun_dist(0, nouns.size() - 1);
    std::uniform_int_distribution<int> availability_dist(0, 1); // 0 for borrowed, 1 for available

    // std::cout << "\nPopulating Library with 100 random books..." << std::endl; // <-- এই লাইনটি কমেন্ট আউট করা হয়েছে
    for (int i = 0; i < 100; ++i) {
        std::string bookID = "B" + std::to_string(100 + i);
        std::string title = adjectives[adj_dist(rng)] + " " + nouns[noun_dist(rng)] + " of " + nouns[noun_dist(rng)];
        std::string author = authors[author_dist(rng)];
        std::string genre = genres[genre_dist(rng)];
        bool isAvailable = (availability_dist(rng) == 1);

        library.addBook(Book(bookID, title, author, genre, isAvailable));
    }
    // std::cout << "Library population complete." << std::endl; // <-- এই লাইনটি কমেন্ট আউট করা হয়েছে
}

// --- New: Populate Cafeteria Data ---
void populateCafeteriaData(Cafeteria& cafeteria) {
    // Example food items with names, prices, and categories
    // std::cout << "\nPopulating Cafeteria menu with 20 items..." << std::endl; // <-- এই লাইনটি কমেন্ট আউট করা হয়েছে
    cafeteria.addMenuItem(FoodItem("F001", "Chicken Biriyani", 180.00, "Main Course"));
    cafeteria.addMenuItem(FoodItem("F002", "Beef Tehari", 200.00, "Main Course"));
    cafeteria.addMenuItem(FoodItem("F003", "Vegetable Khichuri", 120.00, "Main Course"));
    cafeteria.addMenuItem(FoodItem("F004", "Plain Rice & Curry", 100.00, "Main Course"));
    cafeteria.addMenuItem(FoodItem("F005", "Dal Puri (2 pcs)", 30.00, "Snack"));
    cafeteria.addMenuItem(FoodItem("F006", "Samosa (1 pc)", 20.00, "Snack"));
    cafeteria.addMenuItem(FoodItem("F007", "Singara (1 pc)", 15.00, "Snack"));
    cafeteria.addMenuItem(FoodItem("F008", "Vegetable Roll", 40.00, "Snack"));
    cafeteria.addMenuItem(FoodItem("F009", "Chicken Sandwich", 80.00, "Snack"));
    cafeteria.addMenuItem(FoodItem("F010", "Danish Pastry", 50.00, "Snack"));
    cafeteria.addMenuItem(FoodItem("F011", "Coffee (Hot)", 60.00, "Beverage"));
    cafeteria.addMenuItem(FoodItem("F012", "Tea (Milk)", 25.00, "Beverage"));
    cafeteria.addMenuItem(FoodItem("F013", "Cold Drink (Can)", 50.00, "Beverage"));
    cafeteria.addMenuItem(FoodItem("F014", "Fresh Juice (Orange)", 90.00, "Beverage"));
    cafeteria.addMenuItem(FoodItem("F015", "Shahi Tukra", 70.00, "Dessert"));
    cafeteria.addMenuItem(FoodItem("F016", "Firni", 60.00, "Dessert"));
    cafeteria.addMenuItem(FoodItem("F017", "Paratha & Egg Omelette", 70.00, "Breakfast"));
    cafeteria.addMenuItem(FoodItem("F018", "Noodles with Vegetables", 90.00, "Main Course"));
    cafeteria.addMenuItem(FoodItem("F019", "Fruit Salad", 85.00, "Snack"));
    cafeteria.addMenuItem(FoodItem("F020", "Mineral Water", 20.00, "Beverage"));
    // std::cout << "Cafeteria menu population complete." << std::endl; // <-- এই লাইনটি কমেন্ট আউট করা হয়েছে
}


void populateHardcodedData(
    std::vector<Student> &students,
    std::vector<Department> &departments,
    std::vector<Faculty> &faculties,
    std::vector<Course> &courses,
    const std::vector<Course> &availableCourses,
    const std::vector<Faculty> &availableFaculties)
{
    // Add initial departments (with faculty and student counts)
    departments.emplace_back("CSE001", "Computer Science and Engineering", "Dr. Ahmed Khan", 2, 3);
    departments.emplace_back("EEE001", "Electrical and Electronic Engineering", "Dr. Sara Begum", 1, 2);
    departments.emplace_back("BAN001", "Bangla", "Dr. Rafiq Islam", 0, 0);
    departments.emplace_back("ENG001", "English", "Professor Elizabeth Roy", 0, 0);
    departments.emplace_back("TEX001", "Textile", "Dr. Fahmida Sultana", 0, 0);

    // Add initial courses
    courses.emplace_back("CSC101", "Introduction to Programming", "Computer Science and Engineering", 3, "Course on basic C++ programming.");
    courses.emplace_back("EEE201", "Circuit Analysis", "Electrical and Electronic Engineering", 3, "Principles and analysis of electrical circuits.");
    courses.emplace_back("CSC202", "Data Structures", "Computer Science and Engineering", 4, "Discussion on algorithms and data structures.");
    courses.emplace_back("BAN101", "Introduction to Bengali Literature", "Bangla", 3, "Fundamental concepts and periods of Bengali literature.");
    courses.emplace_back("ENG101", "English Composition and Communication", "English", 3, "Improving English writing and communication skills.");
    courses.emplace_back("TEX101", "Textile Fibers", "Textile", 3, "Different types of textile fibers and their properties.");

    // Add initial faculties
    faculties.emplace_back("F001", "Professor Hasan", "Computer Science and Engineering", "Professor", "hasan@univ.edu");
    faculties.emplace_back("F002", "Dr. Farida", "Computer Science and Engineering", "Associate Professor", "farida@univ.edu");
    faculties.emplace_back("F003", "Professor Karim", "Electrical and Electronic Engineering", "Professor", "karim@univ.edu");
    faculties.emplace_back("F004", "Dr. Nusrat Jahan", "Bangla", "Professor", "nusrat@univ.edu");
    faculties.emplace_back("F005", "Professor Peter Smith", "English", "Professor", "peter.smith@univ.edu");

    // Add initial students
    students.emplace_back("S000", "Raiyan Shk", "16-10-2005", "Shuampur, Dhaka", "017XXXXXXXX", "rahim@univ.edu", "Computer Science and Engineering", 3.8, "5.00", "5.00");
    students.emplace_back("S002", "Karim Khan", "15-03-2001", "Dhanmondi, Dhaka", "018XXXXXXXX", "karim@univ.edu", "Computer Science and Engineering", 3.5, "4.80", "4.50");
    students.emplace_back("S003", "Sima Akter", "20-07-2000", "Gulshan, Dhaka", "019XXXXXXXX", "sima@univ.edu", "Computer Science and Engineering", 3.9, "4.90", "5.00");
    students.emplace_back("S004", "Nila Chowdhury", "10-05-2002", "Banani, Dhaka", "016XXXXXXXX", "nila@univ.edu", "Electrical and Electronic Engineering", 3.7, "4.75", "4.60");
    students.emplace_back("S005", "Joy Saha", "25-11-2001", "Tejgaon, Dhaka", "015XXXXXXXX", "joy@univ.edu", "Electrical and Electronic Engineering", 3.6, "4.60", "4.70");
    students.emplace_back("S006", "Ayesha Siddika", "05-02-2003", "Motijheel, Dhaka", "017YYYYYYYY", "ayesha@univ.edu", "Bangla", 3.8, "4.95", "4.85");
    students.emplace_back("S007", "Tanvir Rahman", "12-09-2002", "Mohakhali, Dhaka", "018ZZZZZZZZ", "tanvir@univ.edu", "English", 3.7, "4.70", "4.75");
}