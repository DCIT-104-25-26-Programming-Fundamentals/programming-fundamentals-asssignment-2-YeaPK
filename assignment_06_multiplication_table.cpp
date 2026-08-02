// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

void printMultiplicationTable(int num) {
    cout << "Multiplication Table for " << num << ":\n";
    for (int i = 1; i <= 12; ++i) {
        cout << num << "  x  " << i << "  =  " << (num * i) << "\n";
    }
}

void printMultiplicationTablesUpToN(int n) {
    if (n <= 0) {
        cout << "Invalid value. N must be a positive integer.\n";
        return;
    }

    for (int i = 1; i <= n; ++i) {
        printMultiplicationTable(i);
        if (i < n) {
            cout << "---------------------------\n";
        }
    }
}

int main() {
    int choice;

    do {
        cout << "\n=====================================\n";
        cout << " MULTIPLICATION TABLE MENU\n";
        cout << "=====================================\n";
        cout << "1. Print Multiplication Table for a Number\n";
        cout << "2. Print Multiplication Tables from 1 to N\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int num;
                cout << "Enter a number: ";
                cin >> num;
                printMultiplicationTable(num);
                break;
            }
            case 2: {
                int n;
                cout << "Enter a number N: ";
                cin >> n;
                printMultiplicationTablesUpToN(n);
                break;
            }
            case 0: cout << "\nExiting program. Goodbye!\n"; break;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    } while (choice != 0);

    return 0;
}

