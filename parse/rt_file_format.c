/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_file_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 04:04:47 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/03 04:11:37 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parse.h"

static int	rt_str_is_rt(char *format)
{
	if (*format != 'r')
		return (0);
	format++;
	if (*format != 't')
		return (0);
	format++;
	if (*format == '\0')
		return (1);
	return (0);
}

int	rt_valid_file_format(char *file)
{
	if (!file)
		return (0);
	if (*file == '.')
		return (0);
	while (*file && *file != '.')
		file++;
	if (!*file)
		return (0);
	return (rt_str_is_rt(file));
}
