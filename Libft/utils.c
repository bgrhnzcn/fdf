/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:50:51 by buozcan           #+#    #+#             */
/*   Updated: 2024/01/17 17:06:51 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	deg_to_rad(double deg)
{
	return ((deg / 180) * PI);
}

double	rad_to_deg(double rad)
{
	return (rad * (180 / PI));
}

void	put_pixel(t_img *img, int x, int y, t_color color)
{
	char	*point;

	point = (img->data) + ((img->bits_per_pixel / 8) * x) + (img->size_line * y);
	*(unsigned int *)point = color.value;
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

int	ft_atoi_hex(const char *str)
{
	int	res;
	int	len;
	int	digit;

	if (str == NULL)
		return (0xFFFFFF);
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
