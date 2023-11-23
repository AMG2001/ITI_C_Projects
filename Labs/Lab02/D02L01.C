#include <stdio.h>
#include <conio.h>
void main(void)
{

	int n, num = 1, row = 0, clm;

	clrscr();

	printf("Enter the order of the box\n");

	scanf("%d", &n);

	clm = n / 2;

	for (num = 1; num <= n * n; num++)
	{

		gotoxy((clm + 1) * 15, (row + 1) * 2);

		printf("%d", num);

		if (num % n != 0)
		{

			if (row == 0)
				row = n - 1;

			else
				row--;

			if (clm == 0)
				clm = n - 1;

			else
				clm--;
		}
		else
		{

			if (row == n - 1)
				row = 0;

			else
				row++;
		}
	}

	getch();
}