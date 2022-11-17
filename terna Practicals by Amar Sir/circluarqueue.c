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
