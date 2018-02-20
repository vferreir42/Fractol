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

int				my_key_funct(int keycode, t_map *map)
{
  if (keycode == 53)
    exit (0);
  if (keycode == 69)
  {
    map->zoom -= 0.1;
    ft_clean_image(map);
    fractal_mandelbrot(map);
  }
  if (keycode == 78)
  {
    map->zoom += 0.1;
    ft_clean_image(map);
    fractal_mandelbrot(map);
  }
  return (0);
}
