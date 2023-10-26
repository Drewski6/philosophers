# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/05 10:49:04 by dpentlan          #+#    #+#              #
#    Updated: 2023/10/26 13:03:25 by dpentlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc

SRC 			=	parsing/arg_parse.c \
					parsing/ft_utils.c \
					main_thread/monitor.c \
					main_thread/philo.c \
					main_thread/init_threads.c \
					main_thread/destroy_threads.c \
					main_thread/time_utils.c \
					philos/philo_actions.c \
					philos/philo_eating.c \
					philos/philo_print.c \

NAME			=	philo

OBJ_FOLDER		=	objs/

CFLAGS			=	-Wall -Wextra -Werror -g # -fsanitize=thread

SRC_FOLDER		=	srcs/

HEADERS_FOLDER	=	includes/\

DEPENDS		:=	$(patsubst %.c,$(OBJ_FOLDER)%.d,$(SRC))
OBJS		:=	$(patsubst %.c,$(OBJ_FOLDER)%.o,$(SRC))
COMMANDS	:=	$(patsubst %.c,$(OBJ_FOLDER)%.cc,$(SRC))

all: $(NAME) compile_commands.json

-include $(DEPENDS)

%.a:
	make -C $(@D)

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

COMP_COMMAND = $(CC) -c $(CFLAGS) $(addprefix -I,$(HEADERS_FOLDER)) -MMD -MP $< -o $@
CONCAT = awk 'FNR==1 && NR!=1 {print ","}{print}'

$(OBJ_FOLDER)%.o $(OBJ_FOLDER)%.cc: $(SRC_FOLDER)%.c
	$(COMP_COMMAND)
	@printf '{\n\t"directory" : "$(shell pwd)",\n\t"command" : "$(COMP_COMMAND)",\n\t"file" : "$<"\n}' > $(OBJ_FOLDER)$*.cc

compile_commands.json : $(COMMANDS) Makefile
	@echo "Making compile_commands.json"
	@echo "[" > compile_commands.json
	$(CONCAT) $(COMMANDS) >> compile_commands.json
	@echo "]" >> compile_commands.json

clean:
	rm -f $(OBJS) $(DEPENDS) $(COMMANDS)

fclean: clean
	rm -f $(NAME) compile_commands.json

re: fclean all

.PHONY: all clean fclean re bonus
.SUFFIXES:
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules
