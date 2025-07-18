/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:52:03 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/18 20:41:52 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "libft.h"

static double	ft_strtod_integer(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((double)result);
}

static double	ft_strtod_decimal(char *str)
{
	int	i;
	int	digit;
	int	result;

	i = 0;
	result = 0;
	digit = 1;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		digit *= 10;
		i++;
	}
	return ((double)result / digit);
}

double	ft_strtod(char *str)
{
	int		sign;
	char	**split;
	double	result;

	result = 0;
	sign = 1;
	while (*str == '\t' || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	split = ft_split(str, '.');
	if (split[0])
		result = ft_strtod_integer(split[0]);
	if (split[1])
		result = result + ft_strtod_decimal(split[1]);
	ft_free_split(split);
	return (result * sign);
}
