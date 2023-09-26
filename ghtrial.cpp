//DOUBLE LINKED LIST

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

//create the structure node
struct node{
	int data;
	struct node* next;
	struct node* prev;
};

//create the initial linked list
void create(struct node* head){
	int n,x,i;
	printf("Enter the number of Elements: ");
	scanf("%d",&n);
	printf("Enter an Element: ");
	scanf("%d",&x);
	head->data=x;
	head->next=NULL;
	head->prev=NULL;
	struct node* temp=head;
	for (i=1;i<n;i++){
		struct node* ptr=(struct node*)malloc(sizeof(struct node));
		printf("Enter an Element: ");
		scanf("%d",&x);
		ptr->data=x;
		ptr->next=NULL;
		ptr->prev=temp;
		temp->next=ptr;
		temp=temp->next;
	}
}

//for displaying the linked list
void print(struct node* head){
	struct node* temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

//for inserting an element in the linked list
void insert(struct node* head){
	int x,k,count=0;
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter the Element to be inserted: ");
	scanf("%d",&x);
	printf("Enter the index at which Element is to be inserted: ");
	scanf("%d",&k);
	ptr->data=x;
	ptr->prev=NULL;
	ptr->next=NULL;
	struct node* temp=head;
	struct node* z;
	if (k==0){
		ptr->next=head;
		head->prev=ptr;
		head=ptr;
	}
	else{
		while(temp!=NULL){
			if (count==k-1){
				z=temp->next;
			    temp->next=ptr;
			    ptr->next=z;
			    ptr->prev=temp;
			    ptr->next->prev=ptr;
			    break;
	        }
	        else{
	        	temp=temp->next;
	        	count+=1;
			}
	    }
	}
	print(head);
}

//for deleting a node off the linked list
void deletee(struct node* head){
	int k,count=0,flag=0;
	struct node* temp=head;
	struct node* z;
	printf("Enter the index which you want to delete: ");
	scanf("%d",&k);
	if(k==0){
		head->next->prev=NULL;
		head=head->next;
		flag=1;
	}
	else{
		while(temp!=NULL){
			if(count==k-1){
				z=temp->next->next;
				temp->next->next->prev=temp;
				temp->next=z;
				flag=1;
				break;
			}
			else{
				temp=temp->next;
				count+=1;
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

//for searching if an element is a part of linked list
void Search(struct node* head){
	int k,flag=0;
	printf("Enter the element to be searched: ");
	scanf("%d",&k);
	struct node* temp=head;
	while(temp!=NULL){
		if (k==temp->data){
			flag=1;
			break;
		}
		else{
			temp=temp->next;
		}
	}
	if(flag==1){
		printf("Element Found");
	}
	else{
		printf("Eleement not Found");
	}
}

//Driver Program
int main(){
	int ch;
	struct node* head=(struct node*)malloc(sizeof(struct node));
	create(head);
	printf("You have successfully created a Linked List");
	printf("\n1.Print the LL\n2.Insertion\n3.Deletion\n4.Searching an Element\n");
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
			Search(head);
			break;
		default:
			printf("Invalid Choice Entered");
    }  
}
