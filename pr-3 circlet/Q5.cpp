//Q5 full pyramid pattern
#include <iostream>
using namespace std;

int main(){
	int i,s,j;
	for(i=5;i>=1;i--){
		for(s=1;s<=i;s++){
			cout<<" ";
		}
		for(j=i;j<=5;j++){
			cout<<j;
		}
		for(j=4;j>=i;j--){
			cout<<j;
		}
		cout<<endl;
	}
}
//output:-
//        5
//      4 5 4
//    3 4 5 4 3
//  2 3 4 5 4 3 2
//1 2 3 4 5 4 3 2 1
