#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *tos;
void createStack()
{
 tos=NULL;
}
void push(int e)
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	n->data=e;
	n->next=NULL;
	if(tos==NULL)
	{
		tos=n;
	}
	else
	{
		n->next=tos;
		tos=n;
	}
	printf("\n%d pushed",e);
}
void pop()
								{
									struct node *t;
									if(tos==NULL)
									{
										printf("Stack Empty:");
									}
								 else
									{
								 	t=tos;//1
								 	tos=tos->next;//2
								 	printf("\n%d Poped",t->data);
								 	free(t);
									}
								}	

void printStack()
						 {
						 	struct node *t;
						 	if(tos==NULL)
									{
										printf("Stack Empty:");
									}
								else
								{
									t=tos;//1
									printf("\nContent on stack are:\n");
									while(t!=NULL)//2
								 	{
								 		printf("\n%d ",t->data);
								 		t=t->next;
								 		
										}
									
								}
					 	}
int main()
{
	createStack();
	push(10);
	push(20);
	push(30);
	push(40);	
	printStack();
	pop();
	pop();
		pop();
	pop();
		pop();
	pop();
	printStack();
	return 1;
}

