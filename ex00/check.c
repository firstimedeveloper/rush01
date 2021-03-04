/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanskim <hanskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 16:15:31 by hanskim           #+#    #+#             */
/*   Updated: 2021/03/03 15:12:39 by hanskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern int		g_n;
extern int		**g_condition;
extern int		**g_fix;
extern int		**g_box;
extern void		print_box(void);

int				check_duplicate(int r, int c, int val)
{
	int i;

	i = -1;
	while (++i < g_n)
	{
		if (i == r)
			continue;
		if (g_box[i][c] == val)
		{
			printf("check_duplicate fail in col!\n");
			print_box();
			return (-1);
		}
	}
	i = -1;
	while (++i < g_n)
	{
		if (i == c)
			continue;
		if (g_box[r][i] == val)
		{
			printf("check_duplicate fail in row!\n");
			print_box();
			return (-1);
		}
	}
	return (0);
}

int				check_col_up(int c)
{
	int i;
	int before;
	int cnt;

	before = 0;
	cnt = 0;
	i = -1;
	while (++i < g_n)
	{
		if (g_box[i][c] > before)
		{
			before = g_box[i][c];
			cnt++;
		}
	}
	if (cnt > g_condition[0][c])
	{
		printf("check_col_up fail!\n");
		return (-1);
	}
	return (0);
}

int				check_col_down(int c)
{
	int i;
	int before;
	int cnt;

	before = 0;
	cnt = 0;
	i = g_n;
	while (--i >= 0)
	{
		if (g_box[i][c] > before)
		{
			before = g_box[i][c];
			cnt++;
		}
	}
	if (cnt > g_condition[1][c])
	{
		printf("check_col_down fail!\n");
		return (-1);
	}
	return (0);
}

int				check_row_left(int r)
{
	int i;
	int before;
	int cnt;

	before = 0;
	cnt = 0;
	i = -1;
	while (++i < g_n)
	{
		if (g_box[r][i] > before)
		{
			before = g_box[r][i];
			cnt++;
		}
	}
	if (cnt > g_condition[2][r])
	{
		printf("check_row_left fail!\n");
		return (-1);
	}
	return (0);
}

int				check_row_right(int r)
{
	int i;
	int before;
	int cnt;

	before = 0;
	cnt = 0;
	i = g_n;
	while (--i >= 0)
	{
		if (g_box[r][i] > before)
		{
			before = g_box[r][i];
			cnt++;
		}
	}
	if (cnt > g_condition[3][r])
	{
		printf("check_row_right fail!\n");
		return (-1);
	}
	return (0);
}
