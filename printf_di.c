/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_di.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-dam <avan-dam@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 12:12:53 by avan-dam       #+#    #+#                */
/*   Updated: 2020/02/03 14:50:14 by avan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_header.h"

void	ft_putnbr(long n, t_sto *s1)
{
	char	z;
	long	c;

	if (n < 0)
	{
		write(1, "-", 1);
		s1->retval = s1->retval + 1;
		n = (n * -1);
	}
	c = n;
	while (c >= 10)
		c = c / 10;
	if (n >= 10)
	{
		ft_putnbr(n / 10, s1);
		ft_putnbr(n % 10, s1);
	}
	else
	{
		z = n + '0';
		write(1, &z, 1);
		s1->retval = s1->retval + 1;
	}
}

void	ft_findnumb_more(long numb, t_sto *s1, char c, int y)
{
	int neg;

	neg = (numb < 0 ? 1 : 0);
	if (numb == 0 && s1->precision == 0 && s1->dot != 0)
	{
		if (s1->width)
			ft_putpad(s1->width + 1, ' ', 0, s1);
		return ;
	}
	if (s1->flag != 1 && s1->width != 0)
	{
		if (numb < 0 && s1->precision == ft_len_numb(numb) && c == '0')
		{
			write(1, "-", 1);
			s1->retval = s1->retval + 1;
			numb = numb * -1;
			neg = 3;
		}
		if ((s1->precision != ft_len_numb(numb) && neg == 1) || (neg == 3))
			ft_putpad(s1->width, c, 1, s1);
		else
			ft_putpad(s1->width, c, 0, s1);
	}
	ft_findnumb_more_more(numb, s1, neg, y);
}

void	ft_findnumb_more_more(long numb, t_sto *s1, int neg, int y)
{
	if (s1->precision != ft_len_numb(numb))
	{
		if (numb < 0)
		{
			write(1, "-", 1);
			s1->retval = s1->retval + 1;
			numb = numb * -1;
			if (y == 0)
				ft_putpad(s1->precision, '0', ft_len_numb(numb), s1);
			else
				ft_putpad(s1->precision - 1, '0', ft_len_numb(numb), s1);
		}
		else
			ft_putpad(s1->precision, '0', ft_len_numb(numb), s1);
	}
	ft_putnbr(numb, s1);
	if (s1->flag == 1 && s1->width != 0)
	{
		if (neg == 1 && s1->precision > ft_len_numb(numb))
			ft_putpad(s1->width, ' ', 1, s1);
		else
			ft_putpad(s1->width, ' ', 0, s1);
	}
}

int		special_case(long numb, t_sto *s1, char c)
{
	if (s1->precision == ft_len_numb(numb) && numb < 0)
	{
		s1->precision = ft_len_numb(numb) + 1;
		if (s1->width > s1->precision)
			s1->width = s1->width - ft_len_numb(numb);
		else
			s1->width = 0;
		ft_findnumb_more(numb, s1, c, 1);
		return (1);
	}
	if (s1->precision == 0 && s1->width == 0 && numb == 0 && s1->dot == 3)
	{
		write(1, "0", 1);
		s1->retval = s1->retval + 1;
		return (1);
	}
	if (s1->precision == 0 && numb == 0 && s1->flag != 2 && s1->dot != 0)
	{
		if (s1->width >= 0)
			ft_putpad(s1->width, ' ', 0, s1);
		if (s1->width < 0)
			ft_putpad((s1->width * -1), ' ', 0, s1);
		return (1);
	}
	return (0);
}

void	ft_findnumb(long numb, t_sto *s1, char c)
{
	if (s1->flag == 2 && s1->precision == 0)
		c = '0';
	if (special_case(numb, s1, c) == 1)
		return ;
	if (s1->precision <= ft_len_numb(numb))
		s1->precision = ft_len_numb(numb);
	if (s1->width < 0)
	{
		s1->flag = 1;
		s1->width = s1->width * -1;
	}
	s1->width = s1->width > s1->precision ? s1->width - s1->precision : 0;
	ft_findnumb_more(numb, s1, c, 0);
}
