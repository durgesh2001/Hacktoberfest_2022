#include<stdio.h>
#include<conio.h>
main()
{ int v1, v2;
printf("\nEnter first variable= ");
scanf("%d",&v1);
printf("\nEnter second variable= ");
scanf("%d",&v2);
if(v1!=v2)
{
	printf("the two variables are not equal");
	if(v1>v2){
		printf("\nFirst variable is Greater than second variable");
	}
	else
		printf("\nFirst variable is Smaller than second variable");
}
else
printf("The two variables are Equal");
return(0);
}
