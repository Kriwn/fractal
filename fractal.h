/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:58:52 by krwongwa          #+#    #+#             */
/*   Updated: 2024/05/05 22:04:59 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "lib/MLX42/include/MLX42/MLX42.h"
# include <limits.h>

# define WIDTH 1500
# define HEIGHT 1080
# define ITER 100

typedef struct vector
{
	double	real;
	double	image;
}	t_complex;

typedef struct fractal
{
	mlx_t				*mlx;
	mlx_image_t			*image;
	mlx_win_cursor_t	*cursor;
	double				curx;
	double				cury;
	double				zoom;
	double				posx;
	double				posy;
	int					centerx;
	int					centery;
	int					type;
	int					r;
	int					g;
	int					b;
	int					a;
	t_complex			c;

}	t_fractal;

//--------------- complex.c -----------//
double		modolar(t_complex num);
t_complex	mutiple_complex(t_complex num1, t_complex num2);
t_complex	add_complex(t_complex num1, t_complex num2);
t_complex	mod2_complex(t_complex num1);
t_complex	log2_complex(t_complex num1);
double		sqrt_complex(t_complex num);

//-------------- error.c --------------//
void		ft_putstr_fd(char *s);
size_t		ft_strlen(const char *s);
void		error(t_fractal *fractal);
void		terminate(t_fractal *fractal);

//--------------- ft_atof.c -----------//
int			finddigit(char *arr);
int			check(int *i, char *arr);
double		afterdot(char *arr, double value, int i);
double		ft_atof(char *arr);

//--------------- julia.c -----------//
int			check_julia(int x, int y, t_fractal *fractal);
void		julia(t_fractal *fractal);

//--------------- mandelbrot -----------//
int			checkmandelbrot(int x, int y, t_fractal *fractal);
void		mandelbrot(t_fractal *fractal);

//--------------- mlx_utils.c -----------//
int			get_rgba(int r, int g, int b, int a);
void		ft_hook(mlx_key_data_t keydata, void *param);
void		zoomcenter(int flag, t_fractal *fractal);
void		sc_hook(double xdelta, double ydelta, void *param);
void		mouse_track(double xpos, double ypos, void *param);

//--------------- utils.c -----------//
void		drawer(t_fractal *fractal);
void		checkparameter(int argc, char **argv, t_fractal *fractal);
void		checker(int argc, char **argv, t_fractal *fractal);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		color(t_fractal *fractal);

#endif
