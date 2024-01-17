/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:42:40 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/09 20:47:54 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	*renderer(t_fdf *d, int i, int j, int curr)
{
	t_vec3	*trans_map;

	trans_map = malloc(d->map->map_x * d->map->map_y * sizeof(t_vec3));
	if (trans_map == NULL)
		return (NULL);
	while (i < d->map->map_y)
	{
		j = 0;
		while (j < d->map->map_x)
		{
			curr = (i * d->map->map_x) + j;
			trans_map[curr] = graphic_pipeline(d->data.proj_mtx,
					d->data.mtx_glob, d->data.mtx_loc, d->map->verteces[curr]);
			j++;
		}
		i++;
	}
	return (trans_map);
}

int	draw_image(t_fdf *fdf)
{
	t_vec3		*trans_map;

	fill_img(&fdf->data, set_color(0, 0, 0, 0));
	trans_map = renderer(fdf, 0, 0, 0);
	if (trans_map == NULL)
		exit(1);
	draw_map(fdf, trans_map);
	free(trans_map);
	mlx_put_image_to_window(fdf->data.mlx, fdf->data.win.win, fdf->data.img.img, 0, 0);
	fdf->data.time++;
	return (0);
}
