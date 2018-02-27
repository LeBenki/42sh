/*
** my_str_isalpha.c for my_str_isalpha in /home/Neferett/CPool_Day06
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Oct 10 11:28:39 2016 Bonaldi Jordan
** Last update Wed Dec 21 11:32:04 2016 Bonaldi Jordan
*/

int	my_str_isalpha(char *str)
{
  while (*str)
    {
      if (*str >= 'a' && *str <= 'z')
	return (1);
      str++;
    }
  return (0);
}
