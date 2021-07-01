/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_p.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-dam <avan-dam@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 16:46:01 by avan-dam      #+#    #+#                 */
/*   Updated: 2021/07/01 11:28:03 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putpoi(unsigned long i, t_sto *s1)
{
	char		z;
	long int	c;

	if (i < 0)
	{
		i = i * -1;
		i = 4294967296 - i;
	}
	c = i;
	while (c >= 16)
		c = c / 16;
	if (i >= 16)
	{
		ft_putpoi(i / 16, s1);
		ft_putpoi(i % 16, s1);
	}
	else
	{
		if (i <= 9)
			z = i + '0';
		else
			z = (i - 10) + 'a';
		write(1, &z, 1);
		s1->retval = s1->retval + 1;
	}
}

int		ft_len_poi(unsigned long i)
{
	long int	a;

	a = 0;
	if (i == 0x0)
		return (3);
	if (i == 0)
		return (2);
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
	return (a + 2);
}

void	ft_findpoi_more(unsigned long numb, t_sto *s1, char c, int pre)
{
	if (s1->flag != 1 && s1->width != 0)
	{
		if (s1->precision == ft_len_poi(numb) && c == '0')
		{
			write(1, "0x", 1);
			s1->retval = s1->retval + 2;
			pre = 3;
		}
		if (numb == 0 || numb == 0x0)
			ft_putpad(s1->width, c, 1, s1);
		else
			ft_putpad(s1->width, c, 0, s1);
	}
	if (s1->precision != ft_len_poi(numb))
		ft_putpad(s1->precision, '0', ft_len_poi(numb), s1);
	if (pre != 3)
	{
		write(1, "0x", 2);
		s1->retval = s1->retval + 2;
	}
	ft_putpoi(numb, s1);
	if (s1->flag == 1 && s1->width != 0)
		ft_putpad(s1->width, ' ', 0, s1);
}

int		ft_poi_spec(unsigned long numb, t_sto *s1)
{
	if (numb == 0 && s1->precision == 0)
	{
		if (s1->dot != 0 && s1->flag == 0)
		{
			if (s1->flag != 1 && s1->width != 0)
				ft_putpad(s1->width, ' ', 2, s1);
			write(1, "0x", 2);
			s1->retval = s1->retval + 2;
			if (s1->flag == 1 && s1->width != 0)
				ft_putpad(s1->width, ' ', 2, s1);
		}
		else
		{
			if (s1->flag != 1 && s1->width != 0)
				ft_putpad(s1->width, ' ', 3, s1);
			write(1, "0x0", 3);
			s1->retval = s1->retval + 3;
			if (s1->flag == 1 && s1->width != 0)
				ft_putpad(s1->width, ' ', 3, s1);
		}
		return (1);
	}
	return (0);
}

void	ft_findpoi(unsigned long numb, t_sto *s1, char c)
{
	int		precision;

	if (s1->width < 0)
	{
		s1->flag = 1;
		s1->width = s1->width * -1;
	}
	if (ft_poi_spec(numb, s1) == 1)
		return ;
	if (s1->flag == 2 && s1->precision == 0)
		c = '0';
	if (s1->precision == 0)
		precision = 0;
	if (s1->precision <= ft_len_poi(numb))
		s1->precision = ft_len_poi(numb);
	s1->width = s1->width > s1->precision ? s1->width - s1->precision : 0;
	if ((numb == 0 || numb == 0x0) && precision == 0 && s1->dot != 0)
	{
		ft_putpad(s1->width, ' ', 0, s1);
		write(1, "0x", 2);
		s1->retval = s1->retval + 2;
		return ;
	}
	ft_findpoi_more(numb, s1, c, precision);
}
