/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:09:54 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/18 22:48:53 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	ft_tab_to_space(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		if (*str == '\t')
			*str = ' ';
		str++;
	}
}
