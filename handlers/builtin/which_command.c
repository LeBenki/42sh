/*
** cd_command.c for shell in /home/Neferett/PSU_2016_minishell1
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Sun Jan  8 13:53:08 2017 Bonaldi Jordan
** Last update	Sat Apr 22 00:24:42 2017 Jordan Bonaldi
*/

# include "project.h"

static boolean		is_builtin(t_shell *shell, char *cmd)
{
  int			i;

  i = -1;
  while (shell->builtin[++i].cmd)
    if (!my_strcmp(shell->builtin[i].cmd, cmd))
	return (true);
  return (false);
}

void			builtin_which(t_shell *shell)
{
  int			fd;
  char			**path;
  int			i;
  int			j;
  char			*save;
  int			b;

  if (!(j = 0) && !shell->cmd[1] && (shell->done = 1))
    dprintf(2, "which: Too few arguments.\n");
  path = get_paths(shell);
  while (shell->cmd[++j])
    {
      if ((i = b = -1) && is_builtin(shell, shell->cmd[j]) &&
	  printf("%s: shell built-in command.\n", shell->cmd[j]))
	  continue;
      while (path[++i] && (save = path[i]))
	{
	  path[i] = my_strcat(my_strcat(path[i], "/"), shell->cmd[j]);
	  if (((fd = open(path[i], O_RDONLY)) > 0) && !(b = 0))
	    printf("%s\n", path[i]);
	  1 ? free(path[i]), path[i] = save : 0;
	}
      if (b && (shell->done = 1))
	  dprintf(2, "%s: Command not found.\n", shell->cmd[j]);
    }
}
