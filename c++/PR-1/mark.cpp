#include <iostream>
using namespace std;
main(){
	int n;
	char h;
	
	
	cout<<"Enter the value n:";
	cin>>n;
	
	if(n>=91 &&n>=100){
		h='A';
		cout<<"Your grade is A"<<endl;
	}
	else if(n>=81 && n>=80){
		h='B';
		cout<<"Your grade is B"<<endl;
	}
	else if(n>=71 && n>=70){
		h='C';
		cout<<"Your grade is C"<<endl;
	}
	else if(n>=61 && n>=60){
		h='D';
		cout<<"Your grade is D"<<endl;
	}
	else if(n>=51 && n>=50){
		h='E';
		cout<<"Your grade is E"<<endl;
	}
	else if(n>=41 && n>=40){
		h='F';
		cout<<"Your grade is F"<<endl;
	}
	
		
	
			switch(h)
			{
					case 'A':{
								cout<<"Excellent work!";
								break;
							}
					case'B':{
								cout<<"Well done";
								break;
							}
					case 'C':{
								cout<<"Good job";
								break;
							}
					case 'D':{
								cout<<"You passed,but you could do better";
								break;
							}
					case 'E':{
								cout<<"You passed,but you could do better";
								break;
							}
					case'F':{
								cout<<"Soory, you Failed";
								break;
							}	
					default:
					  cout<<"Invalid choice";										
			}
     
}
