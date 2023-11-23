#include <iostream.h>
#include <math.h>
#include <conio.h>

class Complex
{
private:
	float real;
	float imag;

public:
	Complex();
	Complex(float r);
	Complex(float r, float i);
	// Destructor .
	~Complex()
	{
		cout << "\n Destructor is calling";
	}
	void setReal(float r);
	void setImag(float i)
	{
		imag = i;
	}
	float getReal();
	float getImag();
	Complex add(Complex c);
	Complex sub(Complex c);
	void setAll();				   // setting both of real and imag with 0
	void setAll(float f);		   // setting both of real and imag with f
	void setAll(float r, float i); // setting real and imag with r & i
	void print()
	{
		if (imag < 0)
		{
			cout << real << " - " << fabs(imag) << "i" << endl;
		}
		else
		{
			cout << real << " + " << imag << "i" << endl;
		}
	}
};

void Complex::setAll()
{
	real = imag = 0;
}
void Complex::setAll(float f)
{
	real = f;
	imag = f;
}
void Complex::setAll(float r, float i)
{
	real = r;
	imag = i;
}
Complex::Complex()
{
	real = 0;
	imag = 0;
}
Complex::Complex(float r)
{
	real = r;
	imag = r;
}
Complex::Complex(float r, float i)
{
	real = r;
	imag = i;
}
void Complex ::setReal(float r)
{
	real = r;
}
float Complex::getReal()
{
	return real;
}
float Complex::getImag()
{
	return imag;
}
Complex Complex::add(Complex c)
{
	Complex temp;
	temp.real = real + c.real;
	temp.imag = imag + c.imag;
	return temp;
}
Complex Complex::sub(Complex c)
{
	Complex temp;
	temp.real = real - c.real;
	temp.imag = imag - c.imag;
	return temp;
}

int main()
{
	Complex myComp1, myComp2(3, 4), resultComp(5);
	clrscr();
	myComp1.setReal(7);
	myComp1.setImag(2);
	resultComp = myComp1.add(myComp2);
	resultComp.print();
	resultComp = myComp1.sub(myComp2);
	resultComp.print();
	getch();
	return 0;
}