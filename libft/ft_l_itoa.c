/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:30:58 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/27 16:42:21 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digit(long n)
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

char	*ft_l_itoa(long n)
{
	size_t		digit;
	size_t		i;
	char		*a;

	digit = ft_digit(n);
	a = (char *)malloc(sizeof(char) * digit + 1);
	if (!a)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		a[i] = '-';
		n *= -1;
		i++;
	}
	a[digit] = '\0';
	while (digit > i)
	{
		digit--;
		a[digit] = n % 10 + '0';
		n = n / 10;
	}
	return (a);
}
