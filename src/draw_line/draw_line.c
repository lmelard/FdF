/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:37:27 by lmelard           #+#    #+#             */
/*   Updated: 2022/05/20 17:41:53 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

float	ft_abs(float nbr)
{
	if (nbr < 0)
		nbr = nbr * -1;
	return (nbr);
}

int	ft_get_color(t_point *p1, t_point *p2)
{
	int	color;

	if (p1->color == COLOR_LOW && p2->color == COLOR_LOW)
		color = COLOR_LOW;
	else if (p1->color == COLOR_LOW && p2->color == COLOR_HIGH)
		color = COLOR_HIGH;
	else if (p1->color == COLOR_HIGH && p2->color == COLOR_HIGH)
		color = COLOR_HIGH;
	else if (p1->color == COLOR_HIGH && p2->color == COLOR_LOW)
		color = COLOR_HIGH;
	return (color);
}

void	ft_draw_line(t_point *p1, t_point *p2, t_img *img)
{
	float	dx;
	float	dy;
	float	m;

	dx = ft_abs(p2->x - p1->x);
	dy = ft_abs(p2->y - p1->y);
	m = dy / dx;
	if (dy == 0)
		ft_draw_horizontal(p1, p2, img);
	else if (dx == 0)
		ft_draw_horizontal(p1, p2, img);
	else if (dx >= dy)
		ft_small_slope(p1, p2, img, m);
	else
		ft_big_slope(p1, p2, img, m);
}
