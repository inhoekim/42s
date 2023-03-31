#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int main()
{
	ft_printf(" %p \n", -1);
	printf(" %p \n", (void *)-1);
	ft_printf(" %p \n", 5);
	printf(" %p \n", (void *)5);
	ft_printf(" %p \n", 15);
	printf(" %p \n", (void *)15);
	ft_printf(" %p \n", 30);
	printf(" %p \n", (void *)30);
	//printf("aa%8.7s\n", "hello");
	/*
	printf("%#10x\n", 10);
	printf("%10x\n", 10);
	printf("%10o\n", 10);
	printf("%#10.f\n", 3.14);
	printf("%10.f\n\n", 3.14);

	printf("%8.3f\n", 3.14);
	printf("%08.3f\n\n", 3.14);

	printf("%3d\n", 3);
	printf("%03d\n", 3);
	printf("%.3d\n", 3);
	printf("%803d\n", 3);
	printf("%8.3d\n", 3);
	printf("%08.3d\n\n", 3);

	printf("%10d\n", 3);
	printf("%10.2d\n", 3);
	printf("%010.2d\n", 3);
	// neglect 0 padding
	printf("% 10d\n", 3);
	printf("%010d\n", 3);
	//right adjust and show sign
	printf("%+10d\n", 3);
	printf("%+10d\n\n", -3);
	//left adjust
	printf("%-10d\n", 3);
	printf("%-10d\n", -3);

	int width, digit;
	float f_digit;
	width = 10;
	digit = 6;
	f_digit = 10.1;
	printf("%*d\n", width, digit);
	printf("%2$*1$d\n", width, digit);
	printf("%2$*3$.*1$f\n", 5, f_digit, width);
	printf("%1$*2$d\n", width, digit);
	width = -10;
	printf("%+*d\n", width, digit);
	printf("%+-10d\n", digit);
	printf("%-+10d\n\n", digit);
	// - is overriding +, but sign is remain.
	int n = 1;
	int *p_n = &n;
	printf("%p\n", p_n);
	printf("123%n\n", p_n);
	// The number of characters written so far is stored into the p_n.
	printf("%d\n", *p_n);
	n = printf("123%%456\n");
	printf("%d\n\n", n);

	printf("edge case---------\n");
	// n = printf("%\n234");
	//printf("%d\n\n", n);
	// printf("%13.#f\n", 3.14);
	// printf("%#13.f\n", 3.14);
	// printf("%00010d\n", 1);
	printf("%.05d\n", 321);
	printf("%.05x\n", 0x123);
	printf("%.5%\n");
	// printf("%#c\n", 'c');
	printf("%#%\n");
	printf("%+%\n");
	printf("%u\n", -2);
	printf("%lld\n", (unsigned long long)(-2));
	printf("%3.0d\n", 5);
	printf("%+20d\n", 10, 4);
	printf("%0+10d\n", 10);
	printf("%0-10d\n", 10);
	*/
}