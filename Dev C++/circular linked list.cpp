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
	link->next=NULL;
	if (head==NULL)
	{
		head=link;
		head->next=head;
		return;
	}
	current =head;
	while (current->next!=head)
		current =current->next;
		current->next=link;
		link->next=head;
}
void printlist()
{
	struct node *ptr=head;
	printf("n[head] =>");
	while(ptr->next != head)
{
	printf(" %d =>",ptr->data);
	ptr=ptr->next;
}

	printf(" %d => ",ptr->data);
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

