#include<stdio.h>
#include<conio.h>
#include<stdlib.h>




void swapByReference(int & num1,int & num2){
    int temp = num1;
    num1=num2;
    num2=temp;
}


void main(){
	int x , y ;
	clrscr();
	cout << "Enter X Value : ";
	cin >> x;
	cout << "Enter y value : ";
	cin >> y;
	swapByReference(x,y);
	cout << "After swapping by Referencing - X = "<< x << " , Y = " << y;
	getch();
}
