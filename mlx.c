/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:52:43 by vferreir          #+#    #+#             */
/*   Updated: 2018/02/20 11:52:44 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_clean_image(t_map *map)
{
	free(map->mlx->data);
	map->mlx->image = mlx_new_image(map->mlx->mlx, 1920, 1080);
	map->mlx->data = mlx_get_data_addr(map->mlx->image,
			&map->mlx->bpp, &map->mlx->size_line, &map->mlx->endian);
}

void	ft_put_pixel(t_mlx *mlx, int x, int y, int couleur)
{
	int	r;
	int	g;
	int	b;

	if (y > 1079 || y < 0 || x < 0 || x > 1919)
		return ;
	r = (couleur & 16711680) >> 16;
	g = (couleur & 65280) >> 8;
	b = (couleur & 255);
	mlx->data[y * mlx->size_line + x * mlx->bpp / 8] = b;
	mlx->data[y * mlx->size_line + x * mlx->bpp / 8 + 1] = g;
	mlx->data[y * mlx->size_line + x * mlx->bpp / 8 + 2] = r;
}

void	initialisation_minilibix(t_mlx *mlx)
{
  mlx->mlx = mlx_init();
  mlx->windows = mlx_new_window(mlx->mlx, 1920, 1080, "mlx_42");
	mlx->image = mlx_new_image(mlx->mlx, 1920, 1080);
	mlx->data = mlx_get_data_addr(mlx->image, &mlx->bpp, &mlx->size_line, &mlx->endian);
}
