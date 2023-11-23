#include <stdio.h>
#include<conio.h>

double power(double base,double p) {
	if(p<0){
    return 1/(base*power(base,-1*p-1));
	}
	else if (p == 0) {
		return 1;
	}
	else {
		return base * power(base, p - 1);
	}
}

void main() {
	double base, p,result;
	clrscr();
	printf("Enter the base: ");
	scanf("%lf", &base);
	printf("Enter the p: ");
	scanf("%lf", &p);
	result = power(base, p);
	printf("%.2lf raised to the power of %.2lf is %.2lf\n", base, p, result);
	getch();
}
