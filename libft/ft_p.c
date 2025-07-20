/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:05:40 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/27 16:46:20 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_hexa_digit(size_t arg)
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

int	ft_p(void *arg, char *base)
{
	size_t	digit;
	size_t	s_len;
	size_t	arg_mem;
	char	*s_to_mem;

	if (!arg)
		return (write(1, "(nil)", 5));
	arg_mem = (size_t)arg;
	digit = ft_hexa_digit(arg_mem);
	s_to_mem = (char *)malloc(sizeof(char) * digit + 1);
	if (!s_to_mem)
		return (-1);
	s_len = digit;
	s_to_mem[digit] = '\0';
	while (digit > 0)
	{
		digit--;
		s_to_mem[digit] = base[arg_mem % 16];
		arg_mem = arg_mem / 16;
	}
	write(1, "0x", 2);
	write(1, s_to_mem, s_len);
	free(s_to_mem);
	return (s_len + 2);
}
