
#include <iostream>
using namespace std;
int main(){
	double p,i,t,ans;
	cout<<"Enter the Principal amount:";
	cin>>p;
	cout<<"Enter the Anual interest rate:";
	cin>>i;
	cout<<"Enter time period in year:";
	cin>>t;
	ans=(p*i*t)/100;
	cout<<"Simple interset:"<<ans<<endl;
	return 0;
}
