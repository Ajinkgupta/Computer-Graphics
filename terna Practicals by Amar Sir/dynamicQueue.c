#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *rear,*front;
void createQueue()
{
	rear=NULL;
	front=NULL;
}

void Enqueue(int e)
								{
									struct node *n,*t;
									n=(struct node *)malloc(sizeof(struct node));
									n->data=e;
									n->next=NULL;
									if(rear==NULL)
									{
										front=rear=n;
									}
								 else
								 {
								 	t=front;//1
								 	while(t->next!=NULL)//2
								 	{
								 		t=t->next;
										}
										t->next=n;//3
									}
									printf("\n%d Enqueued",e);
							}
								
								void Dequeue()
								{
									struct node *t;
									if(front==NULL)
									{
										printf("\nQueue Empty:");
									}
								 else
									{
								 	t=front;//1
								 	front=front->next;//2
								 	printf("\n%d Dequeued",t->data);
								 	free(t);
									}
								}
								
							
						 void printQueue()
						 {
						 	struct node *t;
						 	if(front==NULL)
									{
										printf("Queue Empty:");
									}
								else
								{
									printf("\nQueue Has\n");
									t=front;//1
									while(t!=NULL)//2
								 	{
								 		printf("%d ",t->data);
								 		t=t->next;
								 		
										}
									
								}
					 	}
int main()
{
	createQueue();
	Enqueue(10);
 Enqueue(40);
 Enqueue(80);
 Enqueue(100);
 Enqueue(140);
 printQueue();
	Dequeue();
	Dequeue();
	printQueue();
	return 0;
}
					 	
									
								
