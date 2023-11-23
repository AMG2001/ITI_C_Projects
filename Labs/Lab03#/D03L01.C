#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Define some Colors :
#define BLACK 0
#define WHITE 15
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80
#define KEY_ENTER 13
#define ESC 27
typedef struct Employee
{
    int id;
    char name[20];
    int salary;
    int bouns;
    int deduct;
} Employee;

struct Employee empList[5];

int selectedOption = 1, enteredEmp = 0,totalEnteredEmp=0;

// this function rule is only draw the boundaries of the menu.
void drawCustomFrame(int rows_number, int cols_number)
{
	int i = 0, j = 0, col = cols_number, row = rows_number;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (i == 0 || i == row - 1 || j == 0 || j == col - 1)
			{
				gotoxy(j + col - 4, i + row);
				printf("*");
			}
		}
	}
}

// this function is used to show New, Display, and Exit Options inside the Square.
void showMenuItems(int option)
{
	int counter = 2, col = 25, row = 10;
	clrscr();
	drawCustomFrame(row, col);
	gotoxy(col - 3, row + 1);
	printf("Choose Option :");
	for (counter = 2; counter <= 6; counter += 2)
	{
		gotoxy(col + 4, row + counter + 1);
		if (counter == 2)
		{
			if (selectedOption == 1)
			{
				textcolor(BLACK);
				textbackground(WHITE);
			}
			else
			{
				textcolor(WHITE);
				textbackground(BLACK);
			}
			cprintf("New    ");
		}
		if (counter == 4)
		{
			if (selectedOption == 2)
			{
				textcolor(BLACK);
				textbackground(WHITE);
			}
			else
			{
				textcolor(WHITE);
				textbackground(BLACK);
			}
			cprintf("Display");
		}
		if (counter == 6)
		{
			if (selectedOption == 3)
			{
				textcolor(BLACK);
				textbackground(WHITE);
			}
			else
			{
				textcolor(WHITE);
				textbackground(BLACK);
			}
			cprintf("Exit   ");
		}
	}
}

void showMenu()
{
	showMenuItems(selectedOption);
}

void showInsertFields()
{
	int index = 0;
	if (enteredEmp < 5)
	{
		drawCustomFrame(12, 30);
		gotoxy(28, 13 + index * 2);
		printf("Enter emp nom.%d", enteredEmp);

		for (index = 0; index <= 4; index++)
		{
			gotoxy(28, 13 + index * 2);
			switch (index)
			{
			case 0:
				printf("Enter emp Name :");
				break;
			case 1:
				printf("Enter emp ID :");
				break;
			case 2:
				printf("Emp Salary :");
				break;
			case 3:
				printf("Emp Bouns :");
				break;
			case 4:
				printf("Emp Deduct :");
				break;
			}
		}

		index = 0;
		gotoxy(45, 13 + index * 2);
		scanf(" %[^\n]s", &empList[enteredEmp].name);
		index++;
		gotoxy(45, 13 + index * 2);
		scanf(" %d", &empList[enteredEmp].id);
		index++;
		gotoxy(45, 13 + index * 2);
		scanf(" %d", &empList[enteredEmp].salary);
		index++;
		gotoxy(45, 13 + index * 2);
		scanf(" %d", &empList[enteredEmp].bouns);
		index++;
		gotoxy(45, 13 + index * 2);
		scanf(" %d", &empList[enteredEmp].deduct);
		enteredEmp++;
		index = 0;
		clrscr();
		totalEnteredEmp++;
	}
	showMenu();
}

void showInsertPanel()
{
	drawCustomFrame(12, 30);
	showInsertFields();
}

void showDisplayPanel() {
  if (totalEnteredEmp!=0) {
	int i = 0;
	for (i = 0 ; i < totalEnteredEmp ; i++) {
	  // drawCustomFrame(12, 30);
	  gotoxy(28, 11 + i * 2);
	  printf("EMP Number %d", i + 1);
	  gotoxy(28, 12 + i * 2);
	  printf("Enter emp Name : %s", empList[i].name);
	  gotoxy(28, 13 + i * 2);
	  printf("Enter emp ID : %d", empList[i].id);
	  gotoxy(28, 14 + i * 2);
	  printf("Emp Salary : %d", empList[i].salary);
	  gotoxy(28, 15 + i * 2);
	  printf("Emp Bouns : %d", empList[i].bouns);
	  gotoxy(28, 16 + i * 2);
	  printf("Emp Deduct : %d", empList[i].deduct);
	  getch();
	  clrscr();
	}
  } else {
	printf("Employee list is empty.\n");
  }
}


void handleUserInputInMenu()
{
	char key;
	key = getch();
	switch (key)
	{
	case KEY_UP:
		if (selectedOption == 1)
			selectedOption = 3;
		else
			selectedOption -= 1;
		break;
	case KEY_DOWN:
		if (selectedOption == 3)
			selectedOption = 1;
		else
			selectedOption += 1;
		break;
	case KEY_ENTER:
		if (selectedOption == 1)
		{
			clrscr();
			showInsertPanel();
			getch();
		}
		else if (selectedOption == 2)
		{
			clrscr();
			showDisplayPanel();
			getch();
		}
		else if (selectedOption == 3)
		{
			exit(0);
		}
		break;
	case ESC:
		exit(0);
		break;
	}
	showMenuItems(selectedOption);
}

void main()
{
	int app_running = 1;
	clrscr();
	while (app_running)
	{
		showMenu();
		handleUserInputInMenu();
	}
    getch();
}
