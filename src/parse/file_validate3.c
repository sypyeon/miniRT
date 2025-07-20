/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validate3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 22:15:49 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/19 01:27:50 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/structures.h"
#include "../../includes/parse.h"

int	rt_is_comma_or_period(char c)
{
	return (c == '.' || c == ',');
}

void	rt_check_numbers_in_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (rt_is_comma_or_period(line[i]))
		{
			i++;
			if (line[i] == '-' || line[i] == '+')
				i++;
			if (!ft_isdigit(line[i]))
			{
				free(line);
				exit(rt_print_err_msg("Invalid numbers found."));
			}
		}
		i++;
	}
}

char	**rt_gnl_and_split(char *file)
{
	int		fd;
	char	*buf;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(rt_print_err_msg("open failure."));
	line = ft_strdup("");
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		line = rt_strjoin_and_free(line, buf);
	}
	rt_tab_to_space(line);
	rt_check_numbers_in_line(line);
	split = ft_split(line, '\n');
	free(line);
	return (split);
}

void	rt_file_validate_and_save_data(char *file, t_rt_info *info)
{
	t_bool	invalid;
	int		i;
	char	**split;

	if (!rt_valid_file_format(file))
		exit(rt_print_err_msg("Wrong file format."));
	split = rt_gnl_and_split(file);
	if (!split)
		exit(rt_print_err_msg("Split failure."));
	i = 0;
	while (split[i])
	{
		invalid = rt_split_and_identify_line(split[i], info);
		if (invalid)
		{
			rt_free_obj(info);
			rt_free_split(split);
			exit (1);
		}
		i++;
	}
	rt_free_split(split);
	info->current_obj = info->obj_lst.head;
}
