#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

void secHand();
void minHand();
void hrHand();

void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c:\\turboc3\\bgi");
 
 while(1)
 {
  setcolor(WHITE);
  circle(300,220,120);           /*layout of circle */
  setcolor(RED);
  circle(300,220,115);
  setcolor(BLUE);
  circle(300,220,125);
  pieslice(300,220,0,360,5);     /* displaying a circle in the middle of clock */
  secHand();
  hrHand();
  minHand();
  sleep(1);                       /* to pause the screen for 1 sec */
  cleardevice();
 }
}


void secHand()
{
 struct time t;
 int r=90,x=300,y=220,sec;
 float O;
 gettime(&t);
 sec=t.ti_sec;
 O=sec*(3.14/30)-(3.14/2);
 setcolor(YELLOW);
 line(300,220,x+r*cos(O),y+r*sin(O));
}

void minHand()
{
 int r=70,min;
 int x=300,y=220;
 float O;
 struct time t;
 gettime(&t);                       /*getting the seconds in system clock */
 min=t.ti_min;
 O=min*(3.14/30)-(3.14/2);        /* determining the angle of the line with respect to vertical */
 setcolor(RED);
 line(300,220,x+r*cos(O),y+r*sin(O));
}

void hrHand()
{
 int r=60,hr,min;
 int x=300,y=220;
 struct time t;
 float O;
 gettime(&t);                     /*getting the seconds in system clock */
 hr=t.ti_hour;
 min=t.ti_min;
 if(hr<=12)
 {
  O=hr*(3.14/6)-(3.14/2)+(min/12)*(3.14/30);
 }
 if(hr>12)
 {
  O=(hr-12)*(3.14/6)-(3.14/2)+(min/12)*(3.14/30);
 }
 setcolor(WHITE);
 line(300,220,x+r*cos(O),y+r*sin(O));
}
