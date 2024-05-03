#include <iostream>
#include <string>
using namespace std;

const int max = 20;

struct employee {
    string name;
    long int code;
    string designation;
    int sal;
    int age;
};

int num;

// Function prototypes
void showMenu();
void build();
void insert();
void deleteRecord();
void displayRecord();

// Employee array declaration
employee emp[max];

// Function to build the employee table
void build() {
    cout << "Build The Table\n";
    cout << "Maximum Entries can be " << max << "\n";
    cout << "Enter the number of Entries required: ";
    cin >> num;

    if (num > max) {
        cout << "Maximum number of Entries are " << max << "\n";
        num = max;
    }

    cout << "Enter the following data:\n";
    for (int i = 0; i < num; i++) {
        cout << "Name: ";
        cin >> emp[i].name;
        cout << "Employee ID: ";
        cin >> emp[i].code;
        cout << "Designation: ";
        cin >> emp[i].designation;
        cout << "Salary: ";
        cin >> emp[i].sal;
        cout << "Age: ";
        cin >> emp[i].age;
    }

    showMenu();
}

// Function to insert a new entry into the employee table
void insert() {
    if (num < max) {
        cout << "Enter the information of the Employee\n";
        cout << "Name: ";
        cin >> emp[num].name;
        cout << "Employee ID: ";
        cin >> emp[num].code;
        cout << "Designation: ";
        cin >> emp[num].designation;
        cout << "Salary: ";
        cin >> emp[num].sal;
        cout << "Age: ";
        cin >> emp[num].age;
        num++;
    } else {
        cout << "Employee Table Full\n";
    }
    showMenu();
}

// Function to delete a record based on Employee ID
void deleteRecord() {
    cout << "Enter the Employee ID to Delete Record: ";
    long int code;
    cin >> code;
    bool found = false;
    for (int i = 0; i < num; i++) {
        if (emp[i].code == code) {
            found = true;
            for (int j = i; j < num - 1; j++) {
                emp[j] = emp[j + 1];
            }
            num--;
            cout << "Record Deleted Successfully\n";
            break;
        }
    }
    if (!found) {
        cout << "Employee ID not found\n";
    }
    showMenu();
}

// Function to display a record based on Employee ID
void displayRecord() {
    cout << "Enter the Employee ID to Display Record: ";
    long int code;
    cin >> code;
    bool found = false;
    for (int i = 0; i < num; i++) {
        if (emp[i].code == code) {
            cout << "Name: " << emp[i].name << "\n";
            cout << "Employee ID: " << emp[i].code << "\n";
            cout << "Designation: " << emp[i].designation << "\n";
            cout << "Salary: " << emp[i].sal << "\n";
            cout << "Age: " << emp[i].age << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee ID not found\n";
    }
    showMenu();
}

// Function to display the menu and handle user input
void showMenu() {
    cout << "----- Employee Information -----\n\n";
    cout << "Available Options:\n\n";
    cout << "1. Build Table\n";
    cout << "2. Insert New Entry\n";
    cout << "3. Delete Entry\n";
    cout << "4. Display a Record\n";
    cout << "5. Exit\n";
    cout << "Enter Options: ";
    int option;
    cin >> option;
    switch (option) {
        case 1:
            build();
            break;
        case 2:
            insert();
            break;
        case 3:
            deleteRecord();
            break;
        case 4:
            displayRecord();
            break;
        case 5:
            return;
        default:
            cout << "Expected Options are 1/2/3/4/5\n";
            showMenu();
    }
}

// Main function
int main() {
    showMenu();
    return 0;
}
