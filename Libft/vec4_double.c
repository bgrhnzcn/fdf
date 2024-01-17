/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:49:32 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/19 01:21:16 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	vec4_dot(t_vec4 vec1, t_vec4 vec2)
{
	double	res;

	res = 0;
	res += vec1.x * vec2.x;
	res += vec1.y * vec2.y;
	res += vec1.z * vec2.z;
	res += vec1.w * vec2.w;
	return (res);
}

double	vec4_mag(t_vec4 vec)
{
	return (sqrt(vec4_dot(vec, vec)));
}
