/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:34:50 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/17 20:53:46 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

#include "Libft/structs.h"

typedef struct s_fdf_map
{
	t_vec3	*verteces;
	t_color	*vertex_colors;
	int		map_x;
	int		map_y;
}	t_fdf_map;

typedef struct s_fdf_data
{
	char		**data;
	char		*line;
	int			fdf_file;
	int			i;
	int			j;
}	t_fdf_data;

typedef struct s_fdf
{
	t_data		data;
	t_fdf_map	*map;
	t_vec3		translation;
	t_vec3		rotation;
	t_vec3		scale;
	int			proj_type;
}	t_fdf;

#endif
