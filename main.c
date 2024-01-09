#include <stdio.h>
#include "includes/ft_printf.h"
int main()
{
	printf("ft[%d]\n", ft_printf("%d ", 45));
	printf("pf[%d]\n", printf("%d ", 45));
}