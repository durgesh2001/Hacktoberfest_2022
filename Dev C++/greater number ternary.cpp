#include<stdio.h>
main()
{
	int n1,n2,max;
	printf("Enter the number= ");
	scanf("%d %d",&n1,&n2);
	max=(n1>n2)?n1:n2;
	printf("The greater number is %d ",max);
	return 0;
}
