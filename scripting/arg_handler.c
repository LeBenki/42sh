/*
** arg_handler.c for 42sh in /home/benki/Epitech/PSU_2016_42sh/scripting/
**
** Made by Lucas Benkemoun
** Login   <lucas.benkemoun@epitech.eu>
**
** Started on  Sat Apr 29 15:18:17 2017 Lucas Benkemoun
** Last update Sat Apr 29 15:30:48 2017 Lucas Benkemoun
*/

#include "project.h"

void		arg_handler(char **av, char **ae)
{
  t_shell	*shell;

  shell = init_shell(ae);
  shell->cmd = &av[1];
  scripting(shell);
  exit(shell->done == -1 ? shell->ret : shell->done == 1 ? 1 :
      shell->list->n->delay);
}
