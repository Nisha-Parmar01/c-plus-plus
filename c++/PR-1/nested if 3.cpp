#include <iostream>
using namespace std;

int main(){
	int a=100,b=25,c=14;
	
	if(a>b){
		if(a>c){
			cout<<"a is max";
		}
		else{
			cout<<"c is max";
		}
	}
	else{
		if(b>c){
			cout<<"b is max";
		}
		else{
			cout<<"c is max";
		}
	}
}
