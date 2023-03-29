/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:39:07 by salmanso          #+#    #+#             */
/*   Updated: 2023/03/29 18:22:18 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_count_digits(int n)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (++count);
}

char	*ft_itoa_conv(int n, char *str, int len)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		n *= -1;
	}
	i += len;
	while (n >= 10)
	{
		str[--i] = ((n % 10) + 48);
		n /= 10;
	}
	str[--i] = (n % 10) + 48;
	return (str);
}

char	*ft_itoa(int n)
{
	int		len_str;
	char	*str;
	char	*cpy_str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len_str = ft_count_digits(n);
	str = malloc(sizeof(char) * len_str + 1);
	if (!str)
		return (NULL);
	str[len_str] = '\0';
	cpy_str = ft_itoa_conv(n, str, len_str);
	return (cpy_str);
}
