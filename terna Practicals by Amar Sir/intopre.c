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
