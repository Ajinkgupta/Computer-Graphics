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

