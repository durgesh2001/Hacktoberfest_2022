#include<stdio.h>
#include<string.h>
int inversionCount(int input1,int input2[])
{
	int inversionCount=0;
	for (int i=0;i<input1-1;i++)
	{
		for (int j=i+1;j<input1;j++)
		{
			if (input2[i]>input2[j]) {
				inversionCount++;
			}
		}
	}
	return inversionCount;
}
int main()
{
    int input2[] = { 3,2,1 };
    int input1 = sizeof(input2) / sizeof(input2[0]);
    printf(" Number of inversions are %d \n",inversionCount(input1, input2));
    return 0;
}
