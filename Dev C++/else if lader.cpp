#include<stdio.h>
#include<conio.h>
main()
{ int num=0;
printf("Enter an number= ");
scanf("%d",&num);
if(num==42)
{
printf("The inputted number is equal to 42");
}
else if(num==10){
printf("The inputted number is equal to 10");}

else if(num==50){
printf("The inputted number is equal to 50");
}
else
printf("The inputted number is not equal to 10, 42, 50");
return(0);
}
