# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avieira <avieira@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 18:20:01 by avieira           #+#    #+#              #
#    Updated: 2021/10/26 03:40:22 by avieira          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = clang
CFLAGS = -Wall -Wextra -Werror -pthread

RM = rm -rf

SRCS = sources/main.c \
		sources/ft_atoi.c \
		sources/create_dinner.c \
		sources/dinner.c \
		sources/time.c \
		sources/display.c \
		sources/philos.c \
		sources/set_get_philo_info.c

OBJ = $(SRCS:%.c=%.o)

IFLAGS = ./includes/
SRCS_DIR = ./sources/

START_STYLE = \033[1;32m
END_STYLE = \033[0m

all : $(NAME)

%.o: %.c
	@($(CC) $(CFLAGS) -c -I$(IFLAGS) $< -o $(<:.c=.o))

philo: $(OBJ)
	@(printf "$(START_STYLE)Compiling...\n$(END_STYLE)")
	@($(CC) -o $(NAME) -I$(IFLAGS) $^ $(CFLAGS))
	@(printf "$(START_STYLE)Done.\n$(END_STYLE)")

clean:
	@(printf "$(START_STYLE)Cleaning...\n$(END_STYLE)")
	@($(RM) $(SRCS_DIR)/*.o)
	@($(RM) $(SRCS_DIR)/*/*.o)
	@($(RM) $(SRCS_DIR)/*/*/*.o)
	@(printf "$(START_STYLE)Done.\n$(END_STYLE)")

fclean: clean
	@(printf "$(START_STYLE)Fcleaning...\n$(END_STYLE)")
	@($(RM) $(NAME))
	@(printf "$(START_STYLE)Done.\n$(END_STYLE)")

re: fclean all

.PHONY: all clean fclean re
