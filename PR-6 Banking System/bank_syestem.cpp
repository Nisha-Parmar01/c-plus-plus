//bankig system
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
	            cout<<"Amount Withdrawn: Rs. " << amt << endl;
       			cout<<"Available Balance: Rs. " << amuno << endl;
	        }
	 }
};
class SavingAccount : public bank {
public:
     virtual string getType(){
        return "Saving";
    }
};
class CurrentAccount : public bank {
public:
      virtual string getType(){
        return "Current";
    }
};
int	main(){
		bank* Account[50];
		int cnt=0,choice,accno,i,ac_no;
	    double amuno;
	    string name;
		while(1){
		cout<<"--------bank menu--------"<<endl;
		cout<<"press 1 Create Account"<<endl;
		cout<<"press 2 show account details"<<endl;
		cout<<"press 3 diposite Amount"<<endl;
		cout<<"press 4 withdraw Amouunt"<<endl;
		cout<<"press 5 Exit"<<endl;
		cout<<"Enter the choice:";
		cin>>choice;
	    if(choice==4){
	    	cout<<"Thank you";
	    	break;
		}
		int check = 0;
		switch(choice){
			  case 1: {
			  	int type;
			  	 cout<< "Select Account Type:"<<endl;
				cout<<"1. Savings \n2. Current"<<endl;
				cout<<"Enter Choice: ";
       			 cin >> type;
					    if (type == 1) {
                			Account[cnt] = new SavingAccount();
            			} else if (type == 2) {
                			Account[cnt] = new CurrentAccount();
            			} else {
                		cout << "Invalid account type!" << endl;
                		continue;
                		}
	            cout << "Enter the account number: ";
	            cin >> accno;
	            cout << "Enter the account holder name: ";
	            cin >> name;
	            cout << "Enter the amount: ";
	            cin >> amuno;
	            Account[cnt]->setdetails(accno, name, amuno);
	            cnt++;
	            cout << "------ account created successfully -------" << endl;
	            break;
	        }
	    case 2:
	    	check = 0;
			    cout << "Enter Account Number: ";
			    cin >> ac_no;
			    for(i = 0; i < cnt; i++) {
			        if(Account[i]->Acno() == ac_no) {
			            check = 1;
			            Account[i]->getdetails();
			             cout << "---------Account details displayed successfully.------------" << endl;
			            break;
			        }
				}   
			    if(check == 0) {
			        cout << "Account not found" << endl;
			    }
    		break;
			case 3:
				check = 0;
				  double depositAmt;
				 cout << "Enter Account Number: ";
			    cin >> ac_no;
			    for(i = 0; i < cnt; i++) {
			        if(Account[i]->Acno() == ac_no) {
			            check = 1;
				        cout << "Enter amount to deposit: ";
				        cin >> depositAmt;
				       Account[i]->deposite(depositAmt); 
				       	cout<<"---------Amount deposited successfully.--------------"<<endl;
			            break;
			        }
				}   
			    if(check == 0) {
			        cout << "Account not found" << endl;
			        
			    }
				break;
			
			case 4:
				check = 0;
				double withdrawAmt;	
				cout << "Enter Account Number: ";
			    cin >> ac_no;
			    for(i = 0; i < cnt; i++) {
			        if(Account[i]->Acno() == ac_no) {
			            check = 1;
                        cout << "Enter amount to withdraw: ";
                        cin >> withdrawAmt;
                        Account[i]->withdraw(withdrawAmt);
                        cout<<"---------succsefully withdraw amouunt --------------"<<endl;
			            break;
			        }
				}   
			    if(check == 0) {
			        cout << "Account not found" << endl;
			        
			    }
				break;
			default:{
				        cout << "Invalid Choice! Please try again." << endl;
				}
		  }
	    }
	    return 0;
	}
