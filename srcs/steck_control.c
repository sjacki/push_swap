/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steck_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 00:24:21 by alexandr          #+#    #+#             */
/*   Updated: 2021/08/20 00:26:21 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void		sa(t_list *a_steck_head)
{
	int temp;

	if (a_steck_head)
	{
		temp = a_steck_head->value;
		a_steck_head->value = a_steck_head->next->value;
		a_steck_head->next->value = temp;
	}
}

void		sb(t_list *b_steck_head)
{
	int temp;

	if (b_steck_head)
	{
		temp = b_steck_head->value;
		b_steck_head->value = b_steck_head->next->value;
		b_steck_head->next->value = temp;
	}
}

void 		ss(struct  s_val *val)
		{
			sb(val->b_steck_head);
			sa(val->a_steck_head);
		}

void		pb(struct s_val *val)
{
	if (val->a_steck_head)
	{
		if (!val->b_steck_head)
		{
			val->b_steck_head = create_new_list(val->a_steck_head->value);
			val->b_steck_tail = val->b_steck_head;
			val->b_steck_head->end = 1;
		}
		else
		{
			val->b_steck_head = add_node_begin(val->b_steck_tail,
											   val->b_steck_head,
											   val->a_steck_head->value);
		}
		val->a_steck_head = delete_first_node(val->a_steck_head,
											  val->a_steck_tail);
	}
}

void		pa(struct s_val *val)
		{
	if (val->b_steck_head)
	{
		if (!val->a_steck_head)
		{
			val->a_steck_head = create_new_list(val->b_steck_head->value);
			val->a_steck_tail = val->a_steck_head;
			val->a_steck_head->end = 1;
		}
		else
		{
			val->a_steck_head = add_node_begin(val->a_steck_tail,
											   val->a_steck_head,
											   val->b_steck_head->value);
		}
		val->b_steck_head = delete_first_node(val->b_steck_head,
											  val->b_steck_tail);
	}
		}