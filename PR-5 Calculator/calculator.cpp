#include <iostream>
using namespace std;

int add(int x,int y){
	return x+y;
}
int sub(int x,int y){
	return x-y;
}
int mul(int x,int y){
	return x*y;
}
float div(int x,int y){
	return (float)x/y;
}
int mod(int x,int y){
	return x%y;
}
int main(){
	int choice,x,y;
	do{

	cout<<"=====calculator======"<<endl;
	cout<<"Press 1 for +"<<endl;
	cout<<"Press 2 for -"<<endl;
	cout<<"Press 3 for *"<<endl;
	cout<<"Press 4 for /"<<endl;
	cout<<"Press 5 for %"<<endl;
	cout<<"press 0 for the exit"<<endl;
	cout<<"Enter your choice:";
	cin>>choice;
	
	switch(choice){
		case 1:{
			cout<<"Enter the first number:";
			cin>>x;
			cout<<"Enter the second number:";
			cin>>y;
			cout<<"Ans :"<<add(x,y)<<endl;
			break;
		}
			case 2:{
			cout<<"Enter the first number:";
			cin>>x;
			cout<<"Enter the second number:";
			cin>>y;
			cout<<"Ans :"<<sub(x,y)<<endl;
			break;
		}
			case 3:{
			cout<<"Enter the first number:";
			cin>>x;
			cout<<"Enter the second number:";
			cin>>y;
			cout<<"Ans :"<<mul(x,y)<<endl;
			break;
		}
			case 4:{
			cout<<"Enter the first number:";
			cin>>x;
			cout<<"Enter the second number:";
			cin>>y;
			if(y!=0){
				cout<<"Ans :"<<div(x,y)<<endl;
			}
			else{
				 cout<<"Error: Cannot divide by zero!" << endl;
			}
			break;
		}
		case 5:{
			cout<<"Enter the first number:";
			cin>>x;
			cout<<"Enter the second number:";
			cin>>y;
			if(y!=0){
				cout<<"Ans :"<<mod(x,y)<<endl;
			}
			else{
				 cout<<"Error: Cannot take modual by zero!" << endl;
			}
			break;
		}
		case 0:{
		    cout << "Exiting Calculator. Thank you!" << endl;
			break;
		}
		default:{
			cout<<"invalid choice"<<endl;
			break;
	   }
	}
  }while(choice != 0);
  return 0;	
}
