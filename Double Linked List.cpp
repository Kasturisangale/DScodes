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
	int x,k,count=0,flag=0;
	struct node* ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter the Element to be inserted: ");
	scanf("%d",&x);
	printf("Enter the index at which Element is to be inserted (starting with Index 0): ");
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
		flag=1;
	}
	else{
		while(temp!=NULL){
			if (count==k-1){
				z=temp->next;
			    temp->next=ptr;
			    ptr->next=z;
			    ptr->prev=temp;
			    ptr->next->prev=ptr;
				flag=1;
			    break;
	                }
	                else{
	        	temp=temp->next;
	        	count+=1;
			}
	        }
	}
	if(flag==1){
		printf("Inserted Successfully\n");
	}
	else{
		printf("Invalid Index\n");
	}
	print(head);
}

//for deleting a node off the linked list
void deletee(struct node* head){
	int k,count=0,flag=0;
	struct node* temp=head;
	struct node* z;
	printf("Enter the index which you want to delete (starting with Index 0): ");
	scanf("%d",&k);
	if(k==0){
		head->next->prev=NULL;
		head=head->next;
		flag=1;
	}
	else{
		while(temp->next->next!=NULL){
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
                if(flag!=1){
                   if(count==k-1){
                      temp->next=NULL;
                      flag=1;
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
		printf("Element not Found");
	}
}

//To Reverse the LL
void Reverse(struct node* head){
    int arr[50],i,count=0;
	struct node* temp=head;
    while(temp!=NULL){
		arr[count]=temp->data;
		temp=temp->next;
		count+=1;
    }
    for (i=0;i<count;i++){
		printf("%d ",arr[count-1-i]);
    }
}

void Sort(struct node* head){
	int j,i=0,count=0,temp;
	struct node* tempp=head;
	int arr[50];
	while(tempp!=NULL){
		arr[i]=tempp->data;
		count+=1;
		i+=1;
		tempp=tempp->next;
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
		tempp=tempp->next;
	}
}

//Driver Program
int main(){
	int ch;
	struct node* head=(struct node*)malloc(sizeof(struct node));
	create(head);
	printf("You have successfully created a Linked List");
	printf("\n1.Print the LL\n2.Insertion\n3.Deletion\n4.Searching an Element\n5.Reverse the LL\n6.Sort the LL\n");
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
                case 5:
                        Reverse(head);
                        break;
                case 6:
                        Sort(head);
		        print(head);
                        break;
		default:
			printf("Invalid Choice Entered");
       }  
}
