/*
** utils_sig.c for 42sh in /home/benki/Epitech/PSU_2016_42sh
**
** Made by Lucas Benkemoun
** Login   <lucas.benkemoun@epitech.eu>
**
** Started on  Mon May 15 16:14:10 2017 Lucas Benkemoun
** Last update Mon May 15 16:19:02 2017 Lucas Benkemoun
*/

#include "project.h"

static t_shell	*sh;

void	init_sig(t_shell *shell)
{
  sh = shell;
}

void    signal_handling(int signal)
{
  if (signal && !my_printf("\n"))
    prompt(sh);
}
