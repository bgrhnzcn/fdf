/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_vec2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:32:30 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/19 01:21:48 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec2	vec2_inv(t_vec2 vec)
{
	t_vec2	vec2_res;

	vec2_res.x = -vec.x;
	vec2_res.y = -vec.y;
	return (vec2_res);
}

t_vec2	vec2_norm(t_vec2 vec)
{
	return (vec2_div(vec, vec2_mag(vec)));
}
