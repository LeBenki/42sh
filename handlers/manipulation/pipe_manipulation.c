/*
** pipe_manipulation.c for PSU_2016_minishell2
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sun Apr 09 11:49:14 2017 Jordan Bonaldi
** Last update	Sat Apr 22 02:09:33 2017 Jordan Bonaldi
*/

# include "project.h"

static boolean 		exec_pipe2(t_string **line, t_shell *shell)
{
  int   		p[2];
  int			a;
  int			i;
  boolean		sucess;

  if ((a = open(TMP_FILE, O_WRONLY | O_TRUNC | O_CREAT, 0755)) < 0)
    return (false);
  1 ? sucess = true, i = -1, p[0] = dup(1), p[1] = dup(0) : 0;
  while (line[++i] && shell_up(shell, line[i]))
    {
      if (i == 1)
	{
	  dup2(p[0], 1);
	  if ((a = open(TMP_FILE, O_RDONLY)) < 0)
	    return (false);
	  1 ? dup2(a, 0), close(a), search_command(shell),
	  dup2(p[1], 0) : 0;
	  shell->done == 1 ? sucess = false : 0;
	}
      else if (i == 0)
	1 ? dup2(a, 1), search_command(shell), close(a),
      (shell->done == 1 ? sucess = false : 1) : 0;
    }
  return (!sucess ? shell->done = 1 : true);
}

static boolean		exec_pipe_mul(t_string **line, t_shell *shell)
{
  t_pipe		*p;

  1 ? p = xmalloc(sizeof(t_pipe)), p->buff2 = xmalloc(1) : 0;
  if (!(*p->buff2 = 0) && !(p->a = 0) && (p->sucess = true) && !(p->fd = 0)) {}
  while (*line)
    if (pipe2(p->p, O_NONBLOCK) < 0 || (p->pid = vfork()) < 0)
      {
	if (errno == 24 && !(p->buff2[my_strlen(p->buff2) - 1] = 0)
	    && printf("%s", p->buff2)) {}
	return (true);
      }
    else if (!p->pid)
      {
	1 ? dup2(p->fd, 0), (*(line + 1) ? dup2(p->p[1], 1) : 0),
	  good_execution(shell, *line), close(p->p[0]) : 0;
	exit(shell->done ? 1 : shell->list->n->delay);
      }
    else
      {
	while ((p->buff = get_next_line(p->p[0])))
	  p->buff2 = my_strcat(p->buff2, my_strcat(p->buff, "\n"));
	1 ? wait(&p->a), close(p->p[1]), p->fd = p->p[0], line++,
	  (WEXITSTATUS(p->a) != 0 ? p->sucess = false : 0) : 0;
      }
  return (!p->sucess ? shell->done = 1 : true);
}

static boolean		exec_pipe_normal(t_string **line, t_shell *shell)
{
  int   		p[2];
  pid_t 		pid;
  int   		fd;
  int			a;
  boolean 		sucess;

  if (!(a = 0) && (sucess = true) && !(fd = 0)) {}
  while (*line)
    {
      if (pipe2(p, O_NONBLOCK) < 0 || (pid = fork()) < 0)
	return (true);
      else if (!pid)
	{
	  1 ? dup2(fd, 0), (*(line + 1) ? dup2(p[1], 1) : 0),
	  good_execution(shell, *line), close(p[0]) : 0;
	  exit(shell->done ? 1 : shell->list->n->delay);
	}
      else
	1 ? wait(&a), close(p[1]), fd = p[0], line++,
	  (WEXITSTATUS(a) != 0 ? sucess = false : 0) : 0;
    }
  return (!sucess ? shell->done = 1 : true);
}

static boolean		exec_pipe_r_d(t_string **line, t_shell *shell)
{
  while (*line)
    {
      good_execution(shell, *line);
      if (!(shell->done == -1 ? shell->ret : shell->done == 1 ? 1 :
          shell->list->n->delay))
	  break;
      shell->done = 0;
      shell->ret = 0;
      shell->list->n->delay = 0;
      line++;
    }
  return (true);
}

boolean		exec_pipe(t_string **line, t_shell *shell)
{
  if (shell->r_d && !(shell->r_d = false))
    return (exec_pipe_r_d(line, shell));
  else if (st_len(line) == 2)
    return (exec_pipe2(line, shell));
  else if (st_len(line) > 10)
    return (exec_pipe_mul(line, shell));
  else
    return (exec_pipe_normal(line, shell));
}
