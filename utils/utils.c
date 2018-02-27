/*
** utils.c for shell in /home/Neferett/PSU_2016_minishell1
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Thu Jan  5 16:05:54 2017 Bonaldi Jordan
** Last update	Sat Apr 22 23:09:25 2017 Jordan Bonaldi
*/

# include "project.h"

void			add_cmd(t_shell *shell, char **cmd, pid_t pid)
{
  t_list_cmd		*list;

  if (!(list = malloc(sizeof(*list))))
    exit(84);
  list->cmd = cmd;
  list->pid = pid;
  list->delay = 1;
  list->succes = true;
  list->p = shell->list;
  list->n = shell->list->n;
  shell->list->n->p = list;
  shell->list->n = list;
}

static t_list_cmd	*ini_list()
{
  t_list_cmd		*list;

  if (!(list = malloc(sizeof(*list))))
    exit(84);
  list->delay = 0;
  list->n = list;
  list->p = list;
  return (list);
}

t_shell		*init_shell(char **env)
{
  t_shell	*shell;

  if (!(shell = malloc(sizeof(*shell))))
    exit(84);
  1 ? shell->cmd = NULL, shell->r_d = false, shell->and_s = false,
      shell->pipe = false, shell->left = false, shell->right = false,
	  shell->first = false, shell->done = 0, shell->tenv = env,
	      shell->lenv = env_to_list(env), shell->set = init_list_set() : 0;
  shell->list = ini_list();
  shell->path = get_paths(shell);
  shell->builtin = init_builtin(-1);
  shell->alias = init_alias();
  if (!(shell->manip = malloc(sizeof(t_manip))) ||
      !(shell->read = malloc(sizeof(t_read))))
    exit(84);
  shell->read->hist = NULL;
  shell->manip->lefttmpfd = 0;
  shell->manip->lefttmp = 0;
  shell->manip->righttmpfd = 0;
  shell->manip->righttmp = 0;
  return (shell);
}

boolean		is_in_list(t_shell *shell)
{
  t_list_cmd	*tmp;

  tmp = shell->list;
  while (tmp->n != shell->list)
    {
      if (!my_strcmp(*tmp->n->cmd, *shell->cmd))
	return (true);
      tmp = tmp->n;
    }
  return (false);
}

void		segfault(t_shell *shell)
{
  if (WIFSIGNALED(shell->list->n->delay) &&
       WTERMSIG(shell->list->n->delay) == SIGSEGV)
    {
      if (WCOREDUMP(shell->list->n->delay))
	       write(2, "Segmentation fault (core dumped)\n", 33);
      else
	       write(2, "Segmentation fault\n", 19);
      shell->done = -1;
      shell->ret = 139;
    }
  if (WIFSIGNALED(shell->list->n->delay) &&
       WTERMSIG(shell->list->n->delay) == SIGFPE)
    {
      if (WCOREDUMP(shell->list->n->delay))
	write(2, "Floating exception (core dumped)\n", 33);
      else
	write(2, "Floating exception\n", 19);
  shell->done = -1;
  shell->ret = 136;
    }
}
