/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/0 00:51:9 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/0 00:55:59 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILS_H
# define RT_UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include "rt_struct.h"

void	rt_tab_to_space(char *str);
int		rt_strcmp(const char *str, const char *cmp);

int		rt_print_err_msg(const char *msg);

void	rt_free_split(char **split);
void	rt_free_obj(t_rt_info *info);

#endif