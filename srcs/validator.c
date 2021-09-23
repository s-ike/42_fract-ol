/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 23:28:32 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/23 15:53:12 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_bool
	ft_is_valid_args(int argc, char **argv)
{
	int	argi;
	int	type;

	argi = 2;
	if (argc < argi
		|| ft_strlen(argv[argi - 1]) != 1 || !ft_isdigit(*argv[argi - 1]))
	{
		return (FALSE);
	}
	type = ft_atoi(argv[argi - 1]);
	if (TYPE_START < type && type < TYPE_END)
	{
		if (type == TYPE_JULIA)
		{
			argi = 3;
			if (argi <= argc && !isfinite(ft_atof(argv[argi - 1])))
				return (FALSE);
			argi = 4;
			if (argi <= argc && !isfinite(ft_atof(argv[argi - 1])))
				return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}
