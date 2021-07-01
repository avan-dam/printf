/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_u.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-dam <avan-dam@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 16:45:37 by avan-dam      #+#    #+#                 */
/*   Updated: 2021/07/01 11:28:07 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_len_numb(long i)
{
	long	a;

	a = 0;
	if (i < 0)
	{
		i = i * -1;
		a++;
	}
	while (i >= 10)
	{
		i = i / 10;
		a++;
	}
	a++;
	return (a);
}

long int	ft_unsigned(long int i)
{
	long int	a;

	a = 0;
	if (i >= 0)
		return (i);
	a = 4294967296 + i;
	return (a);
}

void		ft_find_unsi_more(long int numb, t_sto *s1, char c, int prec)
{
	if (numb == 0 && prec == 0 && s1->dot != 0)
	{
		if (s1->width)
			ft_putpad(s1->width + 1, ' ', 0, s1);
		return ;
	}
	if (s1->flag != 1 && s1->width != 0)
		ft_putpad(s1->width, c, 0, s1);
	if (s1->precision != ft_len_numb(numb))
		ft_putpad(s1->precision, '0', ft_len_numb(numb), s1);
	ft_putnbr(numb, s1);
	if (s1->flag == 1 && s1->width != 0)
		ft_putpad(s1->width, ' ', 0, s1);
}

void		ft_findunsi(long int numb, t_sto *s1)
{
	int		precision;
	char	c;

	c = ' ';
	precision = (s1->precision == 0 ? 0 : 1);
	numb = ft_unsigned(numb);
	if (s1->dot == 3 && s1->precision == 0 && s1->width == 0 && numb == 0)
	{
		write(1, "0", 1);
		s1->retval = s1->retval + 1;
		return ;
	}
	if (s1->flag == 2 && s1->precision == 0)
		c = '0';
	if (s1->precision <= ft_len_numb(numb))
		s1->precision = ft_len_numb(numb);
	if (s1->width < 0)
	{
		s1->flag = 1;
		s1->width = s1->width * -1;
	}
	s1->width = s1->width > s1->precision ? s1->width - s1->precision : 0;
	ft_find_unsi_more(numb, s1, c, precision);
}
