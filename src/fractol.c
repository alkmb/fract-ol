/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:45:03 by akambou           #+#    #+#             */
/*   Updated: 2023/11/22 17:54:20 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
}

static int	type_cmp(char *argv, char *str, char c, char n)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		argv[i] = ft_tolower(argv[i]);
		i++;
	}
	if (!ft_strncmp(argv, str, ft_strlen(str) + 1))
		return (1);
	else if (argv[1] == '\0' && (argv[0] == c || argv[0] == n))
		return (1);
	return (0);
}

static void	get_set(t_fractol *fractal, int argc, char **argv)
{
	if (type_cmp(argv[1], "mandelbrot", 'm', '0'))
		fractal->set = MANDELBROT;
	else if (type_cmp(argv[1], "julia", 'j', '1'))
		fractal->set = JULIA;
	else if (type_cmp(argv[1], "burned ship", 'b', '2'))
		fractal->set = TRICORN;

	if (fractal->set != JULIA || argc == 2)
	{
		fractal->constant_real = -0.766667;
		fractal->constant_imaginary = -0.090000;
		return ;
	}
	fractal->constant_real = ft_atof(argv[2]);
	fractal->constant_imaginary = ft_atof(argv[3]);
}

void	color_set(t_fractol *fractal)
{
	fractal->color_pattern = (fractal->color_pattern + 1) % 2;
	reinit_img(fractal);
	if (fractal->color_pattern == 0)
		colorcandy(fractal);
	else
		colorgreen(fractal);
}

int	main(int argc, char **argv)
{
	t_fractol	fractal;

	if (argc < 2 || argc > 4)
	{
		putstr("Usage: ./fractol [fractal] [real] [imaginary]\n");
		return (0);
	}
	clean_init(&fractal);
	get_set(&fractal, argc, argv);
	init(&fractal);
	render(&fractal);
	mlx_hook(fractal.win, EVENT_CLOSE_BTN, 0, close_win, &fractal);
	mlx_key_hook(fractal.win, kb_key, &fractal);
	mlx_mouse_hook(fractal.win, mouse_key, &fractal);
	mlx_loop(fractal.mlx);
}
