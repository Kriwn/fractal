/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:15:16 by krwongwa          #+#    #+#             */
/*   Updated: 2024/05/05 18:47:30 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	checkmendelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	int			n;

	z.real = 0;
	z.image = 0;
	n = 0;
	fractal->c.real = (x / fractal->zoom) + fractal->posx;
	fractal->c.image = (y / fractal->zoom) + fractal->posy;
	while (n < ITER)
	{
		z = mutiple_complex(z, z);
		z = add_complex(z, fractal->c);
		if ((z.image * z.image) + (z.real * z.real) >= __DBL_MAX__)
			break ;
		n++;
	}
	return (n);
}

void	mendelbrot(t_fractal *fractal)
{
	int	x;
	int	y;
	int	n;
	int	color;

	y = fractal->centery * -1;
	while (y < fractal->centery)
	{
		x = fractal->centerx * -1;
		while (x < fractal->centerx)
		{
			n = checkmendelbrot(x, y, fractal);
			color = get_rgba((255 * n) / 100, (255 * n)
					/ 100, (255 * n) / 100, 255);
			mlx_put_pixel(fractal->image, fractal->centerx + x,
				fractal->centery + y, color);
			x++;
		}
		y++;
	}
}
