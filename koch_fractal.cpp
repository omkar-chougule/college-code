#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void koch(int x1, int y1, int x2, int y2, int it)
{
	float angle = 60 * 3.14 / 180;
	int x3 = (2 * x1 + x2) / 3;
	int y3 = (2 * y1 + y2) / 3;

	int x4 = (x1 + 2 * x2) / 3;
	int y4 = (y1 + 2 * y2) / 3;

	int x = x3 + (x4 - x3) * cos(angle) + (y4 - y3) * sin(angle);
	int y = y3 - (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle);

	if (it > 0)
	{
		koch(x1, y1, x3, y3, it - 1);
		koch(x3, y3, x, y, it - 1);
		koch(x, y, x4, y4, it - 1);
		koch(x4, y4, x2, y2, it - 1);
	}
	else
	{
		line(x1, y1, x3, y3);
		line(x3, y3, x, y);
		line(x, y, x4, y4);
		line(x4, y4, x2, y2);
	}

}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	int n;int it;
	int x1,y1,x2,y2;
	cout<<"Enter the value for x1,y1:";
	cin>>x1>>y1;
	cout<<"Enter the value for x2,y2:";
	cin>>x2>>y2;
	
	//float angle = 60 * 3.14 / 180;
	//int x3 = x1 + (x2 - x1) * cos(angle) + (y2 - y1) * sin(angle);
	//int y3 = y1 - (x2 - x1) * sin(angle) + (y2 - y1) * cos(angle);

	cout << "enter the iteration you want:" << endl;
	cin >> n;

	koch(x1, y1, x2, y2, n);
	//koch(x3, y3, x2, y2,n);
	//koch(x1, y1, x3, y3,n);
	//koch(x2, y2, x1, y1,n);
	
	delay(10000);
	closegraph();
	return 0;

}