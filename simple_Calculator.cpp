#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Function declarations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, double exponent);
double squareRoot(double num);
double sine(double angle);
double cosine(double angle);
double tangent(double angle);

int main() {
    string operation;
    double operand1, operand2;

    while (true) {
        cout << "Welcome to the Complex Calculator!\n";
        cout << "Enter the operation you want to perform (+, -, *, /, ^, sqrt, sin, cos, tan, q to quit): ";
        cin >> operation;

        if (operation == "q") {
            cout << "Exiting the calculator. Goodbye!\n";
            break;
        }

        if (operation == "+" || operation == "-" || operation == "*" || operation == "/" || operation == "^") {
            cout << "Enter two operands: ";
            if (!(cin >> operand1 >> operand2)) {
                cout << "Error: Invalid input. Please enter numeric values.\n";
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                continue;
            }

            if (operation == "+") {
                cout << "Result: " << add(operand1, operand2) << endl;
            } else if (operation == "-") {
                cout << "Result: " << subtract(operand1, operand2) << endl;
            } else if (operation == "*") {
                cout << "Result: " << multiply(operand1, operand2) << endl;
            } else if (operation == "/") {
                if (operand2 != 0) {
                    cout << "Result: " << divide(operand1, operand2) << endl;
                } else {
                    cout << "Error: Division by zero is undefined.\n";
                }
            } else if (operation == "^") {
                cout << "Result: " << power(operand1, operand2) << endl;
            } else {
                cout << "Error: Invalid operation.\n";
            }
        } else if (operation == "sqrt" || operation == "sin" || operation == "cos" || operation == "tan") {
            cout << "Enter operand: ";
            if (!(cin >> operand1)) {
                cout << "Error: Invalid input. Please enter a numeric value.\n";
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                continue;
            }

            if (operation == "sqrt") {
                if (operand1 >= 0) {
                    cout << "Result: " << squareRoot(operand1) << endl;
                } else {
                    cout << "Error: Cannot calculate square root of a negative number.\n";
                }
            } else if (operation == "sin") {
                cout << "Result: " << sine(operand1) << endl;
            } else if (operation == "cos") {
                cout << "Result: " << cosine(operand1) << endl;
            } else if (operation == "tan") {
                cout << "Result: " << tangent(operand1) << endl;
            } else {
                cout << "Error: Invalid operation.\n";
            }
        } else {
            cout << "Error: Invalid operation.\n";
        }
    }

    return 0;
}

// Function definitions

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
    return a / b;
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double squareRoot(double num) {
    return sqrt(num);
}

double sine(double angle) {
    return sin(angle);
}

double cosine(double angle) {
    return cos(angle);
}

double tangent(double angle) {
    return tan(angle);
}
