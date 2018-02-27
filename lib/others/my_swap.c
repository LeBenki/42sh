/*
** my_swap.c for my_swap in /home/Neferett/CPool_Day04
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Thu Oct  6 08:59:02 2016 Bonaldi Jordan
** Last update Wed Feb  8 16:52:26 2017 Jordan Bonaldi
*/

int	my_swap(int *a, int *b)
{
  int	temp;

  if (*a > *b)
    {
      temp = *a;
      *a = *b;
      *b = temp;
    }
  return (0);
}

void	my_swap_char(char *a, char *b)
{
  char	temp;

  temp = *a;
  *a = *b;
  *b = temp;
}
