/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_newton.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:39:33 by vferreir          #+#    #+#             */
/*   Updated: 2018/03/02 20:38:01 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



static int		magie_noir(double x, double y)
{
	int i = 0;
	double z_r = 0;
	double z_i = 0;
	double tmp = 0;
	double	dd;

	while (i < ITERATION_MAX / 2)
	{
		z_r = x * x;
		z_i = y * y;
		dd = 3.0 * ((z_r - z_i) * (z_r - z_i) + 4.0 * z_r * z_i);
		if (dd == 0.0)
			dd = 0.000001;
		tmp = x;
		x = (2.0 / 3.0) * x + (z_r - z_i) / dd;
		y = (2.0 / 3.0) * y - 2.0 * tmp * y / dd;
		i++;
	}
	if (x == 1)
		return (1);
	if (x >= -0.51 && x <= -0.49)
	{
		if (y >= 0.86 && y <= 0.87)
			return (2);
		if (y >= -0.87 && y <= -0.86)
			return (3);
	}
	return 0;
}

void fractal_newton(t_map *map)
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
			if (i == 1)
				ft_put_pixel(map->mlx, x, y, 0xB9121B);
			if (i == 2)
				ft_put_pixel(map->mlx, x, y, 0xADCF4F);
			if (i == 3)
				ft_put_pixel(map->mlx, x, y, 0x01B0F0);
		}
	}
	add_cross(map);
	mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image, 0, 0);
	printf_info(map);
}
