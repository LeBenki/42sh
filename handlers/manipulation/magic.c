/*
** magic.c for 42 in /Users/neferett/EPITECH/PSU_2016_42sh/handlers/
**
** Made by Jordan Bonaldi
** Login   <Neferett@epitech.eu@epitech.eu>
**
** Started on  Thu May 18 14:26:28 2017 Jordan Bonaldi
** Last update Thu May 18 14:26:28 2017 Jordan Bonaldi
*/

# include "project.h"

void		stock_response(t_shell *shell, t_string *line)
{
  t_shell	*sh;
  int		fd2;
  int		fd;

  if ((fd = open(TMP_FILE, O_WRONLY
				    | O_TRUNC | O_CREAT, 0644)) < 0)
    exit(84);
  fd2 = dup(1);
  close(1);
  dup2(fd, 1);
  sh = init_shell(shell->tenv);
  line->str++;
  line->str[my_strlen(line->str) - 1] = 0;
  good_execution(sh, line);
  close(fd);
  dup2(fd2, 1);
  close(fd2);
}

void		get_response(t_shell *shell, int pos)
{
  int		fd;

  if ((fd = open(TMP_FILE, O_RDONLY)) < 0)
    return;
  shell->cmd[pos] = get_next_line(fd);
  close(fd);
}
