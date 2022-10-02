#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
//struct node * current=NULL;
void printlist()
{
	struct node *ptr=head;
	printf(" n[head=>]");
	while (ptr!=NULL)
	{
	printf(" %d=>",ptr->data);
	ptr=ptr->next;
	}
	printf(" [null]n");
}
void insert (int data)
{
	struct node *link=(struct node*)malloc(sizeof(struct node));
	link->data=data;
	link->next=head;
	head=link;
}
int main()
{
	insert (600);
	insert (500); 
	insert (400);
	insert (300);
	insert (200);
	insert (100);
	printlist();
	return 0;
}


