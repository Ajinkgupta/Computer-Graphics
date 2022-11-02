## 1 To implement DDA Algorithm for Drawing a Line Segment between two Given end Points A(x1,y1) and B(x2,y2) .
```
#include<stdio.h>
#include<graphics.h>
#include<math.h>
void main()
{
float x,y,x1,y1,x2,y2,dx,dy,length;
int i,gd,gm;
clrscr();
printf("Enter the value of x1 :\t");
scanf("%f",&x1);
printf("Enter the value of y1 :\t");
scanf("%f",&y1);
printf("Enter the value of x2 :\t");
scanf("%f",&x2);
printf("Enter the value of y2 :\t");
scanf("%f",&y2);
 
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"\\tc\\BGI");

dx=abs(x2-x1);
dy=abs(y2-y1);

if (dx >= dy)

{
length = dx;
}
else
{
length = dy;
}
dx = (x2-x1)/length;
dy = (y2-y1)/length;
x = x1 + 0.5;  
y = y1 + 0.5;  
putpixel (x, y, 15);
i = 1;  
while(i <= length)
{
x = x + dx;
y = y + dy;
putpixel (x, y, 15);
i = i + 1;
delay(100);  
}
getch();
closegraph();
}
```

## 2 To implement Bresenham's Line Drawing Algorithm


```
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
void main()
{
float x,y,x1,y1,x2,y2,dx,dy,e;
int i,gd,gm;
clrscr(); 
printf("Enter the value of x1 :\t");
scanf("%f",&x1);
printf("Enter the value of y1 :\t");
scanf("%f",&y1);
printf("Enter the value of x2 :\t");
scanf("%f",&x2);
printf("Enter the value of y2 :\t");
scanf("%f",&y2); 
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"c:\\tc\\BGI");

dx=abs(x2-x1);
dy=abs(y2-y1); 
x = x1;
y = y1;
putpixel (x, y, 15) ;
 
e = 2 * dy-dx;

i = 1; 
do
{
while(e >= 0)
{
y = y + 1;
e = e - 2 * dx;
}
x = x + 1;
e = e + 2 * dy;
i = i + 1;
putpixel (x, y, 15);
}
while( i <= dx);
getch();
closegraph();
}
```


## 3 To implement Midpoint circle

```
#include<stdio.h>
#include<graphics.h>
#include<math.h>
void main()
{
float p;
int i,gd,gm,x,y;
int r; 
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"\\tc\\bgi");
 
printf("Enter the radius of the circle :");
scanf("%d",&r);

x=0;
y=r;
p = 1.25 - r;
do
{
putpixel(200+x,200+y,15);
putpixel(200+y,200+x,15);
putpixel(200+x,200-y,15);
putpixel(200+y,200-x,15);
putpixel(200-x,200-y,15);

putpixel(200-x,200+y,15);
putpixel(200-y,200+x,15);
putpixel(200-y,200-x,15);

if (p < 0)
{
x = x+1;
y = y;
p = p + 2*x + 1;
}
else
{
x= x+1;
y= y-1;
p = p + 2*(x-y) + 1;
}
delay(100);
}
while(x < y);
getch();
closegraph();
}
```

## 4 To implement area filling (flood fill)




```
#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void flood(int, int, int, int);
void main()
{int gd,gm;
 
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"\\tc\\bgi");

rectangle(50,50,100,100);
flood(55,55,4,15);
getch();
closegraph();
}

void flood(int seed_x,int seed_y,int foreground_col,int background_col)
{
if(getpixel(seed_x,seed_y)!= background_col &&
getpixel(seed_x,seed_y)!= foreground_col)
{
putpixel(seed_x,seed_y,foreground_col);
flood(seed_x+1,seed_y,foreground_col,background_col);
flood(seed_x-1,seed_y,foreground_col,background_col);
flood(seed_x,seed_y+1,foreground_col,background_col);
flood(seed_x,seed_y-1,foreground_col,background_col);

flood(seed_x+1,seed_y+1,foreground_col,background_col);
flood(seed_x-1,seed_y-1,foreground_col,background_col);
flood(seed_x+1,seed_y-1,foreground_col,background_col);
flood(seed_x-1,seed_y+1,foreground_col,background_col);
}
}
```


