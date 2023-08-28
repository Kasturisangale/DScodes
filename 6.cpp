//SELECTION SORT (ITERATIVE)

#include <iostream>
using namespace std;

int arr[10],n;

int inputArray();
void print(int a[], int n);
void selection_sort(int arr[],int n);

int inputArray(){
    cout << "Enter numbers for array: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}
void print(int arr[], int n){   
    for(int i = 0; i < n; i++){    
       cout<<arr[i]<<" ";     
    }        
} 
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        // Find the index of the minimum element in the remaining unsorted part
        for (int j = i + 1; j < n; ++j){
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the minimum element with the current element
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        // Print the current pass and array
        cout << "Pass " << i + 1 << ": ";
        print(arr,n);
        cout << endl;
    }
}
int main() {
    cout << "Enter the number of elements: ";
    cin >> n;
    inputArray();
    cout<<"SELECTION SORT"<<endl;
    cout<<"Before sorting array elements are - \n";
    print(arr,n);
    putchar('\n');
    selection_sort(arr, n);  
    cout<<"\nAfter sorting array elements are - \n";    
    print(arr, n); 
    return 0;
}

