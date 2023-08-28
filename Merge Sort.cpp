//MERGE SORT 

#include<iostream>
using namespace std;

int arr[10], n;
int inputArray();
void print(int arr[], int n);
void merge(int arr[], int p, int q, int r);
void mergeSort(int arr[], int l, int r);

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
// Merge two subarrays L and M into arr
void merge(int arr[], int l, int m, int r) {
    //size of left and right sub arrays
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i=0, j=0, k=l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) { //extra element in left array
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) { //extra element in right array
        arr[k] = R[j];
        j++;
        k++;
    }
    cout<<"Pass: ";
    print(arr,n); 
    putchar('\n');
}
// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;
    // Sort first and second subarrays
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}
int main(){
    cout << "Enter the number of elements: ";
    cin >> n;
    inputArray();
    cout<<"MERGE SORT"<<endl;
    cout<<"Before sorting array elements are - \n";
    print(arr,n);
    putchar('\n');
    mergeSort(arr,0,n-1); 
    cout<<"\nAfter sorting array elements are - \n";    
    print(arr, n); 
    return 0;
}