## 5 To implement bit map method for given character Genration


```
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
int gd=DETECT,gm,i,j;
int a[20][20]=
{{0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0},
{0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,0},
{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0},
{0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0},
{0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0},
{0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0}};

initgraph(&gd,&gm,"c:\\tc\\bgi");
for(i=0;i<19;i++)
{
for(j=0;j<19;j++)
{
if(a[i][j]==1)
putpixel(100+j,200+i,WHITE);
}
}
getch();

}
```

## 6 To apply Basic 2D Transformation(Translation , rotation , Scaling 

```
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>

   int main()
   {
   int i, x, y, tx, ty, sx, sy, angle=10, xmax, ymax, xmid, ymid, op;
   int gd,gm;
   float p1[10]=  {	50,50,
			100,50,
			100,100,
			50,100,
			50,50,
		   };
   int pi[10];
   float b[3][3]={	1,0,0,
			0,1,0,
			0,0,1
		};
   int c[1][1];
   float a[1][1];
	  printf("\nSelect the transformation : ");
	  printf("\n1 : Traslation");
	  printf("\n2 : Rotation");
	  printf("\n3 : Scaling");
	  printf("\n4 : Rotation about arbitrary point");
	  printf( "\nEnter the option : ");
	  scanf("%d",&op);
	  switch(op)
	  {
		case 1: printf("\nEnter x traslation : ");
				scanf("%d",&tx);
				printf("\nEnter y traslation : ");
				scanf("%d",&ty);

		b[0][0] = 1;
		b[0][1] = 0;
		b[0][2] = 0;

		b[1][0] = 0;
		b[1][1] = 1;
		b[1][2] = 0;

		b[2][0] = tx;
		b[2][1] = ty;
		b[2][2] = 1;

		break;
	case 2: 	printf("\nEnter Rotation angle : ");
				scanf("%d",&angle);
		b[0][0] =cos(angle*3.142/180);
		b[0][1] =sin(angle*3.142/180);
		b[0][2] = 0;

		b[1][0] =-sin(angle*3.142/180);
		b[1][1] = cos(angle*3.142/180);
		b[1][2] = 0;

		b[2][0] = 0;
		b[2][1] = 0;
		b[2][2] = 1;

		break;
	case 3: 	printf("\nEnter x scaling : ");
		scanf("%d",&sx);
		printf("\nEnter y scaling : ");
		scanf("%d",&sy);

		b[0][0] = sx;
		b[0][1] = 0;
		b[0][2] = 0;

		b[1][0] = 0;
		b[1][1] = sy;
		b[1][2] = 0;

		b[2][0] = 0;
		b[2][1] = 0;
		b[2][2] = 1;

		break;
	case 4: 	printf("\nEnter x coordinate of arbitrary point : ");
		scanf("%d",&x);
		printf("\nEnter y coordinate of arbitrary point : ");
		scanf("%d",&y);
		printf("\nEnter Rotation angle : ");
		scanf("%d",&angle);

		tx = x;
		ty = y;

		b[0][0] =cos(angle*3.142/180);
		b[0][1] =sin(angle*3.142/180);
		b[0][2] = 0;

		b[1][0] =-sin(angle*3.142/180);
		b[1][1] = cos(angle*3.142/180);
		b[1][2] = 0;

		b[2][0] = -tx* cos(angle*3.142/180) + ty*sin(angle*3.142/180)+tx;
		b[2][1] = -tx* sin(angle*3.142/180) - ty*cos(angle*3.142/180)+ty;
		b[2][2] = 1;

	  }
		detectgraph(&gd,&gm);
		initgraph(&gd,&gm,"\\tc\\bgi");	// Initialize graphics
	xmax = getmaxx();		// Get maximum x coordinate
	ymax = getmaxy();		// Get maximum y coordinate
	xmid = xmax/2;		// Get the center x coordinate
	ymid = ymax/2;		// Get the center y coordinate

	setcolor(1);
	line(xmid,0,xmid,ymax);	// Draw y coordinate
	line(0, ymid, xmax, ymid);	// Draw x coordinate

	  setcolor(4);
	  for (i=0; i<8;i=i+2)
	  {
	  line(p1[i]+xmid,ymid-p1[i+1],xmid+p1[i+2],ymid-p1[i+3]);
	  }
	  for(i=0;i<9;i=i+2)
	  { 	a[0][0]=p1[i];
		a[0][1]=p1[i+1];
		c[0][0] = a[0][0]*b[0][0]+a[0][1]*b[1][0]+b[2][0];
		c[0][1] = a[0][0]*b[0][1]+a[0][1]*b[1][1]+b[2][1];
		pi[i]=c[0][0];
		pi[i+1]=c[0][1];
	  }
  setcolor(15);
	  for (i=0; i<8;i=i+2)
	  {
	  line(xmid+pi[i],ymid-pi[i+1],xmid+pi[i+2],ymid-pi[i+3]);
	  }
	  getch();
	  closegraph();
	  return 0;
   }
```


