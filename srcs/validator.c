/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 23:28:32 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/07 23:31:39 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_bool
	ft_is_valid_args(int argc, char **argv)
{
	if (argc != 2)
		return (FALSE);
	if (!ft_strcmp(argv[1], ARG_M)
		|| !ft_strcmp(argv[1], ARG_J)
		|| !ft_strcmp(argv[1], ARG_MANDELBROT)
		|| !ft_strcmp(argv[1], ARG_JULIA))
	{
		return (TRUE);
	}
	return (FALSE);
}
