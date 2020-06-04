	   //---------------Pyramid Operations----------------//

#include<conio.h>
#include<stdio.h>
#include<string.h>
#define tc textcolor
#define NODE struct pyramid

NODE
{
	NODE *left,*right,*down,*up;
	int value;
};
NODE *root=NULL,*temp,*temp1,*temp2;

//----------------user interface----------------//
void ui();
//----------------insertion of elements--------------//
void insertion();
//----------------traversion---------------//
void traversion();
//----------traversion-------------//
void traversion_menu();
//----------------searching----------------//
void searching();
//----------------deletion------------------//
void deletion();
//-----------------balancing the pyramid------------------//
char balance_pyramid(int del);
//----------------visualisation----------------//
void visualisation();
//----------------border-----------------//
void lines();
//---------------to create node downside---------------//
void down();
//---------------to create node upper side------------------//
void up();
//---------------to create node on left side-----------------//
void left();
//----------------to create node on right side--------------------//
void right();
//----------------to connect nodes automatically---------------------//
void down_to_right();
void right_to_upper();
void upper_to_left();
void left_to_down();
//----------------functions to connect nodes-------------------//


char status='l',c;
int x,y,i,j,insertion_counter=0;


void main()
{
	ui();
}

void lines()
{
	x=1,y=80;
	textcolor(14);
	xy:
	for(j=0;j<81;j++)
	{
		gotoxy(j,x);
		cprintf("*");
	}
	for(j=1;j<24;j++)
	{
		gotoxy(y,j);
		cprintf("*");
	}
	if(x!=24&&y!=1)
	{
		x=24,y=1;
		goto xy;
	}
}

void ui()
{
	again:
	clrscr();
	lines();
	gotoxy(30,5);
	tc(4);
	cprintf("P");
	tc(15);
	cprintf("YRAMID ");
	tc(4);
	cprintf("D");
	tc(15);
	cprintf("ATA ");
	tc(4);
	cprintf("S");
	tc(15);
	cprintf("TRUCTURE");
	gotoxy(20,10);
	tc(2);
	cprintf("I");
	tc(15);
	cprintf("NSERTION");

	gotoxy(55,10);
	tc(2);
	cprintf("T");
	tc(15);
	cprintf("RAVERSION");

	gotoxy(28,15);
	tc(2);
	cprintf("D");
	tc(15);
	cprintf("ELETION");

	gotoxy(48,15);
	tc(2);
	cprintf("V");
	tc(15);
	cprintf("ISUALISATION");

	gotoxy(37,19);
	tc(2);
	cprintf("S");
	tc(15);
	cprintf("EARCHING");
	gotoxy(41,20);
	cprintf("&");
	tc(2);
	gotoxy(36,21);
	cprintf("P");
	tc(15);
	cprintf("ATH FINDING");

	gotoxy(5,23);
	tc(4);
	cprintf("E");
	tc(15);
	cprintf("XIT");
	c=getch();
	if(c=='i'||c=='I')
	{
		insertion();
	}
	else if(c=='t'||c=='T')
	{
		traversion_menu();
	}
	else if(c=='d'||c=='D')
	{
		deletion();
	}
	else if(c=='v'||c=='V')
	{
		visualisation();
	}
	else if(c=='s'||c=='S'||c=='P'||c=='p')
	{
		searching();
	}
	else if(c=='e'||c=='E')
	{
		exit(0);
	}
	goto again;
}


