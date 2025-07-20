/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:05:37 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/27 16:42:15 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_s(char *arg)
{
	int	str_len;

	if (!arg)
		return (write(1, "(null)", 6));
	str_len = ft_strlen(arg);
	write (1, arg, str_len);
	return (str_len);
}
