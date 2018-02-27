/*
** my_show_wordtab.c for my_showwordtab.c in /home/Neferett/CPool_Day08
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Wed Oct 12 10:23:49 2016 Bonaldi Jordan
** Last update	Sat Apr 22 23:53:47 2017 Jordan Bonaldi
*/

#include "lib.h"

int	my_show_wordtab(char **tab, char c)
{
  int	i;
  int	j;

  i = -1;
  while (tab[++i] && (j = -1) && (i > 0 ? !my_putchar(c) : 1))
    while (tab[i][++j])
      if (tab[i][j] == 92 && tab[i][j + 1] == 92 && ++j && !my_printf("\\"))
	continue;
      else if (tab[i][j] == 92 && tab[i][j + 1] == 99)
	return (1);
      else
	tab[i][j] == 92 && tab[i][j + 1] == 110 && ++j ? !my_printf("\n") :
	  tab[i][j] == 92 && tab[i][j + 1] == 97 && ++j ? !my_printf("\a") :
	  tab[i][j] == 92 && tab[i][j + 1] == 98 && ++j ? !my_printf("\b") :
	  tab[i][j] == 92 && tab[i][j + 1] == 101 && ++j ? !my_printf("%c", 27) :
	  tab[i][j] == 92 && tab[i][j + 1] == 101 && ++j ? !my_printf("%c", 27) :
	  tab[i][j] == 92 && tab[i][j + 1] == 102 && ++j ? !my_printf("\f") :
	  tab[i][j] == 92 && tab[i][j + 1] == 114 && ++j ? !my_printf("\r") :
	  tab[i][j] == 92 && tab[i][j + 1] == 118 && ++j ? !my_printf("\v") :
	  tab[i][j] == 92 && tab[i][j + 1] == '0' && (j += my_strlen(tab[i])) ?
	  !my_printf("%c", my_getnbr_base(tab[i] + 2, "01234567")) :
	  my_printf("%c", tab[i][j]);
  return (0);
}