void insertion()
{
	clrscr();
	lines();
	gotoxy(10,3);
	printf("--------------------");
	tc(3);
	cprintf("INSERTION IN PYRAMID");
	printf("------------------");
	if(root==NULL)
	{
		root=(NODE*)malloc(sizeof(NODE));
		gotoxy(10,10);
		tc(4);
		cprintf("Enter data = ");
		scanf("%d",&root->value);
		root->down=root->left=root->right=root->up=NULL,status='l';
		gotoxy(10,18);
		tc(2);
		cprintf("Data Inserted Successfully");
		getch();
		return;
	}
	else
	{
		insertion_counter++;
		temp=(NODE *)malloc(sizeof(NODE));
		gotoxy(10,10);
		tc(4);
		cprintf("Enter data = ");
		scanf("%d",&temp->value);
		temp->down=temp->left=temp->right=temp->up=NULL;
		gotoxy(10,18);
		tc(2);
		cprintf("Data Inserted Successfully");
		(status=='l')? down() : (status=='d')? (right(),down_to_right()) : (status=='r')? (up(),right_to_upper()) : (status=='u')? (left(),upper_to_left(),left_to_down()) : down();
		getch();
	}

}


void down()
{
	temp1=root;
	while(temp1->down!=NULL)
		temp1=temp1->down;
	temp1->down=temp;
	temp->up=temp1;
	status='d';
}

void right()
{
	temp1=root;
	while(temp1->right!=NULL)
		temp1=temp1->right;
	temp1->right=temp;
	temp->left=temp1;
	status='r';
}

void up()
{
	temp1=root;
	while(temp1->up!=NULL)
		temp1=temp1->up;
	temp1->up=temp;
	temp->down=temp1;
	status='u';
}

void left()
{
	temp1=root;
	while(temp1->left!=NULL)
		temp1=temp1->left;
	temp1->left=temp;
	temp->right=temp1;
	status='l';
}


//---------------to connect down to right--------------//
void down_to_right()
{
	temp=root;
	while(temp->down!=NULL)
		temp=temp->down;
	temp1=root;
	while(temp1->right!=NULL)
		temp1=temp1->right;
	temp->right=temp1;
	temp1->down=temp;
}

//----------------to connect right to upper----------------//
void right_to_upper()
{
	temp=root;
	while(temp->right!=NULL)
		temp=temp->right;
	temp1=root;
	while(temp1->up!=NULL)
		temp1=temp1->up;
	temp->up=temp1;
	temp1->right=temp;
}

//----------------to connect upper to left----------------//
void upper_to_left()
{
	temp=root;
	while(temp->up!=NULL)
		temp=temp->up;
	temp1=root;
	while(temp1->left!=NULL)
		temp1=temp1->left;
	temp->left=temp1;
	temp1->up=temp;
}

//----------------to connect left to down----------------//
void left_to_down()
{
	temp=root;
	while(temp->left!=NULL)
		temp=temp->left;
	temp1=root;
	while(temp1->down!=NULL)
		temp1=temp1->down;
	temp->down=temp1;
	temp1->left=temp;
}

//-----------------visualisation of pyramid-----------------//
void visualisation()
{
	int layer=0;
	char signal='f';
	clrscr();
	lines();
	gotoxy(10,3);
	printf("--------------------");
	tc(3);
	cprintf("VISUALISATION IN PYRAMID");
	printf("------------------");
	if(root==NULL)
	{
		gotoxy(30,15);
		tc(6);
		cprintf("Pyramid is Empty");
		getch();
		return;
	}
	temp=root;
	x=40,y=13;
	tc(4);
	while(temp!=NULL)
	{
		gotoxy(x,y);
		cprintf("%d",temp->value);
		if(signal=='l')
		{
			(temp=temp->down->down,signal='d',layer++,x=40,y=13+(layer*2),tc(3));
		}
		else
			(signal=='f')? (temp=temp->down,signal='d',layer++,x=40,y=13+(layer*2),tc(3)) : (signal=='d')? (temp=temp->right,signal='r',x=40+(layer*5),y=13,tc(6)) : (signal=='r')? (temp=temp->up,signal='u',x=40,y=13-(layer*2),tc(15)) : (temp=temp->left,signal='l',x=40-(layer*5),y=13,tc(2));
	}
	getch();
}

