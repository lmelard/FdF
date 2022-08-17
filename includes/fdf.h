/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:59:46 by lenamelard        #+#    #+#             */
/*   Updated: 2022/05/26 15:35:01 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <math.h>

# define BUFFER_SIZE 100
# define WIN_WIDTH 1600
# define WIN_HEIGHT 1000
# define COLOR_LOW 0x007733FF
# define COLOR_HIGH 0x0033FFA8

typedef struct s_data {
	int		height;
	int		width;
	float	altitude;
	float	zoom;
	int		newx;
	int		newy;
	int		**tab;
}			t_data;

typedef struct s_img {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}			t_img;

typedef struct s_point {
	int	x;
	int	y;
	int	z;
	int	color;
}			t_point;

size_t		ft_strlen(char *s);
size_t		ft_strlcpy(char *dst, char *src);
size_t		ft_strlcat(char *dst, char *src);
char		*ft_strjoin(char *s1, char *s2);
void		ft_bzero(void *s, size_t n);
size_t		ft_check_n(char *s1);
char		*ft_get_line(char *s1);
char		*ft_get_buffer(char *tmp);
char		*ft_find_line(char **tmp, char **line);
char		*get_next_line(int fd);
int			ft_get_height(char *file);
int			ft_get_width(char *file);
int			**ft_free_all(int **tab, int i);
char		**ft_split_fdf(char *s, char c, int width);
long int	ft_atoi_fdf(char *str);
int			**ft_read_map(char *file, t_data *data);
int			*ft_fill_line(int *data, char *line, int width);
void		ft_init_struct(t_data *data, char *file);
void		ft_del_struct(t_data *data);
void		my_pixel_put(t_img *img, int x, int y, int color);
void		ft_draw_map(t_data *data, t_img *img);
float		ft_abs(float nbr);
void		ft_isometric(t_point *point);
t_point		*ft_project(t_point *point, t_data *data);
void		ft_draw_line(t_point *start, t_point *end, t_img *img);
int			ft_min(int a, int b);
t_point		ft_init_point(int x, int y, t_data *data);
void		ft_small_slope(t_point *p1, t_point *p2, t_img *img, float m);
void		ft_big_slope(t_point *p1, t_point *p2, t_img *img, float m);
void		ft_draw_horizontal(t_point *p1, t_point *p2, t_img *img);
void		ft_draw_vertical(t_point *p1, t_point *p2, t_img *img);
int			ft_get_color(t_point *p1, t_point *p2);
void		ft_quit(t_img *img);
int			key_hook(int keycode, t_img *img);

#endif
