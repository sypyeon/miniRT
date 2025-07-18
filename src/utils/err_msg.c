/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:36:47 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/18 21:53:13 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>

int	print_err_msg(const char *msg)
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
