### Stack 
```
#include<stdio.h>
int s[100],tos, maxsize;

void createstack(int n)
{
 maxsize=n;
 tos=-1;
}

void push(int e)
{
 tos++;
 s[tos]=e;
}

int pop()
{
 int temp=s[tos];
 tos--;
 return(temp);
}

int isempty()
{
 if(tos==-1)
  return(1);
 else
  return(0);
}

int isfull()
{
 if(tos==maxsize-1)
  return(1);
 else
  return(0);
}

int peak()
{
 return(s[tos]);
}

void printstack()
{int i;
 for(i=tos;i>=0;i--)
 {
  printf("\n%d",s[i]);
 }
}

int main()
{
 int ch,element,size;

 printf("\nEnter size of stack");
 scanf("%d",&size);
 createstack(size);

 do
 {
  printf("\n\n1. Push\n2. Pop\n3. Peak\n4. Print\n0. Exit\n:");
  scanf("%d",&ch);

  switch(ch)
  {
   case 1:if(isfull()!=1)
	  {
	   printf("\nElement:");
	   scanf("%d",&element);
	   push(element);
	  }
	  else
	   printf("\nStack full");
	   break;
   case 2:if(isempty()!=1)
	  {
	   element=pop();
	   printf("\nElement popped=%d",element);
	  }
	  else
	   printf("\nStack empty");
	   break;
   case 3:if(isempty()!=1)
	  {
	   printf("\nElement at peak=%d",peak());
	  }
	  else
	   printf("\nStack empty");
	   break;
   case 4:printf("\nStack has\n");
	  printstack();
	  break;
   case 0:printf("\nExit");
	  break;
   default:printf("\nError");
	   break;
  }
 }while(ch!=0);
 return(0);
}

```

### Queue.c

```
#include<stdio.h>


int q[100],maxsize,front,rear;
void createqueue(int n)
{
 maxsize=n;
 front=0;
 rear=-1;
}

void enqueue(int e)
{
 rear++;
 q[rear]=e;
}

int dequeue()
{
 int temp;
 temp=q[front];
 front++;
 return(temp);
}

int isfull()
{
 if(rear== maxsize-1)
  return(1);
 else
  return(0);
}

int isempty()
{
 if(front>rear)
  return(1);
 else
  return(0);
}

void printqueue()
{
 int i;
 for(i=front;i<=rear;i++)
 {
  printf("\n%d",q[i]);
 }
}
int main()
{
 int e, size, ch;

 printf("\nEnter size:");
 scanf("%d",&size);
 createqueue(size);

 do
 {
  printf("\n\n1. Enqueue\n2. Dequeue\n3. Print\n0. Exit\n:");
  scanf("%d",&ch);

  switch(ch)
  {
   case 1:if(isfull()!=1)
	  {
	   printf("\nEnter element:");
	   scanf("%d",&e);
	   enqueue(e);
	  }
	  else
	   printf("\nQueue full");
	  break;
   case 2:if(isempty()!=1)
	  {
	   e=dequeue();
	   printf("\nElement removed: %d",e);
	  }
	  else
	   printf("\nQueue empty");
	   break;
   case 3:printf("\nData on queue:");
	  printqueue();
	  break;
   case 0:printf("\nExiting");
	  break;
   default:printf("\Error");
	   break;
  }
 }while(ch!=0);
 return 1;
}
```

### DynamicStack.c

```
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


```
### Dynamicqueue.c

```
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
	
  
  ```
  
  ### circluarqueue.c
  
  ```
  //CIRCULAR QUEUE
#include<stdio.h>
#include<conio.h>

int q[100],MaxSize,front,rear,count;
void createqueue(int n)
{
 MaxSize=n;
 front=0;
 rear=-1;
}

void enqueue(int e)
{
 rear=(rear+1)%MaxSize;
 q[rear]=e;
 count++;
}

int dequeue()
{
 int temp;
 temp=q[front];
 front=(front+1)%MaxSize;
 count--;
 return(temp);
}

int isfull()
{
 if(count==MaxSize)
  return(1);
 else
  return(0);
}

int isempty()
{
 if(count==0)
  return(1);
 else
  return(0);
}

void printqueue()
{
 int i,c;
 for(i=front,c=0;c<count;i=(i+1)%MaxSize,c++)
 {
  printf("\n%d",q[i]);
 }
}

main()
{
 int e, size, ch;
 clrscr();
 printf("\nEnter size:");
 scanf("%d",&size);
 createqueue(size);

 do
 {
  printf("\n\n1. Enqueue\n2. Dequeue\n3. Print\n0. Exit\n:");
  scanf("%d",&ch);

  switch(ch)
  {
   case 1:if(isfull()!=1)
	  {
	   printf("\nEnter element:");
	   scanf("%d",&e);
	   enqueue(e);
	  }
	  else
	   printf("\nQueue full");
	  break;
   case 2:if(isempty()!=1)
	  {
	   e=dequeue();
	   printf("\nElement removed: %d",e);
	  }
	  else
	   printf("\nQueue empty");
	   break;
   case 3:printf("\nData on queue:");
	  printqueue();
	  break;
   case 0:printf("\nExiting");
	  break;
   default:printf("\Error");	
	   break;
  }
 }while(ch!=0);
}

```

