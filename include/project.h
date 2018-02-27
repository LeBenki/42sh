/*
** project.h for project_header in /home/Neferett/bin/IMPORT/include
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 21 01:13:04 2016 Bonaldi Jordan
** Last update	Sat Apr 22 23:29:31 2017 Jordan Bonaldi
*/

#ifndef H_CHECK
# define H_CHECK

# define _DEFAULT_SOURCE
# define _GNU_SOURCE

# include <errno.h>
# include <termios.h>
# include <string.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <dirent.h>
# include <glob.h>
# include "lib.h"
# include "ncurse_import.h"

# define TMP_FILE	".mysh"

typedef struct		s_tab
{
  char			*arr;
  boolean		in;
  char			ini;
  char			*str;
  int			i;
  int			j;
}			t_tab;

typedef struct		s_read
{
  char			**hist;
  char			*str;
  int			error;
  int			i;
  int			h;
  int			hst;
  char			*buff;
  char			*save;
}			t_read;

typedef struct 		iteration_s
{
  int			it_id;
  char			*name;
}			it_t;

typedef struct		s_pos_dir
{
  char			*before;
  char			*after;
}			t_pos_dir;

typedef struct		s_list_cmd
{
  pid_t			pid;
  int			delay;
  char			**cmd;
  boolean		succes;
  struct s_list_cmd	*n;
  struct s_list_cmd	*p;
}			t_list_cmd;

typedef struct		s_list
{
  char			*data;
  struct s_list		*n;
  struct s_list		*p;
}			t_list;

typedef struct		s_set
{
  t_string		*var;
  t_string		*data;
  struct s_set		*n;
  struct s_set		*p;
}			t_set;

typedef struct s_shell t_shell;

typedef struct		s_builtin
{
  char			*cmd;
  void			(*builtin)(t_shell *);
}			t_builtin;

typedef struct		s_manip
{
  int			righttmp;
  int			righttmpfd;
  int			lefttmp;
  int			lefttmpfd;
}			t_manip;

typedef struct 		s_alias
{
  t_string		*cmd;
  t_string		*alias;
  struct s_alias	*n;
  struct s_alias	*p;
}			t_alias;

struct			s_shell
{
  int			ret;
  int			done;
  t_string		**string;
  t_manip		*manip;
  boolean		r_d;
  boolean 		pipe;
  boolean		left;
  boolean 		right;
  boolean		first;
  boolean		and_s;
  boolean		idif;
  t_alias		*alias;
  char			**tenv;
  t_list		*lenv;
  t_set			*set;
  char			**cmd;
  char			**path;
  t_list_cmd		*tmp;
  t_list_cmd		*list;
  t_builtin		*builtin;
  t_read		*read;
};

typedef struct		s_script
{
  char			**argv;
  int			argc;
  char			**var;
  char			**arr;
}			t_script;

typedef struct		s_pipe
{
  int                   p[2];
  pid_t                 pid;
  int                   fd;
  int                   a;
  char                  *buff;
  char                  *buff2;
  boolean               sucess;
}			t_pipe;

t_string		*replace_that_str(char *, char *, char *);
t_string		**start_nd_right(t_shell *, t_string **);
t_string		**start_d_right(t_shell *, t_string **);
t_string		**start_nd_left(t_shell *, t_string **);
t_string		**start_d_left(t_shell *, t_string **);
t_string		**handle_manip(t_shell *, t_string *, char *, t_string **);
t_shell			*init_shell(char **);
t_alias			*init_alias();
t_string		*alias_exists(char *, t_alias *);
t_string		*set_exists(char *, t_set *);
t_string		*search_in_command_line(t_string *, t_shell *);
t_string		**stw_string(t_string *, t_shell *, char *);
t_builtin		*init_builtin(int);
t_list			*env_to_list(char **);
t_list			*init_list();
t_set			*init_list_set();
char			good_char(t_string *, t_shell *);
char			*get_folder_content(char *, char *);
char			*str_cat(char *, char *);
char			*delchar_atpos(char *, int);
char    		*insert_str(char *, char *, int);
char			*get_env(char *, t_list *);
char			*get_input(t_shell *);
char			*set_value(char *, char *);
char			*my_epur_all_str(char *);
char			**add_str(char ** , char *, int);
char			**get_paths(t_shell *);
char			**cpy_tab(char **);
char			**realloc_tab(char **);
char			**read_file(char *);
char			**set_variable(char **, char *, char *);
boolean			in_if(t_string *, char);
boolean			is_shebang(char *);
boolean			good_execution(t_shell *, t_string *);
boolean			is_in_list(t_shell *);
boolean			is_valid(t_string *);
boolean			is_ok(t_string *, char);
boolean			shell_up(t_shell *, t_string *);
boolean			exec_pipe(t_string **, t_shell *);
boolean			look_at_line(t_string *);
boolean			builtin_repeat(t_shell *, t_string *);
boolean			get_permission(char *);
int			ctrld_handler(t_shell *);
int			handle_events(t_shell *);
int			tab_handler(t_shell *);
int			arr_len(char **);
int			str_len(char *);
int			prompt(t_shell *);
int			my_strccmp(char *, char *, char);
int			scripting(t_shell *);
int			my_tablen(char **);
int			exec_script(t_script *, t_shell *);
int			st_len(t_string **);
int			get_read(t_shell *);
int			tab_loop(t_shell *, char **, int *, int *);
int			check_equal(char *);
int			test_if_foreach(char *);
int			if_for_handle(t_shell *, t_string **, int);
void			end_handle_manip(t_shell *, t_string *, char);
void			end_d_left(t_shell *);
void			end_nd_left(t_shell *);
void			end_d_right(t_shell *);
void			end_nd_right(t_shell *);
void			free_tab(t_shell *);
void			search_command(t_shell *);
void			add_cmd(t_shell *, char **, pid_t);
void			add_alias(t_string *, t_string *, t_alias *);
void			replace_that(char *, char *, t_shell *);
void			builtin_cd(t_shell *);
void			builtin_set(t_shell *);
void			builtin_unset(t_shell *);
void			builtin_env(t_shell *);
void			builtin_exit(t_shell *);
void			builtin_alias(t_shell *);
void			builtin_which(t_shell *);
void			builtin_where(t_shell *);
void			builtin_source(t_shell *);
void			builtin_echo(t_shell *);
void			builtin_set_var(t_shell *);
void			builtin_foreach(t_shell *);
void    		signal_handling(int);
void			init_sig(t_shell *);
void			show_env(t_list *);
void			add_env(char *, t_list *);
void			add_end_env(char *, t_list *);
void			my_rm_list(t_list **, void *, int (*)(), int (*)());
void			segfault(t_shell *);
void			signal_handling(int);
void			add_set(t_string *, t_string *, t_set *);
void			is_globbing(t_shell *);
void			arg_handler(char **, char **);
void			builtin_if(t_shell *);
void			my_freetab(char **);
void			my_rm_alias(t_alias **, void *, int (*)(), int (*)());
void			my_rm_set(t_set **, void *, int (*)(), int (*)());
void			builtin_if_sheitan(t_shell *, char **);
void			stock_response(t_shell *, t_string *);
void			get_response(t_shell *, int);
void			*xmalloc(int);

#endif
