#include "printf.h"
#include <stdio.h>

int	main(void)
{
    char    a;
    char    b[6];
    int     c;
    int     d;

    a = 'a';
    b[6] = "hello";
    c = 9393993;
    d = 384784874;
    printf("output from printf is:\n[%c], [%.7s], [%7.s], [%077d], [%x]\n", a, b, b, c, d);
    ft_printf("output from my (ft_)printf is:\n[%c], [%.7s], [%7.s], [%077d], [%x]\n", a, b, b, c, d);
}