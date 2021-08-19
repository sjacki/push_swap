/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_steck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 00:29:38 by alexandr          #+#    #+#             */
/*   Updated: 2021/08/20 00:30:18 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void 		init_a_steck(struct s_val *val, int argc, char **argv, int x)
{
	int		y;

	while(x < argc)
	{
		if (ft_isdigit(*argv[x]) || *argv[x] == 45)
		{
			y = 0;
			while (ft_isdigit(argv[x][y]) || (argv[x][y] == 45 && y == 0))
				y++;
			if (y != (int)ft_strlen(argv[x]))
				err();
			y = ft_atoi(argv[x]);
			if (val->a_steck_head == NULL)
			{
				val->a_steck_head = create_new_list(y);
				val->a_steck_tail = val->a_steck_head;
			}
			else
				val->a_steck_tail = add_node_next(val->a_steck_tail,
												  val->a_steck_head, y);
		}
		else
			err();
		x++;
	}
}

