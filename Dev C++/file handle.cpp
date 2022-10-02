#include<stdio.h>
#include<string.h>
int main()
{
	FILE * filePointer;
	char datatobewritten[50]="Sample of File Handling.";
	filePointer=fopen("file_handle.c","w");
	if(filePointer==NULL)
	{
		printf("file_handle.c file failed to open.");
	}
	else
	{
		printf("The file is now opened.\n");
		if(strlen(datatobewritten)>0)
		{
			fputs(datatobewritten,filePointer);
			fputs("\n",filePointer);
		}
		fclose(filePointer);
		printf("Data succesfully written in file file_handle.c\n");
		printf("The file is now closed.");
	}
	return 0;
}
