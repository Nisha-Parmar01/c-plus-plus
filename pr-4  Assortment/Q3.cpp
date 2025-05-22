//find the transpose matrix from given 2D Array
#include <iostream>
using namespace std;
int main(){
	int i,j,row,col;
	cout<<"Enter the arrays row:";
	cin>>row;
	cout<<"Enter the arrays col:";
	cin>>col;
	int a[row][col];
	int t[col][row];
    //input
    cout<<"Enter arrays elments:"<<endl;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
		cout<<"a["<< i <<"]"<<"["<< j <<"]:s";
		cin>>a[i][j];
		}
		cout<<endl;
	}
  // transform logic
  	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			t[j][i] = a[i][j];
		}
	}
   // output transform
   cout<<"output:"<<endl;
   	cout<<" the  Transfrom matrix any array:"<<endl;
		for(i=0;i<col;i++){
			for(j=0;j<row;j++){
				cout<<t[i][j]<<" ";
			}
		cout<<endl;
	}

}
