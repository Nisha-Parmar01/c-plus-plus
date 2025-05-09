#include <iostream>
using namespace std;
main(){
	int a=10;
	int b=20;
	cout<<"Before Swaping"<<endl;
	cout<<"A:"<<a<<endl;
	cout<<"B:"<<b<<endl;
	
	cout<<"After Swaping"<<endl;
	a=a+b;
	b=a-b;
	a=a-b;
	cout<<"a:"<<a<<endl;
	cout<<"b:"<<b<<endl;
}
