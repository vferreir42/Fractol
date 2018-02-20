/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:01:42 by vferreir          #+#    #+#             */
/*   Updated: 2018/02/20 11:01:43 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include <stdio.h>

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define ITERATION_MAX 50

typedef struct s_mlx
{
    void *mlx;
    void *windows;
    void *image;
    char *data;
    int		endian;
    int		bpp;
    int		size_line;
}             t_mlx;

typedef struct s_map
{
  t_mlx	*mlx;
  double zoom;
}               t_map;

void	initialisation_minilibix(t_mlx *mlx);
void	ft_put_pixel(t_mlx *mlx, int x, int y, int couleur);
void	ft_clean_image(t_map *map);
int		my_key_funct(int keycode, t_map *map);
void fractal_mandelbrot(t_map *map);
