/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_fonction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:54:41 by vferreir          #+#    #+#             */
/*   Updated: 2018/02/21 17:54:43 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int 	my_mouse_funct(int keycode, int pos_x, int pos_y, t_map *map)
{
  if (keycode == BUT1_KEY)
  {
    if (pos_x > 1520 && pos_y >= 243 && pos_y <= 540)
    {
      set_value(map);
      map->mandelbrot = 1;
      fractal_mandelbrot(map);
    }
    else if (pos_x > 1520 && pos_y >= 547 && pos_y <= 812)
    {
      set_value(map);
      map->julia = 1;
      fractal_julia(map);
    }
    else
    {
      map->pos_x = (2.7 / map->zoom * pos_x / SCREEN_WIDTH - 1.35 / map->zoom) + map->pos_x;
      map->pos_y = (2.4 / map->zoom * pos_y / SCREEN_HEIGHT - 1.2 / map->zoom) + map->pos_y;
      ft_clean_image(map);
      if (map->mandelbrot == 1)
        fractal_mandelbrot(map);
      else if (map->julia == 1)
        fractal_julia(map);
      }
  }
  return (0);
}
