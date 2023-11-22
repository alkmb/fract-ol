/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 00:58:25 by akambou           #+#    #+#             */
/*   Updated: 2023/11/22 17:56:29 by akambou          ###   ########.fr       */
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

static int	calc_fractal(t_fractol *fractal, double pr, double pi)
{
	int	nb_iter;

	if (fractal->set == MANDELBROT)
		nb_iter = mandelbrot(pr, pi);
	else if (fractal->set == TRICORN)
		nb_iter = tricorn(pr, pi);
	else if (fractal ->set == JULIA)
		nb_iter = julia(fractal, pr, pi);
	return (nb_iter);
}

void	render(t_fractol *fractal)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		nb_iter;

	mlx_clear_window(fractal->mlx, fractal->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = fractal->min_real + (double)x \
			* (fractal->max_real - fractal->min_real) / WIDTH;
			pi = fractal->max_imaginary + (double)y \
			* (fractal->min_imaginary - fractal->max_imaginary) / HEIGHT;
			nb_iter = calc_fractal(fractal, pr, pi);
			draw_pixel(fractal, x, y, fractal->palette[nb_iter]);
		}
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
		mlx_loop_end(fractal->mlx);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	exit(exit_code);
}

int	close_win(t_fractol *mlx)
{
	kill_win(0, mlx);
	return (0);
}
