#include<stdio.h>
main()
{
	int emp_id[2],i=0;
	emp_id[0]=1001;
	emp_id[1]=1010;
	emp_id[2]=1020;
	emp_id[6]=1030;
	emp_id[5]=1050;
	emp_id[6]=emp_id[5]+emp_id[1];
	for(i=0;i<7;i++)
	{
		printf("%d\n",emp_id[i]);
	}
	return 0;
}
