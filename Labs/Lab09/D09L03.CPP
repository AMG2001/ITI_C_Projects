#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <iostream.h>

class GeoShape
{
protected:
    float dim1, dim2;

public:
    GeoShape() { dim1 = dim2 = 0; }
    GeoShape(float x) { dim1 = dim2 = x; }
    GeoShape(float x, float y)
    {
        dim1 = x;
        dim2 = y;
    }
    void setDim1(float x) { dim1 = x; }
    void setDim2(float x) { dim2 = x; }
    float getDim1() { return dim1; }
    float getDim2() { return dim2; }
    float calcArea() { return 0.0; }
};
class Rect : protected GeoShape
{
public:
    Rect() : GeoShape() {}
    Rect(float x, float y) : GeoShape(x, y) {}
    float calcArea()
    {
        return dim1 * dim2;
    }
};
class Square : protected Rect
{
public:


	Square() : Rect() {}

	Square(float x) : Rect(x, x) {}

	void setDim(int x){
	  dim1=dim2=x;
	}

};

class Triangle : protected GeoShape
{
public:
    Triangle() : GeoShape() {}
    Triangle(float b, float h) : GeoShape(b, h) {}
    float calcArea()
    {
        return 0.5 * dim1 * dim2;
    }
};

class Circle : protected GeoShape
{
public:
    Circle() : GeoShape() {}
    Circle(float r) : GeoShape(r) {}
    float calcArea()
    {                                  // it's ok since dim1 equals to dim2.
        return 22.0 / 7 * dim1 * dim2; // you may write: 22.0/7*dim1*dim1.
    }
};
void main()
{
    clrscr();
    Triangle myT(20, 10);
    cout << myT.calcArea() << endl;
    Circle myC;
    myC.setDim1(3);
    myC.setDim2(3);
    cout << myC.calcArea() << endl;
    Rect myR;
    myR.setDim1(3);
    myR.setDim2(3);
    cout << myR.calcArea() << endl;
    Square myS(5);
    cout << myS.calcArea() << endl;
    // What happened if you try:
    myS.setDim2(4); // Violating the Square Constraint
    myC.setDim2(3); // Violating the Circle Constraint
    getch();
}