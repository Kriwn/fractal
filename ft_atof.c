/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:50:09 by krwongwa          #+#    #+#             */
/*   Updated: 2024/05/05 13:52:40 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	finddigit(char *arr)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (arr[i])
	{
		if (arr[i] >= '0' && arr[i] <= '9')
		{
			n = 1;
			break ;
		}
		i++;
	}
	return (n);
}

int	check(int *i, char *arr)
{
	int	neg;
	int	n;

	n = *i;
	neg = 1;
	while (arr[n] && ((arr[n] >= '\t' && arr[n] <= '\r') || arr[n] == ' '))
		n++;
	if (arr[n] == '+' || arr[n] == '-')
	{
		if (arr[n] == '-')
			neg *= -1;
		n++;
	}
	*i = n;
	return (neg);
}

double	afterdot(char *arr, double value, int i)
{
	double	pos;

	pos = 1;
	while (arr[i] >= '0' && arr[i] <= '9')
	{
		pos /= 10;
		value += (arr[i] - '0') * pos;
		i++;
	}
	return (value);
}

double	ft_atof(char *arr)
{
	double	value;
	int		i;
	int		neg;

	if (!arr)
		return (0.0);
	i = 0;
	value = 0;
	neg = check(&i, arr);
	while (arr[i] >= '0' && arr[i] <= '9')
	{
		value = (value * 10) + (arr[i] - '0');
		i++;
	}
	if (arr[i++] == '.')
		value = afterdot(arr, value, i);
	return (value * neg);
}
