/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_straight_lines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:01:50 by lmelard           #+#    #+#             */
/*   Updated: 2022/05/20 17:02:34 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_draw_horizontal(t_point *p1, t_point *p2, t_img *img)
{
	if (p1->x > p2->x)
	{
		while (p2->x <= p1->x)
		{
			my_pixel_put(img, p1->x, p1->y, ft_get_color(p1, p2));
			p1->x -= 1;
		}
	}
	else
	{
		while (p1->x <= p2->x)
		{
			my_pixel_put(img, p1->x, p1->y, ft_get_color(p1, p2));
			p1->x += 1;
		}
	}
}

void	ft_draw_vertical(t_point *p1, t_point *p2, t_img *img)
{
	if (p1->y > p2->y)
	{
		while (p2->y <= p1->y)
		{
			my_pixel_put(img, p1->x, p1->y, ft_get_color(p1, p2));
			p1->y -= 1;
		}
	}
	else
	{
		while (p1->y <= p2->y)
		{
			my_pixel_put(img, p1->x, p1->y, ft_get_color(p1, p2));
			p1->y += 1;
		}
	}
}
