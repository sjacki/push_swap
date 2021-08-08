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

void		write_steck(int	*f_steck, int	*s_steck, int argc)
{
	int x;

	x = 0;
	while (x < argc - 1)
	{
		printf("%d				%d\n", f_steck[x], s_steck[x]);
		x++;
	}
}

void		sa(int	*f_steck, int	*s_steck, int argc)
{
	int temp;

	temp = f_steck[0];
	f_steck[0] = f_steck[1];
	f_steck[1] = temp;
	printf("		USE SA\nA				B\n---------------------------------\n");
	write_steck(f_steck, s_steck, argc);
}

void		pa(int	*f_steck, int	*s_steck, int argc)
{
	if (s_steck[0] != 0)
	{
			
	}
	printf("		USE PA\nA				B\n---------------------------------\n");
	write_steck(f_steck, s_steck, argc);
}

void		sb(int	*f_steck, int	*s_steck, int argc)
{
	int temp;

	temp = s_steck[0];
	s_steck[0] = s_steck[1];
	s_steck[1] = temp;
	printf("		USE SB\nA				B\n---------------------------------\n");
	write_steck(f_steck, s_steck, argc);
}

void		ss(int	*f_steck, int	*s_steck, int argc)
{
	printf("		USE SS\nA				B\n---------------------------------\nV                               V\n");
	sa(f_steck, s_steck, argc);
	sb(f_steck, s_steck, argc);
	printf("^-------------------------------^\n---------------------------------\n");
}



int			main(int argc, char **argv)
{
	int		*f_steck;
	int		*s_steck;
	int		x;
	int		y;

	x = 1;
	y = 0;

	f_steck = (int*)malloc(argc * sizeof(int));
	s_steck = (int*)malloc(argc * sizeof(int));
	while(x < argc)
	{
		if (ft_isdigit(*argv[x]) || *argv[x] == 45)
			y = ft_atoi(argv[x]);
		f_steck[x - 1] = y;
		x++;
	}
	x = 0;
	printf("	init a and b steck\nA				B\n---------------------------------\n");
	write_steck(f_steck, s_steck, argc);
	sa(f_steck, s_steck, argc);
	sb(f_steck, s_steck, argc);
	ss(f_steck, s_steck, argc);
}