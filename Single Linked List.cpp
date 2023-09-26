//SINGLE LINKED LIST AND ITS OPERATIONS

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//create the structure node
struct node{
	int data;
	struct node* link;
};

//create the main linked list
void create(struct node* head){
	int n,x,i;
	printf("Enter the number of Elements: ");
	scanf("%d",&n);
	printf("Enter an Element: ");
	scanf("%d",&x);
	head->data=x;
	head->link=NULL;
	struct node* temp=head;
	for (i=1;i<n;i++){
		struct node* ptr=(struct node*)malloc(sizeof(struct node));
		printf("Enter an Element: ");
		scanf("%d",&x);
		ptr->data=x;
		ptr->link=NULL;
		temp->link=ptr;
		temp=temp->link;
	}
}

//for the displaying of elements 
void print(struct node* head){
	struct node* tempp=head;
	while(tempp!=NULL){
		printf("%d ",tempp->data);
		tempp=tempp->link;
	}
}

//for the insertion of an element
void insert(struct node* head){
	int i,x,count=0,flag=0,k;
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	struct node* tempp=head;
	struct node* z;
	printf("Enter the Element you want to add: ");
	scanf("%d",&x);
	ptr->data=x;
	ptr->link=NULL;
	printf("Enter the Index at which you want to Insert an Element(starting with 0): ");
	scanf("%d",&k);
	if (k==0){
		ptr->link=head;
		head=ptr;
		flag=1;
    }
    else{
    	
    	while(tempp!=NULL){
    		    if (count==(k-1)){
    		    	z=tempp->link;
    			    tempp->link=ptr;
    			    ptr->link=z;
    			    flag=1;
    			    break;
			    }
			    else{
			    	count+=1;
				    tempp=tempp->link;
			    }
        }
    }
    if (flag==1){
    	printf("Inserted Successfully!\n");
	}
	else{
		printf("Invalid Index\n");
	}
	print(head);
}

//for the deletion of an element
void deletee(struct node* head){
	int count=0,k, flag=0;
	struct node* tempp=head;
	printf("Enter the Index you want to delete: ");
	scanf("%d",&k);
	if (k==0){
		head=head->link;
		flag=1;
	}
	else{
		while(tempp!=NULL){
			if(count==(k-1)){
				tempp->link=tempp->link->link;
				flag=1;
				break;
			}
			else{
				tempp=tempp->link;
				count+=1;
			}
		}
	}
	if (flag==1){
		printf("Deleted Successfully!\n");
	}
	else{
		printf("Invalid Index\n");
	}
	print(head);                                                                                                              
}       
        
//for displaying the reverse of the linked list                                                  
void printReverse(struct node* head){
	int i,j=0;
	struct node* tempp=head;
	int arr[50];
	while(tempp!=NULL){
			arr[j]=tempp->data;
			tempp=tempp->link;
			j+=1;
	    }
	    for (i=0;i<j;i++){
	    	printf("%d ",arr[j-1-i]);
		}
}

//for searching if an element is a part of linked list
void Search(struct node* head){
	int e,flag=0;
	
	printf("Enter the element to be searched: ");
	scanf("%d",&e);
	struct node* tempp=head;
	while(tempp!=NULL){
		if(e==tempp->data){
			flag=1;
			break;
		}
		else{
			tempp=tempp->link;
		}
	}
	if (flag==1){
		printf("Element Found\n");
	}
	else{
		printf("Element not found\n");
	}
}

//for sorting the linked list
void Sort(struct node* head){
	int j,i=0,count=0,temp;
	struct node* tempp=head;
	int arr[50];
	while(tempp!=NULL){
		arr[i]=tempp->data;
		count+=1;
		i+=1;
		tempp=tempp->link;
	}
	for (i=0;i<count-1;i++){
		for (j=0;j<count-1;j++){
			if (arr[j]>arr[j+1]){
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
	tempp=head;
	for (i=0;i<count;i++){
		tempp->data=arr[i];
		tempp=tempp->link;
	}
}

//Driver Program
int main(){
	int ch;
	struct node* head=(struct node*)malloc(sizeof(struct node));
	create(head);
	printf("You have successfully created a Linked List(LL)");
	printf("\n1.Print the LL\n2.Insertion\n3.Deletion\n4.Print the Reverse LL\n5.Searching an Element\n6.Sort the LL\n");
	printf("Select one of the above operations: ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			print(head);
			break;
		case 2:
			insert(head);
			break;
		case 3:
			deletee(head);
			break;
		case 4:
			printReverse(head);
			break;
		case 5:
			Search(head);
			break;
		case 6:
			Sort(head);
			print(head); 
		        break;
	}
}
