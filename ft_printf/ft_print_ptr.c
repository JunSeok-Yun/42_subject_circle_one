/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:49:43 by junseyun          #+#    #+#             */
/*   Updated: 2024/03/26 19:49:47 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_len(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

static void	print_ptr(unsigned long long num)
{
	if (num >= 16)
	{
		print_ptr(num / 16);
		print_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (ft_putstr("(nil)"));
	else
	{
		len += ft_putstr("0x");
		print_ptr(num);
		len += ptr_len(num);
	}
	return (len);
}
