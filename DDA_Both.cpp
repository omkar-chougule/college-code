#include<iostream>
#include<graphics.h>
using namespace std;

void circle(int r, int xc, int yc){
	int x=0,y=r;
	int d=3-2*r;
	while(x<=y){
		if(d>=0){
			d+=4*(x-y)+10;
			x++;
			y--;
		}
		else if(d<0){
			d+=4*(x)+6;
			x++;
		}
		putpixel(xc+x,yc+y, GREEN);
		putpixel(xc+x,yc-y, GREEN);
		putpixel(xc-x,yc+y, GREEN);
		putpixel(xc-x,yc-y, GREEN);
		putpixel(xc+y,yc+x, GREEN);
		putpixel(xc+y,yc-x, GREEN);
		putpixel(xc-y,yc+x, GREEN);
		putpixel(xc-y,yc-x, GREEN);
		delay(10);
	}
}


void line(int x1 ,int y1, int x2, int y2,char color){
	float xi,yi,xn,yn,dx,dy,step;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>=abs(dy))
		step=abs(dx);
	else
		step=abs(dy);

	xi=dx/step;
	yi=dy/step;
	xn=x1 ; yn=y1;
	for(int i=1 ;i<=step ; i++){
		putpixel(round(xn),round(yn),color);
		xn+=xi;
		yn+=yi;
		delay(5);
	}
}

/*int main(){
	int gd=DETECT,gm;
	int r, xc,yc;
	cout<<"Enter values for xc, yc"<<endl;
	cin>>xc>>yc;
	cout<<"Enter radius of circle"<<endl;
	cin>>r;
	initgraph(&gd,&gm,NULL);
	circle(r,xc,yc);
	line(xc,yc-r,xc+(0.86*r),yc+r*0.5,YELLOW);
	line(xc+(0.86*r),yc+r*0.5,xc-(0.86*r),yc+r*0.5,YELLOW);
	line(xc-(0.86*r),yc+r*0.5,xc,yc-r,YELLOW);
	circle(r/2,xc,yc);
	closegraph();
	return 0;
}*/
int main()
{
int gd = DETECT, gm, error,D1,D2,r;
int x,x1,x2,x3,x4,x5,x6,x7,x8;
int y,y1,y2,y3,y4,y5,y6,y7,y8;
cout<<"Enter co-ordinates of diagonal of Quadrilateral:";
cin>>x1>>y1>>x3>>y3;

x2=x3; y2=y1; x4=x1; y4=y3;

x5=(x1+x2)/2; y5=y1;
x6=x3; y6=(y2+y3)/2;
x7=x5; y7=y3;
x8=x1; y8=y6;

D1=x2-x1;
D2=y4-y1;

x=x5; y=y6;
r=(D1*D2)/(2*(sqrt((D1*D1)+(D2*D2))));

initgraph(&gd, &gm, NULL);
line(x1, y1, x2, y2, WHITE);
line(x2, y2, x3, y3, WHITE);
line(x3, y3, x4, y4, WHITE);
line(x4, y4, x1, y1, WHITE);
line(x5, y5, x6, y6, WHITE);
line(x6, y6, x7, y7, WHITE);
line(x7, y7, x8, y8, WHITE);
line(x8, y8, x5, y5, WHITE);

circle(r,x,y);
getch();
return(0);
}