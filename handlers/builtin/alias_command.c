/*
** cd_command.c for shell in /home/Neferett/PSU_2016_minishell1
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Sun Jan  8 13:53:08 2017 Bonaldi Jordan
** Last update	Sun Apr 23 00:04:55 2017 Jordan Bonaldi
*/

# include "project.h"

static void	disp_alias(t_shell *shell)
{
	t_alias	*alias;

	alias = shell->alias;
	if ((!alias || alias->n == shell->alias) &&
			!my_printf("No alias created\n"))
		return;
	while (alias->p != shell->alias)
		{
			my_printf("Alias: %s\t\tCommand: %s\n", alias->p->alias->str,
				alias->p->cmd->str);
			alias = alias->p;
		}
}

static t_string	*get_cmd(t_shell *shell)
{
  char		*str;
  int		i;

  i = 1;
  if (!(str = malloc(1)))
    return (NULL);
  *str = 0;
  while (shell->cmd[++i])
    str = my_strcat(str, my_strcat(shell->cmd[i], " "));
  return (init_string(str));
}

void			handle_all_alias(t_shell *shell)
{
  t_string		*alias;

  if (shell->cmd[1] && my_strcmp(shell->cmd[1], "remove") && shell->cmd[2] &&
      (alias = alias_exists(shell->cmd[2], shell->alias)))
    replace_that_str(shell->cmd[2], shell->cmd[2], alias->str);
}

void			builtin_alias(t_shell *shell)
{
  handle_all_alias(shell);
  if (shell->cmd[1] && my_strcmp(shell->cmd[1], "remove") && shell->cmd[2])
    {
      if (alias_exists(shell->cmd[1], shell->alias))
	my_rm_alias(&shell->alias, shell->cmd[1], &my_strcmp, &my_strlen);
      add_alias(init_string(shell->cmd[1]), get_cmd(shell), shell->alias);
    }
  else if (shell->cmd[1] && !my_strcmp(shell->cmd[1], "remove")
	   && shell->cmd[2])
    if (alias_exists(shell->cmd[2], shell->alias) &&
	!my_printf("Alias %s[%s] removed\n",
		   alias_exists(shell->cmd[2], shell->alias)->str, shell->cmd[2]))
	my_rm_alias(&shell->alias, shell->cmd[2], &my_strcmp, &my_strlen);
      else
	my_printf("Impossible to remove unexistant alias\n");
  else if (shell->cmd[1] && !shell->cmd[2])
     if (alias_exists(shell->cmd[1], shell->alias))
	    my_printf("Alias: %s\t\tCommand: %s\n", shell->cmd[1],
		      alias_exists(shell->cmd[1], shell->alias)->str);
     else
	my_printf("Unknown alias %s\n", shell->cmd[1]);
  else
	  disp_alias(shell);
}
