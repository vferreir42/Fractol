/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:01:52 by vferreir          #+#    #+#             */
/*   Updated: 2018/03/02 20:37:37 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
	t_map map;

	if (!(map.mlx = malloc(sizeof(t_mlx))))
		return (0);
	initialisation_minilibix(map.mlx);
	set_value(&map);
	map.mandelbrot = 1;
	fractal_select(&map);
	mlx_hook(map.mlx->windows, 6, POINTERMOTIONMASK, &motion_hook, &map);
	mlx_hook(map.mlx->windows, KEYPRESS, 0, &fct_key, &map);
	mlx_loop_hook(map.mlx->mlx, &do_change, &map);
	mlx_key_hook(map.mlx->windows, &my_key_funct, &map);
	mlx_mouse_hook(map.mlx->windows, &my_mouse_funct, &map);
	mlx_loop(map.mlx->mlx);
	return (0);
}
