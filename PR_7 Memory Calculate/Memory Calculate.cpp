#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class MemoryCalculate {
private:
    T Id;
    string name;
public:
    MemoryCalculate(T id, string Name) {
        this->Id = id;
        this->name = Name;
    }

    void display() {
        cout << "Student ID: " << Id << endl;
        cout << "Student Name: " << name << endl;
    }

    T getId() {
        return Id;
    }
};
int main() {
    vector<MemoryCalculate<int>> students;
    int Choice;

    while (1) {
        cout << "\n-------Student Management System------" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Remove by Student ID" << endl;
        cout << "4. Search Student by ID" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter the choice: ";
        cin >> Choice;

        if (Choice == 5) {
            cout << "-----------Thank you!-----------" << endl;
            return 0;
        }
        switch (Choice) {
        case 1: {
            int id;
            string Name;
            cout << "Enter the student Id: ";
            cin >> id;
            cout << "Enter the student Name: ";
            cin.ignore();
            getline(cin, Name);

            MemoryCalculate<int> s(id, Name);
            students.push_back(s);
            cout << "---Student added successfully----" << endl;
            break;
        }

        case 2: {
            if (students.empty()) {
                cout << "No students to display." << endl;
            } else {
                cout << "---Student List---" << endl;
                for (int i = 0; i < students.size(); i++) {
                    students[i].display();
                }
                 cout << "---Student Display completed----" << endl;
            }
            break;
        }
        case 3: {
            int rem;
            int check = 0;
            cout << "Enter student ID to remove: ";
            cin >> rem;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getId() == rem) {
                    students.erase(students.begin() + i);
                    check = 1;
                    cout << "----Remove Student ID successfully----" << endl;
                }
            }
            if (check == 0) {
                cout << "Student not found." << endl;
            }
            break;
        }

        case 4: {
            int std;
            int check = 0;
            cout << "Enter student ID to search: ";
            cin >> std;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getId() == std) {
                    cout << "---Student Found---" << endl;
                    students[i].display();
                    check = 1;
                }
            }
            if (check == 0) {
                cout << "Student not found." << endl;
            }
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}

