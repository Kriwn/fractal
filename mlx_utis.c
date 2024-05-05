/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:56:49 by krwongwa          #+#    #+#             */
/*   Updated: 2024/05/05 20:52:35 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(fractal->mlx);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
	{
		fractal->posy -= 50.0 / fractal->zoom;
	}
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
		fractal->posy += 50.0 / fractal->zoom;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
		fractal->posx -= 50.0 / fractal->zoom;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
		fractal->posx += 50.0 / fractal->zoom;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_EQUAL))
		zoomcenter(1, fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_MINUS))
		zoomcenter(0, fractal);
	drawer(fractal);
}

void	zoomcenter(int flag, t_fractal *fractal)
{
	double	level;

	level = 0.125;
	if (flag == 1)
		fractal->zoom *= 1 + level;
	else
		fractal->zoom /= 1 + level;
	fractal->posx = fractal->curx / fractal->zoom + fractal->posx;
	fractal->posy = fractal->cury / fractal->zoom + fractal->posy;
}

void	sc_hook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	double		level;

	if (xdelta >= 0)
	{
		level = 0.125;
		fractal = (t_fractal *)param;
		if (ydelta < 0)
			fractal->zoom *= 1 + level;
		else
			fractal->zoom /= 1 + level;
		fractal->posx = (fractal->curx - fractal->centerx)
			/ fractal->zoom + fractal->posx;
		fractal->posy = (fractal->cury - fractal->centery)
			/ fractal->zoom + fractal->posy;
		drawer(fractal);
	}
}

void	mouse_track(double xpos, double ypos, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	fractal->curx = xpos;
	fractal->cury = ypos;
}
