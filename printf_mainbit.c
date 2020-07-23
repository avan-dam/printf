/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mainbit.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-dam <avan-dam@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 16:24:48 by avan-dam       #+#    #+#                */
/*   Updated: 2020/02/03 15:18:28 by avan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_header.h"

void	ft_check_dot(const char *s, int i, t_sto *s1)
{
	if (s[i] == '.')
		s1->dot = 1;
	if (s[i + 1])
	{
		if ((s[i] == '.') && (s[i + 1] == 'd' || s[i + 1] == 'i' ||
		s[i + 1] == 'c' || s[i + 1] == 's' || s[i + 1] == 'p' ||
		s[i + 1] == 'u' || s[i + 1] == 'x' || s[i + 1] == 'X' ||
		s[i + 1] == '%'))
			s1->dot = 2;
		else if ((s[i] == '-') && (s[i + 1] == 'd' || s[i + 1] == 'i' ||
		s[i + 1] == 'c' || s[i + 1] == 's' || s[i + 1] == 'p' ||
		s[i + 1] == 'u' || s[i + 1] == 'x' || s[i + 1] == 'X' ||
		s[i + 1] == '%'))
			s1->dot = 3;
	}
}

int		ft_find_other(const char *s, int i, va_list argptr, t_sto *s1)
{
	while (s[i] && s[i] != 'd' && s[i] != 'i' && s[i] != 'c' && s[i] != 's' &&
	s[i] != 'p' && s[i] != 'u' && s[i] != 'x' && s[i] != 'X' && s[i] != '%')
	{
		ft_check_dot(s, i, s1);
		if (s[i] == '-')
			s1->flag = 1;
		if (s[i] == '0' && s1->flag != 1 && s1->dot == 0)
			s1->flag = 2;
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (s[i] >= '0' && s[i] <= '9')
				i = ft_find_length(s, i, s1->dot, s1);
		}
		if (s[i] == '*')
		{
			if (s1->dot == 0 || s1->dot == 2)
				s1->width = va_arg(argptr, int);
			if (s1->dot == 1)
				s1->precision = va_arg(argptr, int);
		}
		i++;
	}
	return (i);
}

int		ft_find_specif(const char *s, int i, va_list argptr, t_sto *s1)
{
	i++;
	i = ft_find_other(s, i, argptr, s1);
	if (s[i] == 's')
		ft_findstr(va_arg(argptr, char *), s1);
	if (s[i] == 'd' || s[i] == 'i')
		ft_findnumb(va_arg(argptr, int), s1, ' ');
	if (s[i] == 'c')
		ft_findchar(va_arg(argptr, int), s1);
	if (s[i] == 'u')
		ft_findunsi(va_arg(argptr, unsigned int), s1);
	if (s[i] == 'x')
		ft_findhx(va_arg(argptr, unsigned int), 0, s1);
	if (s[i] == 'X')
		ft_findhx(va_arg(argptr, unsigned int), 1, s1);
	if (s[i] == 'p')
		ft_findpoi(va_arg(argptr, unsigned long), s1, ' ');
	if (s[i] == '%')
		ft_percentage(s1);
	if (s[i] != 'd' && s[i] != 'i' && s[i] != 'c' && s[i] != 's' &&
	s[i] != 'p' && s[i] != 'u' && s[i] != 'x' && s[i] != 'X' && s[i] != '%')
		return (-1);
	ft_zero_struct(s1, 0);
	return (i);
}

int		ft_zero_struct(t_sto *s1, int i)
{
	int	temp;

	temp = 0;
	s1->flag = 0;
	s1->width = 0;
	s1->precision = 0;
	s1->dot = 0;
	if (i == 1)
	{
		temp = s1->retval;
		s1->retval = 0;
		return (temp);
	}
	return (0);
}

int		ft_printf(const char *string, ...)
{
	int		i;
	t_sto	s1;
	va_list	argptr;

	ft_zero_struct(&s1, 1);
	va_start(argptr, string);
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%' && string[i + 1])
		{
			i = ft_find_specif(string, i, argptr, &s1);
			if (i == -1)
				return (-1);
		}
		else
		{
			write(1, &string[i], 1);
			s1.retval = s1.retval + 1;
		}
		i++;
	}
	va_end(argptr);
	return (ft_zero_struct(&s1, 1));
}
