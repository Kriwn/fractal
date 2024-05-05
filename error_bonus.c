/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:45:01 by krwongwa          #+#    #+#             */
/*   Updated: 2024/05/05 20:44:42 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

void	ft_putstr_fd(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

void	error(t_fractal *fractal)
{
	ft_putstr_fd("|***********************************************|");
	ft_putstr_fd("|Should Run ./fractal piture parameter parameter|");
	ft_putstr_fd("|         ./fractal julia 0.285 0.01            |");
	ft_putstr_fd("|         ./fractal mandelbrot                  |");
	ft_putstr_fd("|         ./fractal celtic                      |");
	ft_putstr_fd("|***********************************************|");
	free(fractal);
	exit(22);
}

void	terminate(t_fractal *fractal)
{
	mlx_delete_image(fractal->mlx, fractal->image);
	mlx_close_window(fractal->mlx);
	mlx_destroy_cursor(fractal->cursor);
	mlx_terminate(fractal->mlx);
	if (fractal)
		free(fractal);
}
