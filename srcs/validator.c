/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 23:28:32 by sikeda            #+#    #+#             */
/*   Updated: 2021/09/13 07:44:35 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_bool
	ft_is_valid_args(int argc, char **argv)
{
	if (argc != 2)
		return (FALSE);
	if (ft_strlen(argv[1]) == 1
		&& ft_isdigit(*argv[1])
		&& ft_atoi(argv[1]) > TYPE_START
		&& ft_atoi(argv[1]) < TYPE_END)
	{
		return (TRUE);
	}
	return (FALSE);
}
