/*
** msl.c for 42sh in /home/benki/Epitech/PSU_2016_42sh/lib/others
** 
** Made by Lucas Benkemoun
** Login   <lucas.benkemoun@epitech.eu>
** 
** Started on  Mon May 15 17:34:01 2017 Lucas Benkemoun
** Last update Mon May 15 17:34:02 2017 Lucas Benkemoun
*/

short int     msl(short int nb)
{
  short int   i;

  i = 0;
  if (nb < 0 && (nb *= -1) && i++) {}
  while (nb > 9)
    if ((nb /= 10) && ++i) {}
  return (++i);
}

long int     mll(long int nb)
{
  long int   i;

  i = 0;
  if (nb < 0 && (nb *= -1) && i++) {}
  while (nb > 9)
    if ((nb /= 10) && ++i) {}
  return (++i);
}
