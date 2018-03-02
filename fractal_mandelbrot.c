/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:31:22 by vferreir          #+#    #+#             */
/*   Updated: 2018/03/02 20:37:54 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	printf_info(map);
}
