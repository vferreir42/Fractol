/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julie.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:30:10 by vferreir          #+#    #+#             */
/*   Updated: 2018/02/21 20:42:43 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int magie_noir(double x, double y)
{
	int i = 0;
	double ima_r = x;
	double ima_i = y;
	double tmp_r = 0;
	double c_r = -0.88;
	double c_i = 0.22;

	while (ima_r * ima_r + ima_i * ima_i < 4 && i < ITERATION_MAX)
	{
		tmp_r = ima_r;
		ima_r = ima_r * ima_r - ima_i * ima_i + c_r;
		ima_i = 2 * tmp_r * ima_i + c_i;
		i++;
	}
	return (i);
}

void fractal_julia(t_map *map)
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
			i = magie_noir(2.7 / map->zoom * x / SCREEN_WIDTH - 1.35 / map->zoom + map->pos_x,
					2.4 / map->zoom * y / SCREEN_HEIGHT - 1.2 /map->zoom + map->pos_y);
      ft_put_pixel(map->mlx, x, y, 0xFFFFFF - 256 * i);
		}
	}
	add_cross(map);
	mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image, 0, 0);
  mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image_menu, 1520, 0);
	printf_info(map);
}
