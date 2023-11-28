#include <conio.h>
#include <iostream.h>

class Searching
{
    int intSequntialSearch(int *arr)
    {
        int found = 0,key;
        cout << "Enter the number you look for : ";
        cin >> key;
        for (int i = 0; i < 10; i++)
        {
            if (key == arr[i])
            {
                cout << "Found Key -> " << key << " at index : " << i;
                found = 1;
                break;
            }
        }
        return found;
    }
}

void
main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key;
    int found = 0;
    clrscr();
    Searching search=Searching();
    search.intSequntialSearch(arr);
    
    getch();
}