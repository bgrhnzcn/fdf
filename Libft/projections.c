/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:53:25 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/09 19:05:53 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_orto_conf	set_ort_conf(t_vec4 top_bot_right_left, t_vec2 near_far)
{
	t_orto_conf	conf;

	conf.top = top_bot_right_left.x;
	conf.bot = top_bot_right_left.y;
	conf.right = top_bot_right_left.z;
	conf.left = top_bot_right_left.w;
	conf.near = near_far.x;
	conf.far = near_far.y;
	return (conf);
}

t_pers_conf	set_pers_conf(t_vec4 near_far_fov_aspect)
{
	t_pers_conf	conf;
	conf.near_clip = near_far_fov_aspect.x;
	conf.far_clip = near_far_fov_aspect.y;
	conf.field_of_view = near_far_fov_aspect.z;
	conf.aspect_ratio = near_far_fov_aspect.w;
	return (conf);
}

t_mtx4	orto_init(t_orto_conf configs)
{
	t_mtx4	mtx;
	t_vec4	col1;
	t_vec4	col2;
	t_vec4	col3;
	t_vec4	col4;

	col1 = vec4_set(2 / (configs.right - configs.left), 0, 0, 0);
	col2 = vec4_set(0, 2 / (configs.top - configs.bot), 0, 0);
	col3 = vec4_set(0, 0, -2 / (configs.far - configs.near), 0);
	col4 = vec4_set(-((configs.right + configs.left) / (configs.right - configs.left)),
	-((configs.top + configs.bot) / (configs.top - configs.bot)), -((configs.far + configs.near) / (configs.far - configs.near)), 1);
	mtx.col1 = col1;
	mtx.col2 = col2;
	mtx.col3 = col3;
	mtx.col4 = col4;
	return (mtx);
}

t_mtx4	pers_init(t_pers_conf configs)
{
	t_mtx4	mtx;
	t_vec4	col1;
	t_vec4	col2;
	t_vec4	col3;
	t_vec4	col4;

	col1 = vec4_set(configs.aspect_ratio / (tan(deg_to_rad(configs.field_of_view) / 2)), 0, 0, 0);
	col2 = vec4_set(0, 1 / tan(deg_to_rad(configs.field_of_view) / 2), 0, 0);
	col3 = vec4_set(0, 0,
			-(configs.near_clip + configs.far_clip) / (configs.near_clip - configs.far_clip), 1);
	col4 = vec4_set(0, 0,
			(2 * configs.far_clip * configs.near_clip) / (configs.near_clip - configs.far_clip), 0);
	mtx.col1 = col1;
	mtx.col2 = col2;
	mtx.col3 = col3;
	mtx.col4 = col4;
	return (mtx);
}
