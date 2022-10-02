#include<stdio.h>
void change(int num)
{
	printf("\nThe value before function %d",num);
	num=num+100;
	printf("\n The value after function %d ",num);
}
main()
{
	int x=100;
	printf("\nThe value of x before function call %d",x);
	change(x);
	printf("\n The value of x after function call %d",x);
	return 0;
}
