/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:52:03 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/21 06:27:14 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

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
	free_split(split);
	return (result * sign);
}

static void	ft_int_to_str(char *str, int *i, int num)
{
	char	buf[12];
	int		len;
	int		j;

	len = 0;
	if (num == 0)
		buf[len++] = '0';
	else
	{
		while (num > 0)
		{
			buf[len++] = (num % 10) + '0';
			num /= 10;
		}
	}
	j = len - 1;
	while (j >= 0)
		str[(*i)++] = buf[j--];
}

char	*ft_dtostr(double num)
{
	char	*str;
	int		int_part;
	int		frac_part;
	int		neg;
	int		i;

	neg = (num < 0);
	if (neg)
		num = -num;
	int_part = (int)num;
	frac_part = (int)((num - int_part) * 100 + 0.5);
	str = (char *)malloc(neg + 10);
	if (!str)
		return (NULL);
	i = 0;
	if (neg)
		str[i++] = '-';
	ft_int_to_str(str, &i, int_part);
	str[i++] = '.';
	str[i++] = (frac_part / 10) + '0';
	str[i++] = (frac_part % 10) + '0';
	str[i] = '\0';
	return (str);
}