### Linkedlist.c

```
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
  
  ```
  
  
  ### intopre.c
  
  ```
  //INFIX TO PREFIX
#include<stdio.h>

#include<string.h>
char s[100];
int tos, maxsize;

void createstack(int n)
{
 maxsize=n;
 tos=-1;
}

void push(char e)
{
 tos++;
 s[tos]=e;
}

char pop()
{
 char temp=s[tos];
 tos--;
 return(temp);
}

int isempty()
{
 if(tos==-1)
  return(1);
 else
  return(0);
}

int prec(char ch)
{
 if(ch=='+'||ch=='_')
  return(1);
 if(ch=='*'||ch=='/'||ch=='%')
  return(2);
 else
  return(0);
}

main()
{
 char in[100],pre[100],c;
 int pi,i;

 printf("Enter infix:");
 scanf("%s",in);
 createstack(strlen(in));
 pi=0;

 for(i=strlen(in)-1;i>=0;i--)
 {
  c=in[i];
  switch(c)
  {
   case')':push(c);
	   break;
   case'(':while(s[tos]!=')')
	   {
	    pre[pi]=pop();
	    pi++;
	   }
	   c=pop();
	   break;
   case'+': case'-': case'*': case'/':
	   while((prec(c)<prec(s[tos]))&&(isempty()!=1))
	   {
	    pre[pi]=pop();
	    pi++;
	   }
	   push(c);
	   break;
   default:pre[pi]=c;
	   pi++;
	   break;
  }//switch
 }//for

 while(isempty()!=1)
 {
  pre[pi]=pop();
  pi++;
 }
 printf("\nPrefix is %s",strrev(pre));
return 1;
}




```


### INTOPOST.C
```
#include<stdio.h>
#include<string.h>
char s[100];
int tos, maxsize;
void createstack(int n)
{
 maxsize=n;
 tos=-1;
}
void push(char e)
{
 tos++;
 s[tos]=e;
}
char pop()
{
 char temp=s[tos];
 tos--;
 return(temp);
}
int isempty()
{
 if(tos==-1)
  return(1);
 else
  return(0);
}

int prec(char ch)
{
 if(ch=='+'||ch=='-')
  return(1);
 if(ch=='*'||ch=='/'||ch=='%')
  return(2);
 else
  return(0);
}
main()
{
 char in[100],post[100],c;
 int pi,i;

 printf("Enter infix:");
 scanf("%s",in);
 createstack(strlen(in));
 pi=0;

 for(i=0;i<strlen(in);i++)
 {
  c=in[i];
  switch(c)
  {
   case'(':push(c);
	   break;
   case')':while(s[tos]!='(')
	   {
	    post[pi]=pop();
	    pi++;
	   }
	   c=pop();//remove the bracket
	   break;
   case'+': case'-': case'*': case'/':
	   while((prec(c)<=prec(s[tos]))&&(isempty()!=1))
	   {
	    post[pi]=pop();
	    pi++;
	   }
	   push(c);
	   break;
   default:post[pi]=c;
	   pi++;
	   break;
  }//switch
 }//for

 while(isempty()!=1)
 {
  post[pi]=pop();
  pi++;
 }
 printf("\nPostfix is %s",post);
return 1;
}


```



### graph.c

```

#include<stdio.h>
int adjMat[10][10],size,visited[10];
void creategraph(int nodes)
{
	int scr,dest;
	size=nodes;
	for(scr=0;scr<size;scr++)
	{
		for(dest=0;dest<size;dest++)
		{
			printf("\n%d to %d :",scr,dest);
			scanf("%d",&adjMat[scr][dest]);
		}
	}
}

void resetvisited()
{
	int i;
	for(i=0;i<size;i++)
	 visited[i]=0;
}
void DFS(int start)
{
	int i=0;
	visited[start]=1;
	printf("V%d ",start);
	for(i=0;i<size;i++)
	{
		if(adjMat[start][i]=1 && visited[i]==0)
		{
			DFS(i);
		}
	}
	
}
void BFS(int start)
{
	int q[10],front=0,rear=-1;
	int i,element;
	visited[start]=1;
	q[++rear]=start;
	while(front<=rear)
	{
		element=q[front++];
		printf("V%d  ",element);
		for(i=0;i<size;i++)
		{
			if(adjMat[start][i]=1 && visited[i]==0)
			{
				visited[i]=1;
				q[++rear]=i;
				
			}
		}
	}
}

int main()
{
	creategraph(3);
	resetvisited();
	DFS(0);
	resetvisited();
	BFS(0);
}

```


### <center> * Jay shri Ram * </center>
