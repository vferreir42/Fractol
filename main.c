/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:01:52 by vferreir          #+#    #+#             */
/*   Updated: 2018/02/20 11:01:53 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int magie_noir(double x, double y)
{
  int i = 0;
  double ima_r = 0;
  double ima_i = 0;
  double tmp_r = 0;

  while (ima_r * ima_r + ima_i * ima_i < 4 && i < ITERATION_MAX)
  {
    tmp_r = ima_r;
    ima_r = ima_r * ima_r - ima_i * ima_i + x;
    ima_i = 2 * tmp_r * ima_i + y;
    i++;
  }
  return (i);
}

void fractal_mandelbrot(t_map *map)
{
  int  x;
  int  y;
  int i;

  y = 0;
  while (y < SCREEN_HEIGHT)
  {
    x = 0;
    while (x < SCREEN_WIDTH)
    {
      i = magie_noir(2.7 * x * map->zoom / SCREEN_WIDTH - 2.1 * map->zoom, 2.4 * y * map->zoom / SCREEN_HEIGHT - 1.2 * map->zoom);
      if (i == ITERATION_MAX)
        ft_put_pixel(map->mlx, x, y, 0x000000);
      else
        ft_put_pixel(map->mlx, x, y, 0xFFFFFF);
      x++;
    }
    y++;
  }
  mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image, 0, 0);
}

int main(void)
{
  t_map map;

  if (!(map.mlx = malloc(sizeof(t_mlx))))
    return (0);
  initialisation_minilibix(map.mlx);
  map.zoom = 1;
  fractal_mandelbrot(&map);
  mlx_key_hook(map.mlx->windows, &my_key_funct, &map);
  mlx_loop(map.mlx->mlx);
  free(map.mlx);
  return (0);
}
