/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_min_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:57:08 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/03 04:39:23 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils.h"

t_vec	rt_vec_min(t_vec vec_1, t_vec vec_2)
{
	if (vec_1.x > vec_2.x)
		vec_1.x = vec_2.x;
	if (vec_1.y > vec_2.y)
		vec_1.y = vec_2.y;
	if (vec_1.z > vec_2.z)
		vec_1.z = vec_2.z;
	return (vec_1);
}
