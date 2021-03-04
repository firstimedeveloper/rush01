/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanskim <hanskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 16:20:14 by hanskim           #+#    #+#             */
/*   Updated: 2021/03/03 15:09:38 by hanskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern int		check_duplicate(int r, int c, int val);
extern int		check_col_up(int c);
extern int		check_col_down(int c);
extern int		check_row_left(int r);
extern int		check_row_right(int r);
extern void		print_box(void);


extern int		g_n;
extern int		**g_condition;
extern int		**g_fix;
extern int		**g_box;

int				check(int r, int c, int val)
{
	printf("check: %d %d %d\n", r, c, val);
	if (check_duplicate(r, c, val) < 0)
		return (-1);
	g_box[r][c] = val;
	if (check_col_up(c) || check_col_down(c) ||
		check_row_left(r) || check_row_right(r))
	{
		g_box[r][c] = 0;
		return (-1);
	}
	return (0);
}

void			print_fix(void)
{
	printf("fix\n");
	for (int i = 0; i < g_n; i++)
	{
		for (int j = 0; j < g_n; j++)
		{
			printf("%d ", g_fix[i][j]);
		}
		putchar('\n');
	}
	return ;
}

int				recursive(int r, int c)
{
	printf("rec: %d %d\n", r, c);
	int i;
	int next_r;
	int next_c;

	if ((c == g_n - 1) && (r == g_n - 1))
		return (0);
	next_r = (c == g_n - 1) ? r + 1 : r;
	next_c = (c == g_n - 1) ? 0 : c + 1;
	if (!g_fix[r][c])
	{
		i = 0;
		while (++i <= g_n)
			if (!check(r, c, i))
			{
				printf("in while!\n");
				if (!recursive(next_r, next_c))
					break ;
			}
		if (i > g_n)
		{
			printf("fail!\n");
			print_box();
			return (-1);
		}
	}
	else
	{
		//print_fix();
		printf("in else!\n");
		return (recursive(next_r, next_c));
	}
	return (0);
}
