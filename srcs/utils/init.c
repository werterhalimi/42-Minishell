/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncotte <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:43:51 by ncotte            #+#    #+#             */
/*   Updated: 2022/12/08 16:43:52 by ncotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	init(char *envp[])
{
	int		i;
	t_list	*list;

	i = 0;
	g_var.envp = ft_lstnew(ft_strdup(envp[i++]));
	if (!g_var.envp)
		return (1);
	while (envp[i])
	{
		list = ft_lstnew(ft_strdup(envp[i++]));
		if (!list)
			return (1);
		ft_lstadd_back(&(g_var.envp), list);
	}
	return (export(prompt()));
}

char	*prompt(void)
{
	char	*prompt1;
	char	*prompt2;

	prompt1 = ft_strjoin("PROMPT=", CYAN);
	if (!prompt1)
		return ("> ");
	prompt2 = ft_strjoin(prompt1, "minishell > ");
	free(prompt1);
	if (!prompt2)
		return ("> ");
	prompt1 = ft_strjoin(prompt2, RESET_COLOR);
	free(prompt2);
	if (!prompt1)
		return ("> ");
	return (prompt1);
}