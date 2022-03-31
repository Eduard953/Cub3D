# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 17:16:39 by pstengl           #+#    #+#              #
#    Updated: 2022/03/31 09:59:16 by pstengl          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable Name:
NAME:=			Cub3D

# Folders:
BINARIES:=		./binaries
BUILD:=			./build
INCLUDE:=		./include
SOURCE:=		./source
LIBRARIES:=		./libraries

# Other Variables:
COMPILER:=		gcc
COMPFLAGS:=		-Wall -Werror -Wextra
STDLIBS:=		m
NONSTDLIBS:=

# Source Files:
SRCFILES:=\
	point.c

# ------------------------------------------
# Do not change anything beyond this point!
# ------------------------------------------

# Process Variables
CC:=		$(COMPILER)
CFLAGS:=	$(COMPFLAGS) -I $(INCLUDE) -I $(addprefix $(LIBRARIES)/,$(NONSTDLIBS))
LDFLAGS:=	$(foreach lib,$(NONSTDLIBS),-L$(LIBRARIES)/$(lib))
LDLIBS:=\
		$(foreach lib,$(NONSTDLIBS),-l$(subst lib,,$(lib)))\
		$(foreach lib,$(STDLIBS),-l$(lib))
SRCS:=		$(addprefix $(SOURCE)/,$(SRCFILES))
OBJS:=		$(SRCS:$(SOURCE)/%.c=$(BUILD)/%.o)

.PHONY: $(BINARIES)/$(NAME) $(NAME) all clean fclean re bonus norm

# Catch Rules
all: $(BINARIES)/$(NAME)
$(NAME): $(BINARIES)/$(NAME)

# Compile .c files to .o Files
$(OBJS): $(BUILD)%.o : $(SOURCE)%.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

# Main Build Rule
$(BINARIES)/$(NAME): $(OBJS)
	@for lib in $(NONSTDLIBS);\
		do $(MAKE) -j $(nprocs) -C $(LIBRARIES)/$$lib all;\
	done
	mkdir -p $(BINARIES)
	$(CC) $(CFLAGS) $(OBJS) -o $(BINARIES)/$(NAME) $(LDFLAGS) $(LDLIBS)

# Clean up Objects
clean:
	@for lib in $(NONSTDLIBS);\
		do $(MAKE) -C $(LIBRARIES)/$$lib clean;\
	done
	$(RM) -r $(BUILD)

# Clean up Executables and static libraries
fclean: clean
	@for lib in $(NONSTDLIBS);\
		do $(MAKE) -C $(LIBRARIES)/$$lib fclean;\
	done
	$(RM) -r $(BINARIES)

# Clean the re-compile
re: fclean all

# Rule for the Bonus
bonus:
	@echo "No Bonus!"

# Check the Norm
norm:
	norminette .
