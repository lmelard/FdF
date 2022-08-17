/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:18:07 by lmelard           #+#    #+#             */
/*   Updated: 2022/05/24 20:25:19 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../mlx_linux/mlx.h"

void	ft_quit(t_img *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	mlx_loop_end(img->mlx_ptr);
	mlx_destroy_display(img->mlx_ptr);
	free(img->mlx_ptr);
	exit(0);
}

int	key_hook(int keycode, t_img *img)
{
	if (keycode == 65307)
		ft_quit(img);
	return (0);
}
