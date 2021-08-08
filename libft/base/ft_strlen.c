/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:39:29 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/26 19:54:49 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

size_t		ft_strlen(const char *s)
{
	size_t		x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}