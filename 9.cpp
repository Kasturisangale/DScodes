//QUICK SORT

#include<iostream>
using namespace std;

int arr[10],n;

int inputArray();
void print(int a[], int n);
void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int inputArray(){
    cout << "Enter numbers for array: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}
void print(int a[], int n){     
    for(int i = 0; i < n; i++){    
       cout<<arr[i]<<" ";     
    }        
} 
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  cout<<"Pivot element: "<<pivot<<endl;
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main(){
    cout << "Enter the number of elements: ";
    cin >> n;
    inputArray();
    cout<<"QUICK SORT"<<endl;
    cout<<"Before sorting array elements are - \n";
    print(arr,n);
    putchar('\n');
    quickSort(arr,0,n-1);  
    cout<<"\nAfter sorting array elements are - \n";    
    print(arr, n); 
    return 0;
}


