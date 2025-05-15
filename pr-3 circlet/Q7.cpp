
//Q7 custom pattern
#include<iostream>
using namespace std;

int main(){
	int i,s,j,strat=5;
	for(i=1;i<=5;i++){
		for(j=1;j<=5;j++)
			if(i==1||i==3||j==1||(i==2&&j==5)){
				cout<<"*";
			}
		else{
			cout<<" ";
		}
		cout<<endl;
	}
}
//output:-
//	* * * * *
//	*       *
//	* * * * *
//	*
//	*
//	*
