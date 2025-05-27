/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:37:02 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/27 16:41:59 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_arg(char c, va_list arg)
{
	char	c_arg;

	if (c == 'c')
	{
		c_arg = va_arg(arg, int);
		return (write(1, &c_arg, 1));
	}
	if (c == 's')
		return (ft_s(va_arg(arg, char *)));
	if (c == 'p')
		return (ft_p(va_arg(arg, void *), "0123456789abcdef"));
	if (c == 'd' || c == 'i')
		return (ft_d(va_arg(arg, int)));
	if (c == 'u')
		return (ft_u(va_arg(arg, unsigned int)));
	if (c == 'x')
		return (ft_x(va_arg(arg, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_x(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	if (c == '%')
		return (write (1, "%", 1));
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	int		temp;
	va_list	arg;

	va_start(arg, s);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
			write(1, s + i, 1);
		if (s[i] == '%')
		{
			i++;
			temp = ft_print_arg(s[i], arg);
			if (temp == -1)
				return (-1);
			count += temp - 2;
		}
		i++;
	}
	return (count + i);
}