//-----------------traversion menu-----------------//
void traversion_menu()
{
	clrscr();
	lines();
	gotoxy(10,3);
	printf("----------------");
	tc(3);
	cprintf("CIRCULAR TRAVERSION IN PYRAMID");
	printf("----------------");
	if(root==NULL)
	{
		gotoxy(30,15);
		tc(6);
		cprintf("Pyramid is Empty");
		getch();
		return;
	}
	gotoxy(10,10);
	tc(6);
	cprintf("1. One Line Traversion");
	gotoxy(10,12);
	cprintf("2. Circular Way Traversion");
	again:
	c=getch();
	if(c=='2'||c=='1')
	{
		traversion();
	}
	else
		goto again;
}

//-------------------searching and path finding------------------//
void searching()
{
	char search='f',signal='f',counter=0;
	int s;
	clrscr();
	lines();
	gotoxy(10,3);
	printf("-------------");
	tc(3);
	cprintf("SEARCHING & PATH FINDING IN PYRAMID");
	printf("-------------");
	if(root==NULL)
	{
		gotoxy(30,15);
		tc(6);
		cprintf("Pyramid is Empty");
		getch();
		return;
	}
	gotoxy(10,10);
	tc(4);
	cprintf("Enter Node Element = ");
	scanf("%d",&s);
	temp=root,x=26,y=15;
	gotoxy(10,15);
	tc(6);
	cprintf("Circular Path = ");
	tc(15);
	cprintf("Root ");
	tc(4);
	cprintf("-> ");
	while(temp!=NULL)
	{
		if(temp->value==s)
		{
			search='t';
			break;
		}
		if(signal=='l')
		{
			(temp=temp->down->down,signal='d',counter++);
		}
		else
			(signal=='f')? (temp=temp->down,signal='d',counter++) : (signal=='d')? (temp=temp->right,signal='r') : (signal=='r')? (temp=temp->up,signal='u') : (temp=temp->left,signal='l');
		tc(15);
		x+=8;
		if(x>71)
			x=10,y++,gotoxy(x,y);
		(signal=='l')? cprintf("Left ") : (signal=='d')? cprintf("Down ") : (signal=='r')? cprintf("Right ") : (signal=='u')? cprintf("Up ") : printf(" ");
		tc(4);
		cprintf("-> ");
	}
	if(search!='t')
	{
		clrscr();
			lines();
		gotoxy(10,3);
		printf("-------------");
		tc(3);
		cprintf("SEARCHING & PATH FINDING IN PYRAMID");
		printf("-------------");
		gotoxy(10,15);
		tc(14);
		cprintf("Invalid Node Element");
	}
	else
	{
		tc(2);
		cprintf("\b\b\b\b ->");
		tc(3);
		cprintf(" Destination");
		gotoxy(10,20);
		tc(6);
		x=24,y=20;
		cprintf("Direct Path = ");
		tc(15);
		cprintf("Root ");
		tc(4);
		cprintf("-> ");
		while(counter>0)
		{
			x+=8,tc(15);
			if(x>71)
				x=10,y++,gotoxy(x,y);
			(signal=='l')? cprintf("Left ") : (signal=='d')? cprintf("Down ") : (signal=='r')? cprintf("Right ") : (signal=='u')? cprintf("Up ") : cprintf(" ");
			counter--,tc(4);
			cprintf("-> ");
		}
		tc(2);
		cprintf("\b\b\b\b ->");
		tc(3);
		cprintf(" Destination");
	}
	getch();
}

//----------------deletion----------------//
void deletion()
{
	char delete_signal;
	int del;
	clrscr();
	lines();
	gotoxy(15,3);
	printf("----------------");
	tc(3);
	cprintf("DELETION IN PYRAMID");
	printf("----------------");
	if(root==NULL)
	{
		gotoxy(30,15);
		tc(6);
		cprintf("Pyramid is Empty");
		getch();
		return;
	}
	gotoxy(10,10);
	tc(4);
	cprintf("Enter Node Element = ");
	scanf("%d",&del);
	delete_signal=balance_pyramid(del);
	gotoxy(20,15);
	tc(2+BLINK);
	(delete_signal=='t')? (cprintf("Node Element Deleted Successfully")) : (cprintf("Invalid Node Element"));
	getch();
}

