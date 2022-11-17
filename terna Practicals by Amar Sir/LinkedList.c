#include<stdio.h>
struct node
{
int data;
 struct node *next;
};

struct node *root;

void createLinkedList()
{
	root=NULL;
}


void insertLeft(int e)
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));//1
	n->data=e;//2
	n->next=NULL;//3
	if(root==NULL)
	{
	 root=n;//creation
	}
	else
	{
		n->next=root;//1
		root=n;//2
	}
	printf("\n%d inserted",e);
}

}


void insertRight(int e)
{
	struct node *n,*t;
	n=(struct node *)malloc(sizeof(struct node));//1
	n->data=e;//2
	n->next=NULL;//3
	if(root==NULL)
	{
	 root=n;//creation
	}
	else
	{
		t=root;//1
		while(t->next!=NULL)//2
		{
			t=t->next;
		}
		t->next=n;//3
		printf("\n%d inserted",e);
}}
		
void deleteLeft()
{
	struct node *t;
	if(root==NULL)
	{
		printf("Empty list");
	}
	else
	{
		t=root;//1
		root=root->next;//2
		printf("\n %d deleted",t->data);
		free(t);//3
	}
}
void deleteRight()
{
	struct node *t,*t2;
	if(root==NULL)
		printf("Empty list");
	else
	{
		t=t2=root;//1
		while(t->next!=NULL)//2
		{
			t2=t;
			t=t->next;
		}
		if(t2==root)
		  root=NULL;
		
		t2->next=NULL;//3
		printf("\n %d deleted",t->data);
		free(t);//4
 }
}
		
void printList()
{

	struct node *t;
	if(root==NULL)
		printf("Empty list");
	else
	{
		t=root;
		while(t!=NULL)
		{
			printf("%d   ",t->data);
			t=t->next;
		}
	}
}
void searchList(int key)
{
 struct node *t;
	if(root==NULL)
		printf("Empty list");
	else
	{
		t=root;
		while(t!=NULL)
		{
			if(t->data==key)
			 break;
		}
		if(t==NULL)
		 printf("\n %d not found",key);
	 else
	  printf("\n %d found",key);
	}

				
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
		
		
	}


