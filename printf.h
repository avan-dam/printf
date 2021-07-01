/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-dam <avan-dam@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 14:07:36 by avan-dam      #+#    #+#                 */
/*   Updated: 2021/07/01 11:27:48 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_sto
{
	int			flag;
	int			width;
	int			precision;
	int			dot;
	int			retval;
}				t_sto;

int				ft_printf(const char *string, ...);
int				ft_zero_struct(t_sto *s1, int i);
int				ft_find_specif(const char *s, int i, va_list argptr, t_sto *s1);
void			ft_check_dot(const char *s, int i, t_sto *s1);
int				ft_find_other(const char *s, int i, va_list argptr, t_sto *s1);
int				ft_find_length(const char *s, int i, int dot, t_sto *s1);
void			ft_putpad(int i, char c, int length, t_sto *s1);
void			ft_findstr(char *s, t_sto *s1);
void			ft_putstr(char *s, int y, t_sto *s1);
void			ft_putchar(int ch, t_sto *s1);
int				ft_len(char *s);
void			ft_putnbr(long n, t_sto *s1);
long int		ft_unsigned(long int i);
void			ft_puthx(long int i, int result, t_sto *s1);
void			ft_findnumb(long int numb, t_sto *s1, char c);
void			ft_findnumb_more(long numb, t_sto *s1, char c, int y);
void			ft_findnumb_more_more(long numb, t_sto *s1, int neg, int y);
void			ft_findchar(int ch, t_sto *s1);
void			ft_findstr_more(char *s, t_sto *s1, int len);
int				ft_len_numb(long i);
void			ft_findhx(unsigned int numb, int i, t_sto *s1);
void			ft_findhx_more(unsigned int numb, int i, t_sto *s1, int prec);
void			ft_findunsi(long int numb, t_sto *s1);
void			ft_find_unsi_more(long int numb, t_sto *s1, char c, int prec);
void			ft_findpoin(char *str);
void			ft_findpoi(unsigned long numb, t_sto *s1, char c);
void			ft_findpoi_more(unsigned long numb, t_sto *s1, char c, int pre);
int				ft_len_hx(long int i);
void			ft_percentage(t_sto *s1);
void			ft_putpoi(unsigned long i, t_sto *s1);
int				ft_len_poi(unsigned long i);
int				special_case(long numb, t_sto *s1, char c);
int				ft_poi_spec(unsigned long numb, t_sto *s1);

#endif
