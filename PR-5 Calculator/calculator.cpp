#include <iostream>
using namespace std;

int add(int x, int y) {
    return x + y;
}
int sub(int x, int y) {
    return x - y;
}
int mul(int x, int y) {
    return x * y;
}
float div(int x, int y) {
    return (float)x / y;
}
int mod(int x, int y) {
    return x % y;
}
 main() {
    int choice, x, y;

    do {
        cout << "\n===== Calculator =====" << endl;
        cout << "Press 1 for +" << endl;
        cout << "Press 2 for -" << endl;
        cout << "Press 3 for *" << endl;
        cout << "Press 4 for /" << endl;
        cout << "Press 5 for %" << endl;
        cout << "Press 0 to Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                cout << "Enter the first number: ";
                cin >> x;
                cout << "Enter the second number: ";
                cin >> y;
                break;
        }

        switch (choice) {
            case 1:
                cout << "Ans: " << add(x, y) << endl;
                break;
            case 2:
                cout << "Ans: " << sub(x, y) << endl;
                break;
            case 3:
                cout << "Ans: " << mul(x, y) << endl;
                break;
            case 4:
                if (y != 0) {
                    cout << "Error: Cannot divide by zero!" << endl;
                } else {
                    cout << "Ans: " << div(x, y) << endl;
                }
                break;
            case 5:
                if (y != 0) {
                    cout << "Error: Cannot take modulo by zero!" << endl;
                } else {
                    cout << "Ans: " << mod(x, y) << endl;
                }
                break;
            case 0:
                cout << "Exiting Calculator. Thank you!" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
                break;
        }

    } while (choice != 0);
}

