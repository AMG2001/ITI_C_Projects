#include <iostream.h>
#include <conio.h>
#include <string.h>

class Sorting
{
public:
    void swap(char **x, char **y)
    {
        char *temp = *x;
        *x = *y;
        *y = temp;
    }

    void selectionSort(char *data[], int size)
    {
        int i, j, index = 0;

        for (i = 0; i < size - 1; i++, index = i) // Number of stages
        {
            for (j = i + 1; j < size; j++) // Number of comparisons
                if (strcmp(data[index], data[j]) > 0)
                    index = j;
            swap(&data[i], &data[index]);
        }
    }
    void displayStrArrayContent(char *arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    clrscr();
    char* strArray[] = {"Amgad", "Ahmad", "Ali", "Asmaa", "Osama"};
    Sorting s;
    s.selectionSort(strArray, 5);
    cout << "Strings in Sorted Order : ";
    s.displayStrArrayContent(strArray, 5);
    getch();
    return 0;
}
