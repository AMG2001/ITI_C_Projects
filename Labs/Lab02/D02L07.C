#include<stdio.h>
#include<conio.h>

void main(){
	int min,max,index=0;
	int numbers[]={8,2,11,1,10,4,9,7,3,12,6,5};

	clrscr();

	min=numbers[0];

	max=numbers[0];

	for(index=0;index<12;index++){
		if(max<numbers[index])
			max = numbers[index];

		if(min>numbers[index])
			min = numbers[index];

	}
	printf("Smallest Number : %d",min);

	printf("\nLargest Number : %d",max);

	getch();

}