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
