/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:01:27 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/17 21:35:05 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strarrlen(char **arr)
{
	size_t	i;

	if (arr == NULL)
		return (0);
	i = 0;
	while (arr[i] && *arr[i] != '\n')
		i++;
	return (i);
}

void	free_str_arr(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}
