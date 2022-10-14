# India Flag in Computer Graphics using C

### Problem statement : Write a C program to draw indian Flag using computer graphics

### Code

```
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
  int main()
     {
        int gdriver = DETECT,gmode, a,b,i,r,x,y;

        initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

       //draw the bottom rectangle
        setfillstyle(SOLID_FILL,1);
        rectangle(10,320,200,340);
        floodfill(11,321,15);
        rectangle(30,300,175,320);
        floodfill(31,301,15);
        rectangle(50,280,155,300);
        floodfill(51,281,15);
        //pole
        setfillstyle(SOLID_FILL,3);
        rectangle(100,38,110,280);
        floodfill(101,39,15);
       //draw the top rectangle
        setfillstyle(SOLID_FILL,LIGHTRED);
        rectangle(110,40,220,58);
        floodfill(111,43,15);
        setfillstyle(SOLID_FILL,15);
        rectangle(110,58,220,78);
        floodfill(111,59,15);
        setfillstyle(SOLID_FILL,GREEN);
        rectangle(110,78,220,98);
        floodfill(111,79,15);
       //Ashok chakra
       //
        a=160;
        b=68;
        r=13;
       setcolor(BLUE);
       circle(a,b,r);
       for(i=0;i<=360;i=i+25)
       {
          x=r*cos(i*3.14/180);
          y=r*sin(i*3.14/180);
         line(a,b,a+x,b-y); 
       }
    getch();
    return 0;
   closegraph();
  }
  
  ```
  
  ### Output
![Output](https://cdn.jsdelivr.net/gh/Ajinkgupta/Computer-Graphics@main/India%20flag/outp.png)


[Run this Program](https://onlinegdb.com/k420gwQHo)
