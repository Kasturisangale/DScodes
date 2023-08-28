//BINARY ITERATIVE

#include<stdio.h>
#include<math.h>
#include<conio.h>
int check(int a[],int key);
int main()
{
	int a[5]={3,5,11,12,17},key=12,x;
	x=check(a,key);
	if (x==0)
	{
		printf("Key not found");
	}
	else
	{
		printf("Key found, %d",x);
	}
	return 0;
}

int check(int a[],int key)
{
	int l=1,h=5,mid;
	
	while(h>l)
	{
	
		mid=(h+l)/2;
		if (a[mid]>key)
		{
			h=mid-1;
		}
		else if (a[mid]<key)
		{
			l=mid+1;
		}
		else
		{
			return mid+1;
		}
	}
	return 0;
}
