/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_fonction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:54:41 by vferreir          #+#    #+#             */
/*   Updated: 2018/03/06 11:38:18 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			motion_hook(int x, int y, t_map *map)
{
	if (map->julia == 1 && map->lock == 0)
	{
		map->julia_cr = 2.7 * x / SCREEN_WIDTH - 2;
		map->julia_ci = 2.4 * x / SCREEN_WIDTH - 1.2;
		ft_clean_image(map);
		fractal_julia(map);
	}
	return (0);
}

static void	part_fonction(t_map *map, int pos_y)
{
	set_value(map);
	if (pos_y >= 0 && pos_y <= 240)
	{
		map->pos_x -= 0.45;
		map->mandelbrot = 1;
	}
	else if (pos_y > 240 && pos_y <= 480)
		map->julia = 1;
	else if (pos_y > 480)
		map->newton = 1;
}

int			my_mouse_funct(int keycode, int pos_x, int pos_y, t_map *map)
{
	if (keycode == SCROLLUP_KEY && map->affichage_zoom++)
		map->zoom *= 1.5;
	else if (keycode == SCROLLDOWN_KEY && map->affichage_zoom--)
		map->zoom /= 1.5;
	else if (keycode == BUT1_KEY)
	{
		if (pos_x < 980)
		{
			map->pos_x = 2.7 / map->zoom * pos_x /
				SCREEN_WIDTH - 1.35 / map->zoom + map->pos_x;
			map->pos_y = 2.4 / map->zoom * pos_y
				/ SCREEN_HEIGHT - 1.2 / map->zoom + map->pos_y;
		}
		else
			part_fonction(map, pos_y);
	}
	fractal_select(map);
	return (0);
}
