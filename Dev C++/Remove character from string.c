#include <stdio.h>
#include <string.h>
 
int main()
{
  	char str[100], ch;
  	int i, len, j;
 
  	printf("Enter String: ");
  	gets(str);
  	
  	printf("\nEnter character which need to remove: ");
  	scanf("%c", &ch);
  	
	len = strlen(str);
	   	
  	for(i = 0; i < len; i++)
	{
		if(str[i] == ch)
		{
			for(j = i; j < len; j++)
			{
				str[j] = str[j + 1];
			}
			len--;
			i--;	
		} 
	}	
	printf("\nNew String: %s ",str);
	
  	return 0;
}
