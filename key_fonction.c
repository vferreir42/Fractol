/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:51:12 by vferreir          #+#    #+#             */
/*   Updated: 2018/02/20 14:51:13 by vferreir         ###   ########.fr       */
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
    map->zoom += 1;
    ft_clean_image(map);
    if (map->mandelbrot == 1)
      fractal_mandelbrot(map);
    else if (map->julia == 1)
      fractal_julia(map);
		else if (map->newton == 1)
			fractal_newton(map);
  }
  if (map->key_hook[DEZOOM] == 1)
  {
    if (map->zoom > 1)
      map->zoom -= 1;
    ft_clean_image(map);
    if (map->mandelbrot == 1)
      fractal_mandelbrot(map);
    else if (map->julia == 1)
      fractal_julia(map);
		else if (map->newton == 1)
			fractal_newton(map);
  }
	return (0);
}

int				my_key_funct(int keycode, t_map *map)
{
  if (keycode == ESC_KEY)
    exit (0);
  if (keycode == ZOOM)
    map->key_hook[keycode] = 0;
  if (keycode == DEZOOM)
    map->key_hook[keycode] = 0;
  return (0);
}
