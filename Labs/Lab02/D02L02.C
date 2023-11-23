#include<stdio.h>
#include<conio.h>

void main(){
int sum = 0;
int input_number;
clrscr();
while(sum<100){
printf("Enter the Number : ");
scanf("%d",&input_number);
sum+=input_number;
}
printf("Sum Exceeded 100 with value : %d",sum);
getch();
}