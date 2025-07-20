/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:51:42 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/27 16:46:38 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_d(int arg)
{
	char	*s;
	int		len;

	s = ft_l_itoa((long)arg);
	if (!s)
		return (-1);
	len = write(1, s, ft_strlen(s));
	free(s);
	return (len);
}
