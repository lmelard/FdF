/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_slope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:10:38 by lmelard           #+#    #+#             */
/*   Updated: 2022/05/20 17:43:53 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_decreasing_x(t_point *p1, t_point *p2, t_img *img, float m)
{
	float	error;

	error = 0.0;
	while (p2->x <= p1->x)
	{
		my_pixel_put(img, p1->x, p1->y, ft_get_color(p1, p2));
		error = error + m;
		if (error >= 0.5)
		{
			if (p1->y < p2->y)
			{
				p1->y += 1;
				error = error - 1.0;
			}
			else
			{
				p1->y -= 1;
				error = error + 1.0;
			}
		}
		p1->x -= 1;
	}
}

static void	ft_increasing_x(t_point *p1, t_point *p2, t_img *img, float m)
{
	float	error;

	error = 0.0;
	while (p1->x <= p2->x)
	{
		my_pixel_put(img, p1->x, p1->y, ft_get_color(p1, p2));
		error = error + m;
		if (error >= 0.5)
		{
			if (p1->y < p2->y)
			{
				p1->y += 1;
				error = error - 1.0;
			}
			else
			{
				p1->y -= 1;
				error = error + 1.0;
			}
		}
		p1->x += 1;
	}
}

void	ft_small_slope(t_point *p1, t_point *p2, t_img *img, float m)
{
	if (p1->x > p2->x)
		ft_decreasing_x(p1, p2, img, m);
	else if (p1->x < p2->x)
		ft_increasing_x(p1, p2, img, m);
}
