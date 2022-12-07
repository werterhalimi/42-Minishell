/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:17:21 by shalimi           #+#    #+#             */
/*   Updated: 2022/12/05 21:19:06 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_calloc(size_t nb, size_t len)
{
	void	*ret;
	int		i;

	i = 0;
	ret = malloc(len * nb);
	if (!ret)
		return (0);
	while (i < (int)(len * nb))
		((unsigned char *)ret)[i++] = 0;
	return (ret);
}
