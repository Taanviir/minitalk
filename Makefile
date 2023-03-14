# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanas <tanas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 21:53:47 by tanas             #+#    #+#              #
#    Updated: 2023/03/14 18:56:37 by tanas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FLAGS = -Wall -Wextra -Werror -g3
LIBFT = libft/libft.a

OBJS_DIR = objects

SERVER = server
SERVER_SRC = server.c
SERVER_OBJ = $(OBJS_DIR)/$(SERVER_SRC:.c=.o)

CLIENT = client
CLIENT_SRC = client.c
CLIENT_OBJ = $(OBJS_DIR)/$(CLIENT_SRC:.c=.o)

# colours
GREEN 			= "\033[1;32m"
RED 			= "\033[1;3;31m"
BLUE 			= "\033[3;34m"
YELLOW 			= "\033[0;33m"
COLOUR_RESET 	= "\033[0m"

all : $(LIBFT) $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJ)
	@echo $(YELLOW)"Creating Server"$(COLOUR_RESET)
	@cc $(C_FLAGS) $(SERVER_OBJ) $(LIBFT) -o $@
	@echo $(GREEN)"Server is ready. ✅\n"$(COLOUR_RESET)

$(CLIENT) : $(CLIENT_OBJ)
	@echo $(YELLOW)"Creating Client"$(COLOUR_RESET)
	@cc $(C_FLAGS) $(CLIENT_OBJ) $(LIBFT) -o $@
	@echo $(GREEN)"Client is ready. ✅\n"$(COLOUR_RESET)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@cc $(C_FLAGS) -c $< -o $@

$(LIBFT) :
	@echo $(YELLOW)"Creating $(LIBFT)"$(COLOUR_RESET)
	@make -sC libft
	@echo $(GREEN)"\nLibft is ready. ✅\n"$(COLOUR_RESET)

clean :
	@make clean -sC libft
	@rm -rf $(OBJS_DIR)
	@echo $(RED)"\nRemoving object directory and files."$(COLOUR_RESET)

fclean : clean
	@make fclean -sC libft
	@rm -rf $(SERVER) $(CLIENT)
	@echo $(RED)"Removing executable files.\n"$(COLOUR_RESET)

re : fclean all

.PHONY : all clean fclean re
