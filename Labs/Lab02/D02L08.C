#include <stdio.h>
#include <conio.h>

int temp = 1, x, y, rindex, cindex, value,rsum=0,cavg=0;
int arr[3][4];
void drawHeaderMatrix()
{
	// draw upper header .
	for (x = 20; x <= 40; x += 5)
	{
		if(temp==5){
		//x+=5;
		gotoxy(x, 10);
		printf("Sum");
		gotoxy(x, 11);
		printf("*");
		}else{
		gotoxy(x, 10);
		printf("%d", temp);
		gotoxy(x, 11);
		printf("*");
		temp++;
		}
	}
	temp = 1;
	// draw left Header
	for (y = 12; y <= 18; y += 2)
	{
		if(temp==4){
	   //	y+=2;
		gotoxy(14,y);
		printf("Avg*") ;
		}else{
		gotoxy(16, y);
		printf("%d*", temp);
		temp++;
		}
	}
	temp = 1;
}

void resetX()
{
	x = 20;
}

void resetY()
{
	y = 12;
}

void readNumbersFromUser()
{
	x = 20;
	y = 13;
	for (rindex = 0; rindex < 3; rindex++)
	{
		for (cindex = 0; cindex < 4; cindex++)
		{
			switch (rindex)
			{
			case 0:
				gotoxy(x, 12);
				x += 5;
				break;
			case 1:
				gotoxy(x, 14);
				x += 5;
				break;
			case 2:
				gotoxy(x, 16);
				x += 5;
				break;
			}

			scanf("%d", &value);
			arr[rindex][cindex] = value;
		}
		resetX();
	}
}

void calculateAvgAndSum(){

for(rindex=0;rindex<3;rindex++){

		rsum=0;

		for(cindex=0;cindex<4;cindex++){
			rsum+=arr[rindex][cindex];
		}
		if(rindex==0) gotoxy(40,12);
		else if(rindex==1)gotoxy(40,14);
		else if(rindex==2)gotoxy(40,16);
		printf("%d",rsum);
	}

	 for(cindex=0;cindex<4;cindex++){
		for(rindex=0;rindex<3;rindex++){
			cavg+=arr[rindex][cindex];
		}
	   if(cindex==0)gotoxy(20,18);
	   else if(cindex==1)gotoxy(25,18);
	   else if(cindex==2)gotoxy(30,18);
	   else if(cindex==3)gotoxy(35,18);
	   printf("%d",cavg/3);
	 cavg=0.0;
	 }
}



void main()
{
	clrscr();
	drawHeaderMatrix();
	readNumbersFromUser();
	calculateAvgAndSum();
	getch();
}
