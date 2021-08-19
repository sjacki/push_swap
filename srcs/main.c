/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 00:04:09 by alexandr          #+#    #+#             */
/*   Updated: 2021/07/10 23:56:47 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void 		err(void)
{
	ft_printf("ERROR\n");
	exit(1);
}


int			main(int argc, char **argv)
{
	struct	s_val val;

	val.a_steck_head = NULL;
	val.b_steck_head = NULL;
	init_a_steck(&val, argc, argv, 1);
	pb(&val);
	pb(&val);
	ss(&val);
	draw_list(&val);
}