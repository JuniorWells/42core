/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:42:15 by kchaniot          #+#    #+#             */
/*   Updated: 2021/10/30 17:26:11 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_command	**create_list(int elem, char **argv, char **env, t_command **lst)
{
	int			i;
	t_command	*temp;

	i = 2;
	if (!ft_strncmp(argv[1], HERE_DOC, ft_strlen(HERE_DOC)))
		i = 3;
	while (elem--)
	{
		temp = malloc(sizeof(t_command));
		if (!temp)
			return (0);
		temp = populate(temp, argv[i++], env);
		ft_lst_add_back(lst, temp);
	}
	return (lst);
}

void	ft_lst_add_back(t_command **lst, t_command *new)
{
	t_command	*ptr;

	if (!*lst)
		*lst = new;
	else
	{
		ptr = *lst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
	}
}

t_command	*populate(t_command *cmd, char *s, char **env)
{
	cmd->cmd_args = ft_split(s, ' ');
	cmd->path = get_path(*cmd->cmd_args, env);
	cmd->next = NULL;
	cmd->prev = NULL;
	return (cmd);
}
