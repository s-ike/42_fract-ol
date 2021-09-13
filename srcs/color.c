/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:33:20 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/13 22:35:53 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int
	ft_calc_color(int i)
{
	return ((i % 256) * (255 - (i % 256)) / 65);
}

uint32_t
	ft_rgb(uint8_t r, uint8_t g, uint8_t b)
{
	uint32_t	color;

	color = r;
	color <<= 8;
	color |= g;
	color <<= 8;
	color |= b;
	return (color);
}
