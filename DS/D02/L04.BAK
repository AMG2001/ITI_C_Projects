#include <iostream.h>
#include <conio.h>

class Sorting
{
public:
    void merge(int *A, int *L, int leftCount, int *R, int rightCount)
    {
        int i, j, k;
        i = 0;
        j = 0;
        k = 0;
        while (i < leftCount && j < rightCount)
        {
            if (L[i] < R[j])
                A[k++] = L[i++];
            else
                A[k++] = R[j++];
        }
        while (i < leftCount)
            A[k++] = L[i++];
        while (j < rightCount)
            A[k++] = R[j++];
    }
    void mergeSort(int *A, int n)
    {
        int mid, i, *L, *R;
        if (n < 2)
            return;  // base condition. If the array has less than two element, do nothing.
        mid = n / 2; // find the mid index.
        L = new int[mid];
        R = new int[n - mid];
        for (i = 0; i < mid; i++)
            L[i] = A[i]; // creating left subarray
        for (i = mid; i < n; i++)
            R[i - mid] = A[i];        // creating right subarray
        mergeSort(L, mid);            // sorting the left subarray
        mergeSort(R, n - mid);        // sorting the right subarray
        merge(A, L, mid, R, n - mid); // Merging L and R into A as sorted list.
        delete[] L;
        delete[] R;
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
    s.mergeSort(intArray, 10);
    cout << "Numbers in Sorted Order using merge sort : ";
    s.displayIntArrayContent(intArray, 10);
    getch();
    return 0;
}
