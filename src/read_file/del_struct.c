/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:24:24 by lmelard           #+#    #+#             */
/*   Updated: 2022/05/24 19:19:16 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	ft_del_struct(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->tab[i]);
		data->tab[i] = NULL;
		i++;
	}
	free(data->tab);
	data->tab = NULL;
}
