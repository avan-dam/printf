/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_s.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-dam <avan-dam@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 13:05:35 by avan-dam       #+#    #+#                */
/*   Updated: 2020/02/03 14:03:55 by avan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_header.h"

void	ft_putpad(int i, char c, int length, t_sto *s1)
{
	int k;

	k = 0;
	if (i == 0)
		return ;
	if (i <= length)
		return ;
	if (i > length)
		i = i - length;
	while (k < i)
	{
		write(1, &c, 1);
		s1->retval = s1->retval + 1;
		k++;
	}
}

int		ft_len(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *s, int y, t_sto *s1)
{
	int i;

	i = 0;
	while (s[i] != '\0' && i < y)
	{
		write(1, &s[i], 1);
		s1->retval = s1->retval + 1;
		i++;
	}
}

void	ft_findstr_more(char *s, t_sto *s1, int len)
{
	if (s1->precision < len && s1->precision != 0)
	{
		if (s1->precision < 0)
			s1->precision = s1->precision * -1;
		len = s1->precision;
	}
	if (s1->flag == 1 && s1->dot != 2)
		ft_putstr(s, len, s1);
	if (s1->width > len && s1->dot != 2)
		ft_putpad(s1->width, ' ', len, s1);
	if (s1->dot == 2)
		ft_putpad(s1->width, ' ', 0, s1);
	if (s1->flag != 1 && s1->dot != 2)
		ft_putstr(s, len, s1);
}

void	ft_findstr(char *s, t_sto *s1)
{
	int		len;

	if (!s)
		s = "(null)";
	if (s1->width < 0)
	{
		s1->flag = 1;
		s1->width = s1->width * -1;
	}
	if (s1->precision < 0)
	{
		s1->dot = 0;
		s1->precision = 0;
	}
	if (s1->dot == 1 && s1->precision == 0)
	{
		ft_putpad(s1->width, ' ', 0, s1);
		return ;
	}
	len = ft_len(s);
	if (s1->dot == 0 && s1->flag == 2)
		return ;
	ft_findstr_more(s, s1, len);
}
