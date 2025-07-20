/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:18:29 by sipyeon           #+#    #+#             */
/*   Updated: 2025/04/25 17:19:47 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digit(long long n)
{
	size_t	digit;

	digit = 1;
	if (n < 0)
	{
		digit++;
		n *= -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	long long	lln;
	size_t		digit;
	size_t		i;
	char		*a;

	lln = (long long)n;
	digit = ft_digit(lln);
	a = (char *)malloc(sizeof(char) * digit + 1);
	if (!a)
		return (NULL);
	i = 0;
	if (lln < 0)
	{
		a[i] = '-';
		lln *= -1;
		i++;
	}
	a[digit] = '\0';
	while (digit > i)
	{
		digit--;
		a[digit] = lln % 10 + '0';
		lln = lln / 10;
	}
	return (a);
}
