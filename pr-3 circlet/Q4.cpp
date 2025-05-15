//Q4 left half traingle
#include <iostream>
using namespace std;

int main(){
	int i,s,j;
	for(i=5;i>=1;i--){
		for(s=4;s>=i;s--){
			cout<<" ";
		}
		for(j=1;j<=i;j++){
			if(j%2!=0){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
		cout<<endl;
	}
}
////output:-
//	1 0 1 0 1
//	  1 0 1 0
//	    1 0 1
//	      1 0
//	        1
//       

