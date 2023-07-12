# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 14:27:11 by dpentlan          #+#    #+#              #
#    Updated: 2023/07/12 14:50:33 by dpentlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
RED='\033[0;31m'
GREEN='\033[0;32m'
NOCOLOR='\033[0m'

# ***** Sources *****

SRCS = philo.c \
	time_utils.c \
	arg_parse.c \
	int_utils.c \
	debug_funcs.c \

SRCS_DIR = srcs/

# ***** Includes *****

INCS = philo.h

INCS_DIR = includes/

# ***** Objects *****

OBJS = $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS))

OBJS_DIR = objs/

# ***** Compile and Archiver *****

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

PTHREAD = -lpthread

# ***** Build *****

all: $(NAME)

$(NAME): $(OBJS)
	@echo -e -n ${GREEN}
	@printf "===== MAKING PHILO =====\n"
	@echo -e -n ${NOCOLOR}
	@$(CC) $(CFLAGS) $(PTHREAD) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) -c $(CFLAGS) $(PTHREAD) -I$(INCS_DIR) $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f gdb.txt

re: fclean all
