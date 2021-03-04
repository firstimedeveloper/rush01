/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanskim <hanskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 12:36:08 by hanskim           #+#    #+#             */
/*   Updated: 2021/02/28 14:30:24 by hanskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
	return ;
}

int		is_space(char c)
{
	return ((c == '\0') || (c == ' ') || ((c >= 9) && (c <= 13)));
}

int		is_numeric(char c)
{
	return ((c >= '0') && (c <= '9'));
}
