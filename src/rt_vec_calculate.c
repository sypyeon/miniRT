/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vec_calculate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 04:37:39 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/28 16:18:19 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils_vector.h"

double	rt_vec_inner(t_vec vec_1, t_vec vec_2)
{
	return (vec_1.x * vec_2.x + vec_1.y * vec_2.y + vec_1.z * vec_2.z);
}

t_vec	rt_vec_outer(t_vec vec_1, t_vec vec_2)
{
	t_vec new;

	new.x = vec_1.y * vec_2.z - vec_1.z * vec_2.y;
	new.y = vec_1.z * vec_2.x - vec_1.x * vec_2.z;
	new.z = vec_1.x * vec_2.y - vec_1.y * vec_2.x;
	return (new);
}

t_vec	rt_vec_unit(t_vec vec)
{
	double len = rt_vec_len(vec);
	if (len == 0)
	{
		printf("Error\n:Devider is 0");// 나중에 수정해야됨.
		exit(0);
	}
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}
