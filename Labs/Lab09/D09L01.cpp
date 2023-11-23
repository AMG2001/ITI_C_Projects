#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <iostream.h>

class Base
{
protected: // first, the student should try it as private
    int a;
    int b;

public:
    Base()
    {
        a = b = 0;
    }
    Base(int n)
    {
        a = b = n;
    }
    Base(int x, int y)
    {
        a = x;
        b = y;
    }
    void setA(int x)
    {
        a = x;
    }
    void setB(int y)
    {
        b = y;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
    int calculateSum()
    {
        return a + b;
    }
};

class Derived : public Base
{
private:
    int c;

public:
    Derived() : Base()
    {
        c = 0;
    }
    Derived(int n) : Base(n)
    {
        c = n;
    }
    Derived(int x, int y, int z) : Base(x, y)
    {
        c = z;
    }
    void setC(int z)
    {
        c = z;
    }
    int getC()
    {
        return c;
    }
    int calculateSum() // overriding
    {
        return a + b + c; // only if "a" and "b" were protected,
        // or use getters if it is private
        // other implementation ideas:
        // return Base::calculateSum() + c ;
    }
};

void main()
{
    clrscr();
    Base b(5, 4);
    cout << b.calculateSum() << endl;
    Derived obj1;
    obj1.setA(3);
    obj1.setB(7);
    obj1.setC(1);
    Derived obj2(20);
    Derived obj3(4, 5, 6);
    cout << "obj1: " << obj1.calculateSum() << endl;       // =11
    cout << "obj2: " << obj2.calculateSum() << endl;       // =60
    cout << "obj3: " << obj3.calculateSum() << endl;       // =15
    cout << "obj1: " << obj1.Base::calculateSum() << endl; // only =10

    getch();
}