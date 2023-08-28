//LINEAR ITERATIVE

#include<stdio.h>
#include<math.h>
#include<conio.h>
int linearSearch(int a[],int key);
int main()
{
	int a[5]={3,5,11,17,12},x,key=11;
	x=linearSearch(a,key);
	if (x==-1)
	{
		printf("Number not found");
	}
	else
	{
		printf("Number found at %d",x);
	}
	return 0;
}




int linearSearch(int a[],int key)
{
	int i;
	for(i=0;i<5;i++)
	{
		if (a[i]==key)
		{
			return i+1;
		}
	}
	return -1;
}
