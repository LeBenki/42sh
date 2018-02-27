/*
** utils_globbing.c for 42sh in /Users/neferett/EPITECH/PSU_2016_42sh/utils/
**
** Made by Jordan Bonaldi
** Login   <Neferett@epitech.eu@epitech.eu>
**
** Started on  Thu Apr 27 17:02:57 2017 Jordan Bonaldi
** Last update Fri Apr 28 14:11:05 2017 Jordan Bonaldi
*/

# include "project.h"

static boolean		check_line(char *line)
{
  return (nb_of(line, '*') ||
	  nb_of(line, '?') ||
	  (nb_of(line, '[') && nb_of(line, ']')));
}

void		is_globbing(t_shell *shell)
{
  boolean	use;
  glob_t	g;
  int		i;
  int		ret;

  i = -1;
  use = false;
  while (shell->cmd[++i])
    {
      g.gl_offs = 0;
      if (check_line(shell->cmd[i]))
	{
	  if (!use)
	    ret = glob(shell->cmd[i], GLOB_DOOFFS, NULL, &g);
	  else
	    ret = glob(shell->cmd[i], GLOB_DOOFFS | GLOB_APPEND, NULL, &g);
	  if (ret != 0 && (shell->done = true) &&
	      !my_printf("%s: No match.\n", *shell->cmd))
	    return;
	  shell->cmd = my_tabcat(shell->cmd, g.gl_pathv, i);
	  use = true;
	}
    }
  return;
}
