/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 01:00:53 by akambou           #+#    #+#             */
/*   Updated: 2023/11/22 21:14:19 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia_swap(int x, int y, t_fractol *fractal)
{
	fractal->constant_real = fractal->min_real \
	+ (double)x * (fractal->max_real - fractal->min_real) / WIDTH;
	fractal->constant_imaginary = fractal->max_imaginary \
	+ (double)y * (fractal->min_imaginary - fractal->max_imaginary) / HEIGHT;
	render(fractal);
	return (0);
}

static void	zoom(t_fractol *fractal, double zoom)
{
	double	center_real;
	double	center_imaginary;

	center_real = fractal->min_real - fractal->max_real;
	center_imaginary = fractal->max_imaginary - fractal->min_imaginary;
	fractal->max_real = \
	fractal->max_real + (center_real - zoom * center_real) / 2;
	fractal->min_real = fractal->max_real + zoom * center_real;
	fractal->min_imaginary = \
	fractal->min_imaginary + (center_imaginary - zoom * center_imaginary) / 2;
	fractal->max_imaginary = fractal->min_imaginary + zoom * center_imaginary;
}

static void	move(t_fractol *fractal, double distance, char direction)
{
	double	center_real;
	double	center_imaginary;

	center_real = fractal->max_real - fractal->min_real;
	center_imaginary = fractal->max_imaginary - fractal->min_imaginary;
	if (direction == 'R')
	{
		fractal->min_real += center_real * distance;
		fractal->max_real += center_real * distance;
	}
	else if (direction == 'L')
	{
		fractal->min_real -= center_real * distance;
		fractal->max_real -= center_real * distance;
	}
	else if (direction == 'D')
	{
		fractal->min_imaginary -= center_imaginary * distance;
		fractal->max_imaginary -= center_imaginary * distance;
	}
	else if (direction == 'U')
	{
		fractal->min_imaginary += center_imaginary * distance;
		fractal->max_imaginary += center_imaginary * distance;
	}
}

int	kb_key(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_ESC)
	{
		close_win(mlx);
		return (0);
	}
	else if (keycode == KEY_UP)
		move(mlx, 0.1, 'U');
	else if (keycode == KEY_DOWN)
		move(mlx, 0.1, 'D');
	else if (keycode == KEY_LEFT)
		move(mlx, 0.1, 'L');
	else if (keycode == KEY_RIGHT)
		move(mlx, 0.1, 'R');
	else if (keycode == KEY_SPACE)
		color_set(mlx);
	else
		return (1);
	render(mlx);
	return (0);
}

int	mouse_key(int keycode, int x, int y, t_fractol *mlx)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(mlx, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(mlx, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(mlx, (double)x / WIDTH, 'R');
		if (y < 0)
			move(mlx, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move (mlx, (double)y / HEIGHT, 'D');
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(mlx, 2);
	else if (keycode == MOUSE_BTN)
	{
		if (mlx->set == JULIA)
			julia_swap(x, y, mlx);
	}
	else
		return (0);
	render(mlx);
	return (0);
}
