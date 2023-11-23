#include <iostream.h>
#include <conio.h>
#include <string.h>

class Emp
{
public:
    char *name;
    int age;
    Emp()
    {
        name = new char[20];
        age = 0;
    }
    Emp(char *name, int age)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
    }
};

class Sorting
{
public:
    void swap(Emp &x, Emp &y)
    {
        Emp temp = x;
        x = y;
        y = temp;
    }

    void selectionSortWithName(Emp data[], int size)
    {
        int i, j, index = 0;

        for (i = 0; i < size - 1; i++, index = i) // Number of stages
        {
            for (j = i + 1; j < size; j++) // Number of comparisons
                if (strcmp(data[index].name, data[j].name) > 0)
                    index = j;
            swap(data[i], data[index]);
        }
    }

    void selectionSortWithAge(Emp data[], int size)
    {
        int i, j, index = 0;

        for (i = 0; i < size - 1; i++, index = i) // Number of stages
        {
            for (j = i + 1; j < size; j++) // Number of comparisons
                if (strcmp(data[index].age data[j].name) > 0)
                    index = j;
            swap(data[i], data[index]);
        }
    }
};

void displayAllEmp(Emp *empArr, int numberOfEmp)
{
    cout << endl;
    for (int i = 0; i < numberOfEmp; i++)
    {
        cout << "Emp number : " << i + 1 << " [ Name : " << empArr[i].name << " ] - age : " << empArr[i].age << endl;
    }
}

int main()
{
    int numberOfEmp = 4;

    Emp empArr[] = {Emp("Amgad", 22), Emp("Marwan", 27), Emp("Eman", 25), Emp("Omar", 19)};
    char choice;
    clrscr();
    cout << "Want to show Employees sorted by name {n} or age {a} ? ";
    cin >> choice;
    displayAllEmp(empArr, numberOfEmp);
    if (choice == 'n')
    {
        cout << "Using Selection sort to sort emp depending on Names #";
        Sorting s;
        s.selectionSortWithName(empArr, numberOfEmp);
        displayAllEmp(empArr, numberOfEmp);
    }
    else if (choice == 'a')
    {
        cout << "Using Selection sort to sort emp depending on Ages #";
        Sorting s;
        s.selectionSortWithName(empArr, numberOfEmp);
        displayAllEmp(empArr, numberOfEmp);
    }
    else
    {
        cout << "You entered wrong character - Restart the program please !";
    }
    getch();
    return 0;
}
