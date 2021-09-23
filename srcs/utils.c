/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:53:27 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/23 15:53:39 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int
	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\r'
		|| c == '\f' || c == '\t' || c == '\v');
}

double
	ft_atof(const char *str)
{
	long double	num;
	long double	tmp;
	int			sign;

	num = 0.0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		num = (num * 10) + (*str++ - '0');
	if (*str == '.')
		str++;
	tmp = 10.0;
	while (ft_isdigit(*str))
	{
		num += (*str++ - '0') / tmp;
		tmp *= 10;
	}
	return (sign * num);
}
