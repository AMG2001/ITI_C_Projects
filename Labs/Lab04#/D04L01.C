#include<stdio.h>
#include<conio.h>
#include<stdlib.h>




void swapByAdderss(int * num1,int * num2){
    int temp = *num1;
    *num1=*num2;
    *num2=temp;
}


void main(){
	int x , y ;
	clrscr();
	printf("Enter X Value : ");
	scanf("%d",&x);
	printf("Enter y value : ");
	scanf("%d",&y);
	swapByAdderss(&x,&y);
	printf("After swapping - X = %d , Y = %d",x,y);
	getch();
}
