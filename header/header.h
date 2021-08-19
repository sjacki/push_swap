/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 00:04:04 by alexandr          #+#    #+#             */
/*   Updated: 2021/07/10 05:22:16 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include "../libft/header/libft.h"

typedef struct  s_list
{
    struct s_list   *next;
    struct s_list   *begin;
    int             value;
    int 			end;
}               t_list;

typedef struct  s_val
{
	t_list	*a_steck_head;
	t_list	*a_steck_tail;
	t_list	*b_steck_head;
	t_list	*b_steck_tail;
}               t_val;

void 		draw_list(t_val *val);
t_list		*create_new_list(int value);
t_list 		*add_node_next(t_list *steck_tail, t_list *steck_head, int value);
t_list 		*add_node_begin(t_list *steck_tail, t_list *steck_head, int value);
t_list 		*delete_first_node(t_list *steck_head, t_list *steck_tail);
void 		init_a_steck(struct s_val *val, int argc, char **argv, int x);
void		pb(struct s_val *val);
void		pa(struct s_val *val);
void		sb(t_list *b_steck_head);
void		sa(t_list *a_steck_head);
void 		ss(struct  s_val *val);
void 		err(void);

#endif