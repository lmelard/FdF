/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:31:43 by lmelard           #+#    #+#             */
/*   Updated: 2022/05/24 13:22:10 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_isometric(t_point *point)
{
	int	prev_x;
	int	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = (prev_x - prev_y) * cos(30 * (M_PI / 180));
	point->y = (prev_x + prev_y) * sin(30 * (M_PI / 180)) - point->z ;
}

t_point	*ft_project(t_point *point, t_data *data)
{
	point->x *= data->zoom;
	point->y *= data->zoom;
	point->z *= data->altitude;
	ft_isometric(point);
	point->x += data->newx;
	point->y += data->newy;
	return (point);
}
