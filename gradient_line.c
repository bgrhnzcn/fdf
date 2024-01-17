/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:40:03 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/17 18:20:20 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drw_ln_hlpr_high(t_draw_line *d)
{
	d->x += d->inc;
	d->side_check = d->side_check + (2 * (d->delta.x - d->delta.y));
}

static void	drw_ln_hlpr_low(t_draw_line *d)
{
	d->y += d->inc;
	d->side_check = d->side_check + (2 * (d->delta.y - d->delta.x));
}

static void	draw_line_low(t_img *img, t_vec3 pt1, t_vec3 pt2, t_gradient gra)
{
	t_draw_line	d;

	d.delta.x = pt2.x - pt1.x;
	d.delta.y = pt2.y - pt1.y;
	d.inc = 1;
	if (d.delta.y < 0)
	{
		d.inc = -1;
		d.delta.y = -d.delta.y;
	}
	d.side_check = (2 * d.delta.y) - d.delta.x;
	d.y = pt1.y;
	d.x = pt1.x;
	while (d.x < pt2.x)
	{
		if (d.y <= HEIGHT && d.y >= 0 && d.x <= WIDTH && d.x >= 0)
			put_pixel(img, d.x, d.y, get_gradient_val(gra.from, gra.to,
					normalize(d.x, pt1.x, pt2.x)));
		if (d.side_check > 0)
			drw_ln_hlpr_low(&d);
		else
			d.side_check = d.side_check + (2 * d.delta.y);
		d.x++;
	}
}

static void	draw_line_high(t_img *img, t_vec3 pt1, t_vec3 pt2, t_gradient gra)
{
	t_draw_line	d;

	d.delta.x = pt2.x - pt1.x;
	d.delta.y = pt2.y - pt1.y;
	d.inc = 1;
	if (d.delta.x < 0)
	{
		d.inc = -1;
		d.delta.x = -d.delta.x;
	}
	d.side_check = (2 * d.delta.x) - d.delta.y;
	d.x = pt1.x;
	d.y = pt1.y;
	while (d.y <= pt2.y)
	{
		if (d.y <= HEIGHT && d.y >= 0 && d.x <= WIDTH && d.x >= 0)
			put_pixel(img, d.x, d.y, get_gradient_val(gra.from,
					gra.to, normalize(d.y, pt1.y, pt2.y)));
		if (d.side_check > 0)
			drw_ln_hlpr_high(&d);
		else
			d.side_check = d.side_check + (2 * d.delta.x);
		d.y++;
	}
}

void	gradient_line(t_img *img, t_vec3 pt1, t_vec3 pt2, t_gradient grad)
{
	if ((pt2.x > WIDTH && pt1.x > WIDTH) || (pt2.x < 0 && pt1.x < 0))
		return ;
	if ((pt2.y > HEIGHT && pt1.y > HEIGHT) || (pt2.y < 0 && pt1.y < 0))
		return ;
	if (fabs(pt2.y - pt1.y) < fabs(pt2.x - pt1.x))
	{
		if (pt1.x > pt2.x)
			draw_line_low(img, pt2, pt1, inv_gradient(grad));
		else
			draw_line_low(img, pt1, pt2, grad);
	}
	else
	{
		if (pt1.y > pt2.y)
			draw_line_high(img, pt2, pt1, inv_gradient(grad));
		else
			draw_line_high(img, pt1, pt2, grad);
	}
}
