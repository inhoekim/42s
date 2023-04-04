#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	int a = ft_printf("p6 %.0d\n", 100);
	printf("\n%d\n", a);
	a = printf("p6 %.0d\n", 100);
	printf("\n%d", a);
}
