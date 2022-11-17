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
