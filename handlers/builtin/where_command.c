/*
** where_command.c for 42sh in /home/benki/Epitech/test/handlers/builtin/
**
** Made by Lucas Benkemoun
** Login   <lucas.benkemoun@epitech.eu>
**
** Started on  Fri Apr 2869:35:46 2017 Lucas Benkemoun
** Last update Fri Apr 28 09:47:40 2017 Jordan Bonaldi
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

void			builtin_where(t_shell *shell)
{
  int			fd;
  char			**path;
  int			i;
  int			j;
  char			*save;
  int			b;

  if (!(j = 0) && !shell->cmd[1] && (shell->done = 1))
    dprintf(2, "where: Too few arguments.\n");
  path = get_paths(shell);
  while (shell->cmd[++j])
    {
      i = b = -1;
      while (path[++i] && (save = path[i]))
	{
	  path[i] = my_strcat(my_strcat(path[i], "/"), shell->cmd[j]);
	  if (((fd = open(path[i], O_RDONLY)) > 0) && !(b = 0))
	    printf("%s\n", path[i]);
	  1 ? free(path[i]), path[i] = save : 0;
	}
      if (is_builtin(shell, shell->cmd[j]))
	printf("%s is a shell built-in\n", shell->cmd[j]);
      if (b && (shell->done = 1))
	dprintf(2, "%s: Command not found.\n", shell->cmd[j]);
    }
}
