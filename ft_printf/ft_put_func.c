/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42gyenongs      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:21:09 by junseyun          #+#    #+#             */
/*   Updated: 2024/04/13 15:15:52 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static void	print_null(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
	{
		print_null("(null)");
		return (6);
	}
	while (str[len])
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_putstr(num);
	free(num);
	return (len);
}

int	ft_put_percent(void)
{
	ft_putchar('%');
	return (1);
}
