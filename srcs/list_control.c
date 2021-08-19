/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 00:16:07 by alexandr          #+#    #+#             */
/*   Updated: 2021/08/20 00:16:09 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/header.h"

void 		draw_list(t_val *val)
{
	t_list 	*a_buf;
	t_list 	*b_buf;
	int		flag;

	a_buf = val->a_steck_head;
	b_buf = val->b_steck_head;
	flag = 0;
	while (!a_buf->end)
	{
		ft_printf("%d   ", a_buf->value);
		a_buf = a_buf->next;
		if (b_buf && b_buf->end && !flag)
		{
			ft_printf("%d", b_buf->value);
			flag++;
		}
		if (b_buf && !b_buf->end && ft_printf("%d", b_buf->value))
			b_buf = b_buf->next;
		ft_printf("\n");
	}
	if (a_buf && a_buf->end)
	{
		ft_printf("%d   ", a_buf->value);
		ft_printf("\n");
	}
}

t_list		*create_new_list(int value)
{
	t_list *buf;

	buf = (t_list*)malloc(sizeof(t_list));
	buf->next = buf;
	buf->begin = buf;
	buf->value = value;
	buf->end = 1;
	return (buf);
}

t_list 		*add_node_next(t_list *steck_tail, t_list *steck_head, int value)
{
	t_list	*buf;

	buf = create_new_list(value);
	steck_tail->end = 0;
	steck_tail->next = buf;
	buf->next = steck_head;
	buf->begin = steck_tail;
	return (buf);
}

t_list 		*add_node_begin(t_list *steck_tail, t_list *steck_head, int value)
{
	t_list	*buf;

	buf = create_new_list(value);
	buf->end = 0;
	buf->next = steck_head;
	buf->begin = steck_tail;
	return (buf);
}

t_list 		*delete_first_node(t_list *steck_head, t_list *steck_tail)
{
	t_list 	*temp;

	temp = steck_head->next;
	free(steck_head);
	temp->begin = steck_tail;
	steck_tail->begin = temp;
	return (temp);
}