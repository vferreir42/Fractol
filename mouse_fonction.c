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
  if (keycode == 1)
  {
    map->pos_x = (2.7 * pos_x / SCREEN_WIDTH - 2.1 + 0.75) + map->pos_x;
    map->pos_y = (2.4 * pos_y / SCREEN_HEIGHT - 1.2) + map->pos_y;
    ft_clean_image(map);
    fractal_mandelbrot(map);
  }
  return (0);
}
