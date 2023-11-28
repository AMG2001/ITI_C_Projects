#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream.h>

// Define some Colors :
#define BLACK 0
#define WHITE 15
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80
#define KEY_ENTER 13
#define ESC 27

int selectedOption = 1, enteredEmp = 0, totalEnteredEmp = 0, sizeOfEmpArray;

class Employee
{
public:
    int id;
    char name[20];
    int salary;
    int bouns;
    int deduct;
    Employee() {}
};

Employee *empArray = new Employee[1];
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
                gotoxy(j + col - 3, i + row - 6);
                printf("*");
            }
        }
    }
}

// this function is used to show New, Display, and Exit Options inside the Square.
void showMenuItems(int option)
{
    int counter = 2, col = 25, row = 13;
    clrscr();
    drawCustomFrame(row, col);
    gotoxy(col - 2, row - 5);
    printf("Choose Option :");
    for (counter = 2; counter <= 10; counter += 2)
    {
        gotoxy(col + 5, row + counter - 5);
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
            cprintf("Search  ");
        }
        if (counter == 8)
        {
            if (selectedOption == 4)
            {
                textcolor(BLACK);
                textbackground(WHITE);
            }
            else
            {
                textcolor(WHITE);
                textbackground(BLACK);
            }
            cprintf("Delete  ");
        }
        if (counter == 10)
        {
            if (selectedOption == 5)
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

/**
 * *************** Function that show insert fields as :
 * 1. Name
 * 2. id
 * 3. salary .....
 */
void showInsertFields()
{
    int index = 0;
    if (enteredEmp < sizeOfEmpArray)
    {
        drawCustomFrame(12, 30);
        gotoxy(28, 5);
        printf("Enter emp nom.%d", enteredEmp+1);
        for (index = 0; index <= 4; index++)
        {
            gotoxy(28, 7 + index * 2);
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
        gotoxy(45, 7 + index * 2);
        scanf(" %[^\n]s", empArray[enteredEmp].name);
        index++;
        gotoxy(45, 7 + index * 2);
        cin >> empArray[enteredEmp].id;
        index++;
        gotoxy(45, 7 + index * 2);
        cin >> empArray[enteredEmp].salary;
        index++;
        gotoxy(45, 7 + index * 2);
        cin >> empArray[enteredEmp].bouns;
        index++;
        gotoxy(45, 7 + index * 2);
        cin >> empArray[enteredEmp].deduct;
        enteredEmp++;
        index = 0;
        clrscr();
        totalEnteredEmp++;
    }
    showMenu();
}

/**
 * Just to show Frame and Insert Field
 */
void showInsertPanel()
{
    drawCustomFrame(12, 30);
    showInsertFields();
}

void showSearchPage()
{
    char c, name[20];
    clrscr();
    gotoxy(15, 12);
    cout << "want to search with name {n} or id {i} ? ";
    cin >> c;
    if (c == 'n')
    {
        int found = 0;
        clrscr();
        cout << "Enter Name of Emp you are looking for : ";
        cin >> name;
        for (int i = 0; i < enteredEmp; i++)
        {
            if (strcmp(empArray[i].name,name)==0)
            {
				cout << "Name is Found #"<<endl;
				cout << "Name is : " << empArray[i].name<<endl;
				cout << "ID is : " << empArray[i].id<<endl;
				cout << "Salary is : " << empArray[i].salary<<endl;
				found = 1;
				break;
			}
		}
		if (!found)
		{
			cout << "Sorry but the name is Not Found !!";
		}
		getch();
	}
	else if (c == 'i')
	{
		int id;
		int found = 0;
		clrscr();
		cout << "Enter ID of Emp you are looking for : ";
		cin >> id;
		for (int i = 0; i < enteredEmp; i++)
		{
			if (empArray[i].id == id)
			{
				cout << "ID is Found #"<<endl;
				cout << "Name is : " << empArray[i].name<<endl;
				cout << "ID is : " << empArray[i].id<<endl;
				cout << "Salary is : " << empArray[i].salary<<endl;
				found = 1;
				break;
			}
		}
		if (!found)
		{
			cout << "Sorry but the name is Not Found !!";
		}
		getch();
	}
	else
	{
		gotoxy(15, 14);
		printf("Invalid character !!  , press to start again ->");
		getch();
		showSearchPage();
	}
}

/**
 * ************************* Delete Functions ******************************
 */
// delete with name functionality .
void showDeleteWithNamePage()
{
    char name[20];
    gotoxy(15, 14);
    int isFound = 0;
    cout << "enter the name you want to delete : ";
    cin >> name;
    cout << endl;
    for (int i = 0; i < sizeOfEmpArray; i++)
    {
        if (strcmp(name, empArray[i].name) == 0)
        {
            isFound = 1;
            for (int j = i; j <= sizeOfEmpArray - 1; j++)
            {
                empArray[j] = empArray[j + 1];
            }
            cout << "Name Deleted Successfully #";
            // decrement number of empArray in system .
            totalEnteredEmp--;
            enteredEmp = totalEnteredEmp;

            getch();
            break;
        }
    }
    if (isFound == 0)
    {
        cout << "Name is not Exist !! ";
        getch();
    }
}

// delete with id functionality .
void showDeleteWithIdPage()
{
    int id;
    gotoxy(15, 14);
    int isFound = 0;
    cout << "enter the id you want to delete : ";
    cin >> id;
    cout << endl;
    for (int i = 0; i < sizeOfEmpArray; i++)
    {
        if (id == empArray[i].id)
        {
            isFound = 1;
            for (int j = i; j <= sizeOfEmpArray - 1; j++)
            {
                empArray[j] = empArray[j + 1];
            }
            cout << "Employee with id" << id << "Deleted Successfully #";
            // decrement number of empArray in system .
            totalEnteredEmp--;
            enteredEmp = totalEnteredEmp;
            getch();
            break;
        }
    }
    if (isFound == 0)
    {
        cout << "Name is not Exist !! ";
        getch();
    }
}

// show delete page with 2 options : delete with name or delete with id .
void showDeletePage()
{
    char c;
    clrscr();
    gotoxy(15, 12);
    cout << "want to delete with name {n} or id {i} ? ";
    cin >> c;
    if (c == 'n' || c == 'N')
    {
        showDeleteWithNamePage();
    }
    else if (c == 'i' || c == 'I')
    {
        gotoxy(15, 14);
        showDeleteWithIdPage();
        getch();
    }
    else
    {
        clrscr();
        gotoxy(15, 12);
        cout << "Invalid character !!  , press any button to start again ->";
        getch();
        showDeletePage();
    }
}

/**
 * Show display Employees panel "Square that contain all Emp's with their data".
 */
void showDisplayPanel()
{
    if (totalEnteredEmp != 0)
    {
        int i = 0;
        for (i = 0; i < totalEnteredEmp; i++)
        {
            int y = 8;
            drawCustomFrame(15, 30);
            gotoxy(28, y);
            printf("EMP Number %d", i + 1);
            gotoxy(28, y + 2);
            printf("Enter emp Name : %s", empArray[i].name);
            gotoxy(28, y + 4);
            printf("Enter emp ID : %d", empArray[i].id);
            gotoxy(28, y + 6);
            printf("Emp Salary : %d", empArray[i].salary);
            gotoxy(28, y + 8);
            printf("Emp Bouns : %d", empArray[i].bouns);
            gotoxy(28, y + 10);
            printf("Emp Deduct : %d", empArray[i].deduct);
            getch();
            clrscr();
        }
    }
    else
    {
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
            selectedOption = 5;
        else
            selectedOption -= 1;
        break;
    case KEY_DOWN:
        if (selectedOption == 5)
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
            showSearchPage();
        }
        else if (selectedOption == 4)
        {
            showDeletePage();
        }
        else if (selectedOption == 5)
        {
            free(empArray);
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
    // ask for the size of empArray array you want to allocate .
    cout << "Before starting the program , enter the number of the EMP's : ";
    cin >> sizeOfEmpArray;
    empArray = new Employee[sizeOfEmpArray];
    while (app_running)
    {
        showMenu();
        handleUserInputInMenu();
    }
    getch();
}
