//find the largest elemnet from given 2D Array
#include <iostream>
using namespace std;

int main(){
	int i,j,row,col;
	cout<<"Enter array row size:";
	cin>>row;
	cout<<"Enter array col size:";
	cin>>col;
	int a[row][col];
    //input
    cout<<"Enter array elements:"<<endl;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
		cout<<"a["<< i <<"]"<<"["<< j <<"]:";
		cin>>a[i][j];
		}
		cout<<endl;
	}
   //	output largest element
	   int large=0;
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				if(a[i][j]>large){
					large=a[i][j];
				}
		}
		cout<<endl;
	}
	cout<<"The largest elemnet is:"<<large;
	
}
