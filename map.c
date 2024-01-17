/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:41:35 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/17 15:50:02 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	normalize(double val, double min, double max)
{
	if (min == max)
		return (0);
	return ((val - min) / (max - min));
}

double	lerp(double val, double min, double max)
{
	return ((val * (max - min)) + min);
}
