/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:08:13 by shalimi           #+#    #+#             */
/*   Updated: 2022/12/07 11:50:09 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sigquit_handler(int sig)
{
	(void) sig;
}

void sigint_handler(int sig)
{
	(void) sig;
}

int main(void)
{
	char		*line;
	t_command	command;

	line = malloc(1);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	while (1)
	{
		line = readline("$>");
		command = parse(line);
		printf("\ncommand: %s\n", command.command);
		int i = 0;
		while (i < command.argc)
		{
			printf("argument no %i: %s\n", i, command.args[i]);
			i++;
		}
		free(line);
		if (ft_strncmp(command.command, "quit", 4) == 0)
			break;
	}
	return 0;
}
