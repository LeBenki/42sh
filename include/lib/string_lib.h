/*
** string_lib.h for string_lib in /home/Neferett/LIB
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Thu Jan 26 15:15:59 2017 Bonaldi Jordan
** Last update	Sun Apr 09 23:18:25 2017 Jordan Bonaldi
*/

#ifndef	H_STRING
# define H_STRING

typedef enum		_bool
{
  false = 0,
  true = 1
}			boolean;

typedef struct		s_string t_string;

struct			s_string
{
  char			first;
  char			end;
  char			*str;
  int			size;
  int			(*length)(t_string *);
  void			(*print)(t_string *, char *);
  void			(*capitalize)(t_string *);
  void			(*cut)(t_string *, int);
  int			(*toInt_base)(t_string *, char *);
  int			(*toInt)(t_string *);
  void			(*toString)(t_string *, int);
  void			(*reset)(t_string *);
  void			(*rev)(t_string *);
  void			(*cat)(t_string *, char *);
  boolean      		(*equals)(t_string *, char *);
  boolean      		(*equalsn)(t_string *, char *, int);
  boolean      		(*equalsIgnoreCase)(t_string *, char *);
  boolean      		(*equalsIgnoreCasen)(t_string *, char *, int);
  char			*(*recreate)(t_string *, char *);
  boolean      		(*alpha)(t_string *);
  boolean      		(*lower)(t_string *);
  boolean      		(*num)(t_string *);
  boolean      		(*printable)(t_string *);
  boolean      		(*upper)(t_string *);
  int      		(*contains)(t_string *, char);
  int					(*placeof)(t_string *, char);
  char      		**(*towordtab)(t_string *, char);
};

int					placeof(t_string *, char);
t_string		*init_string(char *);
int			get_length(t_string *);
void			string_print(t_string *, char *);
void			s_capitalizing(t_string *);
boolean			s_islower(t_string *);
boolean			s_isupper(t_string *);
boolean			s_isalpha(t_string *);
boolean			s_isprint(t_string *);
boolean			s_isnum(t_string *);
int			s_toint(t_string *);
int			s_tointbase(t_string *, char *);
void			s_tostring(t_string *, int);
int			s_contains(t_string *, char);
void			s_cat(t_string *, char *);
void			s_rev(t_string *);
void			s_cut(t_string *, int);
void			s_reset(t_string *);
boolean			s_equals(t_string *, char *);
boolean			s_equalsn(t_string *, char *, int);
boolean			s_equalsig(t_string *, char *);
boolean			s_equalsign(t_string *, char *, int);
char			*s_recreate(t_string *, char *);
char			**s_tab(t_string *, char);

#endif
