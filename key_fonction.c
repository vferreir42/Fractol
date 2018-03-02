/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:51:12 by vferreir          #+#    #+#             */
/*   Updated: 2018/03/02 20:38:12 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fct_key(int keycode, t_map *map)
{
	if (keycode == ZOOM)
		map->key_hook[keycode] = 1;
	if (keycode == DEZOOM)
		map->key_hook[keycode] = 1;
	return (0);
}

int				do_change(t_map *map)
{
	if (map->key_hook[ZOOM] == 1)
	{
		map->affichage_zoom += 1;
		map->zoom *= 1.5;
		fractal_select(map);
	}
	else if (map->key_hook[DEZOOM] == 1)
	{
		map->affichage_zoom -= 1;
		map->zoom /= 1.5;
		fractal_select(map);
	}
	return (0);
}

int				my_key_funct(int keycode, t_map *map)
{
	int x;
	int y;

	x = 300;
	y = 720;
	if (keycode == ESC_KEY)
		exit (0);
	if (keycode == L_KEY)
	{
		if (map->lock == 0)
		{
			map->mlx->image_menu = mlx_xpm_file_to_image(map->mlx->mlx, "./img/menu-lock.xpm", &x, &y);
			mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image_menu, 980, 0);
			map->lock = 1;
		}
		else
		{
			map->mlx->image_menu = mlx_xpm_file_to_image(map->mlx->mlx, "./img/menu.xpm", &x, &y);
			mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image_menu, 980, 0);
			map->lock = 0;
		}
	}
	if (keycode == ZOOM)
		map->key_hook[keycode] = 0;
	if (keycode == DEZOOM)
		map->key_hook[keycode] = 0;
	return (0);
}
