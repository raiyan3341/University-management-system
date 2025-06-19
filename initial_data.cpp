// initial_data.cpp
// Defines the function to populate hardcoded initial data.

#include "initial_data.h"
#include <iostream> // For output if needed, though not strictly for data population
#include <vector>   // Ensure vector is included if not already by university_classes.h
#include <string>   // Ensure string is included
#include <iomanip>  // For std::setw, std::setfill if used for ID formatting (not directly for manual add)

void populateHardcodedData(
    std::vector<Student>& students,
    std::vector<Department>& departments,
    std::vector<Faculty>& faculties,
    std::vector<Course>& courses,
    const std::vector<Course>& availableCourses, // Kept for signature compatibility
    const std::vector<Faculty>& availableFaculties // Kept for signature compatibility
) {
    // --- Add Departments ---
    // Ensure these department names match exactly what's used in your University class methods.
    // Assuming Department constructor initializes counts to 0.
    departments.emplace_back("CSE001", "Computer Science and Engineering", "Dr. A. Rahman", 0, 0);
    departments.emplace_back("EEE001", "Electrical and Electronic Engineering", "Prof. S. Islam", 0, 0);
    departments.emplace_back("BAN001", "Bangla", "Dr. M. Akter", 0, 0);
    departments.emplace_back("ENG001", "English", "Prof. R. Chowdhury", 0, 0);
    departments.emplace_back("TEX001", "Textile Engineering", "Dr. K. Hassan", 0, 0);

    // --- Add Courses (Example courses for each department) ---
    // Computer Science and Engineering
    courses.emplace_back("CSE101", "Programming Fundamentals", "Computer Science and Engineering", 3, "Introduction to programming concepts using C++.");
    courses.emplace_back("CSE102", "Data Structures & Algorithms", "Computer Science and Engineering", 3, "Core concepts of data organization and algorithm efficiency.");
    courses.emplace_back("CSE201", "Object-Oriented Programming", "Computer Science and Engineering", 3, "Advanced programming with OOP principles and design patterns.");
    courses.emplace_back("CSE202", "Discrete Mathematics", "Computer Science and Engineering", 3, "Mathematical structures for computer science.");
    courses.emplace_back("CSE301", "Database Management Systems", "Computer Science and Engineering", 3, "Design, implementation, and management of databases.");

    // Electrical and Electronic Engineering
    courses.emplace_back("EEE101", "Basic Electrical Circuits", "Electrical and Electronic Engineering", 3, "Fundamentals of electrical circuit analysis.");
    courses.emplace_back("EEE201", "Electronic Devices and Circuits", "Electrical and Electronic Engineering", 3, "Study of diodes, transistors, and basic circuits.");
    courses.emplace_back("EEE301", "Digital Signal Processing", "Electrical and Electronic Engineering", 3, "Analysis and design of digital filters.");

    // Bangla
    courses.emplace_back("BAN101", "Modern Bangla Poetry", "Bangla", 3, "An in-depth study of prominent modern Bangla poets.");
    courses.emplace_back("BAN201", "Bangla Novel: Form and Content", "Bangla", 3, "Exploration of major Bangla novels and their themes.");

    // English
    courses.emplace_back("ENG101", "Introduction to Literary Studies", "English", 3, "Key concepts and theories in literary analysis.");
    courses.emplace_back("ENG201", "Critical Reading and Writing", "English", 3, "Developing advanced reading and argumentation skills.");

    // Textile Engineering
    courses.emplace_back("TEX101", "Textile Raw Materials", "Textile Engineering", 3, "Properties and processing of natural and synthetic fibers.");
    courses.emplace_back("TEX201", "Fabric Manufacturing", "Textile Engineering", 3, "Principles of weaving, knitting, and non-woven fabric production.");

    // --- Add Students (20 per Department) ---
    // Computer Science and Engineering Students
    students.emplace_back("CSE2024001", "Ali Ahmed", "15-03-2005", "123 Green Rd, Dhaka", "01711111111", "ali.ahmed@cse.edu", "Computer Science and Engineering", 3.85, "4.90", "5.00");
    students.emplace_back("CSE2024002", "Fahim Khan", "22-07-2004", "456 Main St, Chittagong", "01812345678", "fahim.khan@cse.edu", "Computer Science and Engineering", 3.70, "4.85", "4.95");
    students.emplace_back("CSE2024003", "Nadia Islam", "01-11-2005", "789 College Rd, Sylhet", "01913579135", "nadia.islam@cse.edu", "Computer Science and Engineering", 3.92, "5.00", "4.80");
    students.emplace_back("CSE2024004", "Rahat Hasan", "10-02-2004", "321 University Ave, Rajshahi", "01510987654", "rahat.hasan@cse.edu", "Computer Science and Engineering", 3.65, "4.75", "4.88");
    students.emplace_back("CSE2024005", "Zara Rahman", "05-09-2005", "654 Elm St, Khulna", "01612233445", "zara.rahman@cse.edu", "Computer Science and Engineering", 3.95, "5.00", "5.00");
    students.emplace_back("CSE2024006", "Samiha Akter", "12-04-2004", "101 Pine St, Barisal", "01723456789", "samiha.akter@cse.edu", "Computer Science and Engineering", 3.80, "4.80", "4.90");
    students.emplace_back("CSE2024007", "Imran Chowdhury", "28-08-2005", "202 Oak Ave, Rangpur", "01834567890", "imran.chowdhury@cse.edu", "Computer Science and Engineering", 3.78, "4.95", "4.82");
    students.emplace_back("CSE2024008", "Tisha Begum", "19-01-2004", "303 Birch Ln, Mymensingh", "01945678901", "tisha.begum@cse.edu", "Computer Science and Engineering", 3.60, "4.70", "4.75");
    students.emplace_back("CSE2024009", "Kabir Hossain", "07-06-2005", "404 Cedar Dr, Cumilla", "01556789012", "kabir.hossain@cse.edu", "Computer Science and Engineering", 3.90, "4.98", "4.90");
    students.emplace_back("CSE2024010", "Lima Khatun", "25-10-2004", "505 Maple St, Jessore", "01667890123", "lima.khatun@cse.edu", "Computer Science and Engineering", 3.73, "4.88", "4.92");
    students.emplace_back("CSE2024011", "Robiul Islam", "03-03-2005", "606 Poplar Ave, Bogura", "01778901234", "robiul.islam@cse.edu", "Computer Science and Engineering", 3.88, "4.92", "4.98");
    students.emplace_back("CSE2024012", "Ema Khanam", "14-07-2004", "707 Willow Ln, Dinajpur", "01889012345", "ema.khanam@cse.edu", "Computer Science and Engineering", 3.55, "4.65", "4.70");
    students.emplace_back("CSE2024013", "Sakib Al Hasan", "09-12-2005", "808 Cherry Dr, Gazipur", "01990123456", "sakib.hasan@cse.edu", "Computer Science and Engineering", 3.98, "5.00", "5.00");
    students.emplace_back("CSE2024014", "Sadia Afrin", "21-05-2004", "909 Peach St, Narayanganj", "01501234567", "sadia.afrin@cse.edu", "Computer Science and Engineering", 3.77, "4.87", "4.91");
    students.emplace_back("CSE2024015", "Tariq Mahmud", "04-08-2005", "111 Orange Ave, Tangail", "01612345678", "tariq.mahmud@cse.edu", "Computer Science and Engineering", 3.82, "4.90", "4.96");
    students.emplace_back("CSE2024016", "Ishrat Jahan", "17-03-2004", "222 Lemon Ln, Sirajganj", "01723456780", "ishrat.jahan@cse.edu", "Computer Science and Engineering", 3.68, "4.82", "4.89");
    students.emplace_back("CSE2024017", "Rifat Islam", "29-09-2005", "333 Apple Dr, Pabna", "01834567899", "rifat.islam@cse.edu", "Computer Science and Engineering", 3.71, "4.80", "4.85");
    students.emplace_back("CSE2024018", "Nusrat Parvin", "06-02-2004", "444 Grape St, Brahmanbaria", "01945678900", "nusrat.parvin@cse.edu", "Computer Science and Engineering", 3.91, "4.99", "4.97");
    students.emplace_back("CSE2024019", "Asif Abdullah", "11-07-2005", "555 Berry Ave, Naogaon", "01556789011", "asif.abdullah@cse.edu", "Computer Science and Engineering", 3.63, "4.72", "4.78");
    students.emplace_back("CSE2024020", "Afia Nur", "23-12-2004", "666 Fig Ln, Chandpur", "01667890122", "afia.nur@cse.edu", "Computer Science and Engineering", 3.89, "4.94", "4.95");

    // Electrical and Electronic Engineering Students
    students.emplace_back("EEE2024001", "Kamal Uddin", "01-01-2005", "110 Power Rd, Dhaka", "01711223344", "kamal.uddin@eee.edu", "Electrical and Electronic Engineering", 3.75, "4.70", "4.80");
    students.emplace_back("EEE2024002", "Laila Begum", "02-02-2004", "220 Circuit Ave, Gazipur", "01811223344", "laila.begum@eee.edu", "Electrical and Electronic Engineering", 3.60, "4.60", "4.70");
    students.emplace_back("EEE2024003", "Jamal Hasan", "03-03-2005", "330 Volt St, Narayanganj", "01911223344", "jamal.hasan@eee.edu", "Electrical and Electronic Engineering", 3.80, "4.80", "4.90");
    students.emplace_back("EEE2024004", "Sumaiya Akter", "04-04-2004", "440 Ampere Ln, Bogura", "01511223344", "sumaiya.akter@eee.edu", "Electrical and Electronic Engineering", 3.50, "4.50", "4.60");
    students.emplace_back("EEE2024005", "Firoz Mahmud", "05-05-2005", "550 Ohm Dr, Chittagong", "01611223344", "firoz.mahmud@eee.edu", "Electrical and Electronic Engineering", 3.90, "4.90", "5.00");
    students.emplace_back("EEE2024006", "Rina Khatun", "06-06-2004", "660 Watt St, Sylhet", "01711223355", "rina.khatun@eee.edu", "Electrical and Electronic Engineering", 3.65, "4.75", "4.85");
    students.emplace_back("EEE2024007", "Alomgir Hossain", "07-07-2005", "770 Energy Rd, Rajshahi", "01811223366", "alomgir.hossain@eee.edu", "Electrical and Electronic Engineering", 3.70, "4.80", "4.90");
    students.emplace_back("EEE2024008", "Shima Akter", "08-08-2004", "880 Current Ave, Khulna", "01911223377", "shima.akter@eee.edu", "Electrical and Electronic Engineering", 3.55, "4.65", "4.75");
    students.emplace_back("EEE2024009", "Monir Hossain", "09-09-2005", "990 Pulse St, Barisal", "01511223388", "monir.hossain@eee.edu", "Electrical and Electronic Engineering", 3.82, "4.88", "4.98");
    students.emplace_back("EEE2024010", "Sabina Yesmin", "10-10-2004", "1000 Signal Ln, Rangpur", "01611223399", "sabina.yesmin@eee.edu", "Electrical and Electronic Engineering", 3.68, "4.78", "4.88");
    students.emplace_back("EEE2024011", "Rafiqul Islam", "11-11-2005", "1010 Resistor Dr, Mymensingh", "01711223300", "rafiqul.islam@eee.edu", "Electrical and Electronic Engineering", 3.77, "4.85", "4.95");
    students.emplace_back("EEE2024012", "Naznin Sultana", "12-12-2004", "1020 Capacitor St, Cumilla", "01811223311", "naznin.sultana@eee.edu", "Electrical and Electronic Engineering", 3.58, "4.68", "4.78");
    students.emplace_back("EEE2024013", "Babul Khan", "13-01-2005", "1030 Inductor Rd, Jessore", "01911223322", "babul.khan@eee.edu", "Electrical and Electronic Engineering", 3.88, "4.95", "5.00");
    students.emplace_back("EEE2024014", "Farhana Akter", "14-02-2004", "1040 Diode Ave, Bogura", "01511223333", "farhana.akter@eee.edu", "Electrical and Electronic Engineering", 3.62, "4.72", "4.82");
    students.emplace_back("EEE2024015", "Shahinur Begum", "15-03-2005", "1050 Transistor St, Tangail", "01611223344", "shahinur.begum@eee.edu", "Electrical and Electronic Engineering", 3.73, "4.83", "4.93");
    students.emplace_back("EEE2024016", "Jahidul Islam", "16-04-2004", "1060 Grid Ln, Sirajganj", "01711223355", "jahidul.islam@eee.edu", "Electrical and Electronic Engineering", 3.66, "4.76", "4.86");
    students.emplace_back("EEE2024017", "Afroza Rahman", "17-05-2005", "1070 Wire Dr, Pabna", "01811223366", "afroza.rahman@eee.edu", "Electrical and Electronic Engineering", 3.79, "4.89", "4.99");
    students.emplace_back("EEE2024018", "Parvez Khan", "18-06-2004", "1080 Cable St, Brahmanbaria", "01911223377", "parvez.khan@eee.edu", "Electrical and Electronic Engineering", 3.59, "4.69", "4.79");
    students.emplace_back("EEE2024019", "Tanjila Islam", "19-07-2005", "1090 Network Rd, Naogaon", "01511223388", "tanjila.islam@eee.edu", "Electrical and Electronic Engineering", 3.81, "4.91", "4.98");
    students.emplace_back("EEE2024020", "Mominul Haque", "20-08-2004", "1100 System Ave, Chandpur", "01611223399", "mominul.haque@eee.edu", "Electrical and Electronic Engineering", 3.69, "4.79", "4.89");

    // Bangla Students
    students.emplace_back("BAN2024001", "Rumi Akter", "01-01-2005", "10 Bangla Path, Dhaka", "01730000001", "rumi.akter@bangla.edu", "Bangla", 3.80, "4.80", "4.90");
    students.emplace_back("BAN2024002", "Nurul Huda", "02-02-2004", "20 Kobi St, Chittagong", "01830000002", "nurul.huda@bangla.edu", "Bangla", 3.70, "4.70", "4.80");
    students.emplace_back("BAN2024003", "Bristy Rahman", "03-03-2005", "30 Sahitya Lane, Sylhet", "01930000003", "bristy.rahman@bangla.edu", "Bangla", 3.90, "4.90", "5.00");
    students.emplace_back("BAN2024004", "Shafiq Islam", "04-04-2004", "40 Godyo Path, Rajshahi", "01530000004", "shafiq.islam@bangla.edu", "Bangla", 3.65, "4.65", "4.75");
    students.emplace_back("BAN2024005", "Mithu Begum", "05-05-2005", "50 Poddyo Path, Khulna", "01630000005", "mithu.begum@bangla.edu", "Bangla", 3.85, "4.85", "4.95");
    students.emplace_back("BAN2024006", "Rajib Hasan", "06-06-2004", "60 Byakoron Rd, Barisal", "01730000006", "rajib.hasan@bangla.edu", "Bangla", 3.72, "4.72", "4.82");
    students.emplace_back("BAN2024007", "Ruksana Akter", "07-07-2005", "70 Natok Goli, Rangpur", "01830000007", "ruksana.akter@bangla.edu", "Bangla", 3.78, "4.78", "4.88");
    students.emplace_back("BAN2024008", "Mizanur Rahman", "08-08-2004", "80 Probandho Chor, Mymensingh", "01930000008", "mizanur.rahman@bangla.edu", "Bangla", 3.60, "4.60", "4.70");
    students.emplace_back("BAN2024009", "Shila Devi", "09-09-2005", "90 Uponnyash Gali, Cumilla", "01530000009", "shila.devi@bangla.edu", "Bangla", 3.92, "4.92", "4.98");
    students.emplace_back("BAN2024010", "Tareq Bin Azam", "10-10-2004", "100 Chotogolpo Mor, Jessore", "01630000010", "tareq.azam@bangla.edu", "Bangla", 3.69, "4.69", "4.79");
    students.emplace_back("BAN2024011", "Mim Akter", "11-11-2005", "110 Sahitya Bazar, Bogura", "01730000011", "mim.akter@bangla.edu", "Bangla", 3.87, "4.87", "4.97");
    students.emplace_back("BAN2024012", "Kamrul Hasan", "12-12-2004", "120 Grontho Niloy, Dinajpur", "01830000012", "kamrul.hasan@bangla.edu", "Bangla", 3.58, "4.58", "4.68");
    students.emplace_back("BAN2024013", "Sheuly Begum", "13-01-2005", "130 Kobita Kunj, Gazipur", "01930000013", "sheuly.begum@bangla.edu", "Bangla", 3.95, "4.95", "5.00");
    students.emplace_back("BAN2024014", "Joynal Abedin", "14-02-2004", "140 Choron Dalan, Narayanganj", "01530000014", "joynal.abedin@bangla.edu", "Bangla", 3.63, "4.63", "4.73");
    students.emplace_back("BAN2024015", "Anika Tabassum", "15-03-2005", "150 Onubad Goli, Tangail", "01630000015", "anika.tabassum@bangla.edu", "Bangla", 3.81, "4.81", "4.91");
    students.emplace_back("BAN2024016", "Sohag Miah", "16-04-2004", "160 Bangla Bhaban, Sirajganj", "01730000016", "sohag.miah@bangla.edu", "Bangla", 3.67, "4.67", "4.77");
    students.emplace_back("BAN2024017", "Nazma Akter", "17-05-2005", "170 Shobdo Shoroni, Pabna", "01830000017", "nazma.akter@bangla.edu", "Bangla", 3.76, "4.76", "4.86");
    students.emplace_back("BAN2024018", "Faysal Mahmud", "18-06-2004", "180 Bakyo Bithi, Brahmanbaria", "01930000018", "faysal.mahmud@bangla.edu", "Bangla", 3.59, "4.59", "4.69");
    students.emplace_back("BAN2024019", "Dilruba Yesmin", "19-07-2005", "190 Dhoni Path, Naogaon", "01530000019", "dilruba.yesmin@bangla.edu", "Bangla", 3.83, "4.83", "4.93");
    students.emplace_back("BAN2024020", "Emran Hossain", "20-08-2004", "200 Borno Bithi, Chandpur", "01630000020", "emran.hossain@bangla.edu", "Bangla", 3.71, "4.71", "4.81");

    // English Students
    students.emplace_back("ENG2024001", "David Miller", "01-01-2005", "10 Oxford St, London", "01740000001", "david.miller@english.edu", "English", 3.88, "4.90", "5.00");
    students.emplace_back("ENG2024002", "Sarah Johnson", "02-02-2004", "20 Cambridge Rd, Bristol", "01840000002", "sarah.johnson@english.edu", "English", 3.75, "4.80", "4.90");
    students.emplace_back("ENG2024003", "John Smith", "03-03-2005", "30 Shakespeare Ln, Stratford", "01940000003", "john.smith@english.edu", "English", 3.95, "5.00", "4.98");
    students.emplace_back("ENG2024004", "Emily White", "04-04-2004", "40 Dickens Ave, Manchester", "01540000004", "emily.white@english.edu", "English", 3.70, "4.75", "4.85");
    students.emplace_back("ENG2024005", "Michael Brown", "05-05-2005", "50 Chaucer Dr, Leeds", "01640000005", "michael.brown@english.edu", "English", 3.90, "4.95", "5.00");
    students.emplace_back("ENG2024006", "Olivia Davis", "06-06-2004", "60 Poetry Path, Sheffield", "01740000006", "olivia.davis@english.edu", "English", 3.82, "4.85", "4.92");
    students.emplace_back("ENG2024007", "William Green", "07-07-2005", "70 Prose Place, Edinburgh", "01840000007", "william.green@english.edu", "English", 3.78, "4.88", "4.91");
    students.emplace_back("ENG2024008", "Sophia Black", "08-08-2004", "80 Novel Nook, Glasgow", "01940000008", "sophia.black@english.edu", "English", 3.65, "4.70", "4.78");
    students.emplace_back("ENG2024009", "James Wilson", "09-09-2005", "90 Grammar Gdns, Dublin", "01540000009", "james.wilson@english.edu", "English", 3.98, "5.00", "5.00");
    students.emplace_back("ENG2024010", "Ava Taylor", "10-10-2004", "100 Literary Ln, Belfast", "01640000010", "ava.taylor@english.edu", "English", 3.72, "4.77", "4.89");
    students.emplace_back("ENG2024011", "Benjamin Clark", "11-11-2005", "110 Writing Way, Cardiff", "01740000011", "benjamin.clark@english.edu", "English", 3.86, "4.91", "4.96");
    students.emplace_back("ENG2024012", "Isabella Lewis", "12-12-2004", "120 Critical Crescent, Swansea", "01840000012", "isabella.lewis@english.edu", "English", 3.61, "4.68", "4.75");
    students.emplace_back("ENG2024013", "Daniel Hall", "13-01-2005", "130 Language Loop, Cork", "01940000013", "daniel.hall@english.edu", "English", 3.92, "4.97", "4.99");
    students.emplace_back("ENG2024014", "Mia King", "14-02-2004", "140 Rhetoric Row, Galway", "01540000014", "mia.king@english.edu", "English", 3.79, "4.86", "4.90");
    students.emplace_back("ENG2024015", "Alexander Wright", "15-03-2005", "150 Syntax Square, Liverpool", "01640000015", "alexander.wright@english.edu", "English", 3.84, "4.89", "4.94");
    students.emplace_back("ENG2024016", "Charlotte Lee", "16-04-2004", "160 Lexicon Lane, Newcastle", "01740000016", "charlotte.lee@english.edu", "English", 3.69, "4.74", "4.83");
    students.emplace_back("ENG2024017", "Ethan Scott", "17-05-2005", "170 Word Way, Brighton", "01840000017", "ethan.scott@english.edu", "English", 3.74, "4.81", "4.88");
    students.emplace_back("ENG2024018", "Amelia Green", "18-06-2004", "180 Sentence St, Oxford", "01940000018", "amelia.green@english.edu", "English", 3.66, "4.71", "4.79");
    students.emplace_back("ENG2024019", "Jacob Adams", "19-07-2005", "190 Paragraph Place, York", "01540000019", "jacob.adams@english.edu", "English", 3.91, "4.96", "4.98");
    students.emplace_back("ENG2024020", "Harper Baker", "20-08-2004", "200 Discourse Drive, Bath", "01640000020", "harper.baker@english.edu", "English", 3.76, "4.83", "4.90");

    // Textile Engineering Students
    students.emplace_back("TEX2024001", "Abdullah Al Noman", "01-01-2005", "10 Fabric Rd, Narayanganj", "01750000001", "abdullah.noman@textile.edu", "Textile Engineering", 3.70, "4.70", "4.80");
    students.emplace_back("TEX2024002", "Fatema Akter", "02-02-2004", "20 Yarn Ave, Gazipur", "01850000002", "fatema.akter@textile.edu", "Textile Engineering", 3.60, "4.60", "4.70");
    students.emplace_back("TEX2024003", "Rakib Hasan", "03-03-2005", "30 Dyeing St, Dhaka", "01950000003", "rakib.hasan@textile.edu", "Textile Engineering", 3.80, "4.80", "4.90");
    students.emplace_back("TEX2024004", "Salma Begum", "04-04-2004", "40 Weaving Ln, Comilla", "01550000004", "salma.begum@textile.edu", "Textile Engineering", 3.50, "4.50", "4.60");
    students.emplace_back("TEX2024005", "Imran Mahmud", "05-05-2005", "50 Knitting Dr, Chittagong", "01650000005", "imran.mahmud@textile.edu", "Textile Engineering", 3.90, "4.90", "5.00");
    students.emplace_back("TEX2024006", "Roksana Khatun", "06-06-2004", "60 Apparel Rd, Sylhet", "01750000006", "roksana.khatun@textile.edu", "Textile Engineering", 3.65, "4.75", "4.85");
    students.emplace_back("TEX2024007", "Akash Ahmed", "07-07-2005", "70 Fiber Ave, Rajshahi", "01850000007", "akash.ahmed@textile.edu", "Textile Engineering", 3.75, "4.85", "4.95");
    students.emplace_back("TEX2024008", "Nishi Islam", "08-08-2004", "80 Spinning St, Khulna", "01950000008", "nishi.islam@textile.edu", "Textile Engineering", 3.55, "4.65", "4.75");
    students.emplace_back("TEX2024009", "Shuvo Khan", "09-09-2005", "90 Finishing Ln, Barisal", "01550000009", "shuvo.khan@textile.edu", "Textile Engineering", 3.82, "4.90", "4.98");
    students.emplace_back("TEX2024010", "Mitu Begum", "10-10-2004", "100 Textile Tech, Rangpur", "01650000010", "mitu.begum@textile.edu", "Textile Engineering", 3.68, "4.78", "4.88");
    students.emplace_back("TEX2024011", "Nasir Uddin", "11-11-2005", "110 Garment Place, Mymensingh", "01750000011", "nasir.uddin@textile.edu", "Textile Engineering", 3.77, "4.87", "4.97");
    students.emplace_back("TEX2024012", "Bristi Akter", "12-12-2004", "120 Fabric Lab, Jessore", "01850000012", "bristi.akter@textile.edu", "Textile Engineering", 3.58, "4.68", "4.78");
    students.emplace_back("TEX2024013", "Faruk Hossain", "13-01-2005", "130 Fiber Factory, Bogura", "01950000013", "faruk.hossain@textile.edu", "Textile Engineering", 3.88, "4.95", "5.00");
    students.emplace_back("TEX2024014", "Shahnaz Begum", "14-02-2004", "140 Thread Mill, Dinajpur", "01550000014", "shahnaz.begum@textile.edu", "Textile Engineering", 3.62, "4.72", "4.82");
    students.emplace_back("TEX2024015", "Rashed Khan", "15-03-2005", "150 Design Studio, Gazipur", "01650000015", "rashed.khan@textile.edu", "Textile Engineering", 3.73, "4.83", "4.93");
    students.emplace_back("TEX2024016", "Jannatul Ferdous", "16-04-2004", "160 Dyehouse Rd, Narayanganj", "01750000016", "jannatul.ferdous@textile.edu", "Textile Engineering", 3.66, "4.76", "4.86");
    students.emplace_back("TEX2024017", "Saiful Islam", "17-05-2005", "170 Textile Park, Tangail", "01850000017", "saiful.islam@textile.edu", "Textile Engineering", 3.79, "4.89", "4.99");
    students.emplace_back("TEX2024018", "Amena Khatun", "18-06-2004", "180 Weft Ln, Sirajganj", "01950000018", "amena.khatun@textile.edu", "Textile Engineering", 3.59, "4.69", "4.79");
    students.emplace_back("TEX2024019", "Tuhin Chowdhury", "19-07-2005", "190 Warp Way, Pabna", "01550000019", "tuhin.chowdhury@textile.edu", "Textile Engineering", 3.81, "4.91", "4.98");
    students.emplace_back("TEX2024020", "Laboni Akter", "20-08-2004", "200 Loom St, Brahmanbaria", "01650000020", "laboni.akter@textile.edu", "Textile Engineering", 3.69, "4.79", "4.89");


    // --- Add Faculties (15 per Department) ---
    // Computer Science and Engineering Faculties
    faculties.emplace_back("CSEF001", "Dr. Zobair Khan", "Computer Science and Engineering", "Professor", "zobair.khan@cse.edu");
    faculties.emplace_back("CSEF002", "Ms. Roksana Islam", "Computer Science and Engineering", "Assistant Professor", "roksana.islam@cse.edu");
    faculties.emplace_back("CSEF003", "Mr. Tanvir Hasan", "Computer Science and Engineering", "Lecturer", "tanvir.hasan@cse.edu");
    faculties.emplace_back("CSEF004", "Dr. Farida Yesmin", "Computer Science and Engineering", "Professor", "farida.yesmin@cse.edu");
    faculties.emplace_back("CSEF005", "Mr. Karim Ullah", "Computer Science and Engineering", "Assistant Professor", "karim.ullah@cse.edu");
    faculties.emplace_back("CSEF006", "Ms. Shumi Akter", "Computer Science and Engineering", "Lecturer", "shumi.akter@cse.edu");
    faculties.emplace_back("CSEF007", "Dr. Hasan Mahmud", "Computer Science and Engineering", "Professor", "hasan.mahmud@cse.edu");
    faculties.emplace_back("CSEF008", "Mr. Sifat Rahman", "Computer Science and Engineering", "Assistant Professor", "sifat.rahman@cse.edu");
    faculties.emplace_back("CSEF009", "Ms. Nabila Afsar", "Computer Science and Engineering", "Lecturer", "nabila.afsar@cse.edu");
    faculties.emplace_back("CSEF010", "Dr. Kamrul Islam", "Computer Science and Engineering", "Professor", "kamrul.islam@cse.edu");
    faculties.emplace_back("CSEF011", "Mr. Asif Iqbal", "Computer Science and Engineering", "Assistant Professor", "asif.iqbal@cse.edu");
    faculties.emplace_back("CSEF012", "Ms. Tania Sultana", "Computer Science and Engineering", "Lecturer", "tania.sultana@cse.edu");
    faculties.emplace_back("CSEF013", "Dr. Monir Hossain", "Computer Science and Engineering", "Professor", "monir.hossain@cse.edu");
    faculties.emplace_back("CSEF014", "Mr. Alomgir Kabir", "Computer Science and Engineering", "Assistant Professor", "alomgir.kabir@cse.edu");
    faculties.emplace_back("CSEF015", "Ms. Jarin Tasnim", "Computer Science and Engineering", "Lecturer", "jarin.tasnim@cse.edu");

    // Electrical and Electronic Engineering Faculties
    faculties.emplace_back("EEEF001", "Dr. Saifuddin Ahmed", "Electrical and Electronic Engineering", "Professor", "saifuddin.ahmed@eee.edu");
    faculties.emplace_back("EEEF002", "Ms. Nazma Begum", "Electrical and Electronic Engineering", "Assistant Professor", "nazma.begum@eee.edu");
    faculties.emplace_back("EEEF003", "Mr. Shakil Khan", "Electrical and Electronic Engineering", "Lecturer", "shakil.khan@eee.edu");
    faculties.emplace_back("EEEF004", "Dr. Khaled Mahmud", "Electrical and Electronic Engineering", "Professor", "khaled.mahmud@eee.edu");
    faculties.emplace_back("EEEF005", "Ms. Pervin Akter", "Electrical and Electronic Engineering", "Assistant Professor", "pervin.akter@eee.edu");
    faculties.emplace_back("EEEF006", "Mr. Rubel Miah", "Electrical and Electronic Engineering", "Lecturer", "rubel.miah@eee.edu");
    faculties.emplace_back("EEEF007", "Dr. Sumon Barua", "Electrical and Electronic Engineering", "Professor", "sumon.barua@eee.edu");
    faculties.emplace_back("EEEF008", "Ms. Lucky Khatun", "Electrical and Electronic Engineering", "Assistant Professor", "lucky.khatun@eee.edu");
    faculties.emplace_back("EEEF009", "Mr. Ripon Ali", "Electrical and Electronic Engineering", "Lecturer", "ripon.ali@eee.edu");
    faculties.emplace_back("EEEF010", "Dr. S. K. Roy", "Electrical and Electronic Engineering", "Professor", "sk.roy@eee.edu");
    faculties.emplace_back("EEEF011", "Ms. Mousumi Akter", "Electrical and Electronic Engineering", "Assistant Professor", "mousumi.akter@eee.edu");
    faculties.emplace_back("EEEF012", "Mr. Emon Chowdhury", "Electrical and Electronic Engineering", "Lecturer", "emon.chowdhury@eee.edu");
    faculties.emplace_back("EEEF013", "Dr. Joyanta Saha", "Electrical and Electronic Engineering", "Professor", "joyanta.saha@eee.edu");
    faculties.emplace_back("EEEF014", "Ms. Liza Islam", "Electrical and Electronic Engineering", "Assistant Professor", "liza.islam@eee.edu");
    faculties.emplace_back("EEEF015", "Mr. Bipul Chandra", "Electrical and Electronic Engineering", "Lecturer", "bipul.chandra@eee.edu");

    // Bangla Faculties
    faculties.emplace_back("BANF001", "Prof. Abul Kalam Azad", "Bangla", "Professor", "abul.azad@bangla.edu");
    faculties.emplace_back("BANF002", "Dr. Sharmin Akter", "Bangla", "Assistant Professor", "sharmin.akter@bangla.edu");
    faculties.emplace_back("BANF003", "Ms. Farida Khanam", "Bangla", "Lecturer", "farida.khanam@bangla.edu");
    faculties.emplace_back("BANF004", "Prof. Rashed Zaman", "Bangla", "Professor", "rashed.zaman@bangla.edu");
    faculties.emplace_back("BANF005", "Dr. Nahid Sultana", "Bangla", "Assistant Professor", "nahid.sultana@bangla.edu");
    faculties.emplace_back("BANF006", "Mr. Jamal Uddin", "Bangla", "Lecturer", "jamal.uddin@bangla.edu");
    faculties.emplace_back("BANF007", "Prof. Kamrun Nahar", "Bangla", "Professor", "kamrun.nahar@bangla.edu");
    faculties.emplace_back("BANF008", "Dr. Sumon Das", "Bangla", "Assistant Professor", "sumon.das@bangla.edu");
    faculties.emplace_back("BANF009", "Ms. Rina Parvin", "Bangla", "Lecturer", "rina.parvin@bangla.edu");
    faculties.emplace_back("BANF010", "Prof. Alamgir Hossain", "Bangla", "Professor", "alamgir.hossain@bangla.edu");
    faculties.emplace_back("BANF011", "Dr. Nazmul Hasan", "Bangla", "Assistant Professor", "nazmul.hasan@bangla.edu");
    faculties.emplace_back("BANF012", "Ms. Afrin Jahan", "Bangla", "Lecturer", "afrin.jahan@bangla.edu");
    faculties.emplace_back("BANF013", "Prof. Mizanur Rahman", "Bangla", "Professor", "mizanur.rahman@bangla.edu");
    faculties.emplace_back("BANF014", "Dr. Liza Akter", "Bangla", "Assistant Professor", "liza.akter@bangla.edu");
    faculties.emplace_back("BANF015", "Mr. Rubel Ahmed", "Bangla", "Lecturer", "rubel.ahmed@bangla.edu");

    // English Faculties
    faculties.emplace_back("ENGF001", "Prof. Edward Smith", "English", "Professor", "edward.smith@english.edu");
    faculties.emplace_back("ENGF002", "Dr. Sarah Adams", "English", "Assistant Professor", "sarah.adams@english.edu");
    faculties.emplace_back("ENGF003", "Mr. Daniel Brown", "English", "Lecturer", "daniel.brown@english.edu");
    faculties.emplace_back("ENGF004", "Prof. Olivia Wilson", "English", "Professor", "olivia.wilson@english.edu");
    faculties.emplace_back("ENGF005", "Dr. Robert Taylor", "English", "Assistant Professor", "robert.taylor@english.edu");
    faculties.emplace_back("ENGF006", "Ms. Sophia Martin", "English", "Lecturer", "sophia.martin@english.edu");
    faculties.emplace_back("ENGF007", "Prof. James White", "English", "Professor", "james.white@english.edu");
    faculties.emplace_back("ENGF008", "Dr. Emily Davis", "English", "Assistant Professor", "emily.davis@english.edu");
    faculties.emplace_back("ENGF009", "Mr. David Johnson", "English", "Lecturer", "david.johnson@english.edu");
    faculties.emplace_back("ENGF010", "Prof. Ava Lee", "English", "Professor", "ava.lee@english.edu");
    faculties.emplace_back("ENGF011", "Dr. William Green", "English", "Assistant Professor", "william.green@english.edu");
    faculties.emplace_back("ENGF012", "Ms. Mia Hall", "English", "Lecturer", "mia.hall@english.edu");
    faculties.emplace_back("ENGF013", "Prof. Joseph King", "English", "Professor", "joseph.king@english.edu");
    faculties.emplace_back("ENGF014", "Dr. Grace Wright", "English", "Assistant Professor", "grace.wright@english.edu");
    faculties.emplace_back("ENGF015", "Mr. Christopher Clark", "English", "Lecturer", "christopher.clark@english.edu");

    // Textile Engineering Faculties
    faculties.emplace_back("TEXF001", "Dr. Rehana Chowdhury", "Textile Engineering", "Professor", "rehana.chowdhury@textile.edu");
    faculties.emplace_back("TEXF002", "Mr. Imtiaz Ahmed", "Textile Engineering", "Assistant Professor", "imtiaz.ahmed@textile.edu");
    faculties.emplace_back("TEXF003", "Ms. Khadija Begum", "Textile Engineering", "Lecturer", "khadija.begum@textile.edu");
    faculties.emplace_back("TEXF004", "Dr. Shafiqul Islam", "Textile Engineering", "Professor", "shafiqul.islam@textile.edu");
    faculties.emplace_back("TEXF005", "Mr. Nasir Uddin", "Textile Engineering", "Assistant Professor", "nasir.uddin@textile.edu");
    faculties.emplace_back("TEXF006", "Ms. Sumaiya Akter", "Textile Engineering", "Lecturer", "sumaiya.akter@textile.edu");
    faculties.emplace_back("TEXF007", "Dr. Golam Sarwar", "Textile Engineering", "Professor", "golam.sarwar@textile.edu");
    faculties.emplace_back("TEXF008", "Mr. Tareq Aziz", "Textile Engineering", "Assistant Professor", "tareq.aziz@textile.edu");
    faculties.emplace_back("TEXF009", "Ms. Sanjida Khanam", "Textile Engineering", "Lecturer", "sanjida.khanam@textile.edu");
    faculties.emplace_back("TEXF010", "Dr. Fahim Murshed", "Textile Engineering", "Professor", "fahim.murshed@textile.edu");
    faculties.emplace_back("TEXF011", "Mr. Farhan Rahman", "Textile Engineering", "Assistant Professor", "farhan.rahman@textile.edu");
    faculties.emplace_back("TEXF012", "Ms. Afrin Sultana", "Textile Engineering", "Lecturer", "afrin.sultana@textile.edu");
    faculties.emplace_back("TEXF013", "Dr. Jamal Hossain", "Textile Engineering", "Professor", "jamal.hossain@textile.edu");
    faculties.emplace_back("TEXF014", "Mr. Alamin Miah", "Textile Engineering", "Assistant Professor", "alamin.miah@textile.edu");
    faculties.emplace_back("TEXF015", "Ms. Tanjila Haque", "Textile Engineering", "Lecturer", "tanjila.haque@textile.edu");

    // --- Update Department Counts ---
    // This loop ensures that the totalStudentCount and totalFacultyCount in each Department object
    // are accurate based on the manually added students and faculties.
    // Assuming Department constructor correctly initializes totalStudentCount and totalFacultyCount to 0.
    for (auto& dept : departments) {
        // Since Department objects are created with initial counts (0,0),
        // we can directly increment them. No explicit resetCounts() needed here
        // if your constructor correctly initializes them to zero.
        for (const auto& student : students) {
            if (student.getDepartment() == dept.getName()) {
                dept.incrementStudentCount();
            }
        }

        for (const auto& faculty : faculties) {
            if (faculty.getDepartment() == dept.getName()) {
                dept.incrementFacultyCount();
            }
        }
    }
}

