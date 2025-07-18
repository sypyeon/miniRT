/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:09:28 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/18 20:57:05 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*ft_fill_buf(char *str, int i, int int_part, int frac_part)
{
    int len = 0;
    char buf[12];
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
    for (int j = len - 1; j >= 0; --j)
        str[i++] = buf[j];
    str[i++] = '.';
    str[i++] = (frac_part / 10) + '0';
    str[i++] = (frac_part % 10) + '0';
    str[i] = '\0';
    return (str);
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
    int tmp = int_part;
    int len = 0;
    char buf[12];
    if (tmp == 0)
        buf[len++] = '0';
    else
    {
        while (tmp > 0)
        {
            buf[len++] = (tmp % 10) + '0';
            tmp /= 10;
        }
    }
    for (int j = len - 1; j >= 0; --j)
        str[i++] = buf[j];
    str[i++] = '.';
    str[i++] = (frac_part / 10) + '0';
    str[i++] = (frac_part % 10) + '0';
    str[i] = '\0';
    return (ft_fill_buf(str, i, int_part, frac_part));
}
