/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:51:23 by buozcan           #+#    #+#             */
/*   Updated: 2024/01/18 22:25:46 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "fdf_structs.h"
# include "libft.h"
# include <math.h>
# include "mlx.h"
# include "ft_printf.h"
# include "get_next_line.h"

//Special include to work on multi platform.
# ifdef __linux__
#  include <X11/keysym.h>
#  define ESC_KEY XK_Escape
#  define X_KEY XK_x
#  define Z_KEY XK_z
#  define O_KEY XK_o
#  define P_KEY XK_p
# else
#  define ESC_KEY 53
#  define X_KEY 7
#  define Z_KEY 6
#  define O_KEY 31
#  define P_KEY 35
# endif

//Window Aspects
# define WIDTH		1000.
# define HEIGHT		1000.
//Ortographic Camera Options
# define O_TOP			10.
# define O_BOT			-10.
# define O_RIGHT		10.
# define O_LEFT			-10.
# define O_NEAR 		1.
# define O_FAR 			10.
//Perspective Camera Options
# define P_NEAR_CLIP	.1
# define P_FAR_CLIP		10.
# define P_FOV			70.
//Error codes
# define INVALID_FORMAT	0
# define LOAD_ERROR		1
# define MLX_ERROR		2
//Proj types
# define ORTHO			0
# define PERS			1

void		main_init(t_fdf *fdf, char *obj_path);
int			error_msg(int error_code);
int			terminate_prog(t_fdf *fdf, int exit_state);
void		null_checker(t_fdf *fdf, void *value, int error_code);
int			input(int keycode, t_fdf *fdf);
t_orto_conf	set_ort_conf(t_vec4 top_bot_right_left, t_vec2 near_far);
t_pers_conf	set_pers_conf(t_vec4 near_far_fov_aspect);
t_mtx4		orto_init(t_orto_conf configs);
t_mtx4		pers_init(t_pers_conf configs);
t_mtx4		transform_mtx(t_vec3 t, t_vec3 r, t_vec3 s);
t_vec3		graphic_pipeline(t_mtx4 proj, t_mtx4 mtx_glob,
				t_mtx4 mtx_loc, t_vec3 vec);
t_vec3		*renderer(t_fdf *d, int i, int j, int curr);
t_mtx4		transform_mtx(t_vec3 t, t_vec3 r, t_vec3 s);
t_mtx4		mtx4_rot(double x, double y, double z);
t_mtx4		mtx4_scale(double x, double y, double z);
t_mtx4		mtx4_trans(double x, double y, double z);
int			get_color(const char *str);
void		gradient_line(t_img *img, t_vec3 pt1, t_vec3 pt2, t_gradient grad);
void		draw_map(t_fdf *d, t_vec3 *tr_map);
int			draw_image(t_fdf *fdf);
int			fdf_get_size(t_fdf_data *d, t_fdf_map *map);
int			fdf_map_init_color(t_fdf_data *d, t_fdf_map *map, char *path);
t_fdf_map	*fdf_map_init(char *fdf_path);
int			fdf_map_init_pos_data(t_fdf_data *d, t_fdf_map *map, char *path);

#endif
