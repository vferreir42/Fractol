/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:51:12 by vferreir          #+#    #+#             */
/*   Updated: 2018/03/04 20:31:54 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fct_key(int keycode, t_map *map)
{
	if (keycode == ZOOM)
		map->key_hook[keycode] = 1;
	else if (keycode == DEZOOM)
		map->key_hook[keycode] = 1;
	else if (keycode == UP_KEY)
		map->key_hook[keycode] = 1;
	else if (keycode == DOWN_KEY)
		map->key_hook[keycode] = 1;
	else if (keycode == RIGHT_KEY)
		map->key_hook[keycode] = 1;
	else if (keycode == LEFT_KEY)
		map->key_hook[keycode] = 1;
	return (0);
}

int	do_change(t_map *map)
{
	if (map->key_hook[ZOOM] == 1)
	{
		map->affichage_zoom += 1;
		map->zoom *= 1.5;
	}
	else if (map->key_hook[DEZOOM] == 1)
	{
		map->affichage_zoom -= 1;
		map->zoom /= 1.5;
	}
	else if (map->key_hook[UP_KEY] == 1)
		map->pos_y -= (0.25 / map->zoom);
	else if (map->key_hook[DOWN_KEY] == 1)
		map->pos_y += 0.25 / map->zoom;
	else if (map->key_hook[LEFT_KEY] == 1)
		map->pos_x -= 0.18 / map->zoom;
	else if (map->key_hook[RIGHT_KEY] == 1)
		map->pos_x += 0.18 / map->zoom;
	fractal_select(map);
	return (0);
}

int	my_key_funct(int keycode, t_map *map)
{
	int x;
	int y;

	x = 300;
	y = 720;
	if (keycode == ESC_KEY)
		exit(0);
	if (keycode == L_KEY)
	{
		if (map->lock == 0)
		{
			map->mlx->image_menu = mlx_xpm_file_to_image(map->mlx->mlx, "./img/menu-lock.xpm", &x, &y);
			map->lock = 1;
		}
		else
		{
			map->mlx->image_menu = mlx_xpm_file_to_image(map->mlx->mlx, "./img/menu.xpm", &x, &y);
			map->lock = 0;
		}
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image_menu, 980, 0);
	}
	if (keycode == ZOOM || keycode == DEZOOM || keycode == UP_KEY
		|| keycode == DOWN_KEY || keycode == LEFT_KEY || keycode == RIGHT_KEY)
		map->key_hook[keycode] = 0;
	return (0);
}
