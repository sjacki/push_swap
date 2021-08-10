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

void 		draw_list(t_list *steck_head)
{
	t_list 	*buf;

	buf = steck_head;
	while (!buf->end)
	{
		ft_printf("%d\n", buf->value);
		buf = buf->next;
	}
	ft_printf("%d\n\n", buf->value);
}

void		sa(t_list *a_steck_head)
{
	int temp;

	temp = a_steck_head->value;
	a_steck_head->value = a_steck_head->next->value;
	a_steck_head->next->value = temp;
	draw_list(a_steck_head);
}

/*void		pa(int	*f_steck, int	*s_steck, int argc)
{
	if (s_steck[0] != 0)
	{
			
	}
}*/

/*void		sb(int	*f_steck, int	*s_steck, int argc)
{
	int temp;

	temp = s_steck[0];
	s_steck[0] = s_steck[1];
	s_steck[1] = temp;
}*/

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
	steck_head->end = 0;
	buf->end = 0;
	buf->next = steck_head;
	buf->begin = steck_tail;
	return (buf);
}

void 		err(void)
{
	ft_printf("ERROR\n");
	exit(1);
}

int			main(int argc, char **argv)
{
	int		x;
	int		y;

	x = 1;
	y = 0;

	t_list *a_steck_head;
	t_list *a_steck_tail;
//	t_list *b_steck_head;
//	t_list *b_steck_tail;

	a_steck_head = NULL;
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
			if (a_steck_head == NULL)
			{
				a_steck_head = create_new_list(y);
				a_steck_tail = a_steck_head;
			}
			else
				a_steck_tail = add_node_next(a_steck_tail, a_steck_head, y);
		}
		else
			err();
		x++;
	}
	draw_list(a_steck_head);
	sa(a_steck_head);

}