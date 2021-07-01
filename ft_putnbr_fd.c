/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 10:56:03 by rbliss            #+#    #+#             */
/*   Updated: 2020/11/06 16:12:24 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		doz;
	int		mod;
	char	c;

	doz = 1;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n *= -1;
			write(fd, "-", 1);
		}
		while (n / doz > 9)
			doz *= 10;
		while (doz)
		{
			mod = n / doz;
			c = mod + 48;
			write(fd, &c, 1);
			n %= doz;
			doz /= 10;
		}
	}
}
