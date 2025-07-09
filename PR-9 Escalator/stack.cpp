//stack
#include <iostream>
using namespace std;
class Stack{
	public:
		int *arr;
		int top;
		int capacity;
		Stack(int size){
			capacity=size;
			arr= new int[capacity];
			top=-1;
		}
		bool full(){
			return top==capacity-1;
		}
		bool Empty(){
			return top==-1;
		}
		void push(int element){
			if(full()){
				cout<<"-----stack is overflow------"<<endl;
				return ;
			}else{
				arr[++top]=element;
				cout<<element<<"pushed is stack"<<endl;
			}
		}
		int pop(){
			if(Empty()){
				cout<<"------stack is overflow------"<<endl;
			}else{
				int element=arr[top--];
				return element;
			}
		}
		int peek() {
	        if (Empty()) {
	            cout << "Stack is empty" << endl;
	            return -1;
	        } else {
	            return arr[top];
        	}
    	}
        void display() {
        if (Empty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements are: ";
            for (int i =0; i <= top; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
int main(){
	int choice,element;
	int size;
	cout<<"Enter the size:";
	cin>>size;

	Stack s(size);
	while(1){
		cout<<"-------Menu--------"<<endl;
		cout<<"press 1 push"<<endl;
		cout<<"press 2 pop"<<endl;
		cout<<"press 3 peek"<<endl;
		cout<<"press 4 display"<<endl;
		cout<<"press 5 stack is full"<<endl;
		cout<<"press 6 stack is Empty"<<endl;
		cout<<"press 0 Exit"<<endl;
		cout<<" Enter the choice:";
		cin>>choice;
		
		if(choice==0){
			cout<<"----------Thank you---------"<<endl;
			return 0;
		}
		switch(choice){
			case 1:
				cout<<"Enter the your element:";
				cin>>element;
				s.push(element);
				break;
			case 2:
			element=s.pop();
				if(element!=-1){
					cout<<" popped element:"<<element<<endl;
				}
			     break;
			case 3:
				element=s.peek();
				if(element!=-1){
					cout<<" Top element:"<<element<<endl;
				}
			     break;    
			case 4:
				s.display();
			     break;
			case 5:
				 if (s.full()){
				 	cout << "Yes, stack is full." << endl;
				 } else{
				 	cout << "No, stack is not full." << endl;
				 }
				break;
			case 6:
				if (s.Empty()) {
						cout << "Yes, stack is empty." << endl;
				} else {
						cout << "No, stack is not empty." << endl;
				}
				break;
	
			default:
			cout<<"--------Invalid choice-------"<<endl;	 	
		}
	}
}
