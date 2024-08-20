/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42gyenongs      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:08:26 by junseyun          #+#    #+#             */
/*   Updated: 2024/03/26 16:58:33 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(int n)
{
	int	len;
	int	tmp;

	tmp = n;
	len = 0;
	if (tmp <= 0)
		len = 1;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	return (len);
}

static char	*neg_arr(char *res, int len, int n)
{
	int				i;
	long long int	tmp;

	tmp = (long long int)n;
	i = len - 1;
	res[0] = '-';
	tmp *= -1;
	while (i >= 1)
	{
		res[i] = tmp % 10 + '0';
		tmp /= 10;
		i--;
	}
	res[len] = 0;
	return (res);
}

static char	*pos_arr(char *res, int len, int n)
{
	int				i;
	long long int	tmp;

	tmp = (long long int)n;
	i = len - 1;
	while (i >= 0)
	{
		res[i] = tmp % 10 + '0';
		tmp /= 10;
		i--;
	}
	res[len] = 0;
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = num_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (0);
	if (n < 0)
		res = neg_arr(res, len, n);
	else if (n >= 0)
		res = pos_arr(res, len, n);
	return (res);
}
