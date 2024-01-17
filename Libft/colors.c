/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 02:59:42 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/17 21:23:19 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color	set_color(__uint8_t a, __uint8_t r, __uint8_t g, __uint8_t b)
{
	t_color	color;

	color.alpha = a;
	color.red = r;
	color.green = g;
	color.blue = b;
	return (color);
}

t_color	get_gradient_val(t_color from, t_color to, double value)
{
	t_color	color;

	color.red = lerp(value, from.red, to.red);
	color.green = lerp(value, from.green, to.green);
	color.blue = lerp(value, from.blue, to.blue);
	return (color);
}

t_gradient	set_gradient(t_color from, t_color to)
{
	t_gradient	grad;

	grad.from = from;
	grad.to = to;
	return (grad);
}

t_gradient	inv_gradient(t_gradient in)
{
	t_gradient	out;

	out.from = in.to;
	out.to = in.from;
	return (out);
}
