//BUBBLE SORT (ITERATIVE)

#include<iostream>    
using namespace std; 

int a[10],n;

int inputArray(){
    cout << "Enter numbers for array: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}
void print(int a[], int n){ //function to print array elements     
    for(int i = 0; i < n; i++){    
       cout<<a[i]<<" ";     
    }        
}  
int bubble(int a[10],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-(i+1);j++){ //comparisons
            if(a[j]>a[j+1]){ //compare & swap
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        cout<<"Pass:==>"<<i+1<<endl;
        print(a,n); 
        putchar('\n');
    }
}
int main(){    
    cout << "Enter the number of elements: ";
    cin >> n;
    inputArray(); 
    cout<<"BUBBLE SORT"<<endl;
    cout<<"Before sorting array elements are - \n";
    print(a,n);
    putchar('\n');
    bubble(a, n);  
    cout<<"\nAfter sorting array elements are - \n";    
    print(a, n);  
return 0;  
}
