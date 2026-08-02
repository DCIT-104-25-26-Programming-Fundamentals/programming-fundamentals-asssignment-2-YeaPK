// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("Error: Cannot divide by zero.");
    }
    return a / b;
}

double modulusOp(int a, int b) {
    if (b == 0) {
        throw runtime_error("Error: Cannot perform modulus by zero.");
    }
    return a % b;
}

double mod(int a, int b) {
    return modulusOp(a, b);
}

double exponentiate(double base, double exponent) {
    return pow(base, exponent);
}

double getNumberInput(const string& prompt) {
    double num;
    cout << prompt;
    cin >> num;
    return num;
}

double getIntegerInput(const string& prompt) {
    int num;
    cout << prompt;
    cin >> num;
    return num;
}

int main() {
    int choice;

    do {
        cout << "\n============================\n";
        cout << "      SIMPLE CALCULATOR\n";
        cout << "============================\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Modulus\n";
        cout << "6. Exponentiation\n";
        cout << "7. Quit\n";
        cout << "Select an operation (1-7): ";
        cin >> choice;

        double num1, num2, result;
        try {
            switch (choice) {
                case 1:
                    num1 = getNumberInput("Enter first number: ");
                    num2 = getNumberInput("Enter second number: ");
                    result = add(num1, num2);
                    cout << fixed << setprecision(2) << num1 << " + " << num2 << " = " << result << endl;
                    break;
                case 2:
                    num1 = getNumberInput("Enter first number: ");
                    num2 = getNumberInput("Enter second number: ");
                    result = subtract(num1, num2);
                    cout << fixed << setprecision(2) << num1 << " - " << num2 << " = " << result << endl;
                    break;
                case 3:
                    num1 = getNumberInput("Enter first number: ");
                    num2 = getNumberInput("Enter second number: ");
                    result = multiply(num1, num2);
                    cout << fixed << setprecision(2) << num1 << " * " << num2 << " = " << result << endl;
                    break;
                case 4:
                    num1 = getNumberInput("Enter first number: ");
                    num2 = getNumberInput("Enter second number: ");
                    result = divide(num1, num2);
                    cout << fixed << setprecision(2) << num1 << " / " << num2 << " = " << result << endl;
                    break;
                case 5: {
                    int intNum1, intNum2;
                    intNum1 = static_cast<int>(getIntegerInput("Enter first integer: "));
                    intNum2 = static_cast<int>(getIntegerInput("Enter second integer: "));
                    result = mod(intNum1, intNum2);
                    cout << intNum1 << " % " << intNum2 << " = " << static_cast<int>(result) << endl;
                    break;
                }
                case 6:
                    num1 = getNumberInput("Enter base: ");
                    num2 = getNumberInput("Enter exponent: ");
                    result = exponentiate(num1, num2);
                    cout << fixed << setprecision(2) << num1 << " ^ " << num2 << " = " << result << endl;
                    break;
                case 7:
                    cout << "Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please select a number between 1 and 7." << endl;
            }   
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    } while (choice != 7);

    return 0;
}

    

