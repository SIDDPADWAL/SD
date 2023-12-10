#include <iostream>
#include <vector>

using namespace std;

// Function to accept roll numbers
vector<int> acceptRoll() {
    vector<int> rollNumbers;
    int numberOfStudents;

    cout << "Enter the number of students: ";
    cin >> numberOfStudents;

    for (int i = 0; i < numberOfStudents; ++i) {
        int rollNumber;
        cout << "Enter Roll Number of Student " << i + 1 << ": ";
        cin >> rollNumber;
        rollNumbers.push_back(rollNumber);
    }

    return rollNumbers;
}

// Function to print roll numbers
void printRoll(const vector<int>& rollNumbers) {
    for (int i = 0; i < rollNumbers.size(); ++i) {
        cout << rollNumbers[i] << endl;
    }
}

// Insertion Sort for Sorting the list of Roll Numbers
vector<int> insertionSort(vector<int> rollNumbers) {
    for (int i = 1; i < rollNumbers.size(); ++i) {
        int key = rollNumbers[i];
        int j = i - 1;

        while (j >= 0 && key < rollNumbers[j]) {
            rollNumbers[j + 1] = rollNumbers[j];
            --j;
        }

        rollNumbers[j + 1] = key;
    }

    return rollNumbers;
}

// Function for performing Non-Recursive Ternary Search
int nonRecursiveTernarySearch(const vector<int>& rollNumbers, int rollToFind) {
    int left = 0;
    int right = rollNumbers.size() - 1;

    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = left + 2 * (right - left) / 3;

        if (rollToFind == rollNumbers[left]) {
            return left;
        } else if (rollToFind == rollNumbers[right]) {
            return right;
        } else if (rollToFind < rollNumbers[left] || rollToFind > rollNumbers[right]) {
            return -1;
        } else if (rollToFind <= rollNumbers[mid1]) {
            right = mid1;
        } else if (rollToFind > rollNumbers[mid1] && rollToFind <= rollNumbers[mid2]) {
            left = mid1 + 1;
            right = mid2;
        } else {
            left = mid2 + 1;
        }
    }

    return -1;
}

// Function for performing Recursive Ternary Search
int recursiveTernarySearch(const vector<int>& rollNumbers, int left, int right, int rollToFind) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (rollNumbers[mid1] == rollToFind) {
            return mid1;
        }

        if (rollNumbers[mid2] == rollToFind) {
            return mid2;
        }

        if (rollToFind < rollNumbers[mid1]) {
            return recursiveTernarySearch(rollNumbers, left, mid1 - 1, rollToFind);
        } else if (rollToFind > rollNumbers[mid2]) {
            return recursiveTernarySearch(rollNumbers, mid2 + 1, right, rollToFind);
        } else {
            return recursiveTernarySearch(rollNumbers, mid1 + 1, mid2 - 1, rollToFind);
        }
    }

    return -1;
}

int main() {
    vector<int> unsortedRoll;  // Move the declaration outside the switch statement
    int choice = 1;

    while (choice == 1) {
        cout << "\n---------------------MENU---------------------" << endl;
        cout << "1. Accept Student Roll Numbers" << endl;
        cout << "2. Display the Roll Numbers of Student" << endl;
        cout << "3. Sort Roll Numbers from the list" << endl;
        cout << "4. Perform Non-Recursive Ternary Search" << endl;
        cout << "5. Perform Recursive Ternary Search" << endl;
        cout << "6. Exit" << endl;

        cout << "\nEnter your choice (from 1 to 6): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                unsortedRoll = acceptRoll();
                break;
            }
            case 2: {
                printRoll(unsortedRoll);
                break;
            }
            case 3: {
                cout << "Elements after performing Insertion Sort:" << endl;
                vector<int> sortedRoll = insertionSort(unsortedRoll);
                printRoll(sortedRoll);
                break;
            }
            case 4: {
                int findRoll;
                cout << "Enter the Roll Number to be searched: ";
                cin >> findRoll;
                int indexNR = nonRecursiveTernarySearch(unsortedRoll, findRoll);
                if (indexNR != -1) {
                    cout << "The Roll Number " << findRoll << " is found at position " << indexNR + 1 << endl;
                } else {
                    cout << "Roll Number " << findRoll << " not found!!" << endl;
                }
                break;
            }
            case 5: {
                int findRollRec;
                cout << "Enter the Roll Number to be searched: ";
                cin >> findRollRec;
                int left = 0;
                int right = unsortedRoll.size() - 1;
                int indexR = recursiveTernarySearch(unsortedRoll, left, right, findRollRec);
                if (indexR != -1) {
                    cout << "The Roll Number " << findRollRec << " is found at position " << indexR + 1 << endl;
                } else {
                    cout << "Roll Number " << findRollRec << " not found!!" << endl;
                }
                break;
            }
            case 6:
                cout << "Thanks for using this program!!" << endl;
                choice = 0;
                break;
            default:
                cout << "Wrong choice!!" << endl;
                choice = 0;
                break;
        }
    }

    return 0;
}
