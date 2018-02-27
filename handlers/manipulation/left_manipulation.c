/*
** left_manipulation.c for PSU_2016_minishell2
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sun Apr 09 11:48:50 2017 Jordan Bonaldi
** Last update	Fri Apr 14 19:56:25 2017 Jordan Bonaldi
*/

# include "project.h"

t_string		**start_nd_left(t_shell *shell, t_string **string)
{
  if ((shell->manip->lefttmp =
       open(++string[st_len(string) - 1]->str,
	    O_RDONLY)) < 0)
    {
      my_printf("%s: No such file or directory.\n",
		string[st_len(string) - 1]->str);
      shell->left = false;
      return (NULL);
    }
  shell->manip->lefttmpfd = dup(0);
  close(0);
  dup2(shell->manip->lefttmp, 0);
  string[st_len(string) - 1] = NULL;
  return (string);
}

void		end_nd_left(t_shell *shell)
{
  close(shell->manip->lefttmp);
  dup2(shell->manip->lefttmpfd, 0);
  shell->left = false;
  shell->r_d = false;
}

t_string 		**start_d_left(t_shell *shell, t_string **string)
{
  char	*buff;
  char	*str;

  if (!(str = malloc(1)))
    exit(84);
  if ((shell->manip->lefttmp = open(TMP_FILE, O_WRONLY
				    | O_TRUNC | O_CREAT, 0755)) < 0)
    exit(84);
  isatty(STDIN_FILENO) ? my_printf("? ") : 1;
  while ((buff = get_next_line(0)))
    if (!my_strcmp(buff,
		  string[st_len(string) - 1]->str + 1))
      break;
    else if (!(isatty(STDIN_FILENO) ? my_printf("? ") : 0))
      str = my_strcat(str, my_strcat(buff, "\n"));
  str[my_strlen(str) - 1] = 0;
  write(shell->manip->lefttmp, my_strcat(str, "\n"), my_strlen(str) + 1);
  close(shell->manip->lefttmp);
  shell->manip->lefttmpfd = dup(0);
  close(0);
  if ((shell->manip->lefttmp = open(TMP_FILE, O_RDONLY)) < 0)
    exit(84);
  dup2(shell->manip->lefttmp, 0);
  string[st_len(string) - 1] = NULL;
  return (string);
}

void		end_d_left(t_shell *shell)
{
  close(shell->manip->lefttmp);
  dup2(shell->manip->lefttmpfd, 0);
  close(shell->manip->lefttmpfd);
  shell->left = false;
  shell->r_d = false;
}
