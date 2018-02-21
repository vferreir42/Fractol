/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:01:52 by vferreir          #+#    #+#             */
/*   Updated: 2018/02/21 15:34:12 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
	t_map map;

	if (!(map.mlx = malloc(sizeof(t_mlx))))
		return (0);
	initialisation_minilibix(map.mlx);
  map.zoom = 1;
  map.pos_x = 0;



  fractal_mandelbrot(&map);



  mlx_mouse_hook(map.mlx->windows, &my_mouse_funct, &map);

	mlx_key_hook(map.mlx->windows, &my_key_funct, &map);
	mlx_loop(map.mlx->mlx);
	free(map.mlx);
	return (0);
}
