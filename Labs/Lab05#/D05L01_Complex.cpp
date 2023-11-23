#include <iostream.h>
#include <math.h>
#include <conio.h>

class Complex {
  private:
	float real;
	float imag;
  public:
	Complex(){
		real =0;
		imag = 0;
	}
	Complex(float r){
		real = r;
		imag =r;
	}
	Complex(float r, float i){
		real = r ;
		imag =i;
	}
	~Complex(){
		cout<<"\n Destructor is calling";
	}
	void setReal(float r) {
		real = r ;
	}
	void setImag(float i) {
		imag = i;
	}
	float getReal() {
		return real;
	}
	float getImag() {
		return imag;
	}
	Complex add(Complex c){
		Complex temp;
		temp.real = real + c.real;
		temp.imag = imag + c.imag;
		return temp;
	}
	Complex sub(Complex c){
		Complex temp;
		temp.real = real - c.real;
		temp.imag = imag - c.imag;
		return temp;
	}
	void print(){
		if(imag<0){
			cout<<real<<" - "<<fabs(imag)<<"i"<<endl;
		}
		else{
			cout<<real<<" + "<<imag<<"i"<<endl;
		}
	}
};

int main() {
	Complex myComp1, myComp2(3, 4), resultComp(5) ;
	clrscr();
	myComp1.setReal(7) ;
	myComp1.setImag(2) ;
	resultComp = myComp1.add(myComp2) ;
	resultComp.print() ;
	resultComp = myComp1.sub(myComp2) ;
	resultComp.print() ;
	getch();
	return 0;
}