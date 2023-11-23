/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:00:00 by  by   akamb       #+#    #+#             */
/*   Updated: 2023/11/23 20:37:01 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia(t_fractol *fractal, double z_real, double z_imaginary)
{
	int		n;
	double	temp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((z_imaginary * z_imaginary + z_real * z_real) > 4.0)
			break ;
		temp = 2 * z_real * z_imaginary + fractal->constant_imaginary;
		z_real = z_real * z_real - z_imaginary * z_imaginary + \
		fractal->constant_real;
		z_imaginary = temp;
		n++;
	}
	return (n);
}

int	mandelbrot(double c_real, double c_imaginary)
{
	int		n;
	double	z_real;
	double	z_imaginary;
	double	temp;

	z_real = 0;
	z_imaginary = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((z_real * z_real + z_imaginary * z_imaginary) > 4.0)
			break ;
		temp = 2 * z_real * z_imaginary + c_imaginary;
		z_real = z_real * z_real - z_imaginary * z_imaginary + c_real;
		z_imaginary = temp;
		n++;
	}
	return (n);
}

int	tricorn(double c_real, double c_imaginary)
{
	int		n;
	double	z_real;
	double	z_imaginary;
	double	temp;

	z_real = c_real;
	z_imaginary = c_imaginary;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((z_real * z_real + z_imaginary * z_imaginary) > 4.0)
			break ;
		temp = -2 * z_real * z_imaginary + c_imaginary;
		z_real = z_real * z_real - z_imaginary * z_imaginary + c_real;
		z_imaginary = temp;
		n++;
	}
	return (n);
}

void	colorcandy(t_fractol *fractal)
{
	int	i;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		if (i % 3 == 0)
			fractal->palette[i] = 0xFF << 24 | 0xFF << 16 | 0x69 << 8 | 0xB4;
		else if (i % 3 == 1)
			fractal->palette[i] = 0xFF << 24 | 0x00 << 16 | 0xBF << 8 | 0xFF;
		else
			fractal->palette[i] = 0xFF << 24 | 0xFF << 16 | 0xFF << 8 | 0x00;
		i++;
	}
}

void	colorgreen(t_fractol *fractal)
{
	int	i;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		if (i % 3 == 0)
			fractal->palette[i] = 0xFF << 24 | 0x00 << 16 | 0xFF << 8 | 0x09;
		else if (i % 3 == 1)
			fractal->palette[i] = 0xFF << 24 | 0xAD << 16 | 0xFF << 8 | 0x2F;
		else
			fractal->palette[i] = 0xFF << 24 | 0x00 << 16 | 0x64 << 8 | 0x09;
		i++;
	}
}
