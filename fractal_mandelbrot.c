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

int magie_noir(double x, double y)
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



  printf("%f\n", map->zoom);
  y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		x = -1;
		while (++x < SCREEN_WIDTH)
		{
			i = magie_noir(2.7 * x / (SCREEN_WIDTH * map->zoom) + (-2.1 + map->pos_x) / map->zoom,
                    2.4 * y / (SCREEN_HEIGHT * map->zoom) + (-1.2 + map->pos_y) / map->zoom);
			if (i == ITERATION_MAX)
				ft_put_pixel(map->mlx, x, y, 0x000000);
			else
				ft_put_pixel(map->mlx, x, y, 0xFFFFFF);
		}
	}

  i = -1;
  while (++i < 1920)
    ft_put_pixel(map->mlx, i, 540, 0xFC5D5D);
  i = -1;
  while (++i < 1080)
    ft_put_pixel(map->mlx, 960, i, 0xFC5D5D);


	mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image, 0, 0);
}