## 7 To implement Cohen sutherland Line Clipping Algorithm

```
#include<stdio.h>
	#include<conio.h>
	#include<stdlib.h>
	#include<dos.h>
	#include<math.h>
	#include<graphics.h>
 	typedef struct coordinate
	{
	int x,y;
	char code[4];
	}PT;
	void drawwindow();
	void drawline (PT p1,PT p2,int cl);
	PT setcode(PT p);
	int visibility (PT p1,PT p2);
	PT resetendpt (PT p1,PT p2);
	main()
	{
	int gd=DETECT, gm,v;
	PT p1,p2,ptemp;
	initgraph(&gd,&gm,"\\tc\\bgi");
	cleardevice();
	printf("\n\n\t\tENTER END-POINT 1 (x,y): ");
	scanf("%d,%d",&p1.x,&p1.y);
	printf("\n\n\t\tENTER END-POINT 2 (x,y): ");
	scanf("%d,%d",&p2.x,&p2.y);
	cleardevice();
	drawwindow();
	getch();
	drawline(p1,p2,15);
	getch();
	p1=setcode(p1);
	p2=setcode(p2);
	v=visibility(p1,p2);
	switch(v)
		{
		case 0:	cleardevice(); /* Line completely visible*/
				drawwindow();
				drawline(p1,p2,15);
				break;
		case 1:	cleardevice(); /* Line completely invisible */
				drawwindow();
				break;
		case 2:	cleardevice(); 	/* line partly visible */
				p1=resetendpt (p1,p2);
				p2=resetendpt(p2,p1);
				drawwindow();
				drawline(p1,p2,15);
				break;
		}
	getch();
	closegraph();
	return(0);
	}
 void drawwindow()
	{
	setcolor(RED);
	line(150,100,450,100);
	line(450,100,450,350);
	line(450,350,150,350);
	line(150,350,150,100);
	}
 	void drawline (PT p1,PT p2,int cl)
	{
	setcolor(cl);
	line(p1.x,p1.y,p2.x,p2.y);
	}
     PT setcode(PT p)
	{
	PT ptemp;
	if(p.y<100)
	ptemp.code[0]='1'; /* TOP */
	else
	ptemp.code[0]='0';
	if(p.y>350)
	ptemp.code[1]='1'; /* BOTTOM */
	else
	ptemp.code[1]='0';
	if (p.x>450)
	ptemp.code[2]='1'; /* RIGHT */
	else
	ptemp.code[2]='0';
	if (p.x<150) /* LEFT */
	ptemp.code[3]='1';
	else
	ptemp.code[3]='0';
	ptemp.x=p.x;
	ptemp.y=p.y;
	return(ptemp);
	}
	 int visibility (PT p1,PT p2)
	{
	int i,flag=0;
	for(i=0;i<4;i++)
	{
	if((p1.code[i]!='0')||(p2.code[i]!='0'))
	flag=1;
	}
	if(flag==0)
	return(0);
	for(i=0;i<4;i++)
	{
	if((p1.code[i]==p2.code[i]) &&(p1.code[i]=='1'))
	flag=0;
	}
	if(flag==0)
	return(1);
	return(2);
	}
 	PT resetendpt (PT p1,PT p2)
	{
	PT temp;
	int x,y,i;
	float m,k;
	if( p1.code[3]=='1') /* Cutting LEFT Edge  */
	x=150;
	if(p1.code[2]=='1')  /* Cutting RIGHT Edge */
	x=450;
	if((p1.code[3]=='1')||(p1.code[2]=='1'))
	{
	m=(float) (p2.y-p1.y)/(p2.x-p1.x);
	k=(p1.y+(m*(x-p1.x)));
	temp.y=k;
	temp.x=x;
	for(i=0;i<4;i++)
	temp.code[i]=p1.code[i];
	if(temp.y<=350&&temp.y>=100)
	return(temp);
	}
	if(p1.code[0]=='1')  /* Cutting TOP Edge */
	y=100;
	if(p1.code [1]=='1') /* Cutting BOTTOM Edge */
	y=350;
	if((p1.code[0]=='1')||(p1.code[1]=='1'))
	{
	m=(float)(p2.y-p1.y)/(p2.x-p1.x);
	k=(float)p1.x+(float)(y-p1.y)/m;
	temp.x=k;
	temp.y=y;
	for(i=0;i<4;i++)
	temp.code[i]=p1.code[i];
	return(temp);
	}
	else
	return(p1);
	}

```

