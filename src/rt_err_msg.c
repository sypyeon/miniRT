/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_err_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 03:55:02 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/25 16:51:44 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils.h"

int	rt_print_err_msg(const char *msg)
{
	int	i;

	i = 0;
	write(STDERR_FILENO, "Error\n", 7);
	while (msg[i])
	{
		write(STDERR_FILENO, msg + i, 1);
		i++;
	}
	write(STDERR_FILENO, "\n", 1);
	return (1);
}
