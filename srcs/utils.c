/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:35:02 by vferreir          #+#    #+#             */
/*   Updated: 2018/03/04 20:30:07 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_value(t_map *map)
{
	int i;

	i = -1;
	while (++i < 300)
		map->key_hook[i] = 0;
	map->zoom = 1;
	map->pos_x = 0;
	map->pos_y = 0;
	map->mandelbrot = 0;
	map->julia = 0;
	map->julia_cr = -0.88;
	map->julia_ci = 0.22;
	map->newton = 0;
	map->affichage_zoom = 1;
}

void	fractal_select(t_map *map)
{
	ft_clean_image(map);
	if (map->mandelbrot == 1)
		fractal_mandelbrot(map);
	else if (map->julia == 1)
		fractal_julia(map);
	else if (map->newton == 1)
		fractal_newton(map);
}

void	printf_info(t_map *map)
{
	char *string;
	char *tmp;

	string = ft_strdup("Zoom : ");
	tmp = ft_itoa(map->affichage_zoom);
	string = ft_strjoindel(string, tmp);
	free(tmp);
	mlx_string_put(map->mlx->mlx, map->mlx->windows, 10, 10, 0xFC5D5D, string);
	free(string);
	string = ft_strdup("Pos x = ");
	tmp = ft_itoa(map->pos_x * SCREEN_WIDTH / 2);
	string = ft_strjoindel(string, tmp);
	free(tmp);
	mlx_string_put(map->mlx->mlx, map->mlx->windows, 10, 30, 0xFC5D5D, string);
	free(string);
	string = ft_strdup("Pos y = ");
	tmp = ft_itoa((map->pos_y * SCREEN_HEIGHT / 2) * -1);
	string = ft_strjoindel(string, tmp);
	free(tmp);
	mlx_string_put(map->mlx->mlx, map->mlx->windows, 10, 50, 0xFC5D5D, string);
	free(string);
}

void	add_cross(t_map *map)
{
	int i;

	i = 15 * SCREEN_WIDTH / 32;
	while (++i < 17 * SCREEN_WIDTH / 32)
		ft_put_pixel(map->mlx, i, SCREEN_HEIGHT / 2, 0xFC5D5D);
	i = 14.8 * SCREEN_HEIGHT / 32;
	while (++i < 17.2 * SCREEN_HEIGHT / 32)
		ft_put_pixel(map->mlx, SCREEN_WIDTH / 2, i, 0xFC5D5D);
}
