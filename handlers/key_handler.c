/*
** key_handler.c for PSU_2016_tetris
**
** Made by	Jordan Bonaldi
** Login	Neferett@epitech.net
**
** Started on	Wed Mar 08 13:43:41 2017 Jordan Bonaldi
** Last update	Tue Mar 14 16:13:42 2017 Jordan Bonaldi
*/

# include "project.h"

int				get_key(char *s)
{
  if (!s || !*s)
    return (0);
  return (!my_strcmp(tigetstr("kcub1"), s) ? -1 :
	  !my_strcmp(tigetstr("kcuf1"), s) ? -2 :
	  !my_strcmp(tigetstr("kbs"), s) ? -3 :
	  !my_strcmp(tigetstr("khome"), s) ? -4 :
	  !my_strcmp(tigetstr("kend"), s) ? -5 :
	  !my_strcmp(tigetstr("kcuu1"), s) ? -6 :
	  !my_strcmp(tigetstr("kcud1"), s) ? -7 : 0);
}

int				is_invalid_char(char s, int pos)
{
  return (tigetstr("kcub1")[pos] == s ||
	  tigetstr("kcuf1")[pos] == s);
}

void			key_pad(boolean mode, boolean time)
{
  static struct termios old;
  static struct termios new;

  if
    (!mode)
    {
      ioctl(0, TCGETS, &old);
      ioctl(0, TCGETS, &new);
      new.c_lflag &= ~ECHO;
      new.c_lflag &= ~ICANON;
      if (time)
        {
          new.c_cc[VMIN] = 0;
          new.c_cc[VTIME] = 1;
        }
      ioctl(0, TCSETS, &new);
    }
  else
    ioctl(0, TCSETS, &old);
}

int			get_read(t_shell *sh)
{
  int	i;
  int	state;
  char	c;
  char *s;

  1 ? state = 0, i = -1: 0;
  key_pad(0, true);
  if (!(s = malloc(100)))
    exit(84);
  *s = 0;
  while (!(c = 0))
    {
      state = read(0, &c, 1);
      i++;
      if (!c)
	break;
      s = my_strcatc(s, c);
      if (get_key(s) || !is_invalid_char(c, i))
        break;
    }
  s = my_strcatc(s, 0);
  key_pad(1, true);
  sh->read->error = get_key(s);
  (!get_key(s) && state) ? (sh->read->str = s) : (sh->read->str = NULL);
  return (1);
}
