#include <stdio.h>
#include <iostream.h>
#include <conio.h>

class Point
{
private:
	int x;
	int y;

public:
	Point()
	{
		x = y = 0;
		cout << "Point default constructor is calling" << endl;
	}
	Point(int m)
	{
		x = y = m;
		cout << "Point one parameter constructor is calling" << endl;
	}
	Point(int m, int n)
	{
		x = m;
		y = n;
		cout << "Point two parameter constructor is calling" << endl;
	}
	~Point() { cout << "Point destructor is calling" << endl; }

	void setX(int m)
	{
		x = m;
	}
	void setY(int n)
	{
		y = n;
	}
	void setXY(int m, int n)
	{
		x = m;
		y = n;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	void print() { cout << "\n Point Data : x =" << x << " y =" << y << endl; }
};

class Line
{
private:
	Point start;
	Point end;

public:
	Line() : start(), end()
	{ // start.setXY(0,0); end.setXY(0,0);
		cout << "Line default constructor is calling" << endl;
	}
	Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2)
	{ // start.setXY(x1,y1); end.setXY(x2,y2);
		cout << "Line constructor with 4 parameters is calling" << endl;
	}
	~Line() { cout << "Line destructor is calling" << endl; }
	void print()
	{
		cout << "\nStart :";
		start.print();
		cout << "\nEnd :";
		end.print();
	}
};

class Circle
{
private:
	Point center;
	int rad;

public:
	Circle() : center(), rad(0)
	{ // center.setXY(0,0); rad = 0;
		cout << "Circle default constructor is calling" << endl;
	}
	Circle(int x1, int y1, int r) : center(x1, y1), rad(r)
	{ // center.setXY(x1,y1); rad = 0;
		cout << "Circle constructor with 3 parameters is calling" << endl;
	}
	~Circle() { cout << "Circle destructor is calling" << endl; }
	void print()
	{
		cout << "\ncenter :";
		center.print();
		cout << "\nRadius = " << rad << endl;
	}
};

class Rect
{
private:
	Point UL;
	Point LR;

public:
	Rect() : UL(), LR()
	{ // UL.setXY(0,0); LR.setXY(0,0);
		cout << "Rect default constructor is calling" << endl;
	}
	Rect(int x1, int y1, int x2, int y2) : UL(x1, y1), LR(x2, y2)
	{ // UL.setXY(x1,y1); LR.setXY(x2,y2);
		cout << "Rect constructor with 4 parameter is calling" << endl;
	}
	~Rect() { cout << "Rect destructor is calling" << endl; }
	void print()
	{
		cout << "\nUpper Left :";
		UL.print();
		cout << "\nLower Right :";
		LR.print();
	}
};

class Picture
{
private:
	int cNum;
	int rNum;
	int lNum;
	Circle *pCircles;
	Rect *pRects;
	Line *pLines;

public:
	Picture()
	{
		cNum = 0;
		rNum = 0;
		lNum = 0;
		pCircles = NULL;
		pRects = NULL;
		pLines = NULL;
	}
	Picture(int cn, int rn, int ln, Circle *pC, Rect *pR, Line *pL)
	{
		cNum = cn;
		rNum = rn;
		lNum = ln;
		pCircles = pC;
		pRects = pR;
		pLines = pL;
	}
	void setCircles(int cn, Circle *cptr)
	{
		cNum = cn;
		pCircles = cptr;
	}
	void setRects(int rn, Rect *rptr)
	{
		rNum = rn;
		pRects = rptr;
	}
	void setLines(int ln, Line *lptr)
	{
		lNum = ln;
		pLines = lptr;
	}
	void print()
	{
		int i=0;
		for (i = 0; i < cNum; i++)
		{
			pCircles[i].print();
		}
		for (i = 0; i < rNum; i++)
		{
			pRects[i].print();
		}
		for (i = 0; i < lNum; i++)
		{
			pLines[i].print();
		}
	}
};

void main()
{
	Picture myPic;
	Circle cArr[3] = {Circle(50, 50, 50), Circle(200, 100, 100),
					  Circle(420, 50, 30)};
	Rect rArr[2] = {Rect(30, 40, 170, 100), Rect(420, 50, 500, 300)};
	Line lArr[2] = {Line(420, 50, 300, 300), Line(40, 500, 500, 400)};
	myPic.setCircles(3, cArr);
	myPic.setRects(2, rArr);
	myPic.setLines(2, lArr);
	myPic.print();
	getch();
	
}