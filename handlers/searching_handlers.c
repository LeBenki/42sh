/*
** searching_handlers.c for shell in /home/Neferett/PSU_2016_minishell1
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Fri Jan  6 18:16:43 2017 Bonaldi Jordan
** Last update	Sat Apr 22 23:08:31 2017 Jordan Bonaldi
*/

# include "project.h"

static boolean			command_exists(char *cmd, char *path)
{
  struct dirent			*d;
  DIR				*dir;

  if (!(dir = opendir(path)))
    return (false);
  while ((d = readdir(dir)))
    if (!my_strcmp(cmd, d->d_name))
	{
	  closedir(dir);
	  return (true);
	}
  closedir(dir);
  return (false);
}

static boolean			try_direct_command(t_shell *shell)
{
  int				pid;

  if (is_shebang(*shell->cmd))
	return (scripting(shell));
  if (!(pid = fork()) && (execve(*shell->cmd, shell->cmd, shell->tenv)) < 0)
    {
      if (errno == ENOEXEC &&
	  !my_printf("%s: Exec format error. Binary file not executable.\n",
		     *shell->cmd))
	exit(2);
      exit(1);
    }
  else
    {
	wait(&shell->list->n->delay);
	if (WEXITSTATUS(shell->list->n->delay) == 1)
	    return (false);
	else if (WEXITSTATUS(shell->list->n->delay) == 2 &&
		 (shell->done = -1) && (shell->ret = true))
	    return (true);
	segfault(shell);
	shell->list->n->delay = WEXITSTATUS(shell->list->n->delay);
	add_cmd(shell, shell->cmd, pid);
	return (true);
    }
}

static boolean			searching_in_path(t_shell *shell)
{
  char				*path;
  int				i;

  i = -1;
  while (shell->path[++i])
    if (command_exists(*shell->cmd, shell->path[i]))
      {
	add_cmd(shell, shell->cmd, fork());
	path = my_strcat(my_strcat(shell->path[i], "/"), *shell->list->n->cmd);
	if (!shell->list->n->pid && (execve(path, shell->cmd, shell->tenv) < 0))
	  {
	    my_printf("bad execution\n");
	    shell->list->n->succes = false;
	  }
	shell->done = false;
	wait(&shell->list->n->delay);
	segfault(shell);
	shell->list->n->delay = WEXITSTATUS(shell->list->n->delay);
	return (true);
      }
  return (false);
}

void				search_command(t_shell *shell)
{
  int				i;

  i = -1;
  signal(SIGINT, signal_handling);
  if (!get_permission(*shell->cmd) &&
      !my_printf("%s: Permission denied.\n", *shell->cmd)
				&& (shell->done = 1))
    return;
  if (try_direct_command(shell))
    return;
  while (shell->builtin[++i].cmd)
    if (!my_strcmp(*shell->cmd, shell->builtin[i].cmd))
      {
	shell->done = false;
	add_cmd(shell, shell->cmd, 0);
	shell->list->n->delay = 0;
	shell->builtin[i].builtin(shell);
	return;
      }
  if (searching_in_path(shell))
    return;
  shell->done = true;
  if (errno != 24)
    write(2, my_strcat(*shell->cmd, ": Command not found.\n"),
	  my_strlen(*shell->cmd) + 21);
}
