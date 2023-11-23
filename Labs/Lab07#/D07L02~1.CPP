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
    /**
     * Operators overload
     */

    Complex operator+(Complex &x);
    Complex operator-(Complex &x);
    Complex operator+(float f);
    friend Complex operator+(float f, Complex &x);
    friend istream &operator>>(istream &in, Complex &c);
	friend ostream &operator<<(ostream &out, Complex &c);

    Complex operator++()
    { // prefix
        real++;
        imag++;
        return *this;
    }
    Complex operator--()
    { // prefix
        real--;
        imag--;
        return *this;
    }
    Complex operator++(int dumy)
    { // postfix
        Complex temp(*this);
        real++;
		imag++;
		return temp;
	}
	Complex operator--(int dumy)
	{ // postfix
		Complex temp(*this);
		real--;
		imag--;
		return temp;
	}
	Complex &operator=(Complex &c)
	{
		real = c.real;
		imag = c.imag;
		return *this;
	}
	Complex &operator+=(Complex &c)
	{
		real += c.real;
		imag += c.imag;
		return *this;
	}
	Complex &operator-=(Complex &c)
	{
		real -= c.real;
		imag -= c.imag;
		return *this;
	}
	int operator==(Complex &c)
	{
		return (real == c.real && imag == c.imag);
	}
	int operator!=(Complex &c)
	{
		return (real != c.real || imag != c.imag);
	}
	operator float()
	{
		return sqrt(real * real + imag * imag);
	}
	
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

    void setAll();                 // setting both of real and imag with 0
    void setAll(float f);          // setting both of real and imag with f
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

Complex Complex::operator+(Complex &x) {
    float newReal = real + x.real;
    float newImag = imag + x.imag;
    return Complex(newReal, newImag);
}

Complex Complex::operator-(Complex &x) {
    float newReal = real - x.real;
    float newImag = imag - x.imag;
    return Complex(newReal, newImag);
}

Complex Complex::operator+(float f) {
    float newReal = real + f;
    return Complex(newReal, imag);
}
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

Complex operator+(float f, Complex &x)
{
    return Complex(x.real + f, x.imag);
    // Complex temp(f+x.real,x.img);
    // return temp;
}

istream &operator>>(istream &in, Complex &c)
{
    cout << "\nEnter real part: ";
    in >> c.real;
    cout << "Enter img part: ";
    in >> c.imag;
    return in;
}
ostream &operator<<(ostream &out, Complex &c)
{
    if (c.imag < 0)
        out << c.real << " - " << fabs(c.imag) << "i" << endl;
    else
		out << c.real << " + " << c.imag << "i" << endl;
    return out;
}

void main()
{
    clrscr();
    Complex c1(12, 7), c2(10, -5), c3;
    c3 = c1 + c2;
    c3.print();
    c3 = c1 + 13.65;
    c3.print();
    c3 = 6.2 + c2;
    c3.print();
    c3 = ++c1;
    c1.print();
    c3.print();
    c3 = c2++;
    c2.print();
    c3.print();
    c3 = c1;
    c1.print();
    c3.print();
    c2 = c1 = c3;
    c1.print();
    c2.print();
    c3.print();
    cin>>c1;
    cout<<"C1 is : "<<c1;
    getch();
}