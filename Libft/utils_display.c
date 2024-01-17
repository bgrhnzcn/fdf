/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:42:40 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/09 20:09:18 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	draw_tri(t_data *data, t_tri *tris, int j, t_color color)
{
	draw_line(data, tris[j].pts[0],
		tris[j].pts[1], color);
	draw_line(data, tris[j].pts[1],
		tris[j].pts[2], color);
	draw_line(data, tris[j].pts[2],
		tris[j].pts[0], color);
}

void	fill_img(t_data *data, t_color color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->win.width)
	{
		j = 0;
		while (j < data->win.height)
		{
			put_pixel(&(data->img), i, j, color);
			j++;
		}
		i++;
	}
}
