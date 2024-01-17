/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:38:33 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/19 01:22:03 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec2	vec2_set(double x, double y)
{
	t_vec2	vec_res;

	vec_res.x = x;
	vec_res.y = y;
	return (vec_res);
}

t_vec2	vec2_add(t_vec2 vec1, t_vec2 vec2)
{
	t_vec2	vec_res;
	
	vec_res.x = vec1.x + vec2.x;
	vec_res.y = vec1.y + vec2.y;
	return (vec_res);
}

t_vec2	vec2_sub(t_vec2	vec1, t_vec2 vec2)
{
	t_vec2	vec_res;

	vec_res.x = vec1.x - vec2.x;
	vec_res.y = vec1.y - vec2.y;
	return (vec_res);
}

t_vec2	vec2_mul(t_vec2 vec, double mul)
{
	t_vec2	vec_res;

	vec_res.x = vec.x * mul;
	vec_res.y = vec.y * mul;
	return (vec_res);
}

t_vec2	vec2_div(t_vec2 vec, double div)
{
	t_vec2	vec_res;

	vec_res.x = vec.x / div;
	vec_res.y = vec.y / div;
	return (vec_res);
}
