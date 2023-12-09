/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 00:58:25 by akambou           #+#    #+#             */
/*   Updated: 2023/12/09 21:01:56 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	draw_pixel(t_fractol *fractal, int x, int y, int color)
{
	fractal->buf[x * 4 + y * WIDTH * 4] = color;
	fractal->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	fractal->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	fractal->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

static int	calc_fractal(t_fractol *fractal, double real_part, \
double imaginary_part)
{
	int	nb_iter;

	if (fractal->set == MANDELBROT)
		nb_iter = mandelbrot(real_part, imaginary_part);
	else if (fractal->set == TRICORN)
		nb_iter = tricorn(real_part, imaginary_part);
	else
		nb_iter = julia(fractal, real_part, imaginary_part);
	return (nb_iter);
}

void	render(t_fractol *fractal)
{
	int		x;
	int		y;
	double	real_part;
	double	imaginary_part;
	int		nb_iter;

	mlx_clear_window(fractal->mlx, fractal->win);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real_part = fractal->min_real + (double)x \
			* (fractal->max_real - fractal->min_real) / WIDTH;
			imaginary_part = fractal->max_imaginary + (double)y \
			* (fractal->min_imaginary - fractal->max_imaginary) / HEIGHT;
			nb_iter = calc_fractal(fractal, real_part, imaginary_part);
			draw_pixel(fractal, x, y, fractal->palette[nb_iter]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}

void	kill_win(int exit_code, t_fractol *fractal)
{
	if (!fractal)
		exit(exit_code);
	if (fractal->palette)
		free(fractal->palette);
	if (fractal->img)
		mlx_destroy_image(fractal->mlx, fractal->img);
	if (fractal->win && fractal->mlx)
		mlx_destroy_window(fractal->mlx, fractal->win);
	if (fractal->mlx)
	{
		clean_init(fractal);
		free(fractal->mlx);
	}
	exit(exit_code);
}

int	close_win(t_fractol *mlx)
{
	kill_win(0, mlx);
	return (0);
}
