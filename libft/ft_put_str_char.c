/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:15:05 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/27 16:42:09 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(int c)
{
	c = (unsigned char)c;
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}
