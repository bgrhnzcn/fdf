/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:17:19 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/17 21:29:47 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_ortho(t_fdf *fdf)
{
	fdf->data.proj_mtx = orto_init(set_ort_conf(vec4_set(
						O_TOP, O_BOT, O_RIGHT, O_LEFT),
					vec2_set(O_NEAR, O_FAR)));
	fdf->data.mtx_loc = transform_mtx(vec3_set(-2, -2, 0),
			vec3_set(45, 35.16, 0), vec3_add(vec3_set(1, 1, 1), fdf->scale));
	fdf->data.mtx_glob = transform_mtx(vec3_set(0, 0, 0),
			vec3_set(0, 0, 0), vec3_set(1, 1, 1));
	draw_image(fdf);
	mlx_put_image_to_window(fdf->data.mlx, fdf->data.win.win,
					fdf->data.img.img, 0, 0);
}

void	draw_pers(t_fdf *fdf)
{
	fdf->data.proj_mtx = pers_init(set_pers_conf(
					vec4_set(P_NEAR_CLIP, P_FAR_CLIP, P_FOV, P_ASPECT_R)));
	fdf->data.mtx_loc = transform_mtx(vec3_set(-2, -2, -20),
			vec3_set(45, 35.16, 0), vec3_add(vec3_set(1, 1, 1), fdf->scale));
	fdf->data.mtx_glob = transform_mtx(vec3_set(0, 0, 0),
			vec3_set(0, 0, 0), vec3_set(1, 1, 1));
	draw_image(fdf);
	mlx_put_image_to_window(fdf->data.mlx, fdf->data.win.win,
						fdf->data.img.img, 0, 0);
}

int	input(int keycode, t_fdf *fdf)
{
	if (keycode == O_KEY)
		fdf->proj_type = ORTHO;
	if (keycode == P_KEY)
		fdf->proj_type = PERS;
	if (keycode == ESC_KEY)
		terminate_prog(fdf, EXIT_SUCCESS);
	if (keycode == Z_KEY)
	{
		fdf->scale = vec3_add(fdf->scale, vec3_set(1, 1, 1));
		if (fdf->proj_type == PERS)
			draw_pers(fdf);
		else
			draw_ortho(fdf);
	}
	if (keycode == X_KEY)
	{
		fdf->scale = vec3_add(fdf->scale, vec3_set(-1, -1, -1));
		if (fdf->proj_type == PERS)
			draw_pers(fdf);
		else
			draw_ortho(fdf);
	}
	return (0);
}

int	terminate_prog(t_fdf *fdf, int exit_state)
{
	if (fdf->data.img.img != NULL)
		mlx_destroy_image(fdf->data.mlx, fdf->data.img.img);
	if (fdf->data.win.win != NULL)
		mlx_destroy_window(fdf->data.mlx, fdf->data.win.win);
	if (fdf->map != NULL && fdf->map->verteces != NULL)
		free(fdf->map->verteces);
	if (fdf->map != NULL && fdf->map->vertex_colors != NULL)
		free(fdf->map->vertex_colors);
	if (fdf->map != NULL)
		free(fdf->map);
	free(fdf);
	exit(exit_state);
	return (0);
}