## 8 To implement Bezier Curve

```
#include <stdio.h>
	#include <graphics.h>
	#include <conio.h>
	#include<stdio.h>
	#include<process.h>
	int gd,gm,maxx,maxy;
	float xxx[4][2];

	/* Function to draw line from relative position
		specified in array xxx-----------------------*/

	void line1(float x2,float y2)
	{
	line(xxx[0][0],xxx[0][1],x2,y2);
	xxx[0][0]=x2;
	xxx[0][1]=y2;
	}
	/* Bezier function
	-------------------- */
	void bezier(float xb,float yb,float xc,float yc,float xd,float yd,int n)
	{
	float xab,yab,xbc,ybc,xcd,ycd;
	float xabc,yabc,xbcd,ybcd;
	float xabcd,yabcd;
	if (n==0)
		{
		 line1(xb,yb);
		 line1(xc,yc);
		 line1(xd,yd);
		}
	else
		{
		 xab = (xxx[0][0]+xb)/2;
		 yab = (xxx[0][1]+yb)/2;
		 xbc = (xb+xc)/2;
		 ybc = (yb+yc)/2;
		 xcd = (xc+xd)/2;
		 ycd = (yc+yd)/2;
		 xabc = (xab+xbc)/2;
		 yabc = (yab+ybc)/2;
		 xbcd = (xbc+xcd)/2;
		 ybcd = (ybc+ycd)/2;
		 xabcd = (xabc+xbcd)/2;
		 yabcd = (yabc+ybcd)/2;
		 n=n-1;
		 bezier(xab,yab,xabc,yabc,xabcd,yabcd,n);
		 bezier(xbcd,ybcd,xcd,ycd,xd,yd,n);
		}
	}

	/* Function to initialise graphics
	----------------------------------- */
	void igraph()
		{
		detectgraph(&gd,&gm);
		if(gd<0)
			{
			puts("CANNOT DETECT A GRAPHICS CARD");
			exit(1);
			}
		initgraph(&gd,&gm,"\\tc\\bgi");
		}
       void  main()
		{
		int i;
		float temp1,temp2;
		igraph();

		/* Read two end points and two control points of the curve
		---------------------------------------------------------- */
		for(i=0;i<4;i++)
		{
		printf("Enter (x,y) coordinates of point%d : ",i+1);
		scanf("%f,%f",&temp1,&temp2);
		xxx[i][0] = temp1;
		xxx[i][1] = temp2;
		}
		bezier(xxx[1][0],xxx[1][1],xxx[2][0],xxx[2][1],xxx[3][0],xxx[3][1],8);
		getch();
		closegraph();
	}

```
## 9 To implement Fractal Genration (koch Curve)


