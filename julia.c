/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:06:32 by krwongwa          #+#    #+#             */
/*   Updated: 2024/05/05 22:49:22 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	check_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	int			n;

	z.real = 0;
	z.image = 0;
	n = 0;
	z.real = (x / fractal->zoom) + fractal->posx;
	z.image = (y / fractal->zoom) + fractal->posy;
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

void	julia(t_fractal *fractal)
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
			n = check_julia(x, y, fractal);
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
