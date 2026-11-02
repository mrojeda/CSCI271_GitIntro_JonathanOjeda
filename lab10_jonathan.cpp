// ===========================================
// CSCI 271 – Lab 10: Student Information Management (Struct + File I/O)
// Objective:
// Practice using struct, functions, and file I/O in C++.
// The program automatically creates sample student records,
// saves them to a file, reads them back, and displays results.
// ===========================================

// TODO: include required headers
// (e.g., iostream, fstream, etc.)
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// =======================
// Struct Definition
// =======================
struct Student {
    // TODO: Add required fields (7 total)
    string studentID;
    string name;
    string major;
    string hobby;
    double gpa;
    string email;
    string city; 
};

// =======================
// Function Prototypes 
// =======================
void saveToFile(Student s[], int n, const string& filename);
int loadFromFile(Student s[], const string& filename);
void displayAll(Student s[], int n);
int countHonors(Student s[], int n);
void queryByCity(Student s[], int n, const string& city);

// =======================
// Function Definitions
// =======================

// Step 2 – Write all students to file
void saveToFile(Student s[], int n, const string& filename) {
    // TODO: Use ofstream to open file and write all student data
    ofstream outFile(filename);
    
    // Example: out << s[i].id << " " << s[i].name << " " << ... << endl;
    if (outFile.is_open()) {
        for (int i = 0; i < n; ++i) {
            outFile <<
                s[i].studentID << " " <<
                s[i].name << " " <<
                s[i].major << " " <<
                s[i].hobby << " " <<
                s[i].gpa << " " <<
                s[i].email << " " <<
                s[i].city << " " << endl;
        }
        outFile.close();
    }
    else {
        cout << "Error opening file for writing!" << endl;
    }

    cout << "[1] Data saved to " << filename << endl;

}

// Step 3 – Read students from file
int loadFromFile(Student s[], const string& filename) {
    // TODO: Use ifstream to read all student data from the file
    ifstream inFile(filename);
    int count = 0;
    
    // TODO: Replace with actual number of records read
    if (inFile.is_open()) {
        while (count< 100 && inFile
            >> s[count].studentID
            >> s[count].name
            >> s[count].major
            >> s[count].hobby
            >> s[count].gpa
            >> s[count].email
            >> s[count].city) {
            count++;
        }
        inFile.close();
    }
    else {
        cout << "Error opening file for reading!" << endl;
    }

    // and count how many records were read successfully
    cout << "[2] Loaded " << count << " students from " << filename << endl;
     
    return count;
}

// Step 4 – Display all students
void displayAll(Student s[], int n) {
    // TODO: Loop through all students and print formatted info
    cout << "\n[3] Displaying all students:\n" <<
        "---------------------------------------------" << endl;
    for (int i = 0; i < n; ++i) {
        cout << s[i].studentID
            << " " << s[i].name
            << " (" << s[i].major
            << ") - " << s[i].city
            << " GPA: " << fixed << setprecision(1) << s[i].gpa << endl;
    }
}

// Step 5 – Count students with GPA >= 3.0
int countHonors(Student s[], int n) {
    // TODO: Return count of students whose GPA >= 3.0
    int honorsCount = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i].gpa >= 3.0) {
            honorsCount++;
        }
    }
    return honorsCount;
}

// Step 6 – Query by city
void queryByCity(Student s[], int n, const string& city) {
    // TODO: Display all students whose city matches the given input
    // If none match, print "No students found in that city."
    cout << "\n[5] Students from " << city << endl;
    int found = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i].city == city) {
            cout << s[i].name << " (" << s[i].major << ", GPA " << fixed << setprecision(1) << s[i].gpa << ")" << endl;
            found++;
        }
    }
    if (found == 0) {
        cout << "No students found in that city." << endl;
    }
}

// =======================
// Main Function
// =======================
int main() {
    Student students[100];
    int n = 3;

    // Step 1 – Create and store sample data
    students[0] = {"S01", "Tom", "MATH", "Football", 2.8, "tom@google.com", "Modesto"};
    students[1] = {"S02", "Alice", "CS", "Reading", 3.5, "alice@google.com", "Modesto"};
    students[2] = {"S03", "Scott", "CS", "Basketball", 3.2, "scott@google.com", "SanJose"};

    // Step 2 – Write to file
    saveToFile(students, n, "students.txt");

    // Step 3 – Read back from file
    Student loaded[100];
    int count = loadFromFile(loaded, "students.txt");

    // Step 4 – Display all students
    displayAll(loaded, count);

    // Step 5 – Count honors students
    cout << "\n[4] Students with GPA >= 3.0: "
         << countHonors(loaded, count) << endl;

    // Step 6 – Query by city (example: Modesto)
    queryByCity(loaded, count, "Modesto");

    cout << "\nProgram finished." << endl;
    return 0;
}
