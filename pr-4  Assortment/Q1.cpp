//find all the nagative elements from a given 1D Array
#include <iostream>
using namespace std;

int main(){
	
	int n,i;
    //input
	cout<<"Enter the Array of size:";
	cin>>n;
	int a[n];
	cout<<"Enter array elementa:"<<endl;
	for(i=0;i<n;i++){
		cout<<"a["<< i<<"]:";
		cin>>a[i];
	}
    //	output
	cout<<"Nagtive elemnet from an Array:";
	for(i=0;i<n;i++){
		if(a[i]<0){
			cout<<a[i]<<" ";
		}
		else{
			cout<<"invalide!"<<endl;
		}
		cout<<endl;
	}
}


