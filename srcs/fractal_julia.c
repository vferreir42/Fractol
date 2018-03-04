/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julie.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:30:10 by vferreir          #+#    #+#             */
/*   Updated: 2018/03/04 20:24:28 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	magie_noir(t_map *map, double ima_r, double ima_i)
{
	int		i;
	double	tmp_r;

	i = 0;
	tmp_r = 0;
	while (ima_r * ima_r + ima_i * ima_i < 4 && i < ITERATION_MAX)
	{
		tmp_r = ima_r;
		ima_r = ima_r * ima_r - ima_i * ima_i + map->julia_cr;
		ima_i = 2 * tmp_r * ima_i + map->julia_ci;
		i++;
	}
	return (i);
}

void		fractal_julia(t_map *map)
{
	int	x;
	int	y;
	int i;

	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		x = -1;
		while (++x < SCREEN_WIDTH)
		{
			i = magie_noir(map, 2.7 / map->zoom * x / SCREEN_WIDTH -
					1.35 / map->zoom + map->pos_x,
					2.4 / map->zoom * y / SCREEN_HEIGHT -
					1.2 / map->zoom + map->pos_y);
			if (i == ITERATION_MAX)
				ft_put_pixel(map->mlx, x, y, 0x000000);
			else
				ft_put_pixel(map->mlx, x, y, 0x004098 + i * 256);
		}
	}
	add_cross(map);
	mlx_put_image_to_window(map->mlx->mlx,
			map->mlx->windows, map->mlx->image, 0, 0);
	printf_info(map);
}
