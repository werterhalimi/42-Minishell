/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:19:38 by shalimi           #+#    #+#             */
/*   Updated: 2022/12/06 13:48:14 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;

	if (start >= ft_strlen(s))
	{
		ptr = malloc(sizeof(char));
		ptr[0] = 0;
		return (ptr);
	}
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	ptr = (char *) malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (i < (int) len && s[start])
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = 0;
	return (ptr);
}
