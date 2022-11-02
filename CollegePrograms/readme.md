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
