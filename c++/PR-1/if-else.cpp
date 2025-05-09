#include <iostream>
using namespace std;

main(){
	
	
	int n;
	char h;
	cout<<"Enter the value m:";
	cin>>n;
	
	
    if (n >= 91 && n <= 100) {
        h = 'A';
        cout << "Your grade is A";
    }
    else if (n >= 81 && n <= 90) {
        h = 'B';
        cout << "Your grade is B";
    }
    else if (n >= 71 && n <= 80) {
        h = 'C';
        cout << "Your grade is C";
    }
    else if (n >= 61 && n <= 70) {
        h = 'D';
        cout << "Your grade is D";
    }
    else if (n >= 51 && n <= 60) {
        h = 'E';
        cout << "Your grade is E";
    }
    else {
        h = 'F';
        cout << "Your grade is F";
    }

    if (h >= 'A' && h <= 'E') {
        cout << "Congratulations! You are eligible for the next level.\n";
    } else {
        cout << "Please try again next time.\n";
    }
}
