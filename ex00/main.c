/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanskim <hanskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 12:04:16 by hanskim           #+#    #+#             */
/*   Updated: 2021/02/28 15:34:15 by hanskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern void		ft_putstr(int fd, char *str);
extern int		preprocedure(char *str);
extern void		print_box(void);
extern int		rush01(void);

int				g_n = 0;
int				**g_condition = 0;
int				**g_fix = 0;
int				**g_box = 0;

void			free_all(void)
{
	int i;

	if (g_condition)
	{
		i = -1;
		while (++i < 4)
			free(g_condition[i]);
		free(g_condition);
		g_condition = 0;
	}
	if (g_box)
	{
		i = -1;
		while (++i < g_n)
			free(g_box[i]);
		free(g_box);
		g_box = 0;
	}
	if (!g_fix)
		return ;
	i = -1;
	while (++i < g_n)
		free(g_fix[i]);
	free(g_fix);
	g_fix = 0;
}

int				main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr(2, "number of condition is not correct.\n");
		return (1);
	}
	if (preprocedure(argv[1]) < 0)
		return (1);
	if (rush01() < 0)
		ft_putstr(1, "Error\n");
	print_box();
	free_all();
	return (0);
}
