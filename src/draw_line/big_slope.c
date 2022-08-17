/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_slope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:30:27 by lmelard           #+#    #+#             */
/*   Updated: 2022/05/20 17:44:13 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_decreasing_y(t_point *p1, t_point *p2, t_img *img, float m)
{
	float	error;

	error = 0.0;
	while (p2->y <= p1->y)
	{
		my_pixel_put(img, p1->x, p1->y, ft_get_color(p1, p2));
		error = error + m;
		if (error >= 0.5)
		{
			if (p1->x < p2->x)
			{
				p1->x += 1;
				error = error - 1.0;
			}
			else
			{
				p1->x -= 1;
				error = error + 1.0;
			}
		}
		p1->y -= 1;
	}
}

static void	ft_increasing_y(t_point *p1, t_point *p2, t_img *img, float m)
{
	float	error;

	error = 0.0;
	while (p1->y <= p2->y)
	{
		my_pixel_put(img, p1->x, p1->y, ft_get_color(p1, p2));
		error = error + m;
		if (error >= 0.5)
		{
			if (p1->x < p2->x)
			{
				p1->x += 1;
				error = error - 1.0;
			}
			else
			{
				p1->x -= 1;
				error = error + 1.0;
			}
		}
		p1->y += 1;
	}
}

void	ft_big_slope(t_point *p1, t_point *p2, t_img *img, float m)
{
	if (p1->y > p2->y)
		ft_decreasing_y(p1, p2, img, m);
	else if (p1->y < p2->y)
		ft_increasing_y(p1, p2, img, m);
}
