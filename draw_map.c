/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:25:32 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/18 18:41:56 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_map_ver(t_fdf *d, t_vec3 *tr_map, t_color *ver_col)
{
	int			i;
	int			j;
	int			k;

	j = 0;
	while (j < d->map->map_x)
	{
		i = 0;
		while (i < d->map->map_y -1)
		{
			k = (i * d->map->map_x) + j;
			gradient_line(&d->data.img, tr_map[k], tr_map[k + d->map->map_x],
				ft_set_gradient(ver_col[k], ver_col[k + d->map->map_x]));
			i++;
		}
		j++;
	}
}

static void	draw_map_hor(t_fdf *d, t_vec3 *tr_map, t_color *ver_col)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	while (i < d->map->map_y)
	{
		j = 0;
		while (j < d->map->map_x -1)
		{
			k = (i * d->map->map_x) + j;
			gradient_line(&d->data.img, tr_map[k], tr_map[k + 1],
				ft_set_gradient(ver_col[k], ver_col[k + 1]));
			j++;
		}
		i++;
	}
}

void	draw_map(t_fdf *d, t_vec3 *tr_map)
{
	t_color		*ver_col;

	ver_col = d->map->vertex_colors;
	draw_map_ver(d, tr_map, ver_col);
	draw_map_hor(d, tr_map, ver_col);
}
