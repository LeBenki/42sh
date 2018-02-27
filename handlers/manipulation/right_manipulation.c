/*
** right_manipulation.c for PSU_2016_minishell2
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sun Apr 09 11:38:08 2017 Jordan Bonaldi
** Last update	Fri Apr 14 19:56:42 2017 Jordan Bonaldi
*/

# include "project.h"

t_string		**start_nd_right(t_shell *shell, t_string **string)
{
  shell->manip->righttmpfd = dup(1);
  close(1);
  if ((shell->manip->righttmp =
	     open(++string[st_len(string) - 1]->str,
		     O_WRONLY | O_TRUNC | O_CREAT, 0644)) < 0)
    exit(84);
  dup2(shell->manip->righttmp, 1);
  string[st_len(string) - 1] = NULL;
  return (string);
}

void		end_nd_right(t_shell *shell)
{
  close(shell->manip->righttmp);
  dup2(shell->manip->righttmpfd, 1);
  close(shell->manip->righttmpfd);
  shell->right = false;
}

t_string		**start_d_right(t_shell *shell, t_string **string)
{
  if ((shell->manip->righttmp =
       open(++string[st_len(string) - 1]->str,
	    O_APPEND | O_WRONLY | O_CREAT, 0644)) < 0)
    exit(4);
  shell->manip->righttmpfd = dup(1);
  close(1);
  dup2(shell->manip->righttmp, 1);
  string[st_len(string) - 1] = NULL;
  return (string);
}

void		end_d_right(t_shell *shell)
{
  close(shell->manip->righttmp);
  dup2(shell->manip->righttmpfd, 1);
  close(shell->manip->righttmpfd);
  shell->right = false;
  shell->r_d = false;
}
