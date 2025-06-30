/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_file_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 04:04:47 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/30 18:20:40 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parse.h"

static int	rt_str_is_rt(char *format, int i)
{
	if (format[i] != '.')
		return (0);
	i++;
	if (format[i] != 'r')
		return (0);
	i++;
	if (format[i] != 't')
		return (0);
	i++;
	if (format[i] == '\0')
		return (1);
	return (0);
}

int	rt_valid_file_format(char *file)
{
	int	i;

	i = 0;
	if (!file)
		return (0);
	if (file[0] == '.')
		return (0);
	while (file[i] && file[i] != '.')
		i++;
	if (!file[i])
		return (0);
	return (rt_str_is_rt(file, i));
}