void populateLibraryData(Library& library) {
    // Add specific initial books
    library.addBook(Book("B001", "The Alchemist", "Paulo Coelho", "Fiction", true));
    library.addBook(Book("B002", "Sapiens: A Brief History of Humankind", "Yuval Noah Harari", "History", true));
    library.addBook(Book("B003", "1984", "George Orwell", "Dystopian", true));
    library.addBook(Book("B004", "Cosmos", "Carl Sagan", "Science", true));
    library.addBook(Book("B005", "To Kill a Mockingbird", "Harper Lee", "Fiction", true));
    library.addBook(Book("B006", "Pride and Prejudice", "Jane Austen", "Romance", true));
    library.addBook(Book("B007", "The Lord of the Rings", "J.R.R. Tolkien", "Fantasy", true));
    library.addBook(Book("B008", "The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "Science Fiction", true));
    library.addBook(Book("B009", "Educated", "Tara Westover", "Memoir", true));
    library.addBook(Book("B010", "Dune", "Frank Herbert", "Science Fiction", true));
    library.addBook(Book("B011", "Crime and Punishment", "Fyodor Dostoevsky", "Classic", true));
    library.addBook(Book("B012", "The Great Gatsby", "F. Scott Fitzgerald", "Classic", true));
    library.addBook(Book("B013", "Atomic Habits", "James Clear", "Self-help", true));
    library.addBook(Book("B014", "Deep Work", "Cal Newport", "Self-help", true));
    library.addBook(Book("B015", "The Lean Startup", "Eric Ries", "Business", true));
}

void populateCafeteriaData(Cafeteria& cafeteria) {
    // Add specific initial menu items
    cafeteria.addMenuItem(FoodItem("F001", "Chicken Biriyani", 180.00, "Main Course"));
    cafeteria.addMenuItem(FoodItem("F002", "Vegetable Curry with Rice", 120.00, "Main Course"));
    cafeteria.addMenuItem(FoodItem("F003", "Beef Burger", 150.00, "Fast Food"));
    cafeteria.addMenuItem(FoodItem("F004", "French Fries", 80.00, "Snack"));
    cafeteria.addMenuItem(FoodItem("F005", "Coffee (Hot)", 50.00, "Beverage"));
    cafeteria.addMenuItem(FoodItem("F006", "Tea (Hot)", 30.00, "Beverage"));
    cafeteria.addMenuItem(FoodItem("F007", "Cold Coffee", 70.00, "Beverage"));
    cafeteria.addMenuItem(FoodItem("F008", "Mineral Water", 20.00, "Beverage"));
    cafeteria.addMenuItem(FoodItem("F009", "Samosa (2 pcs)", 40.00, "Snack"));
    cafeteria.addMenuItem(FoodItem("F010", "Vegetable Roll", 60.00, "Snack"));
    cafeteria.addMenuItem(FoodItem("F011", "Doi Fuchka", 100.00, "Snack"));
    cafeteria.addMenuItem(FoodItem("F012", "Sandwich", 90.00, "Snack"));
    cafeteria.addMenuItem(FoodItem("F013", "Fruit Salad", 110.00, "Dessert"));
    cafeteria.addMenuItem(FoodItem("F014", "Chocolate Cake Slice", 130.00, "Dessert"));
    cafeteria.addMenuItem(FoodItem("F015", "Ice Cream", 70.00, "Dessert"));
}