```
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#define SIN 0.86602540   // sin(60 degrees)


void koch(int x1, int y1, int x2, int y2, int m)
{
int xx, yy, x[5], y[5], lx, ly, offx = 50, offy = 300;

		lx = (x2-x1)/3;
		ly = (y2-y1)/3;
		x[0] = x1;       		// Store point p0
		y[0] = y1;
		x[4] = x2;                             	 // Store point p4
		y[4] = y2;
		x[1] = x[0] + lx;                   		  // Store point p1
		y[1] = y[0] + ly;
		x[3] = x[0] + 2*lx;                		 // Store point p3
		y[3] = y[0] + 2*ly;
		xx =  x[3] - x[1];                    	// Translate point p2 to origin
		yy =  y[3] - y[1];
		x[2] =  xx*(0.5) + yy*(SIN);    	// Perform rotation for point p3
		y[2] = - xx*(SIN) + yy*(0.5);
		x[2] = x[2] + x[1];                		  // Perform inverse translation
		y[2] = y[2] + y[1];
	if(m>0)
	{
		koch(x[0], y[0], x[1], y[1], m-1);	// Recursive call to Draw part1
		koch(x[1], y[1], x[2], y[2], m-1);	// Recursive call to Draw part2
		koch(x[2], y[2], x[3], y[3], m-1);	// Recursive call to Draw part3
		koch(x[3], y[3], x[4], y[4], m-1);	// Recursive call to Draw part4
	}
	else
	{
		line(offx + x[0], offy + y[0] , offx + x[1], offy + y[1]);
		line(offx + x[1], offy + y[1] , offx + x[2], offy + y[2]);
		line(offx + x[2], offy + y[2] , offx + x[3], offy + y[3]);
		line(offx + x[3], offy + y[3] , offx + x[4], offy + y[4]);

	}
}
void main()
{
int n, gd, gm;
int x1 = 0, x2 = 550, y1= 0, y2 = 0;
/* Initialise graphics mode
---------------------------------- */
printf("\n Enter the level of curve generation : ");
scanf("%d", &n);
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"\\tc\\bgi");
koch(x1, y1, x2, y2, n);             // Draw Koch curve

getch();
closegraph();
}

```

## 10 To implement program for projection of 3d object on projection Plane


```
#include <stdio.h>
#include <stdlib.h>
#include<graphics.h>
#include<conio.h>
void draw3d(int s,int x[20],int y[20],int d);
void main()
{
	int gd=DETECT,gm;
	int x[20],y[20],i,s,d;
	initgraph(&gd,&gm,"");
	printf("Enter the No of sides : ");
	scanf("%d",&s);
	for(i=0;i<s;i++)
	{
		printf("(x%d,y%d) :",i,i);
		scanf("%d%d",&x[i],&y[i]);
	}
	printf("Depth :");
	scanf("%d",&d);
	draw3d(s,x,y,d);
	getch();
	setcolor(14);
	for(i=0;i<s-1;i++)
	{
		line(x[i]+200,y[i],x[i+1]+200,y[i+1]);
	}
	line(x[i]+200,y[i],x[0]+200,y[0]);
	getch();//top view
	for(i=0;i<s-1;i++)
	{
		line(x[i],300,x[i+1],300);
		line(x[i],300+d*2,x[i+1],300+d*2);
		line(x[i],300,x[i],300+d*2);
		line(x[i+1],300,x[i+1],300+d*2);
	}
	getch();//side view
	for(i=0;i<s-1;i++)
	{
		line(10,y[i],10,y[i+1]);
		line(10+d*2,y[i],10+d*2,y[i+1]);
		line(10,y[i],10+d*2,y[i]);
		line(10,y[i+1],10+d*2,y[i+1]);
	}
	getch();
	closegraph();
}
void draw3d(int s,int x[20],int y[20],int d)
{
	int i,j,k=0;
	for(j=0;j<2;j++)
	{
		for(i=0;i<s-1;i++)
			line(x[i]+k,y[i]-k,x[i+1]+k,y[i+1]-k);
		line(x[i]+k,y[i]-k,x[0]+k,y[0]-k);
		k=d;
	}
	for(i=0;i<s;i++)
		line(x[i],y[i],x[i]+d,y[i]-d);
}
```

<p align="center">|| जय श्री राम || 
</p>

