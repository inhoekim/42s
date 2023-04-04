#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int a = ft_printf("%-10.100s, %-10.100s, %-10.100s, %-10.100s", (char *)NULL, "", "test", "joihwh     hgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
	printf("\n-----------------\n");
	int b = printf("%-10.100s, %-10.100s, %-10.100s, %-10.100s", (char *)NULL, "", "test", "joihwh     hgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
	printf("\n-----------------\n");
	printf("%d %d",a, b);
}
