/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:14:49 by shalimi           #+#    #+#             */
/*   Updated: 2022/12/07 12:01:21 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_baskslash(char *str)
{
	int	i;
	int	len;

	len = (int) ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (str[i] == '\\')
		{
			ft_memcpy(str + i, str + i + 1, ft_strlen(str + i));
			len -= 1;
			str[len] = 0;
		}
		i++;
	}
	return (str);
}

t_command	parse(char *line)
{
	char		**split;
	int			len;
	char		*current;
	t_command	ret;
	int			i;
	int			y;

	len = ft_countchar(line, ' ') + 1;
	split = ft_split(line, ' ');
	ret.args = ft_calloc(sizeof(*(ret.args)), len);
	i = 0;
	y = 0;
	while (i < len)
	{
		current = ft_strtrim(split[i], " ");
		if (current[0] == '\'' || current[0] == '"')
			while (current[ft_strlen(current) - 1] != current[0] && i < len)
				current = ft_strjoin(current,split[++i]);
		current = ft_baskslash(current);
		if (current[0] == current[ft_strlen(current) - 1] && (
					current[0] == '\'' ||
					current[0] == '"'))
			current = ft_substr(current, 1, ft_strlen(current) - 2);
		ret.args[y++] = current;
		i++;
	}
	ret.command = split[0];
	ret.argc = y;
	return (ret);
}
