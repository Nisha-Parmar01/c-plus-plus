#include <iostream>
using namespace std;

 int main(){
  int a, b,c;
     cout<<"Enter the value A:";
     cin>>a;
       cout<<"Enter the value B:";
     cin>>b;
       cout<<"Enter the value C:";
     cin>>c;
     
    if(a>b && a>c ){
    	cout<<"a is max"<<endl;
	}
	else if(b>a && b>c){
		cout<<"b is max"<<endl;
	}
	else{
		cout<<"c is max"<<endl;
	}
}
