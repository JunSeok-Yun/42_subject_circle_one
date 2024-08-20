/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:31:40 by junseyun          #+#    #+#             */
/*   Updated: 2024/04/03 16:59:28 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	u_num_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_u_itoa(unsigned int n)
{
	char	*res;
	int		len;

	len = u_num_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (0);
	res[len] = 0;
	while (n != 0)
	{
		res[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (res);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len += ft_putchar('0');
	else
	{
		num = ft_u_itoa(n);
		len += ft_putstr(num);
		free(num);
	}
	return (len);
}
