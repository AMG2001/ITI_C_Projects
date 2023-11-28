#include <conio.h>
#include <iostream.h>
#include <string.h>

int searchForString(char **ptr, int size, char *key)
{
    int i, Lo = 0, Hi = size - 1, Mid;
    Mid = (Lo + Hi) / 2;
    while (Hi >= Lo)
    {
        Mid = (Hi + Lo) / 2;
        int result = strcmp(ptr[Mid], key);
        if (result > 0)
        {
            Hi = Mid - 1;
        }
        else if (result < 0)
        {
            Lo = Mid + 1;
        }
        else
        {
            return Mid;
        }
    }
    return -1;
}

int main()
{
    char *arr[] = {"ahmad", "amgad", "hazem", "marwan", "mona", "osama", "peter"};
    clrscr();
    cout << "Enter The number you are looking for : ";
    char key[50];
    cin >> key;
    int indexOfKey = searchForString(arr, 7, key);
    if (indexOfKey == -1)
        cout << "Key is not Found !!";
    else
        cout << "Key is Founded At " << indexOfKey;
    getch();
    return 0;
}
