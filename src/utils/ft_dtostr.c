/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:24:47 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/20 19:26:44 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

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
