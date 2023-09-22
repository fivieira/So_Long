/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:41:55 by fivieira          #+#    #+#             */
/*   Updated: 2023/04/27 10:04:37 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int		a;
	char			c[10];
	short int		i;

	a = n;
	i = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (a < 0)
	{
		a = a * -1;
		write(fd, "-", 1);
	}
	while (a != 0)
	{
		c[i++] = (a % 10) + 48;
		a = a / 10;
	}
	while (i > 0)
	{
		write(fd, &c[--i], 1);
	}
}

// int	main(void)
// {
// 	ft_putnbr_fd(454, 2);
// 	write(1, "\n", 1);
// }