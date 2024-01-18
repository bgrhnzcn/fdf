/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:03:36 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/18 18:38:12 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mtx4	mtx4_trans(double x, double y, double z)
{
	t_mtx4	translation;

	translation.col1 = ft_vec4_set(1, 0, 0, x);
	translation.col2 = ft_vec4_set(0, 1, 0, y);
	translation.col3 = ft_vec4_set(0, 0, 1, z);
	translation.col4 = ft_vec4_set(0, 0, 0, 1);
	return (translation);
}

t_mtx4	mtx4_scale(double x, double y, double z)
{
	t_mtx4	scale;

	scale.col1 = ft_vec4_set(x, 0, 0, 0);
	scale.col2 = ft_vec4_set(0, y, 0, 0);
	scale.col3 = ft_vec4_set(0, 0, z, 0);
	scale.col4 = ft_vec4_set(0, 0, 0, 1);
	return (scale);
}

t_mtx4	mtx4_rot(double x, double y, double z)
{
	t_mtx4	rot;

	x = ft_deg_to_rad(x);
	y = ft_deg_to_rad(y);
	z = ft_deg_to_rad(z);
	rot.col1 = ft_vec4_set(
			cos(y) * cos(z),
			cos(y) * sin(z),
			-sin(y), 0);
	rot.col2 = ft_vec4_set(
			(sin(x) * sin(y) * cos(z)) - (cos(x) * sin(z)),
			(sin(x) * sin(y) * sin(z)) + (cos(x) * cos(z)),
			(sin(x) * cos(y)), 0);
	rot.col3 = ft_vec4_set(
			(cos(x) * sin(y) * cos(z)) + (sin(x) * sin(z)),
			(cos(x) * sin(y) * sin(z)) - (sin(x) * cos(z)),
			cos(x) * cos(y), 0);
	rot.col4 = ft_vec4_set(0, 0, 0, 1);
	return (rot);
}

t_mtx4	transform_mtx(t_vec3 t, t_vec3 r, t_vec3 s)
{
	t_mtx4	mtx;

	r.x = ft_deg_to_rad(r.x);
	r.y = ft_deg_to_rad(r.y);
	r.z = ft_deg_to_rad(r.z);
	mtx.col1 = ft_vec4_set(
			cos(r.y) * cos(r.z),
			cos(r.y) * sin(r.z),
			-sin(r.y), 0);
	mtx.col2 = ft_vec4_set(
			(sin(r.x) * sin(r.y) * cos(r.z)) - (cos(r.x) * sin(r.z)),
			(sin(r.x) * sin(r.y) * sin(r.z)) + (cos(r.x) * cos(r.z)),
			(sin(r.x) * cos(r.y)), 0);
	mtx.col3 = ft_vec4_set(
			(cos(r.x) * sin(r.y) * cos(r.z)) + (sin(r.x) * sin(r.z)),
			(cos(r.x) * sin(r.y) * sin(r.z)) - (sin(r.x) * cos(r.z)),
			cos(r.x) * cos(r.y), 0);
	mtx.col1 = ft_vec4_mul(mtx.col1, s.x);
	mtx.col2 = ft_vec4_mul(mtx.col2, s.y);
	mtx.col3 = ft_vec4_mul(mtx.col3, s.z);
	mtx.col4 = ft_vec4_set(t.x, t.y, t.z, 1);
	return (mtx);
}
