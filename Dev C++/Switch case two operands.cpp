#include<stdio.h>
main()
{
	char opr;
	int num_1, num_2;
	printf("\nEnter the operator ( +,-,*,/)= ");
	scanf("%c",&opr);
	printf("Enter two operands= ");
	scanf("%d %d",&num_1,&num_2);
	switch(opr)
	{
		case '+':
			printf("%d + %d = %d", num_1,num_2,num_1+num_2);
			break;
		case '-':
			printf("%d - %d = %d", num_1,num_2,num_1-num_2);
			break;
		case '*':
			printf("%d * %d = %d", num_1,num_2,num_1*num_2);
			break;
		case '/':
			printf("%d / %d = %d", num_1,num_2,num_1/num_2);
			break;
		default :
			printf("Error! The operator is not Matched.");
	}
	return 0;
}
