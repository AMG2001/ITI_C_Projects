#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>

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

Complex Complex::operator+(Complex &x)
{
    float newReal = real + x.real;
    float newImag = imag + x.imag;
    return Complex(newReal, newImag);
}

Complex Complex::operator-(Complex &x)
{
    float newReal = real - x.real;
    float newImag = imag - x.imag;
    return Complex(newReal, newImag);
}

Complex Complex::operator+(float f)
{
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

int seqSearchForComplex(Complex *arr, Complex c)
{
    int found = -1;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i].getReal() == c.getReal() && arr[i].getImag() == c.getImag())
        {
            found = i;
            break;
        }
    }
    return found;
}

int binSearchForComplex(Complex *ptr, Complex c)
{
    int Lo = 0, Hi = 4, Mid;
    while (Hi >= Lo)
    {
        Mid = (Lo + Hi) / 2;
        if (ptr[Mid].getReal() == c.getReal() && ptr[Mid].getImag() == c.getImag())
            return Mid;
        else if (ptr[Mid].getReal() < c.getReal() || (ptr[Mid].getReal() == c.getReal() && ptr[Mid].getImag() < c.getImag()))
            Lo = Mid + 1;
        else
            Hi = Mid - 1;
    }
    return -1;
}

void main()
{
    clrscr();
    int real, img;
    Complex arr[5] = {Complex(), Complex(2), Complex(2, 4), Complex(2, 5), Complex(5, 7)};
    char option;
    cout << "you want to search with seq search {s} or binary search {b} ? ";
    cin >> option;
    /**
     * Sequntial Search Block .
     */
    if (option == 's')
    {
        cout << "enter the real number : ";
        cin >> real;
        cout << "enter imag number : ";
        cin >> img;
        Complex comp = Complex(real, img);
        int found = seqSearchForComplex(arr, comp);
        if (found == -1)
            cout << "The Complex number you are looking for is not found !!";
        else
            cout << "The complex you are looking for exist at index : " << found;
    }
    /**
     * Binary Search Block .
     */
    else if (option == 'b')
    {
        cout << "enter the real number : ";
        cin >> real;
        cout << "enter imag number : ";
        cin >> img;
        Complex comp = Complex(real, img);
        int found = binSearchForComplex(arr, comp);
        if (found == -1)
            cout << "The Complex number you are looking for is not found !!";
        else
            cout << "The complex you are looking for exist at index : " << found;
    }
    else
    {
        cout << "Invalid Character , restart the program !!";
    }
    getch();
}