/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:01:42 by vferreir          #+#    #+#             */
/*   Updated: 2018/03/04 20:36:23 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "mlx_keycode.h"
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# define SCREEN_WIDTH 980
# define SCREEN_HEIGHT 720
# define ITERATION_MAX 100

typedef struct	s_mlx
{
	void		*mlx;
	void		*windows;
	void		*image;
	void		*image_menu;
	char		*data_menu;
	char		*data;
	int			endian;
	int			bpp;
	int			size_line;
}				t_mlx;

typedef struct	s_map
{
	t_mlx		*mlx;
	int			mandelbrot;
	int			julia;
	double		julia_cr;
	double		julia_ci;
	int			newton;
	int			lock;
	int			affichage_zoom;
	double		zoom;
	double		pos_x;
	double		pos_y;
	int			key_hook[300];
}				t_map;

void			fractal_select(t_map *map);
int				motion_hook(int x, int y, t_map *map);
void			initialisation_minilibix(t_mlx *mlx);
void			set_value(t_map *map);
void			ft_put_pixel(t_mlx *mlx, int x, int y, int couleur);
void			ft_clean_image(t_map *map);
int				my_key_funct(int keycode, t_map *map);
int				my_mouse_funct(int keycode, int pos_x, int pos_y, t_map *map);
void			fractal_mandelbrot(t_map *map);
void			fractal_julia(t_map *map);
void			fractal_newton(t_map *map);
void			printf_info(t_map *map);
int				do_change(t_map *map);
int				fct_key(int keycode, t_map *map);
void			add_cross(t_map *map);

#endif
