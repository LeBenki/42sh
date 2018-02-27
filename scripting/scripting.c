/*
** scripting.c for 42sh in /home/benki/Epitech/PSU_2016_42sh/scripting/
**
** Made by Lucas Benkemoun
** Login   <lucas.benkemoun@epitech.eu>
**
** Started on  Fri Apr 21 23:22:12 2017 Lucas Benkemoun
** Last update Fri Apr 28 13:28:47 2017 Lucas Benkemoun
*/

#include "project.h"

int		scripting(t_shell *shell)
{
  t_script	*s;
  int		i;
  char		c[2];
  t_shell	*new;

  i = -1;
  s = malloc(sizeof(t_script));
  new = init_shell(shell->tenv);
  s->argv = shell->cmd;
  s->argc = tab_len(s->argv);
  s->var = cpy_tab(shell->tenv);
  c[0] = s->argc + 48;
  c[1] = 0;
  s->var = set_variable(s->var, "#", c);
  while (s->argv[++i])
    {
      c[0] = i + 48;
      s->var = set_variable(s->var, c, s->argv[i]);
    }
  if (!(s->arr = read_file(s->argv[0])))
    return (false);
  if (exec_script(s, new))
    return (false);
  return (true);
}
