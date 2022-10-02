#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head=NULL;
struct node *last=NULL;
struct node *current=NULL;

void insert (int data)
{
	struct node *link=(struct node*)malloc(sizeof(struct node));
	link->data= data;
	link->prev= NULL;
	link->next=NULL;
	if (head==NULL)
	{
		head=link;
		return;
	}
	current =head;
	while (current->next!=NULL)
		current =current->next;
		current->next=link;
		last=link;
		link->prev=current;
}
void printlist()
{
	struct node *ptr=head;
	printf("n[head] <=>");
	while(ptr->next != NULL)
{
	printf(" %d <=>",ptr->data);
	ptr=ptr->next;
}

	printf(" %d <=> ",ptr->data);
	printf("[head]n");

}
int main()
{
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	insert(60);
	printlist();
	return 0;
}

