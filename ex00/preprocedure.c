/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocedure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanskim <hanskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:26:07 by hanskim           #+#    #+#             */
/*   Updated: 2021/03/03 15:07:14 by hanskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern void		ft_putstr(int fd, char *str);
extern int		is_space(char c);
extern int		is_numeric(char c);

extern int		g_n;
extern int		**g_condition;
extern int		**g_fix;
extern int		**g_box;

int				token_check(char *str)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (1)
	{
		if (i > 0)
		{
			if (is_numeric(str[i - 1]))
			{
				if (is_space(str[i]))
					cnt++;
				else
					return (-1);
			}
		}
		if (!str[i])
			break ;
		if (!is_numeric(str[i]) && !is_space(str[i]))
			return (-1);
		i++;
	}
	return (cnt);
}

int				**generate_condition(char *str)
{
	int	i;
	int j;

	g_condition = (int **)malloc(sizeof(int *) * 4);
	i = -1;
	while (++i < 4)
	{
		g_condition[i] = (int *)malloc(sizeof(int) * g_n);
		j = -1;
		while (++j < g_n)
		{
			while (is_space(*str))
				str++;
			g_condition[i][j] = *str - '0';
			str++;
		}
	}
	return (g_condition);
}

int				condition_check(void)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < g_n)
			if (g_condition[i][j] < 1 || g_condition[i][j] > g_n)
				return (-1);
	}
	return (0);
}

int				preprocedure(char *str)
{
	int	i;
	int cnt;

	cnt = token_check(str);
	if (cnt < 0)
	{
		ft_putstr(2, "Some condition are not one digit.\n");
		return (-1);
	}
	else if (!cnt || cnt % 4)
	{
		ft_putstr(2, "Number of condition is not correct.\n");
		return (-1);
	}
	g_n = cnt / 4;
	i = -1;
	g_condition = generate_condition(str);
	if (condition_check() < 0)
	{
		ft_putstr(2, "Some condition are not correct number.\n");
		return (-1);
	}
	return (0);
}

void			print_box(void)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < g_n)
	{
		j = -1;
		while (++j < g_n)
		{
			if (g_box[i][j] < 0 || g_box[i][j] > 9)
				c = 'E';
			else
				c = g_box[i][j] + '0';
			putchar(c);
			//write(1, &c, 1);
			putchar(' ');
			//ft_putstr(1, " ");
		}
		putchar('\n');
		//ft_putstr(1, "\n");
	}
	return ;
}
