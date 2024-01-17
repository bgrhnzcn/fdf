/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:08:20 by buozcan           #+#    #+#             */
/*   Updated: 2023/12/07 17:06:58 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Transformation from Clip Space to Screen Space.
static t_vec3	clip_to_screen(t_vec3 vec)
{
	vec = vec3_add(vec, vec3_set(1, 1, 0));
	vec.x *= 0.5 * WIDTH;
	vec.y *= 0.5 * HEIGHT;
	return (vec);
}

/*This function is part of the Graphics pipeline.
Used for local space transformations.*/
static t_vec4	loc_trans(t_mtx4 mtx, t_vec3 vec)
{
	return (mtx_vec_mul4(mtx, vec3_to_vec4(vec, 1)));
}

/*This function is part of the Graphics pipeline.
Used for global space transformations.*/
static t_vec4	glob_trans(t_mtx4 mtx_glob, t_mtx4 mtx_loc, t_vec3 vec)
{
	return (mtx_vec_mul4(mtx_glob, loc_trans(mtx_loc, vec)));
}

/*Transformation from Global Space to Clip Space.
proj = Selected projection matrix.*/
static t_vec4	glob_to_clip(t_mtx4 proj, t_mtx4 mtx_glob,
				t_mtx4 mtx_loc, t_vec3 vec)
{
	return (mtx_vec_mul4(proj, glob_trans(mtx_glob, mtx_loc, vec)));
}

t_vec3	graphic_pipeline(t_mtx4 proj, t_mtx4 mtx_glob,
				t_mtx4 mtx_loc, t_vec3 vec)
{
	t_vec4	temp;

	temp = glob_to_clip(proj, mtx_glob, mtx_loc, vec);
	if (temp.w != 0)
		temp = vec4_div(temp, temp.w);
	return (clip_to_screen(vec4_to_vec3(temp)));
}
