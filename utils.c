/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:42:40 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/18 18:37:52 by bgrhnzcn         ###   ########.fr       */
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
			trans_map[curr] = graphic_pipeline(d->proj_mtx,
					d->mtx_glob, d->mtx_loc, d->map->verteces[curr]);
			j++;
		}
		i++;
	}
	return (trans_map);
}

int	draw_image(t_fdf *fdf)
{
	t_vec3		*trans_map;

	ft_fill_img(&fdf->data, ft_set_color(0, 0, 0, 0));
	trans_map = renderer(fdf, 0, 0, 0);
	if (trans_map == NULL)
		exit(1);
	draw_map(fdf, trans_map);
	free(trans_map);
	mlx_put_image_to_window(fdf->data.mlx, fdf->data.win.win,
		fdf->data.img.img, 0, 0);
	fdf->data.time++;
	return (0);
}

static int	get_int_value_of_hex(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	if (c >= 'A' && c <= 'F')
		return (c - 55);
	if (c >= 'a' && c <= 'f')
		return (c - 87);
	return (0);
}

int	get_color(const char *str)
{
	int	res;
	int	len;
	int	digit;

	if (str == NULL)
		return (0xFFFFFFFF);
	len = ft_strlen(str) - 2;
	digit = 0;
	res = 0;
	while (len > 0)
	{
		res += get_int_value_of_hex(str[len + 1]) * pow(16, digit);
		digit++;
		len--;
	}
	return (res);
}
