/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:45:38 by krwongwa          #+#    #+#             */
/*   Updated: 2024/05/05 19:43:06 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

void	drawer(t_fractal *fractal)
{
	if (fractal->type == 1)
		mendelbrot(fractal);
	else if (fractal->type == 2)
		julia(fractal);
	else if (fractal->type == 3)
		celtic(fractal);
}

void	checkparameter(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 2)
	{
		fractal->c.real = 0;
		fractal->c.image = 0.8;
	}
	else if (argc == 4)
	{
		if (finddigit(argv[2]) == 0 || finddigit(argv[3]) == 0)
			error(fractal);
		fractal->c.real = ft_atof(argv[2]);
		fractal->c.image = ft_atof(argv[3]);
	}
	fractal->type = 2;
}

void	checker(int argc, char **argv, t_fractal *fractal)
{
	if (argc > 1)
	{
		if (argc == 2 && ft_strncmp(argv[1], "mendelbrot", 10) == 0)
			fractal->type = 1;
		else if (ft_strncmp(argv[1], "julia", 5) == 0)
			checkparameter(argc, argv, fractal);
		else if (ft_strncmp(argv[1], "celtic", 6) == 0 && argc == 2)
			fractal->type = 3;
		else
			error(fractal);
	}
	else
		error(fractal);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s_s1;
	unsigned char	*s_s2;

	i = 0;
	s_s1 = (unsigned char *)s1;
	s_s2 = (unsigned char *)s2;
	if (ft_strlen(s1) != n)
		return (1);
	while ((s_s1[i] || s_s2[i]) && i < n)
	{
		if (s_s1[i] != s_s2[i])
			return (s_s1[i] - s_s2[i]);
		i++;
	}
	return (0);
}
