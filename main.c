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

void set_value(t_map *map)
{
  int i = -1;
  while (++i < 300)
    map->key_hook[i] = 0;
  map->zoom = 1;
  map->pos_x = 0;
  map->pos_y = 0;
  map->mandelbrot = 0;
  map->julia = 0;
  map->newton = 0;
}

int main(void)
{
	t_map map;

	if (!(map.mlx = malloc(sizeof(t_mlx))))
		return (0);
	initialisation_minilibix(map.mlx);
  set_value(&map);

  map.newton = 1;
  if (map.mandelbrot == 1)
    fractal_mandelbrot(&map);
  else if (map.julia == 1)
    fractal_julia(&map);
  else if (map.newton == 1)
    fractal_newton(&map);


  mlx_mouse_hook(map.mlx->windows, &my_mouse_funct, &map);

  mlx_hook(map.mlx->windows, 2, 0, &fct_key, &map);
	mlx_loop_hook(map.mlx->mlx, &do_change, &map);
  mlx_key_hook(map.mlx->windows, &my_key_funct, &map);


  mlx_loop(map.mlx->mlx);
	return (0);
}
