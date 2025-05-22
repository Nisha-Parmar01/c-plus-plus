//sum of elements in row and sum of 2DArray
#include <iostream>
using namespace std;

int main() {
    int i,j,row,col,r,c;

    cout<<"Enter array row size:";
    cin >> row;
    cout<<"Enter array col size:";
    cin >> col;

    int a[row][col];

    // Input elements
    cout << "nEnter array elements:"<<endl;
    for (i=0; i<row; i++) {
        for (j=0; j<col; j++) {
            cout << "a["<<i<<"]"<<"["<<j<<"]:";
            cin >> a[i][j];
        }
    }

    // Row input and sum
    cout << "Enter the row:";
    cin >> r;

    if (r<0||r>=row) {
        cout << "? Invalid row index!" << endl;
        return 1;
    }
    int rowsum = 0;
    cout << "Elements of row :";
    for (int j = 0; j < col; j++) {
        cout << a[r][j] << " ";
        rowsum += a[r][j];
    }
     cout<<endl;
    cout << "Sum of row :"<< rowsum << endl;

    // Column input and sum
    cout << "Enter the column: ";
    cin >> c;
	  if (c<0||c>=col) {
        cout << "? Invalid col index!" << endl;
        return 1;
    }
    int colsum = 0;
    cout << "Elements of column :";
    for (int i = 0; i < row; i++) {
        cout << a[i][c] << " ";
        colsum += a[i][c];
    }
    cout<<endl;
    cout << "Sum of column "<< colsum << endl;
    
}
