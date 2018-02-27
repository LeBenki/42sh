/*
** main.c for  in /home/scrountchy/PSU_2016_42sh
**
** Made by Sacha PERIN
** Login   <sacha.perin@epitech.eu>
**
** Started on  Wed May  3 14:47:22 2017 Sacha PERIN
** Last update Sat May 20 13:40:51 2017 Lucas Benkemoun
*/

# include "project.h"

void		set_ret_value(t_shell *shell)
{
  if (set_exists("?", shell->set))
    my_rm_set(&shell->set, "?", &my_strcmp, &my_strlen);
  add_set(init_string("?"),
	  init_string(my_itoa(shell->done == -1 ? shell->ret :
			      shell->done == 1 ? 1 :
			      shell->list->n->delay)), shell->set);
}

void		test_exit(char *input)
{
  if (!strcmp(my_epur_all_str(input), "else"))
    exit(0);
}

void		main_handling(t_shell *shell)
{
  int		i;
  char		*input;
  t_string	*buff;

  1 ? i = 0, buff = init_string("NULL"), shell->tmp = shell->list : 0;
  while ((input = get_input(shell)))
    {
      if ((!buff->recreate(buff, my_epur_str(input)) ||
	   !strcmp(my_epur_all_str(input), "endif")) && prompt(shell))
	continue;
      test_exit(input);
      1 ? shell->tmp = shell->list,
  	      set_ret_value(shell), shell->done = false : 0;
      if ((!buff->first) && prompt(shell)) {}
      else
  	{
  	  if (((!(buff = search_in_command_line(buff, shell)) ||
		(!look_at_line(buff) && !my_printf("Invalid null command.\n"))) &&
	       ++i && (shell->done = 1)) && prompt(shell))
	    continue;
  	  good_execution(shell, buff);
  	  prompt(shell);
  	  i++;
  	}
    }
}

int		init_42shrc(t_shell *shell)
{
  good_execution(shell, init_string("source .42shrc"));
  return (1);
}

int		main(int argc, char **argv, char **ae)
{
  t_shell	*shell;

  if (argc > 1)
	arg_handler(argv, ae);
  shell = init_shell(ae);
  if (!ae || !**argv)
    return (84);
  if (isatty(STDIN_FILENO) &&
      setupterm(get_env("TERM", shell->lenv), 1, (int *)0) < 0)
    exit (84);
  if (isatty(STDIN_FILENO) && init_42shrc(shell))
	my_printf("%s", tigetstr("smkx"));
  prompt(shell);
  add_set(init_string("0"), init_string(argv[0] + 2), shell->set);
  add_set(init_string("#"), init_string(my_itoa(argc - 1)), shell->set);
  init_sig(shell);
  signal(SIGINT, signal_handling);
  main_handling(shell);
  if (isatty(STDIN_FILENO))
    my_printf("exit\n");
  return (shell->done == -1 ? shell->ret : shell->done == 1 ? 1 :
      shell->list->n->delay);
}
