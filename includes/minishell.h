/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:20:03 by shalimi           #+#    #+#             */
/*   Updated: 2022/12/07 11:57:49 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
#include <stdio.h>
#include <readline/readline.h>
#include <signal.h>
#include <readline/history.h>
#include <stdlib.h>


typedef struct s_command
{
	char	*command;
	char	**args;
	int		argc;
}	t_command;

t_command	parse(char *line);
size_t		ft_strlen(const char *str);
void		*ft_calloc(size_t nb, size_t len);
int			ft_countchar(const char *s, char c);
char		**ft_split(const char *s, char c);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_substr(const char *s, unsigned int start, size_t len);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
