/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:44:26 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/11/19 01:22:11 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec4	vec3_to_vec4(t_vec3 vec3, double w)
{
	return (vec4_set(vec3.x, vec3.y, vec3.z, w));
}

t_vec3	vec4_to_vec3(t_vec4 vec4)
{
	return(vec3_set(vec4.x, vec4.y, vec4.z));
}