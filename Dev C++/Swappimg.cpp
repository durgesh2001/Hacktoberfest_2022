#include<stdio.h>
void swap(int *a,int *b)
{
	printf("\nBefore swap a= %d b= %d ",*a,*b);
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	printf("\nAfter swap a= %d b= %d \n",*a,*b);
}
main()
{
	int a=10;
	int b=20;
	printf("Before swapping the values of  a= %d & b= %d ",a,b);
	swap(&a,&b);
	printf("After swapping the values of  a= %d & b= %d ",a,b);
	return 0;
}
