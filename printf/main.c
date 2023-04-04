#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	int a = ft_printf("%-5c", (char)27);
	printf("\n----------------------------------------------\n");
	int b = printf("%-5c", (char)27);
	printf("\n----------------------------------------------\n");
	printf("%d %d",a, b);
}
