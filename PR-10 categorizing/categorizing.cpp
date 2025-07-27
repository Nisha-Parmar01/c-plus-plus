//categorizing
#include <iostream>
#include <vector>
using namespace std;
vector<int> inputArray(int &n) {
    cout << "Enter Array size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
    }
    return arr;
}
void selection_sort(vector<int>& arr ,int n) {
 for (int i = 0; i<n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
		if (arr[j] < arr[minIndex]) {
		minIndex = j;
		}
		}
		if (minIndex != i) {
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
		}
	}
    cout << "Sorted array using Selection Sort: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void merge(vector<int> &a,int low, int mid, int high){
		vector<int> tmp;
		int left = low;
		int right = mid + 1;
		while(left<=mid && right <= high){
			if(a[left] <= a[right]){
			tmp.push_back(a[left]);
			left++;
			}else{
			tmp.push_back(a[right]);
			right++;
			}
		}
		while(left<=mid){
			tmp.push_back(a[left]);
			left++;
		}
		while(right<=high){
			tmp.push_back(a[right]);
			right++;
		}
		for(int i=low;i<=high;i++){
		a[i] = tmp[i-low];
	}
}
void merge_sort(vector<int> &a,int low,int high){
		if(low>=high){
		return;
		}
		int mid = (low + high) / 2;
		merge_sort(a, low, mid); 
		merge_sort(a, mid+1, high);
		merge(a,low,mid,high);
	}
int binary_search(vector<int>& arr, int n,int target) {
	    int low = 0, high =n-1;
	    while(low <= high) {
	        int mid = (low + high) / 2;
	        if(arr[mid] == target){
	        	return mid;
			} else if(arr[mid] < target){
				low = mid + 1;
			}else{
				 high = mid - 1;
			}  
	    }
	    return -1;
}		
int linear_search(vector<int> &arr,int n, int target) {
	    for(int i = 0; i<n; i++){
	        if(arr[i] == target)
	            return i;
	    }
	    return -1;
}
int main(){
	int choice;
	while(1){
	cout<<"-----------Menu-----------"<<endl;
	cout<<"press 1 selection sort"<<endl;
	cout<<"press 2 merge sort"<<endl;
	cout<<"press 3 binary search"<<endl;
	cout<<"press 4 linear search"<<endl;
	cout<<"press 0 Exit"<<endl;
	cout<<"Enter the choice:";
	cin>>choice;
	if(choice==0){
		cout << "Thank you..."<<endl;
		break;
	}
	 int n, target;
    vector<int> arr;
	switch(choice){
		case 1:{	
				 arr = inputArray(n);
				selection_sort(arr,n);
			break;
		}
		case 2:{
				 arr = inputArray(n);
                merge_sort(arr, 0, n-1);
                cout << "Sorted array using Merge Sort: ";
                for (int i = 0; i < n; i++)
                    cout << arr[i] << " ";
                cout << endl;
                break;
			break;
		}
		case 3: {
			   arr = inputArray(n);
                merge_sort(arr, 0, n - 1); 
                cout << "Sorted array: ";
                for (int i = 0; i < n; i++) {
                	cout << arr[i] << " ";
				}
                cout << "\nEnter target to search: ";
                cin >> target;
                {
                    int index = binary_search(arr, n, target);
                    if(index != -1)
                        cout << "Element found at index: " << index << endl;
                    else
                        cout << "Element not found." << endl;
                }
                break;
		}
		case 4: {
				arr = inputArray(n);
                cout << "Enter target to search: ";
                cin >> target;
                {
                    int index = linear_search(arr, n, target);
                    if(index != -1)
                        cout << "Element found at index: " << index << endl;
                    else
                        cout << "Element not found." << endl;
                }
                break;
		}
		default:
			cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
			cout<<"     Invaild choice!"<<endl;	
			cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;			
	}
  }
}

