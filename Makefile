# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 17:16:39 by pstengl           #+#    #+#              #
#    Updated: 2022/03/30 18:17:01 by pstengl          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable Name
NAME=		Cub3D

# Folders:
BINARIES=	./binaries/
BUILD=		./build/
INCLUDE=	./include/
SOURCE=		./source/
LIBRARIES=	./libraries/

# Other Variables:
COMPILER=	gcc
COMPFLAGS=	-Wall -Werror -Wextra
STDLIBS=	m
#NONSTDLIBS=	libft minilibx

# Source Files
SRCFILES=main.c

## Process Variables
CC=			$(COMPILER)
CFLAGS=		$(COMPFLAGS) -I $(INCLUDE)
LDFLAGS=	$(foreach lib,$(NONSTDLIBS),-L $(LIBRARIES)/$(lib))
LDLIBS=		$(foreach lib,$(join $(STDLIBS),$(NONSTDLIBS)),-l $(lib))
SRCS=		$(addprefix $(SOURCE),$(SRCFILES))
OBJS=		$(SRCS:$(SOURCE)/%.c=$(BUILD)/%.o)

.PHONY: $(BINARIES)/$(NAME) $(NAME) all clean fclean re bonus

# Catch Rules
$(BINARIES)/$(NAME): all
$(NAME): all

# Compile .c files to .o Files
$(OBJS): $(BUILD)/%.o : $(SOURCE)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Main Build Rule
all: $(OBJS)
	@echo "SRCS: $(SRCS) OBJS:$(OBJS)"
	mkdir -p $(BINARIES)
	$(CC) $(CFLAGS) $(BUILD)/$(OBJS) -o $(BINARIES)/$(NAME) $(LDFLAGS) $(LDLIBS)

# Clean up Objects
clean:
	$(RM) -r $(BUILD)

# Clean up Executables and static libraries
fclean: clean
	$(RM) -r $(BINARIES)

# Clean the re-compile
re: fclean all

# Rule for the Bonus
bonus:
	@echo "No Bonus!"

