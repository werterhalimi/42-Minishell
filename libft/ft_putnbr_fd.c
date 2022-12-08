/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncotte <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:54:30 by ncotte            #+#    #+#             */
/*   Updated: 2022/10/12 10:59:29 by ncotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	if ((n > 9) || (n < -9))
		ft_putnbr_fd(n / 10, fd);
	else if ((n < 0) && (n > -10))
		write(fd, "-", 1);
	if (n < 0)
	{
		n = n % 10 * (-1) + '0';
		write(fd, &n, 1);
	}
	else
	{
		n = n % 10 + '0';
		write(fd, &n, 1);
	}
}