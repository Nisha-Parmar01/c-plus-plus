#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    int count;
    LinkedList() {
        head = NULL;
        count = 0;
    }

    void create(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;    
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        count++;
    }

    void display() {
        if (head == NULL) {
            cout << "Linked List is empty."<<endl;
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void update(int position, int newData) {
        if (position < 0 || position >= count) {
            cout << "Invalid position."<<endl;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }
        temp->data = newData;
    }

    void deleteNode(int position) {
        if (position < 0 || position >= count || head == NULL) {
            cout << "Invalid position."<<endl;
            return;
        }
        Node* temp;
        if (position == 0) {
            temp = head;
            head = head->next;
        } else {
            Node* prev = head;
            for (int i = 0; i < position - 1; i++) {
                prev = prev->next;
            }
            temp = prev->next;
            prev->next = temp->next;
        }
        delete temp;
        count--;
    }
};
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
void merge(vector<int>& a, int low, int mid, int high) {
    vector<int> tmp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high) {
        if (a[left] <= a[right]) {
            tmp.push_back(a[left]);
            left++;
        } else {
            tmp.push_back(a[right]);
            right++;
        }
    }
    while (left <= mid) {
        tmp.push_back(a[left]);
        left++;
    }
    while (right <= high) {
        tmp.push_back(a[right]);
        right++;
    }
    for (int i = 0; i < tmp.size(); i++) {
        a[low + i] = tmp[i];
    }
}

void merge_sort(vector<int>& a, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);
    merge(a, low, mid, high);
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    LinkedList list;
    vector<int> sortedArray;
    int sortedArr[100], sortedSize = 0;
    int choice;

    while (true) {
        cout << "---------------- Menu ----------------"<<endl;
        cout << "1. Insert into Linked List\n";
        cout << "2. Display Linked List\n";
        cout << "3. Update Linked List\n";
        cout << "4. Delete from Linked List\n";
        cout << "5. Binary Search\n";
        cout << "6. Merge Sort\n";
        cout << "7. Quick Sort\n";
        cout << "8. Display Sorted Array\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int data;
            cout << "Enter value to insert: ";
            cin >> data;
            list.create(data);
            cout<<"----------------create sucessfully----------------"<<endl;
            break;
        }
        case 2:
            list.display();
            break;

        case 3: {
            int position, newData;
            cout << "Enter position to update: ";
            cin >> position;
            cout << "Enter new value: ";
            cin >> newData;
            list.update(position, newData);
            cout<<"----------------update sucessfully----------------"<<endl;
            break;
        }

        case 4: {
            int position;
            cout << "Enter position to delete: ";
            cin >> position;
            list.deleteNode(position);
        	cout<<"----------------delete sucessfully----------------"<<endl;
            break;
        }

        case 5: {
            int arr[100], n, key;
            cout << "Enter array size: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "a[" << i << "] = ";
                cin >> arr[i];
            }
            cout << "Enter key to search: ";
            cin >> key;
            int index = binarySearch(arr, n, key);
            if (index != -1){
            	 cout << "Element found at index: " << index << endl;
			}else{
				cout << "Element not found." << endl;

			}
            break;
        }

        case 6: {
            int n, element;
            sortedArray.clear();
            cout << "Enter array size: ";
            cin >> n;
            sortedSize = n;
            for (int i = 0; i < n; i++) {
                cout << "a[" << i << "] = ";
                cin >> element;
                sortedArray.push_back(element);
            }
            merge_sort(sortedArray, 0, n - 1);
            cout << "Merge Sorted array: ";
            for (int i = 0; i < n; i++){
            		cout << sortedArray[i] << " ";	
			}
            cout << endl;
            break;
        }

        case 7: {
            cout << "Enter array size: ";
            cin >> sortedSize;
            for (int i = 0; i < sortedSize; i++) {
                cout << "a[" << i << "] = ";
                cin >> sortedArr[i];
            }
            quickSort(sortedArr, 0, sortedSize - 1);
            cout << "Quick Sorted array: ";
            for (int i = 0; i < sortedSize; i++){
            		cout << sortedArr[i] << " ";	
			}
            cout << endl;
            break;
        }
 		case 8: {
		    cout << "------------------ Display Section ------------------" << endl;
		    cout << "Current Linked List: ";
		    if (list.head ==NULL) {
		        cout << "No linked list data found." << endl;
		    } else {
		        list.display();
		    }
		    cout << "Last Merge Sorted array: ";
		    if (sortedArray.empty()) {
		        cout << "No merge sort data available." << endl;
		    } else {
		        for (int i = 0; i < sortedArray.size(); i++) {
		            cout << sortedArray[i] << " ";
		        }
		        cout << endl;
		    }
		    cout << "Last Quick Sorted array: ";
		    if (sortedSize == 0) {
		        cout << "No quick sort data available." << endl;
		    } else {
		        for (int i = 0; i < sortedSize; i++) {
		            cout << sortedArr[i] << " ";
		        }
		        cout << endl;
		    }
		    cout << "------------------ Display Successful ------------------" << endl;
		    break;
		}

        case 9:
            cout << "------------ Thank you! ------------"<<endl;
            return 0;

        default:
            cout << "Invalid choice!endl"<<endl;
        }
    }
    return 0;
}
