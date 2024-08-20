/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42gyenongs      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:55:30 by junseyun          #+#    #+#             */
/*   Updated: 2024/04/03 17:00:00 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char format, va_list ap)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(ap, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (format == 'u')
		len += ft_print_unsigned(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_print_hex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		len += ft_put_percent();
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;
	int		i;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += check_type(format[i + 1], ap);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
