/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:05:38 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/27 16:47:19 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexa_digit(unsigned int arg)
{
	int	digit;

	digit = 1;
	while (arg >= 16)
	{
		arg = arg / 16;
		digit++;
	}
	return (digit);
}

int	ft_x(unsigned int arg, char *base)
{
	size_t	digit;
	size_t	s_len;
	char	*x;

	digit = ft_hexa_digit(arg);
	x = (char *)malloc(sizeof(char) * digit + 1);
	if (!x)
		return (-1);
	x[digit] = '\0';
	s_len = digit;
	while (digit > 0)
	{
		digit--;
		x[digit] = base[arg % 16];
		arg = arg / 16;
	}
	write(1, x, s_len);
	free(x);
	return (s_len);
}
