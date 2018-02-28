/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:31:22 by vferreir          #+#    #+#             */
/*   Updated: 2018/02/21 16:31:23 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void printf_info(t_map *map)
{
  char *string;
  char *tmp;

  // Zoom
  string = ft_strdup("Zoom : ");
  tmp = ft_itoa(map->zoom);
  string = ft_strjoindel(string, tmp);
  free(tmp);
  mlx_string_put(map->mlx->mlx, map->mlx->windows, 10, 10, 0xFC5D5D, string);
  free(string);
  // Pos x
  string = ft_strdup("Pos x = ");
  tmp = ft_itoa(map->pos_x * SCREEN_WIDTH / 2);
  string = ft_strjoindel(string, tmp);
  free(tmp);
  mlx_string_put(map->mlx->mlx, map->mlx->windows, 10, 30, 0xFC5D5D, string);
  free(string);
  // Pos y
  string = ft_strdup("Pos y = ");
  tmp = ft_itoa((map->pos_y * SCREEN_HEIGHT / 2) * -1);
  string = ft_strjoindel(string, tmp);
  free(tmp);
  mlx_string_put(map->mlx->mlx, map->mlx->windows, 10, 50, 0xFC5D5D, string);
  free(string);
}

void add_cross(t_map *map)
{
  int i;

  i = 15 * SCREEN_WIDTH / 32;
  while (++i < 17 * SCREEN_WIDTH / 32)
    ft_put_pixel(map->mlx, i, SCREEN_HEIGHT / 2, 0xFC5D5D);
  i = 14.8 * SCREEN_HEIGHT / 32;
  while (++i < 17.2 * SCREEN_HEIGHT / 32)
    ft_put_pixel(map->mlx, SCREEN_WIDTH / 2, i, 0xFC5D5D);
}

static int magie_noir(double x, double y)
{
	int i = 0;
	double ima_r = 0;
	double ima_i = 0;
	double tmp_r = 0;

	while (ima_r * ima_r + ima_i * ima_i < 4 && i < ITERATION_MAX)
	{
		tmp_r = ima_r;
		ima_r = ima_r * ima_r - ima_i * ima_i + x;
		ima_i = 2 * tmp_r * ima_i + y;
		i++;
	}
	return (i);
}

void fractal_mandelbrot(t_map *map)
{
	int  x;
	int  y;
	int i;

  y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		x = -1;
		while (++x < SCREEN_WIDTH)
    {
			i = magie_noir((2.7 / map->zoom) * x / SCREEN_WIDTH - (1.35 / map->zoom) + map->pos_x,
                    ((2.4 / map->zoom) * y / SCREEN_HEIGHT - (1.2 / map->zoom) + map->pos_y));
      ft_put_pixel(map->mlx, x, y, 0xFFFFFF - 256 * i);
		}
	}
  add_cross(map);
	mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image, 0, 0);
  mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image_menu, 1520, 0);
  printf_info(map);
}
