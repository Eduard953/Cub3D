# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 17:16:39 by pstengl           #+#    #+#              #
#    Updated: 2022/05/23 13:33:53 by pstengl          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output Name:
NAME:=			Cub3D
# Can be 'library' or 'executable'
TYPE:=			executable

# Folders:
BINARIES:=		./binaries
BUILD:=			./build
INCLUDE:=
SOURCE:=		./source
LIBRARIES:=		./libraries
TESTS:=			./tests

# Other Variables:
COMPILER:=		gcc
COMPFLAGS:=		-Wall -Werror -Wextra -g
LIBPATHS:=		/usr/X11
STDLIBS:=		m X11 Xext z
NONSTDLIBS:=	libft gnl mlx
NORMFLAGS:=

# Source Files:
SRCFILES:=\
	point/point.c\
	point/pointtocoord.c\
	ray/cast.c\
	texture.c\
	load_images.c\
	image_tools.c\
	free_data.c\
	draw_wall.c\
	minimap.c\
	angles.c\
	cast_all_rays.c\
	check_arguments.c\
	parse_helpers.c\
	parse_map.c\
	parsing.c\
	hook.c\
	doors.c\
	exit.c\
	rotate.c\
	movements.c\
	main.c\

# ------------------------------------------
# Do not change anything beyond this point!
# ------------------------------------------

# Process Variables
CC:=		$(COMPILER)
CFLAGS:=\
		$(COMPFLAGS)\
		$(addprefix -I ,$(INCLUDE))\
		$(addprefix -I $(LIBRARIES)/,$(NONSTDLIBS))\
		$(addprefix -I $(LIBRARIES)/,$(addsuffix /include,$(NONSTDLIBS)))\
		$(addprefix -I ,$(addsuffix /include,$(LIBPATHS)))
LDFLAGS:=\
		$(addprefix -L $(LIBRARIES)/,$(NONSTDLIBS))\
		$(addprefix -L $(LIBRARIES)/,$(addsuffix /binaries,$(NONSTDLIBS)))\
		$(addprefix -L ,$(addsuffix /lib,$(LIBPATHS)))
LDLIBS:=\
		$(addprefix -l,$(subst lib,,$(NONSTDLIBS)))\
		$(addprefix -l,$(STDLIBS))
ARFLAGS:=	rcs
SRCS:=		$(addprefix $(SOURCE)/,$(SRCFILES))
OBJS:=		$(SRCS:$(SOURCE)/%.c=$(BUILD)/%.o)
NORM:=		$(shell which norminette)

# If we are compiling a library, add .a to the name
ifeq ($(TYPE),library)
	NAME:= $(NAME).a
endif

.PHONY: all clean fclean re bonus norm test memtest

# Catch Rules
all: $(BINARIES)/$(NAME)
$(NAME): $(BINARIES)/$(NAME)

# Compile .c files to .o Files
$(OBJS): $(BUILD)%.o : $(SOURCE)%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

# Main Build Rule
$(BINARIES)/$(NAME): $(OBJS)
	@for lib in $(NONSTDLIBS); do\
		echo "Compiling $$lib";\
		if [ -f $(LIBRARIES)/$$lib/configure ]; then\
			cd $(LIBRARIES)/$$lib;\
			./configure;\
			cd ../../;\
		fi;\
		$(MAKE) -j $(nprocs) -C $(LIBRARIES)/$$lib;\
	done
	mkdir -p $(BINARIES)
ifeq ($(TYPE),library)
	@echo "Creating Library $(NAME)"
	$(AR) $(ARFLAGS) $(BINARIES)/$(NAME) $(OBJS)
else
	@echo "Compiling executable $(NAME)"
	$(CC) $(CFLAGS) $(OBJS) -o $(BINARIES)/$(NAME) $(LDFLAGS) $(LDLIBS)
endif

# Clean up Objects
clean:
	@for lib in $(NONSTDLIBS); do \
		echo "Cleaning $$lib";\
		$(MAKE) -C $(LIBRARIES)/$$lib clean;\
	done
	@echo "Cleaning $(NAME)"
	$(RM) -r $(BUILD)

# Clean up Executables and static libraries
fclean: clean
	@for lib in $(NONSTDLIBS); do \
		echo "Force Cleaning $$lib";\
		$(MAKE) -C $(LIBRARIES)/$$lib fclean || true;\
	done
	@echo "Force Cleaning $(NAME)"
	$(RM) -r $(BINARIES)

# Clean the re-compile
re: fclean all

# Rule for the Bonus
bonus:
	@echo "No Bonus!"
	@exit 1

# Check the Norm
norm:
ifeq ($(strip $(NORM)),)
	$(error "Norminette not installed")
endif
	@$(NORM) --version
	@$(NORM) $(NORMFLAGS) $(SOURCE) $(INCLUDE) | grep -v "OK!" || true
ifeq ($(strip $(shell $(NORM) $(NORMFLAGS) $(SOURCE) $(INCLUDE) | grep -v "OK!")),)
	@echo "No Norm Errors found. Everything OK!"
else
	@exit 1
endif

# Run the test script
test: norm re
ifeq ($(wildcard $(TESTS)/test.sh),)
	$(error "Test Script test.sh not found in $(TESTS)")
endif
	@./tests/test.sh
