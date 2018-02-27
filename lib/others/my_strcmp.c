/*
** my_strcmp.c for my_strcmp in /home/Neferett/CPool_Day06
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Mon Oct 10 10:25:18 2016 Bonaldi Jordan
** Last update Tue May  2 20:01:25 2017 Sacha PERIN
*/
int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i += 1;
  return (s1[i] - s2[i]);
}
