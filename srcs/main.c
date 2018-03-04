/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:01:52 by vferreir          #+#    #+#             */
/*   Updated: 2018/03/04 20:26:39 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	select_fractal(t_map *map, int argc, char *argv)
{
	if (ft_strcmp(argv, "mandelbrot") == 0 && argc == 2)
	{
		map->mandelbrot = 1;
		map->pos_x -= 0.45;
	}
	else if (ft_strcmp(argv, "julia") == 0 && argc == 2)
		map->julia = 1;
	else if (ft_strcmp(argv, "newton") == 0 && argc == 2)
		map->newton = 1;
	else
	{
		write(1, "usage: ./fractol [mandelbrot | julia | newton]\n", 47);
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	t_map	map;

	if (!(map.mlx = malloc(sizeof(t_mlx))))
		return (0);
	map.lock = 1;
	set_value(&map);
	select_fractal(&map, argc, argv[1]);
	initialisation_minilibix(map.mlx);
	fractal_select(&map);
	mlx_hook(map.mlx->windows, 6, POINTERMOTIONMASK, &motion_hook, &map);
	mlx_hook(map.mlx->windows, KEYPRESS, 0, &fct_key, &map);
	mlx_loop_hook(map.mlx->mlx, &do_change, &map);
	mlx_key_hook(map.mlx->windows, &my_key_funct, &map);
	mlx_mouse_hook(map.mlx->windows, &my_mouse_funct, &map);
	mlx_loop(map.mlx->mlx);
	return (0);
}
