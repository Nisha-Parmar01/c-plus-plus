#include <iostream>
using namespace std;
class bank{
		private:
			int accno;
			double amuno;
			string name;
			public:
	    void setdetails(int accno, string name,double amuno) {
	        this->accno = accno;
	    	this->name=name;
	    	this->amuno=amuno;
	    }
	    int Acno(){
	    	return accno ;
		}
		void getdetails(){
			cout<<"------------------------------"<<endl;
			cout<<"Account number:"<<this->accno<<endl;
			cout<<"Account Name:"<<this->name<<endl;
			cout<<"Account blance:"<<this->amuno<<endl;
			cout<<"------------------------------"<<endl;
		}
		void deposite(double amt){
		  amuno += amt;
        cout << "Amount Deposited: Rs. "<< amt << endl;
        cout << "Updated Balance: Rs. "<< amuno << endl;
		}
	    void withdraw(double amt) {
	        if (amt > amuno) {
	            cout << "?Insufficient Balance!" << endl;
	        } else {
	            amuno -= amt;
	            cout << "Rs. " << amt<< endl;
	            cout << "Updated Balance: Rs. " << amuno << endl;
	        }
	 }
};
int	main(){
		bank b[50];
		int cnt=0,choice,check = 0,accno,i,ac_no;
	    double amuno;
	    string name;
		while(1){
		cout<<"--------bank menu--------"<<endl;
		cout<<"press 1 Create Account"<<endl;
		cout<<"press 2  check Bank details"<<endl;
		cout<<"press 3 diposite Amount"<<endl;
		cout<<"press 4 withdraw Amouunt"<<endl;
		cout<<"press 5 Exit"<<endl;
		cout<<"Enter the choice:";
		cin>>choice;
	    if(choice==5){
	    	cout<<"Thank you";
	    	break;
		}
		switch(choice){
			  case 1: {
	            cout << "Enter the account number: ";
	            cin >> accno;
	            cout << "Enter the account holder name: ";
	            cin >> name;
	            cout << "Enter the amount: ";
	            cin >> amuno;
	            b[cnt++].setdetails(accno, name, amuno);
	            cout << "------ account created successfully -------" << endl;
	            break;
	        }
	    case 2:
			    cout << "Enter Account Number: ";
			    cin >> ac_no;
			    for(i = 0; i < cnt; i++) {
			        if(b[i].Acno() == ac_no) {
			            check = 1;
			            b[i].getdetails();
			            break;
			        }
				}   
			    if(check == 0) {
			        cout << "Account not found" << endl;
			    }
			    cout << "----------account details--------------" << endl;
    		break;
			case 3:
				  double depositAmt;
				 cout << "Enter Account Number: ";
			    cin >> ac_no;
			    for(i = 0; i < cnt; i++) {
			        if(b[i].Acno() == ac_no) {
			            check = 1;
				        cout << "Enter amount to deposit: ";
				        cin >> depositAmt;
				        b[i].deposite(depositAmt); 
			            break;
			        }
				}   
			    if(check == 0) {
			        cout << "Account not found" << endl;
			        
			    }
						cout<<"---------deposited successfully!--------------"<<endl;
				break;
			
			case 4:
				double withdrawAmt;	
				cout << "Enter Account Number: ";
			    cin >> ac_no;
			    for(i = 0; i < cnt; i++) {
			        if(b[i].Acno() == ac_no) {
			            check = 1;
                        cout << "Enter amount to withdraw: ";
                        cin >> withdrawAmt;
                        b[i].withdraw(withdrawAmt);
			            break;
			        }
				}   
			    if(check == 0) {
			        cout << "Account not found" << endl;
			        
			    }
						cout<<"---------succsefully withdraw amouunt --------------"<<endl;
				break;
			default:{
				        cout << "Invalid Choice! Please try again." << endl;
			}
		  }
	    }
	    return 0;
	}
