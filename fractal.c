/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:21:45 by krwongwa          #+#    #+#             */
/*   Updated: 2024/05/05 18:46:20 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init(t_fractal *fractal)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "Fractal", false);
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->posx = -0.00125;
	fractal->posy = 0.00125;
	fractal->zoom = 300;
	fractal->centerx = WIDTH / 2;
	fractal->centery = HEIGHT / 2;
	fractal->cursor = mlx_create_std_cursor(1);
}

int32_t	main(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (-1);
	checker(argc, argv, fractal);
	init(fractal);
	drawer(fractal);
	mlx_image_to_window(fractal->mlx, fractal->image, 0, 0);
	mlx_key_hook(fractal->mlx, ft_hook, fractal);
	mlx_scroll_hook(fractal->mlx, sc_hook, fractal);
	mlx_cursor_hook(fractal->mlx, mouse_track, fractal);
	mlx_loop(fractal->mlx);
	terminate(fractal);
	return (EXIT_SUCCESS);
}
