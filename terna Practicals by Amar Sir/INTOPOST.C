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

