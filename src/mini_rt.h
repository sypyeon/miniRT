/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 02:33:13 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/01 06:46:19 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H
# include <fcntl.h>
# include "../ft_printf/src/ft_printf.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_dvec
{
	double	*ptr;
	size_t	len;
	size_t	cap;
}	t_dvec;

void			_push_back(t_list **dyn, t_dvec *_Nonnull vec,
					const double value);
void			_push_front(t_list **dyn, t_dvec *_Nonnull vec,
					const double value);
double	*_Nullable	_pop_back(t_list **dyn, t_dvec *_Nullable vec);
void			_vecalloc(t_list **dyn, t_dvec *_Nonnull vec);
t_dvec	*_Nullable	_veccpy(t_list **dyn, const t_dvec v);
_Bool			_velem(const double c, const t_dvec v);
int				_veccmp(const t_dvec v1, const t_dvec v2);

#endif
