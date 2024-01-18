/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:53:25 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/18 18:43:46 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf_map	*fdf_map_init(char *fdf_path)
{
	t_fdf_data	data;
	t_fdf_map	*map;
	int			map_status;

	ft_printf("Loading Map...\n");
	map = malloc(sizeof(t_fdf_map));
	if (map == NULL)
		return (NULL);
	data.fdf_file = open(fdf_path, O_RDONLY);
	map_status = fdf_get_size(&data, map);
	close(data.fdf_file);
	if (map_status == -1)
		return (NULL);
	if (map_status == 0 && map->map_y == 0)
		return (NULL);
	if (fdf_map_init_pos_data(&data, map, fdf_path) == -1)
		return (NULL);
	if (fdf_map_init_color(&data, map, fdf_path) == -1)
		return (NULL);
	return (map);
}

void	main_init(t_fdf *fdf, char *obj_path)
{
	fdf->data.win.height = HEIGHT;
	fdf->data.win.width = WIDTH;
	fdf->data.mlx = mlx_init();
	null_checker(fdf, fdf->data.mlx, MLX_ERROR);
	fdf->proj_mtx = orto_init(set_ort_conf(ft_vec4_set(
					O_TOP, O_BOT, O_RIGHT, O_LEFT),
				ft_vec2_set(O_NEAR, O_FAR)));
	fdf->translation = ft_vec3_set(0, 0, 0);
	fdf->rotation = ft_vec3_set(0, 0, 0);
	fdf->scale = ft_vec3_set(1, 1, 1);
	mlx_do_key_autorepeaton(fdf->data.mlx);
	fdf->map = fdf_map_init(obj_path);
	null_checker(fdf, fdf->map, LOAD_ERROR);
	ft_printf("Map Loaded Succesfully...\n");
	fdf->data.win.win = mlx_new_window(fdf->data.mlx, WIDTH, HEIGHT, "Test");
	null_checker(fdf, fdf->data.win.win, MLX_ERROR);
	fdf->data.img.img = mlx_new_image(fdf->data.mlx, WIDTH, HEIGHT);
	null_checker(fdf, fdf->data.img.img, MLX_ERROR);
	fdf->data.img.data = mlx_get_data_addr(fdf->data.img.img,
			&fdf->data.img.bits_per_pixel,
			&fdf->data.img.size_line, &fdf->data.img.endian);
	null_checker(fdf, fdf->data.img.data, MLX_ERROR);
}
