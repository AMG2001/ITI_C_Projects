#include<conio.h>
#include<iostream.h>

int searchForNumber(int *ptr, int size, int Num)
{
    int i, Lo = 0, Hi = size - 1, Mid;
    Mid = (Lo + Hi) / 2;
    while (Hi >= Lo)
    {
        Mid = (Hi + Lo) / 2;
        if (ptr[Mid] > Num)
            Hi = Mid - 1;
        else if (ptr[Mid] < Num)
            Lo = Mid + 1;
        else
            return Mid;
    }
    return -1;
}


void main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    clrscr();
    cout<<"Enter The number you are looking for : ";
    int key;
    cin>>key;
    int indexOfKey = searchForNumber(arr,15,key);
    if(indexOfKey==-1)cout<<"Key is not Found !!";
    else cout << "Key is Founded At "<<indexOfKey;
    getch();
}