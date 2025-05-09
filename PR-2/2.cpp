#include <iostream>
using namespace std;

int main(){
	int n,c;
	 
	 cout<<"Ente any  Number:";
	 cin>>n;
	 
	 if(n==0){
	 	c=1;
	 }
	while(n != 0){
			 	n/=10;
			 	c++;
			     }


	 cout<<"Total number of digit:"<<c;
}
