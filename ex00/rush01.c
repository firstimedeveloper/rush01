/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanskim <hanskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 12:36:54 by hanskim           #+#    #+#             */
/*   Updated: 2021/02/28 18:43:18 by hanskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern int		recursive(int r, int c);

extern int		g_n;
extern int		**g_condition;
extern int		**g_fix;
extern int		**g_box;

void			init(void)
{
	int	i;
	int	j;

	g_fix = (int **)malloc(sizeof(int *) * g_n);
	g_box = (int **)malloc(sizeof(int *) * g_n);
	i = -1;
	while (++i < g_n)
	{
		g_fix[i] = (int *)malloc(sizeof(int) * g_n);
		g_box[i] = (int *)malloc(sizeof(int) * g_n);
		j = -1;
		while (++j < g_n)
		{
			g_fix[i][j] = 0;
			g_box[i][j] = 0;
		}
	}
	return ;
}

int				solve_n(void)
{
	int	i;
	int	j;
	int k;
	int r;
	int c;

	i = -1;
	while ((j = -1) && (++i < g_n))
		while (++j < g_n)
			if ((k = -1) && (g_condition[i][j] == g_n))
				while (++k < g_n)
				{
					r = i < 2 ? k : j;
					c = i < 2 ? j : k;
					if (g_fix[r][c] &&
						(g_box[r][c] != (i % 2 ? g_n - k : k + 1)))
						return (-1);
					g_box[r][c] = i % 2 ? g_n - k : k + 1;
					g_fix[r][c] = 1;
				}
	return (0);
}

int				solve_one(void)
{
	int	i;
	int	j;
	int row;
	int col;
	int val;

	i = -1;
	while (++i < g_n)
	{
		j = -1;
		while (++j < g_n)
			if (g_condition[i][j] == 1)
			{
				val = i % 2 ? g_n - 1 : 0;
				row = i >= 2 ? j : val;
				col = i < 2 ? j : val;
				val = g_n;
				if (g_fix[row][col] && g_box[row][col] != val)
					return (-1);
				g_box[row][col] = val;
				g_fix[row][col] = 1;
			}
	}
	return (0);
}

int				solve_others(void)
{
	return (recursive(0, 0));
}

int				rush01(void)
{
	init();
	if (solve_n() < 0)
		return (-1);
	if (solve_one() < 0)
		return (-1);
	if (solve_others() < 0)
		return (-1);
	return (0);
}
