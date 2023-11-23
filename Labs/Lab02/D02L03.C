#include<stdio.h>
#include<conio.h>

void main(){
int option;
clrscr();
printf("Chooce any option :\n1. Option 1.\n2. Option 2.\n3. Option3\n");
scanf("%d",&option);
switch(option){
case 1:
printf("Option 1 Choosed\n");
break;
case 2:
printf("Option 2 Choosed\n");
break;
case 3:
printf("Option 3 Choosed");
break;

}
getch();
}