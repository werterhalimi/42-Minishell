/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:17:07 by shalimi           #+#    #+#             */
/*   Updated: 2022/12/05 21:48:22 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_strlenuntil(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i);
}

int	ft_countchar(const char *s, char c)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (c == 0)
		return (-1);
	while (s[i])
	{
		if (s[i++] == c)
		{
			if (s[i] == c || !s[i])
				continue ;
			else
				ret++;
		}
	}
	if (!ret)
		return (-1);
	if (s[0] == c || s[i - 1] == c)
		ret--;
	return (ret);
}

static char	**ft_manage(const char *s, char c)
{
	int		i;
	char	**ret;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			ret = malloc (sizeof(char *) * 2);
			ret[0] = ft_substr(&s[i], 0, ft_strlenuntil(&s[i], c));
			ret[1] = 0;
			return (ret);
		}
		i++;
	}
	ret = malloc(sizeof(char *));
	ret[0] = 0;
	return (ret);
}

static void	bullshit(int *i, int *j)
{
	*j = 0;
	*i = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	int		len;
	int		i;
	int		j;	

	len = ft_countchar(s, c) + 1;
	if (!len)
		return (ft_manage(s, c));
	ret = ft_calloc(sizeof(char *), (len + 1));
	if (!ret)
		return (0);
	bullshit(&i, &j);
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		ret[j] = ft_substr(&s[i], 0, ft_strlenuntil(&s[i], c));
		if (!ret[j])
			return (0);
		i += ft_strlen(ret[j++]);
	}
	return (ret);
}
