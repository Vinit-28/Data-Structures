//----------------------Doubly Linked List Operations-----------------//

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define NODE struct node
//------------structure------------------//
NODE
{
	int num;
	NODE *prev,*next;
};

//------------------structure type pointers------------------//
NODE *p,*start=NULL,*temp;

//----------global variables-----------//
int count=0;
char c;

//------------List Functions------------//
void create_list();
void show_list();
void delete_list();

//--------------main function----------------//
void main()
{
	clrscr();
	printf("\n-----------------------Doubly Linked List Operations-------------------------\n\n");
	printf("1.Insertion\n2.Traversing\n3.Deletion\n4.Exit\n");
	c=getch();
	if(c=='1')
	{
		create_list();
	}
	else if(c=='2')
	{
		show_list();
	}
	else if(c=='3')
	{
		delete_list();
	}
	else if(c=='4')
	{
		exit(0);
	}
	main();
}

//--------------create list function-----------------//
void create_list()
{
	do
	{
		clrscr();
		count++;
		printf("\n-----------------------Insertion Operation------------------\n\n");
		p=(NODE *)malloc(sizeof(NODE));
		printf("Enter an element::");
		scanf("%d",&p->num);
		if(start==NULL)
		{
			start=p;
			p->prev=NULL;
			p->next=NULL;
		}
		else
		{
			temp=start;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=p;
			p->prev=temp;
			p->next=NULL;
		}
		printf("\n\n--------------Press 1 to enter more or 0 to menu--------------\n");
		c=getch();
	}while(c=='1');
	main();
}

//--------------show list function---------------//
void show_list()
{
	clrscr();
	if(count==0)
	{
		printf("\n\n\n\n-------------------Doubly Linked List is Empty------------------\n");
		getch();
		return;
	}
	count=0;
	temp=start;
	clrscr();
	printf("\n-----------------------Doubly Linked List Elements--------------------------\n\n");
	do
	{
		printf("%d node element::%d\tO.A = %u\tP.A. = %u\tN.A. = %u\n",count+1,temp->num,temp,temp->prev,temp->next);
		temp=temp->next;
		count++;
	}while(temp!=NULL);
	printf("\n\n---------------------Total Nodes::%d-----------------------\n",count);
	printf("\nO.A. = Own Address\tP.A. = Previous Address\tN.A. = Next Address\n");
	getch();
	main();
}


//---------------delete list function--------------//
void delete_list()
{
	int d,counter;
	clrscr();
	if(count==0)
	{
		printf("\n\n\n\n-------------------Doubly Linked List is Empty------------------\n");
		getch();
		return;
	}
	printf("-----------------------Deletion Operation------------------\n\n");
	printf("Enter element::");
	scanf("%d",&d);
	temp=start;
	counter=count;
	while(counter>0)
	{
		p=temp->next;
		counter--;
		if(d==temp->num)
		{
			temp->num=p->num;
			temp->next=p->next;
			p=p->next;
			p->prev=temp;
			d=0;
			goto out;
		}
		else
			temp=temp->next;
	}
	out:
	if(d==0)
		printf("\n\n-------------------Element Deleted---------------\n");
	else
		printf("\n\n-------------------Element not Found---------------\n");
	getch();
	main();
}
