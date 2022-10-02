#include<stdio.h>
#include<conio.h>
main()
{ int num;
printf("Enter an number= ");
scanf("%d",&num);
if(num%2==0)
{
printf("The Number %d is even",num);
}
else
printf("the number %d is not even",num);
return(0);
}
