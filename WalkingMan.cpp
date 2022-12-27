#include<iostream>
#include<graphics.h>
#include<math.h>
void man()
{    
int i,j,x,y,getmaxx();
    for(i=0;i<getmaxx()-140;i++)
    {
    delay(5);
    cleardevice();
    line(0,450,getmaxx(),450);
    rectangle(10+i,400,50+i,340);
    line(15+i,400,45+i,450);
    line(45+i,400,15+i,450);
    circle(30+i,330,10);
    line(30+i,350,70+i,390);
    line(50+i,370,70+i,350);
    line(70+i,350,70+i,310);
    line(0+i,310,140+i,310);
    arc(70+i,310,180,0,70);
    for(j=0;j<100;j++)
    {
    x=rand()%getmaxx();
    y=rand()%getmaxy();
    line(x,y,x+4,y+4);
    }
}
}
int main()
{
 int gd=DETECT, gm;
    initgraph(&gd,&gm,NULL);
    man();
    delay(10000);
    closegraph();
    return 0;
}