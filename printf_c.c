/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_c.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-dam <avan-dam@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 16:26:39 by avan-dam      #+#    #+#                 */
/*   Updated: 2021/07/01 11:27:55 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_find_length(const char *s, int i, int dot, t_sto *s1)
{
	long int res;

	res = 0;
	while (s[i] != '\0' && s[i] > 47 && s[i] < 58)
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	if (dot == 0 || dot == 2)
		s1->width = res;
	if (dot == 1)
		s1->precision = res;
	if (i > 0)
		i = i - 1;
	return (i);
}

void	ft_percentage(t_sto *s1)
{
	int		len;
	char	c;

	c = ' ';
	len = 1;
	if (s1->width < 0)
	{
		s1->flag = 1;
		s1->width = s1->width * -1;
	}
	if (s1->flag == 2)
		c = '0';
	if (s1->flag == 1)
	{
		write(1, "%", 1);
		s1->retval = s1->retval + 1;
	}
	if (s1->width > 1)
		ft_putpad(s1->width, c, 1, s1);
	if (s1->flag != 1)
	{
		write(1, "%", 1);
		s1->retval = s1->retval + 1;
	}
}

void	ft_putchar(int ch, t_sto *s1)
{
	write(1, &ch, 1);
	s1->retval = s1->retval + 1;
}

void	ft_findchar(int ch, t_sto *s1)
{
	int		len;

	len = 1;
	if (s1->width < 0)
	{
		s1->flag = 1;
		s1->width = s1->width * -1;
	}
	if (s1->precision > len && s1->dot != 1)
		len = s1->precision;
	if (s1->precision > len && s1->dot != 1)
		ft_putpad(s1->precision, ' ', 1, s1);
	if (s1->flag == 1 && s1->dot != 1)
		ft_putchar(ch, s1);
	if (s1->width > len && s1->dot != 1)
		ft_putpad(s1->width, ' ', len, s1);
	if (s1->flag != 1 && s1->dot != 1)
		ft_putchar(ch, s1);
}
