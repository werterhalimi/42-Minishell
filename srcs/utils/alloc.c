/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:10:03 by shalimi           #+#    #+#             */
/*   Updated: 2022/12/12 22:17:01 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_alloc(int size, int len, t_list **buff)
{
	void	*ret;

	ret = ft_calloc(size, len);
	ft_lstadd_back(buff, ft_lstnew(ret));
	return (ret);
}