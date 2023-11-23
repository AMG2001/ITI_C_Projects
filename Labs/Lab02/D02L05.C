#include<stdio.h>
#include<conio.h>

void main(){
int i,j,number,number1,number2;
int cindex=1;
	clrscr();
	number=10;
	// Print Upper Header .
	for(i=1;i<=10;i++){
		gotoxy(i*5+10,5);
		printf("%d",number);
		gotoxy(i*5+10,6);
		printf("*");
		number--;
	}
	number=10;
	// print left Header .
	for(i=1;i<=10;i++){
	gotoxy(10,i*2+5);
	printf("%d *",number);
	number--;
	}
	number1=10;
	number2=10;

	// loop to print values inside the table .
	for(i=1;i<=10;i++){
		for(j=1;j<=10;j++){
			gotoxy(i*5+10,j*2+5);
			printf("%d",number1*number2);
			number1--;
		}
		number1=10;
		number2--;
	}
	getch();
}