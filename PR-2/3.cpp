#include <iostream>
using namespace std;


int main(){
	int n ,ram, sum;
	 cout<<"Enter any number:";
	 cin>>n;
	 
	 ram=n%10;
	
	while(n>=10){
		n=n/10;
	}
	sum=ram+n;
	cout<<"The sum of frist and last digit:"<<sum;
	
	
}
