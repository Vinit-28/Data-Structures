	   //---------------Binary Tree Operations----------------//

#include<conio.h>
#include<stdio.h>
#include<string.h>
#define tc textcolor

struct tree
{
	struct tree *left,*right;
	int value;
};
struct tree *root=NULL,*temp,*temp1,*temp2;

void ui();
void insertion();
void traversion();
void show_tree_left_priority(struct tree *);
void show_tree_right_priority(struct tree *);
void show_tree_in_order(struct tree *);
void show_tree_post_order(struct tree *);
void BFS();
void bfs(struct tree *t);
void deletion();
void searching();
void tree_vision(struct tree *t, int xx, int yy);
void lines();

char c;
int x,y,a[50],level_counter=0,level=0,i,j;


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
	cprintf("B");
	tc(15);
	cprintf("INARY ");
	tc(4);
	cprintf("T");
	tc(15);
	cprintf("REE ");
	tc(4);
	cprintf("O");
	tc(15);
	cprintf("PERATIONS");
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
		traversion();
	}
	else if(c=='d'||c=='D')
	{
		deletion();
	}
	else if(c=='v'||c=='V')
	{
		clrscr();
		lines();
		gotoxy(10,3);
		tc(3);
		printf("----------------");
		cprintf("VISIUALISATION OF BINARY TREE");
		printf("----------------");
		if(root==NULL)
		{
			gotoxy(10,15);
			printf("--------------");
			tc(14);
			cprintf("Tree is Empty");
			printf("--------------");
		}
		else
			tree_vision(root,39,6);
		getch();
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

void tree_vision(struct tree *t, int xx, int yy)
{
	(t->value==root->value)? tc(4):tc(x);
	gotoxy(xx,yy);
	cprintf("%d",t->value);
	if(t->left!=NULL)
	{
		(t==root)? (gotoxy(xx-6,yy+1),x=3,tc(14),cprintf("/"),tree_vision(t->left,xx-12,yy+3)) : (gotoxy(xx-2,yy+1),x=3,tc(14),cprintf("/"),tree_vision(t->left,xx-5,yy+2));
	}
	if(t->right!=NULL)
	{
		(t==root)? (gotoxy(xx+8,yy+1),x=2,tc(14),cprintf("\\"),tree_vision(t->right,xx+12,yy+3)) : (gotoxy(xx+2,yy+1),x=2,tc(14),cprintf("\\"),tree_vision(t->right,xx+4,yy+2));
	}
}

void insertion()
{
	clrscr();
	lines();
	gotoxy(10,3);
	printf("--------------------");
	tc(3);
	cprintf("INSERTION IN BINARY TREE");
	printf("------------------");
	if(root==NULL)
	{
		root=(struct tree*)malloc(sizeof(struct tree));
		if(root==NULL)
		{
			printf("Memory not created");
			getch();
			return;
		}
		tc(6);
		gotoxy(10,10);
		cprintf("Enter Node Element = ");
		scanf("%d",&root->value);
		root->left=NULL;
		root->right=NULL;
		tc(2);
		gotoxy(20,14);
		cprintf("Data Inserted Successfully");
		getch();
		return;
	}
	else
	{
		temp=(struct tree*)malloc(sizeof(struct tree));
		if(temp==NULL)
		{
			printf("Memory not created");
			getch();
			return;
		}
		again:
		tc(6);
		gotoxy(10,10);
		cprintf("Enter Node Element = ");
		scanf("%d",&temp->value);
		temp->left=NULL;
		temp->right=NULL;
		temp1=root;
		while(temp1!=NULL)
		{
			temp2=temp1;
			if(temp->value>temp1->value)
			{
				c='r';
				temp1=temp1->right;
			}
			else if(temp->value==temp1->value)
			{
				gotoxy(10,14);
				printf("----------");
				tc(4);
				cprintf("Node Element Already Exists");
				printf("----------");
				tc(15);
				getch();
				clrscr();
				lines();
				gotoxy(10,3);
				printf("--------------------");
				tc(3);
				cprintf("INSERTION IN BINARY TREE");
				printf("------------------");
				goto again;
			}
			else
			{
				c='l';
				temp1=temp1->left;
			}
		}
		if(c=='l')
		{
			temp2->left=temp;
		}
		else
		{
			temp2->right=temp;
		}
		tc(2);
		gotoxy(20,14);
		cprintf("Data Inserted Successfully");
		getch();
		return;
	}
}

void traversion()
{
	clrscr();
	lines();
	gotoxy(10,3);
	printf("---------------");
	tc(3);
	cprintf("TRAVERSION IN BINARY TREE");
	printf("--------------");
	if(root==NULL)
	{
		gotoxy(10,15);
		printf("--------------");
		tc(14);
		cprintf("Tree is Empty");
		printf("--------------");
		getch();
		return;
	}
	tc(6);
	gotoxy(10,10);
	cprintf("1. BREADTH FIRST SEARCH");
	gotoxy(10,12);
	cprintf("2. DEPTH FIRST SEARCH");
	gotoxy(10,14);
	cprintf("3. PRIORITY TRAVERSION");
	again:
	c=getch();
	if(c=='1')
	{
		BFS();
	}
	else if(c=='2')
	{
		clrscr();
		lines();
		gotoxy(10,3);
		printf("---------------");
		tc(3);
		cprintf("TRAVERSION IN BINARY TREE");
		printf("--------------");
		tc(6);
		gotoxy(10,10);
		cprintf("1. BREADTH FIRST SEARCH");
		gotoxy(10,12);
		cprintf("2. DEPTH FIRST SEARCH");
		gotoxy(15,14);
		tc(3);
		cprintf("(a). Pre-Order");
		gotoxy(15,15);
		cprintf("(b). In-Order");
		gotoxy(15,16);
		cprintf("(c). Post-Order");
		gotoxy(10,18);
		tc(6);
		cprintf("3. PRIORITY TRAVERSION");
		agan:
		c=getch();
		if(c=='a'||c=='A')
		{
			clrscr();
			lines();
			gotoxy(10,3);
			tc(3);
			printf("---------------");
			cprintf("PRE ORDER TRAVERSION IN BINARY TREE");
			printf("---------------");
			i=10,j=12;
			show_tree_left_priority(root);
		}
		else if(c=='b'||c=='B')
		{
			clrscr();
			lines();
			gotoxy(10,3);
			tc(3);
			printf("---------------");
			cprintf("IN ORDER TRAVERSION IN BINARY TREE");
			printf("---------------");
			i=10,j=12;
			show_tree_in_order(root);
		}
		else if(c=='c'||c=='C')
		{
			clrscr();
			lines();
			gotoxy(10,3);
			tc(3);
			printf("---------------");
			cprintf("POST ORDER TRAVERSION IN BINARY TREE");
			printf("---------------");
			i=10,j=12;
			show_tree_post_order(root);
		}
		else
			goto agan;
		printf("\b\b\b\b            ");
		getch();
	}
	else if(c=='3')
	{
		clrscr();
		lines();
		gotoxy(10,3);
		printf("---------------");
		tc(3);
		cprintf("TRAVERSION IN BINARY TREE");
		printf("--------------");
		tc(6);
		gotoxy(10,10);
		cprintf("1. BREADTH FIRST SEARCH");
		gotoxy(10,12);
		cprintf("2. DEPTH FIRST SEARCH");
		gotoxy(10,14);
		cprintf("3.PRIORITY TRAVERSION");
		gotoxy(15,16);
		tc(3);
		cprintf("(a). Left Priority Traversion");
		gotoxy(15,17);
		cprintf("(b). Right Priority Traversion\n");
		agn:
		c=getch();
		if(c=='a'||c=='A')
		{
			clrscr();
			lines();
			gotoxy(10,3);
			tc(3);
			printf("---------------");
			cprintf("LEFT PRIORITY TRAVERSION IN BINARY TREE");
			printf("---------------");
			i=10,j=12;
			show_tree_left_priority(root);
		}
		else if(c=='b'||c=='B')
		{
			clrscr();
			lines();
			gotoxy(10,3);
			tc(3);
			printf("---------------");
			cprintf("RIGHT PRIORITY TRAVERSION IN BINARY TREE");
			printf("---------------");
			i=10,j=12;
			show_tree_right_priority(root);
		}
		else
			goto agn;
		printf("\b\b\b     ");
		getch();
	}
	else
		goto again;
}


void BFS()
{
	int i,j,xp,yp;
	clrscr();
	lines();
	gotoxy(10,3);
	tc(3);
	printf("---------------");
	cprintf("BREADTH FIRST SEARCH IN BINARY TREE");
	printf("---------------");
	x=0,level_counter=0,level=0;
	bfs(root),xp=10,yp=12;
	for(j=0;j<=level;j++)
	{
		for(y=0;y<x;y++)
		{
			if(a[y]%10==j)
			{
				gotoxy(xp,yp);
				xp+=7;
				tc(15);
				cprintf("%d ",a[y]/10);
				tc(4);
				cprintf("->");
			}
			if(xp>75)
				xp=10,yp++;
		}
	}
	printf("\b\b\b     ");
	getch();
}

void bfs(struct tree *t)
{
	if(t->left!=NULL)
	{
		level_counter++,level++;
		bfs(t->left);
	}
	if(t->right!=NULL)
	{
		level_counter++,level++;
		bfs(t->right);
	}
	a[x]=(t->value*10)+level_counter;
	level_counter--,x++;
}

void show_tree_right_priority(struct tree *t)
{
	tc(15);
	gotoxy(i,j);
	cprintf("%d ",t->value);
	tc(4);
	cprintf("->");
	i+=7;
	if(i>75)
		i=10,j++;
	if(t->right!=NULL)
		show_tree_right_priority(t->right);
	if(t->left!=NULL)
		show_tree_right_priority(t->left);
}

void show_tree_left_priority(struct tree *t)
{
	tc(15);
	gotoxy(i,j);
	cprintf("%d ",t->value);
	tc(4);
	cprintf("->");
	i+=7;
	if(i>75)
		i=10,j++;
	if(t->left!=NULL)
		show_tree_left_priority(t->left);
	if(t->right!=NULL)
		show_tree_left_priority(t->right);
}

void show_tree_in_order(struct tree *t)
{
	if(t->left!=NULL)
		show_tree_in_order(t->left);
	tc(15);
	gotoxy(i,j);
	cprintf("%d ",t->value);
	tc(4);
	cprintf("->");
	i+=7;
	if(i>75)
		i=10,j++;
	if(t->right!=NULL)
		show_tree_in_order(t->right);
}

void show_tree_post_order(struct tree *t)
{
	if(t->left!=NULL)
		show_tree_post_order(t->left);
	if(t->right!=NULL)
		show_tree_post_order(t->right);
	tc(15);
	gotoxy(i,j);
	cprintf("%d ",t->value);
	tc(4);
	cprintf("->");
	i+=7;
	if(i>75)
		i=10,j++;
}

void deletion()
{
	char signal='f';
	int del;
	clrscr();
	lines();
	gotoxy(10,3);
	tc(3);
	printf("---------------");
	cprintf("DELETION IN BINARY TREE");
	printf("---------------");
	if(root==NULL)
	{
		gotoxy(10,15);
		printf("--------------");
		tc(14);
		cprintf("Tree is Empty");
		printf("--------------");
		getch();
		return;
	}
	gotoxy(10,10);
	tc(6);
	cprintf("Enter Node Element = ");
	scanf("%d",&del);
	temp=root;
	do
	{
		if(del>temp->value)
		{
			temp1=temp;
			temp=temp->right;
			c='r';
		}
		else if(temp->value>del)
		{
			temp1=temp;
			temp=temp->left;
			c='l';
		}
		if(temp->value==del)
		{
			if((temp->left!=NULL&&temp->right==NULL))
			{
				(root->value==temp->value)? (root=root->left) : (c=='l')? (temp1->left=temp->left) : (temp1->right=temp->left);
				free(temp);
				gotoxy(10,15);
				tc(14);
				printf("------------");
				cprintf("Node Element Deleted Successfully");
				printf("------------");
				goto out;
			}
			else if(temp->left==NULL&&temp->right!=NULL)
			{
				(root->value==temp->value)? (root=root->right) : (c=='l')? (temp1->left=temp->right) : (temp1->right=temp->right);
				free(temp);
				gotoxy(10,15);
				tc(14);
				printf("------------");
				cprintf("Node Element Deleted Successfully");
				printf("------------");
				goto out;
			}
			else if(temp->left!=NULL&&temp->right!=NULL)
			{
				gotoxy(10,15);
				tc(14);
				printf("------------");
				cprintf("Root With Two Childs Cannot Be Deleted");
				printf("------------");
				getch();
				return;
			}
			else if(del==root->value)
			{
				free(root);
				root=NULL;
				gotoxy(10,15);
				tc(14);
				printf("------------");
				cprintf("Node Element Deleted Successfully");
				printf("------------");
				goto out;
			}
			else
			{
				signal='s';
				if(c=='l')
				{
					temp1->left=NULL;
					free(temp);
				}
				if(c=='r')
				{
					temp1->right=NULL;
					free(temp);
				}
				gotoxy(10,15);
				tc(14);
				printf("------------");
				cprintf("Node Element Deleted Successfully");
				printf("------------");
				goto out;
			}
		}
	} while(temp->left!=NULL||temp->right!=NULL);
	if(signal=='f')
	{
		gotoxy(10,15);
		tc(14);
		printf("------------");
		cprintf("Invalid Node Element");
		printf("------------");
		out:
		getch();
		return;
	}
}

void searching()
{
	char signal='f';
	int search;
	clrscr();
	lines();
	gotoxy(10,3);
	tc(3);
	printf("---------------");
	cprintf("SEARCHING IN BINARY TREE");
	printf("---------------");
	if(root==NULL)
	{
		gotoxy(10,15);
		printf("--------------");
		tc(14);
		cprintf("Tree is Empty");
		printf("--------------");
		getch();
		return;
	}
	gotoxy(10,10);
	tc(6);
	cprintf("Enter Node Element = ");
	scanf("%d",&search);
	tc(6);
	gotoxy(10,15);
	cprintf("PATH = ");
	tc(4);
	cprintf("Root");
	temp=root,x=0;
	do
	{
		if(search>temp->value)
		{
			temp1=temp;
			temp=temp->right;
			c='r',x++;
			tc(14);
			cprintf(" -> ");
			tc(2);
			cprintf("Right");
		}
		else if(temp->value>search)
		{
			temp1=temp;
			temp=temp->left;
			c='l',x++;
			tc(14);
			cprintf(" -> ");
			tc(3);
			cprintf("Left");
		}
		if(temp->value==search)
		{
			signal='t';
			break;
		}
	} while(temp->left!=NULL||temp->right!=NULL);
	if(signal=='f')
	{
		clrscr();
		lines();
		gotoxy(10,3);
		tc(3);
		printf("---------------");
		cprintf("SEARCHING IN BINARY TREE");
		printf("---------------");
		gotoxy(10,15);
		tc(14);
		printf("------------");
		cprintf("Invalid Node Element");
		printf("------------");
	}
	else
	{
		gotoxy(10,18);
		tc(3);
		cprintf("Data Found = ");
		tc(14);
		cprintf("%d",search);
		gotoxy(40,18);
		tc(3);
		cprintf("Level = ");
		tc(2);
		cprintf("%d",x);
	}
	getch();
}
