#include<stdio.h>
main()
{
	int arr[10]= {1,2,3,4,5,6,7,8,9,10};
	int *ptr;
	ptr=arr;
	for (int i=0;i<10;i++)
	{
		printf("Value of *ptr= %d\n",*ptr);
		printf("Value of ptr= %d\n",ptr);
		ptr++;
	}
	return 0;
}
