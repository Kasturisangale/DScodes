//INSERTION SORT (ITERATIVE)

#include<iostream>
using namespace std;

int a[10],n;

int inputArray();
void print(int a[], int n);
int insertionsort(int a[],int n);

int inputArray(){
    cout << "Enter numbers for array: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}
void print(int a[], int n){   
    for(int i = 0; i < n; i++){    
       cout<<a[i]<<" ";     
    }        
}  
int insertionsort(int a[],int n){
    int i,j,key;
    for(i=1;i<n;i++){ 
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        cout<<"Pass:"<<i<<endl;
        print(a,n);
        putchar('\n');
    }
}
int main(){
    cout << "Enter the number of elements: ";
    cin >> n;
    inputArray(); 
    cout<<"INSERTION SORT"<<endl;
    cout<<"Before sorting array elements are - \n";
    print(a,n);
    putchar('\n');
    insertionsort(a, n);  
    cout<<"\nAfter sorting array elements are - \n";    
    print(a, n); 
    return 0;
}
