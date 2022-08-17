/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:11:09 by lmelard           #+#    #+#             */
/*   Updated: 2022/05/26 17:02:16 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx_linux/mlx.h"

static void	ft_wrong_arg(void)
{
	write(1, "Error : wrong number of arguments\n", 34);
	exit(EXIT_FAILURE);
}

static void	ft_check_directory(char *file)
{
	int	fd;

	fd = 0;
	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
	{
		write(1, "Error\n", 6);
		close(fd);
		exit(EXIT_FAILURE);
	}
	else
		close(fd);
}

int	main(int argc, char **argv)
{
	t_img	img;
	t_data	data;

	if (argc == 2)
	{
		ft_check_directory(argv[1]);
		ft_init_struct(&data, argv[1]);
		img.mlx_ptr = mlx_init();
		img.win_ptr = mlx_new_window(img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
		img.img = mlx_new_image(img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_lenght, &img.endian);
		ft_draw_map(&data, &img);
		ft_del_struct(&data);
		mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);
		mlx_key_hook(img.win_ptr, key_hook, &img);
		mlx_hook(img.win_ptr, 17, 1L << 17, (void *)ft_quit, &img);
		mlx_loop(img.mlx_ptr);
	}
	else
		ft_wrong_arg();
	return (0);
}
