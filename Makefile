##
## Makefile for Makefile in /home/Neferett/Makefile
##
## Made by Bonaldi Jordan
## Login   <Neferett@epitech.net>
##
## Started on  Fri Oct 14 12:57:09 2016 Bonaldi Jordan
## Last update Sun May 21 03:15:58 2017 Sacha PERIN
##

SRC	=	main.c				\
		handlers/searching_handlers.c	\
		handlers/key_handler.c		\
		handlers/builtin/env_command.c	\
		handlers/builtin/set_command.c	\
		handlers/builtin/repeat_command.c	\
		handlers/builtin/unset_command.c\
		handlers/builtin/for-each_command.c \
		handlers/builtin/for-each_command_sheitan.c\
		handlers/builtin/cd_command.c	\
		handlers/builtin/source_command.c	\
		handlers/builtin/if_command.c	\
		handlers/builtin/if_command_sup.c	\
		handlers/builtin/if_command_sheitan.c \
		handlers/builtin/echo_command.c\
		handlers/builtin/where_command.c\
		handlers/builtin/alias_command.c\
		handlers/builtin/exit_command.c	\
		handlers/builtin/which_command.c	\
		handlers/builtin/set_var_command.c	\
		handlers/good_execution.c\
		handlers/command_handler.c\
		handlers/prompt_handler.c\
		handlers/manipulation/magic.c\
		handlers/manipulation/right_manipulation.c\
		handlers/manipulation/left_manipulation.c\
		handlers/manipulation/pipe_manipulation.c\
		handlers/manipulation/handler_manip.c\
		utils/utils_manipulations.c\
		utils/inhibitor_utils.c\
		utils/utils_env.c		\
		utils/utils_free.c		\
		utils/utils_parser.c\
		utils/utils_list.c\
		utils/utils_permission.c	\
		utils/utils_globbing.c		\
		utils/utils_builtin.c		\
		utils/utils_prompt.c		\
		utils/utils_arr_prompt.c	\
		utils/utils_str_prompt.c	\
		utils/utils_sig.c		\
		utils/utils_alias.c		\
		utils/utils_replace.c\
		utils/utils_set.c\
		utils/utils_if.c\
		utils/utils.c \
		scripting/scripting.c \
		scripting/init_script.c \
		scripting/exec_script.c \
		scripting/file.c \
		scripting/util.c \
		scripting/condition_handler.c \
		scripting/arg_handler.c

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

CC	=	gcc

LIB	=	lib/others/my_strlen.c			\
		lib/others/my_strupcase.c		\
		lib/others/my_swap.c			\
		lib/others/my_str_islower.c		\
		lib/others/my_str_isupper.c		\
		lib/others/my_str_isalpha.c		\
		lib/others/my_str_isprintable.c		\
		lib/others/my_str_isnum.c		\
		lib/others/my_getnbr.c			\
		lib/others/my_getnbr_base.c		\
		lib/others/my_strdup.c			\
		lib/others/my_itoa.c			\
		lib/others/my_strlowcase.c		\
		lib/others/nb_of.c			\
		lib/others/my_strcmp.c			\
		lib/others/my_strncmp.c			\
		lib/others/my_strcat.c			\
		lib/others/my_strcpy.c			\
		lib/others/my_strncat.c			\
		lib/others/my_strncpy.c			\
		lib/others/my_revstr.c			\
		lib/others/my_epur_str.c		\
		lib/others/get_next_line.c		\
		lib/others/get_next_line2.c		\
		lib/others/tab_len.c\
		lib/others/my_str_to_wordtab.c		\
                lib/others/my_putnbru_base.c            \
                lib/others/my_putnbruh_base.c           \
                lib/others/my_putnbrul_base.c           \
                lib/others/my_putu_nbr.c                \
                lib/others/my_putul_nbr.c               \
                lib/others/my_putuh_nbr.c               \
                lib/others/my_putl_nbr.c                \
                lib/others/my_puth_nbr.c                \
                lib/others/specific_print.c		\
		lib/others/mil_convert.c	        \
		lib/others/mil_convertu.c		\
                lib/others/msl.c                        \
		lib/others/my_tabcat.c			\
                lib/others/my_advanced_sort_wordtab.c   \
                lib/others/my_capitalize.c              \
                lib/others/my_fact_rec.c                \
                lib/others/my_find_prime_sup.c          \
                lib/others/my_isneg.c                   \
                lib/others/my_is_prime.c                \
                lib/others/my_power_rec.c               \
                lib/others/my_putnbr_base.c             \
                lib/others/my_put_nbr.c                 \
                lib/others/my_putstr.c			\
                lib/others/my_show_wordtab.c            \
                lib/others/my_sort_int_tab.c            \
                lib/others/my_sort_wordtab.c            \
                lib/others/my_square_root.c             \
		lib/printf/my_printf.c			\
		lib/printf/methods/chars_methods.c	\
		lib/printf/methods/int_methods.c	\
		lib/printf/methods/methods.c		\
		lib/printf/methods/others.c		\
		lib/printf/utils/utils.c		\
		lib/printf/utils/utils_checker.c	\
		lib/printf/utils/utils_methods.c	\
		lib/printf/utils/params.c		\
		lib/printf/utils/init.c			\
		lib/printf/utils/utils_setter.c		\
		lib/string_lib/init_string.c		\
		lib/string_lib/methods/length.c		\
		lib/string_lib/methods/print.c		\
		lib/string_lib/methods/capitalize.c	\
		lib/string_lib/methods/num.c		\
		lib/string_lib/methods/cat_and_cut.c	\
		lib/string_lib/methods/recreate.c	\
		lib/string_lib/methods/equals.c		\


OBJSLIB =       $(LIB:.c=.o)

CFLAGS  += -Wextra -Wall -Werror

CFLAGS  += -ansi -pedantic

CFLAGS  += -Iinclude/lib/ -Iinclude/

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJSLIB) $(OBJ)
	ar rc lib/libmy.a $(OBJSLIB)
	$(CC) $(OBJ) -o $(NAME) -Llib/ -lmy -lncurses

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJSLIB)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur

.PHONY: all clean fclean re
