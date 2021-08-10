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


#endif