//-------------circular trav---------------//
void traversion()
{
	int layer=0;
	char signal='f';
	clrscr();
	lines();
	gotoxy(10,3);
	printf("----------------");
	tc(3);
	(c=='1')? cprintf("ONE LINE TRAVERSION IN PYRAMID") : cprintf("CIRCULAR WAY TRAVERSION IN PYRAMID");
	printf("----------------");
	gotoxy(10,22);
	tc(15);
	cprintf("Press Any Key");
	temp=root;
	x=40,y=13,i=10,j=13;
	tc(4);
	if(c=='1')
		gotoxy(i,j);
	while(temp!=NULL)
	{
		if(c=='1')
		{
			if(i>75)
			{
				i=10,j++;
				gotoxy(i,j);
			}
			cprintf("%d   ",temp->value);
			i+=7;
		}
		else
		{
			gotoxy(x,y);
			cprintf("%d",temp->value);
		}
		if(signal=='l')
		{
			(temp=temp->down->down,signal='d',layer++,x=40,y=13+(layer*2),tc(3));
		}
		else
			(signal=='f')? (temp=temp->down,signal='d',layer++,x=40,y=13+(layer*2),tc(3)) : (signal=='d')? (temp=temp->right,signal='r',x=40+(layer*5),y=13,tc(6)) : (signal=='r')? (temp=temp->up,signal='u',x=40,y=13-(layer*2),tc(15)) : (temp=temp->left,signal='l',x=40-(layer*5),y=13,tc(2));
		getch();
	}
	gotoxy(10,22);
	tc(2+BLINK);
	cprintf("completed      ");
	getch();
}

//--------------balancing the pyramid----------------//
char balance_pyramid(int del)
{
	char signal='f',signal_1='f';
	if(root->value==del&&root->left==NULL&&root->right==NULL&&root->up==NULL&&root->down==NULL)
	{
		free(root);
		root=NULL;
		return('t');
	}
	temp1=temp=root,c='f';
	while(temp1!=NULL)
	{
		if(signal_1=='l')
		{
			(temp1=temp1->down->down,signal_1='d');
		}
		else
			(signal_1=='f')? (temp1=temp1->down,signal_1='d') : (signal_1=='d')? (temp1=temp1->right,signal_1='r') : (signal_1=='r')? (temp1=temp1->up,signal_1='u') : (temp1=temp1->left,signal_1='l');
		if(temp1==NULL)
			break;
		if(temp->value==del || c=='t')
		{
			c='t';
			temp->value=temp1->value;
		}
		if(signal=='l')
		{
			(temp=temp->down->down,signal='d');
		}
		else
			(signal=='f')? (temp=temp->down,signal='d') : (signal=='d')? (temp=temp->right,signal='r') : (signal=='r')? (temp=temp->up,signal='u') : (temp=temp->left,signal='l');
	}
	if(temp->value==del)
		c='t';
	if(signal=='l'&&c=='t')
	{
		temp->up->left=NULL;
		temp->down->left=NULL;
		temp->right->left=NULL;
		status='u';
	}
	else if(signal=='r'&&c=='t')
	{
		temp->up->right=NULL;
		temp->down->right=NULL;
		temp->left->right=NULL;
		status='d';
	}
	else if(signal=='u'&&c=='t')
	{
		temp->down->up=NULL;
		temp->left->up=NULL;
		temp->right->up=NULL;
		status='r';
	}
	else if(signal=='d'&&c=='t')
	{
		temp->up->down=NULL;
		temp->left->down=NULL;
		temp->right->down=NULL;
		status='l';
	}
	free(temp);
	return(c);
}