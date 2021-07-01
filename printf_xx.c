/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_xx.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-dam <avan-dam@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 16:45:17 by avan-dam      #+#    #+#                 */
/*   Updated: 2021/07/01 11:28:09 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_puthx(long int i, int result, t_sto *s1)
{
	char		z;
	long int	c;

	c = i;
	while (c >= 16)
		c = c / 16;
	if (i >= 16)
	{
		ft_puthx(i / 16, result, s1);
		ft_puthx(i % 16, result, s1);
	}
	else
	{
		if (i <= 9)
			z = i + '0';
		else
		{
			if (result == 1)
				z = (i - 10) + 'A';
			else
				z = (i - 10) + 'a';
		}
		write(1, &z, 1);
		s1->retval = s1->retval + 1;
	}
}

int		ft_len_hx(long int i)
{
	long int	a;

	a = 0;
	if (i < 0)
	{
		i = i * -1;
		i = 4294967296 - i;
	}
	while (i >= 16)
	{
		i = i / 16;
		a++;
	}
	a++;
	return (a);
}

void	ft_findhx_more(unsigned int numb, int i, t_sto *s1, int prec)
{
	char	c;

	c = ' ';
	if (s1->flag == 2 && prec == 0)
		c = '0';
	if (s1->flag != 1 && s1->width != 0)
		ft_putpad(s1->width, c, 0, s1);
	if (s1->precision != ft_len_hx(numb))
		ft_putpad(s1->precision, '0', ft_len_hx(numb), s1);
	if (numb < 0)
	{
		i = i * -1;
		i = 4294967296 - i;
	}
	ft_puthx(numb, i, s1);
	if (s1->flag == 1 && s1->width != 0)
		ft_putpad(s1->width, ' ', 0, s1);
}

void	ft_findhx(unsigned int numb, int i, t_sto *s1)
{
	int		precision;

	precision = (s1->precision == 0 ? 0 : 1);
	if (s1->dot == 3 && s1->precision == 0 && s1->width == 0 && numb == 0)
	{
		write(1, "0", 1);
		s1->retval = s1->retval + 1;
		return ;
	}
	if (s1->precision <= ft_len_hx(numb))
		s1->precision = ft_len_hx(numb);
	if (s1->width < 0)
	{
		s1->flag = 1;
		s1->width = s1->width * -1;
	}
	s1->width = s1->width - (s1->width > s1->precision ?
	s1->precision : s1->width);
	if (numb == 0 && precision == 0 && s1->dot != 0)
	{
		if (s1->width)
			ft_putpad(s1->width + 1, ' ', 0, s1);
		return ;
	}
	ft_findhx_more(numb, i, s1, precision);
}
