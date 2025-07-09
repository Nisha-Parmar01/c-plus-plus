//Queue
#include <iostream>
using namespace std;
	class Queue{
		private:
			int*arr;
			int 
			front,rear,size,capacity;
		public:
			Queue(int cap){
				capacity=cap;
				arr=new int[capacity];
				front=-1;
				rear=-1;
				size=0;
			}
			bool isfull(){
				return rear==capacity-1;
			}
			bool isEmpty(){
				return front==-1||front>rear;
			}
			void enqueue(int value){
				if( isfull()){
					cout<<"Queue is full(overflow)"<<endl;
					return;
				}
				if(front==-1)
				front=0;
				rear++;
				arr[rear]=value;
				size++;
				cout<<value<<endl;
			}
			void dequeue(){
					if( isEmpty()){
						cout<<"Queue is empty (underflow)"<<endl;
						return;
					}
					cout << "Dequeued: " << arr[front] << endl;
					front++;
					size--;
			}	
			void peek(){
					if( isEmpty()){
						cout<<"Queue is empty (underflow)"<<endl;
						return;
					}else{
						cout<<"Front element is:"<<arr[front]<<endl;
					}
			}
				
			void display(){
					if( isEmpty()){
						cout<<"Queue is empty"<<endl;
						return;
					}
					cout<<"Queue elements: ";
					for(int i=front;i<=rear;i++){
						cout<<arr[i]<<" ";
					}
					cout<<endl;
			}
			~Queue(){
				delete[]arr;	
			}
	};
	int main(){
		int choice,value;
		int capacity;
		cout<<" Enter queue capacity:";
		cin>>capacity;
		Queue q(capacity);
	
		while(1){
			cout<<"--------Menu-----------"<<endl;
			cout<<"press 1 enqueue(insert)"<<endl;
			cout<<"press 2 dequeue(remove)"<<endl;
			cout<<"press 3 front(peeek)"<<endl;
			cout<<"press 4 display"<<endl;
			cout<<"press 5 queue is full"<<endl;
			cout<<"press 5 queue is Empty"<<endl;
			cout<<"press 0 Exit:"<<endl;
			cout<<"Enter the choice:";
			cin>>choice;
			if(choice==0){
			cout<<"----------Thank you-----------"<<endl;
			break;
			}
			switch(choice){
				case 1:
					cout<<"Enter the value:";
					cin>>value;
					q.enqueue(value);
					cout<<"---------Enqueued is sucessfully----------"<<endl;
					break;
					
				case 2:
					q.dequeue();
					break;
					
				case 3:
					q.peek();
					break;
						
				case 4:
					q.display();
					break;
					
				case 5:
					if (q.isfull()){
					 	cout << "Yes, Queue is full." << endl;
					 } else{
					 	cout << "No, Queue is not full." << endl;
					 }
					break;
				case 6:
					if (q.isEmpty()) {
						cout << "Yes, Queue is empty." << endl;
					} else {
						cout << "No, Queue is not empty." << endl;
					}	
				default:
				   cout<<"Invalid choice!"<<endl;		
			}
		}
	
		return 0;
	}
