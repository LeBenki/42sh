/*
** source_command.c for 42sh in /home/benki/Epitech/PSU_2016_42sh/handlers/builtin/
**
** Made by Lucas Benkemoun
** Login   <lucas.benkemoun@epitech.eu>
**
** Started on  Sun May 14 21:59:25 2017 Lucas Benkemoun
** Last update Sun May 14 22:08:28 2017 Lucas Benkemoun
*/

#include "project.h"

void			builtin_source(t_shell *shell)
{
  t_script		*s;

  if (!shell->cmd[1])
    dprintf(2, "source: Too few arguments.\n");
  else
    {
      if (!(s = malloc(sizeof(t_script))))
	return ;
      if (!(s->arr = read_file(shell->cmd[1])))
	return ;
      exec_script(s, shell);
    }
}
