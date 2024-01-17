/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 04:26:54 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/09 20:45:06 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	error_msg(int error_code)
{
	if (error_code == INVALID_FORMAT)
		return (ft_printf("Error: Invalid file format.\n"));
	if (error_code == LOAD_ERROR)
		return (ft_printf("Error: Error occured while loading map.\n"));
	if (error_code == MLX_ERROR)
		return (ft_printf("Error: Get an error when using MiniLibX.\n"));
	return (0);
}

void	null_checker(t_fdf *fdf, void *value, int error_code)
{
	if (value == NULL)
	{
		error_msg(error_code);
		terminate_prog(fdf, EXIT_FAILURE);
	}
	return ;
}
