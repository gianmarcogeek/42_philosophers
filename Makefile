# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpuscedd <gpuscedd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 20:18:01 by gpuscedd          #+#    #+#              #
#    Updated: 2025/10/01 01:16:57 by gpuscedd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ANSI colors
BOLD   = \e[1m
GREEN  = \e[92m
YELLOW = \e[93m
RESET  = \e[0m

NAME	= philo

SRCS	= src/main.c src/utils.c src/threads.c src/routine_actions.c src/init.c src/monitor.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -pthread

RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)$(BOLD)Philo table compiled.$(RESET)\n"

clean:
	@printf "$(YELLOW)Cleaning...$(RESET)\n"
	@$(RM) $(OBJS)

fclean: clean
	@printf "$(YELLOW)Removing executable...$(RESET)\n"
	@$(RM) $(NAME)

re: fclean all
	@printf "$(GREEN)$(BOLD)Rebuild complete.$(RESET)\n"

.PHONY: all clean fclean re
