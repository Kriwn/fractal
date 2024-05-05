/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:26:38 by krwongwa          #+#    #+#             */
/*   Updated: 2024/05/05 22:49:50 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

int	checkceltic(int x, int y, t_fractal *fractal)
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
		z.image = z.real * z.image * -2.0 + fractal->c.image;
		z.real = fabs((z.real * z.real)
				- (z.image * z.image)) + fractal->c.real;
		if ((z.image * z.image) + (z.real * z.real) >= __DBL_MAX__)
			break ;
		n++;
	}
	return (n);
}

void	celtic(t_fractal *fractal)
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
			n = checkceltic(x, y, fractal);
			if (n == ITER)
				color = get_rgba(0, 0, 0, fractal->a);
			else
				color = get_rgba((fractal->r * n) / 100, (fractal->g * n)
						/ 100, (fractal->b * n) / 100, fractal->a);
			mlx_put_pixel(fractal->image, fractal->centerx + x,
				fractal->centery + y, color);
			x++;
		}
		y++;
	}
}
