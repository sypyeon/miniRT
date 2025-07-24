/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:02:35 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/25 01:42:31 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

static void int_part_str(char *str, int int_part, int frac_part, int i)
{
	int		j;
    int		len;
    char	buf[12];

	len = 0;
    if (int_part == 0)
		buf[len++] = '0';
    else
    {
		while (int_part > 0)
        {
			buf[len++] = (int_part % 10) + '0';
            int_part /= 10;
        }
    }
	j = len - 1;
	while (j >= 0)
	{
		str[i++] = buf[j];
		j--;
	}
    str[i++] = '.';
    str[i++] = (frac_part / 10) + '0';
    str[i++] = (frac_part % 10) + '0';
    str[i] = '\0';
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
    if (frac_part >= 100)
    {
        int_part++;
        frac_part = 0;
    }
    str = malloc(neg + 10);
    i = 0;
    if (neg)
	{
		str[i] = '-';
		i++;
	}
    int_part_str(str, int_part, frac_part, i);
    return (str);
}
