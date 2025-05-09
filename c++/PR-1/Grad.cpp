#include <iostream>
using namespace std;
main(){
	int x;
	
	cout<<"Enter the value n:";
	cin>>x;
	
					(x>=91  &&   x<=100)
			    		?printf("your grade is A")
			    		:
			      		(x>81 && x<90)
			      			?printf("your grade is B")
			      			:
							(x>=71 && x<=80)
								?printf("your garde is C")
								:
				  				(x>=61 && x<=70)
				  	   			?printf("your garde is D")
				  					:
				   					 (x>=51 && x<=60)
				     					?printf("your grade is E")
				     					:
				    						(x>=34 && x<=50)
				      							 ?printf("your garde is f")
				       							 :printf("sorry you are fail");
}
