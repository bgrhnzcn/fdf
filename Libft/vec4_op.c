/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:40:31 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/19 01:21:08 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec4	vec4_set(double x, double y, double z, double w)
{
	t_vec4	vec_res;

	vec_res.x = x;
	vec_res.y = y;
	vec_res.z = z;
	vec_res.w = w;
	return (vec_res);
}

t_vec4	vec4_add(t_vec4 vec1, t_vec4 vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	vec1.z += vec2.z;
	vec1.w += vec2.w;
	return (vec1);
}

t_vec4	vec4_sub(t_vec4 vec1, t_vec4 vec2)
{
	vec1.x -= vec2.x;
	vec1.y -= vec2.y;
	vec1.z -= vec2.z;
	vec1.w -= vec2.w;
	return (vec1);
}

t_vec4	vec4_mul(t_vec4 vec, double mul)
{
	vec.x /= mul;
	vec.y /= mul;
	vec.z /= mul;
	vec.w /= mul;
	return (vec);
}

t_vec4	vec4_div(t_vec4 vec, double div)
{
	vec.x /= div;
	vec.y /= div;
	vec.z /= div;
	vec.w /= div;
	return (vec);
}