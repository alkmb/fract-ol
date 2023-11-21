/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 02:55:02 by akambou           #+#    #+#             */
/*   Updated: 2023/11/21 23:05:08 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../printf/includes/ft_printf.h"
# include "../libft/libft.h"
# include <math.h>

# define WIDTH 1200
# define HEIGHT 900
# define MAX_ITERATIONS 100
# define MANDELBROT 1
# define JULIA 2

# define EVENT_CLOSE_BTN 17
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_SPACE 32
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_BTN 1

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		set;
	int		*palette;
	int		color_pattern;
	int		color;
	double	min_real;
	double	max_real;
	double	min_imaginary;
	double	max_imaginary;
	double	constant_real;
	double	constant_imaginary;
	double	scale_x;
	double	translate_x;
	double	factor_x;
}	t_fractol;

void	clean_init(t_fractol *fractal);
void	init(t_fractol *fractal);
void	init_layout(t_fractol *fractal);
void	reinit_img(t_fractol *fractal);
void	render(t_fractol *fractal);
int		close_win(t_fractol *mlx);
void	kill_win(int error_code, t_fractol *fractal);
int		mandelbrot(double c_real, double c_imaginary);
void	colorcandy(t_fractol *fractal);
void	color_set(t_fractol *fractal);
void	colorgreen(t_fractol *fractal);
int		julia(t_fractol *fractal, double z_real, double z_imaginary);
int		julia_swap(int x, int y, t_fractol *fractal);
void	color_set(t_fractol *fractal);
int		kb_key(int keycode, t_fractol *mlx);
int		mouse_key(int keycode, int x, int y, t_fractol *mlx);

#endif
