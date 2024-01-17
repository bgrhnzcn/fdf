/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:14:42 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/12/06 17:07:36 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_get_size(t_fdf_data *d, t_fdf_map *map)
{
	map->map_x = 0;
	map->map_y = 0;
	while (1)
	{
		d->line = get_next_line(d->fdf_file);
		if (d->line == NULL)
			return (0);
		d->data = ft_split(d->line, ' ');
		if (d->data == NULL)
			return (free(d->line), -1);
		if (map->map_x == 0)
			map->map_x = ft_strarrlen(d->data);
		if (map->map_x != (int)ft_strarrlen(d->data))
		{
			free_str_arr(d->data);
			return (free(d->line), -1);
		}
		map->map_y++;
		free_str_arr(d->data);
		free(d->line);
	}
	return (0);
}

static int	fdf_map_get_pos_data(t_fdf_data *d, t_fdf_map *map)
{
	d->j = 0;
	while (d->j < map->map_y)
	{
		d->line = get_next_line(d->fdf_file);
		if (d->line == NULL)
			return (0);
		d->data = ft_split(d->line, ' ');
		if (d->data == NULL)
			return (free(d->line), -1);
		d->i = 0;
		while (d->i < map->map_x)
		{
			map->verteces[d->i + (map->map_x * d->j)].x = d->i;
			map->verteces[d->i + (map->map_x * d->j)].y = d->j;
			map->verteces[d->i + (map->map_x * d->j)].z
				= ft_atoi(d->data[d->i]);
			d->i++;
		}
		d->j++;
		free_str_arr(d->data);
		free(d->line);
	}
	return (0);
}

int	fdf_map_init_pos_data(t_fdf_data *d, t_fdf_map *map, char *path)
{
	int	res;

	ft_printf("Loading Position Data...\n");
	map->verteces = malloc(sizeof(t_vec3) * ((map->map_x * map->map_y) + 1));
	if (map->verteces == NULL)
		return (-1);
	d->fdf_file = open(path, O_RDONLY);
	res = fdf_map_get_pos_data(d, map);
	close(d->fdf_file);
	if (res == -1)
	{
		free(map->verteces);
		return (-1);
	}
	return (0);
}

static int	fdf_map_get_color(t_fdf_data *d, t_fdf_map *map)
{
	d->j = 0;
	while (d->j < map->map_y)
	{
		d->line = get_next_line(d->fdf_file);
		if (d->line == NULL)
			return (0);
		d->data = ft_split(d->line, ' ');
		if (d->data == NULL)
			return (free(d->line), -1);
		d->i = 0;
		while (d->i < map->map_x)
		{
			map->vertex_colors[d->i + (map->map_x * d->j)].value = ft_atoi_hex(
					ft_strnstr(d->data[d->i], "0x",
						ft_strlen(d->data[d->i])));
			d->i++;
		}
		d->j++;
		free_str_arr(d->data);
		free(d->line);
	}
	return (0);
}

int	fdf_map_init_color(t_fdf_data *d, t_fdf_map *map, char *path)
{
	int	res;

	ft_printf("Loading Color Data...\n");
	map->vertex_colors = malloc(sizeof(int) * map->map_x * map->map_y);
	if (map->vertex_colors == NULL)
		return (-1);
	d->fdf_file = open(path, O_RDONLY);
	res = fdf_map_get_color(d, map);
	close(d->fdf_file);
	if (res == -1)
	{
		free(map->vertex_colors);
		return (-1);
	}
	return (0);
}
