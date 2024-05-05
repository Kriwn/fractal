/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:27:23 by krwongwa          #+#    #+#             */
/*   Updated: 2024/05/05 14:12:15 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	modolar(t_complex num)
{
	return (sqrt(num.real * num.real) + (num.image * num.image));
}

t_complex	mutiple_complex(t_complex num1, t_complex num2)
{
	t_complex	n;

	n.real = 0;
	n.image = 0;
	n.real = (num1.real * num2.real) - (num1.image * num2.image);
	n.image = (num1.real * num2.image) + (num1.image * num2.real);
	return (n);
}

t_complex	add_complex(t_complex num1, t_complex num2)
{
	t_complex	n;

	n.real = 0;
	n.image = 0;
	n.real = num1.real + num2.real;
	n.image = num1.image + num2.image;
	return (n);
}

t_complex	mod2_complex(t_complex num1)
{
	t_complex	n;

	n.real = (int)num1.real % 2;
	n.image = (int)num1.image % 2;
	return (n);
}

t_complex	log2_complex(t_complex num1)
{
	t_complex	n;

	n.real = log(modolar(num1));
	n.image = atan(num1.image / num1.real);
	return (n);
}
