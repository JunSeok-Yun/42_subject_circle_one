/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42gyenongs      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:52:15 by junseyun          #+#    #+#             */
/*   Updated: 2024/04/08 15:56:34 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_put_percent(void);
int		ft_putchar(int c);
int		check_type(const char format, va_list ap);
int		ft_printf(const char *format, ...);
int		ft_print_hex(unsigned int num, const char format);
char	*ft_itoa(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_ptr(unsigned long long int num);
int		ft_put_percent(void);

#endif
