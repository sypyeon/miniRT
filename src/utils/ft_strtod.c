/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:52:03 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/22 02:38:04 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

double	ft_strtod(const char *str, char **str_end)
{
	double	res;
	ssize_t	digits;
	ssize_t	sign;
	ssize_t	dots;

	*str_end = (char *)str;
	digits = ft_digits(str);
	sign = ft_signs(str);
	dots = ft_dots(str);
	if (digits > 15 || digits <= 0 || sign < 0 || sign > 1
		|| dots < 0 || dots > 1)
		return (NAN);
	sign = (str[0] == '-') * (-1) + (str[0] != '-');
	if (str[0] == '-' || str[0] == '+')
		++*str_end;
	res = sign * (**str_end - '0');
	while (*(++*str_end))
	{
		if (**str_end == '.')
			continue ;
		res = res * 10 + sign * (**str_end - '0');
	}
	return (res * ft_exp(str));
}

ssize_t	ft_digits(const char *str)
{
	size_t	i;
	ssize_t	n;

	if (ft_isdigit(str[0]))
		i = 0;
	else if (str[0] == '+' || str[0] == '-')
		i = 1;
	else
		return (-1);
	n = 0;
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '.'))
	{
		if (ft_isdigit(str[i]))
			n++;
		i++;
	}
	if (str[i])
		return (-1);
	return (n);
}

ssize_t	ft_signs(const char *str)
{
	size_t	i;
	ssize_t	n;

	i = 0;
	if (ft_isdigit(str[0]))
		n = 0;
	else if (str[0] == '+' || str[0] == '-')
		n = 1;
	else
		return (-1);
	if (ft_strchr(str + n, '+') || ft_strchr(str + n, '-'))
		return (-1);
	return (n);
}

ssize_t	ft_dots(const char *str)
{
	size_t	i;
	ssize_t	n;

	if (str[0] == '.')
		return (-1);
	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '.')
			n++;
		i++;
	}
	if (str[i - 1] == '.')
		return (-1);
	return (n);
}

double	ft_exp(const char *str)
{
	char	*dot_pos;
	ssize_t	exp_len;

	dot_pos = ft_strchr(str, '.');
	if (!dot_pos)
		return (1);
	exp_len = str + ft_strlen(str) - dot_pos - 1;
	return (pow(10, -(double)exp_len));
}
