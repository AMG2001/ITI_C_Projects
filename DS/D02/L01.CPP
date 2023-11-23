#include <iostream.h>
#include <conio.h>

class Sorting
{
public:
	void swap(int &x, int &y)
	{
		int temp = x;
		x = y;
		y = temp;
	}

	void selectionSort(int *data, int size)
	{
		int i, j, index = 0;

		for (i = 0; i < size - 1; i++, index = i) // Number of stages
		{
			for (j = i + 1; j < size; j++) // Number of comparisons
				if (data[index] > data[j])
					index = j;
			swap(data[i], data[index]);
		}
	}
    void displayIntArrayContent(int *arr, int size)
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
	int intArray[] = {15, 22, 18, 17, 2, 9, 26, 30, 14, 3};
	Sorting s;
	s.selectionSort(intArray, 10);
	cout<<"Numbers in Sorted Order : ";
	s.displayIntArrayContent(intArray, 10);
	getch();
	return 0;
}
