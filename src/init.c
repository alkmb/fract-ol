/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 03:55:00 by akambou           #+#    #+#             */
/*   Updated: 2023/11/21 22:24:14 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_layout(t_fractol *fractal)
{
	if (fractal->set == JULIA)
	{
		fractal->min_real = -2.0;
		fractal->max_real = 2.0;
		fractal->min_imaginary = -2.0;
		fractal->max_imaginary = fractal->min_imaginary \
		+ (fractal->max_real - fractal->min_real) * HEIGHT / WIDTH;
	}
	else
	{
		fractal->min_real = -2.0;
		fractal->max_real = 1.0;
		fractal->max_imaginary = -1.5;
		fractal->min_imaginary = fractal->max_imaginary \
		+ (fractal->max_real - fractal->min_real) * HEIGHT / WIDTH;
	}
}

static void	init_img(t_fractol *fractal)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buf;

	fractal->palette = ft_calloc((MAX_ITERATIONS + 1), sizeof(int));
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	buf = mlx_get_data_addr(fractal->img, &pixel_bits, &line_bytes, &endian);
	fractal->buf = buf;
}

void	reinit_img(t_fractol *fractal)
{
	if (fractal->mlx && fractal->img)
		mlx_destroy_image(fractal->mlx, fractal->img);
	if (fractal->palette)
		free(fractal->palette);
	if (fractal->buf)
		fractal->buf = NULL;
	init_img(fractal);
}

void	init(t_fractol *fractal)
{
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Fract-ol");
	fractal->scale_x = 2.0;
	fractal->translate_x = 0.5;
	fractal->factor_x = 1.0;
	init_layout(fractal);
	color_set(fractal);
}

void	clean_init(t_fractol *fractal)
{
	fractal->mlx = NULL;
	fractal->win = NULL;
	fractal->img = NULL;
	fractal->buf = NULL;
	fractal->set = -1;
	fractal->min_real = 0;
	fractal->max_real = 0;
	fractal->min_imaginary = 0;
	fractal->max_imaginary = 0;
	fractal->constant_real = 0;
	fractal->constant_imaginary = 0;
	fractal->scale_x = 0;
	fractal->translate_x = 0;
	fractal->factor_x = 0;
	fractal->palette = NULL;
	fractal->color_pattern = -1;
	fractal->color = 0;
}
