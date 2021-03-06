# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 17:16:39 by pstengl           #+#    #+#              #
#    Updated: 2022/04/02 15:16:44 by pstengl          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output Name:
NAME:=			libgnl
# Can be 'library' or 'executable'
TYPE:=			library

# Folders:
BINARIES:=		./binaries
BUILD:=			./build
INCLUDE:=		./include
SOURCE:=		./source
LIBRARIES:=		./libraries
TESTS:=			./tests

# Other Variables:
COMPILER:=		gcc
COMPFLAGS:=		-Wall -Werror -Wextra
STDLIBS:=
NONSTDLIBS:=
NORMFLAGS:=

# Source Files:
SRCFILES:=\
		get_next_line.c\
		get_next_line_utils.c\

# ------------------------------------------
# Do not change anything beyond this point!
# ------------------------------------------

# Process Variables
CC:=		$(COMPILER)
CFLAGS:=\
		$(COMPFLAGS)\
		$(addprefix -I ,$(INCLUDE))\
		$(addprefix -I $(LIBRARIES)/,$(NONSTDLIBS))\
		$(addprefix -I $(LIBRARIES)/,$(addsuffix /include,$(NONSTDLIBS)))
LDFLAGS:=\
		$(addprefix -L $(LIBRARIES)/,$(NONSTDLIBS))\
		$(addprefix -L $(LIBRARIES)/,$(addsuffix /binaries,$(NONSTDLIBS)))
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
		$(MAKE) -j $(nprocs) -C $(LIBRARIES)/$$lib;\
	done
	mkdir -p $(BINARIES)
ifeq ($(TYPE),library)
	@echo "Creating a Library"
	$(AR) $(ARFLAGS) $(BINARIES)/$(NAME) $(OBJS)
else
	@echo "Compiling an executable"
	$(CC) $(CFLAGS) $(OBJS) -o $(BINARIES)/$(NAME) $(LDFLAGS) $(LDLIBS)
endif

# Clean up Objects
clean:
	@for lib in $(NONSTDLIBS); do \
		$(MAKE) -C $(LIBRARIES)/$$lib clean;\
	done
	$(RM) -r $(BUILD)

# Clean up Executables and static libraries
fclean: clean
	@for lib in $(NONSTDLIBS); do \
		$(MAKE) -C $(LIBRARIES)/$$lib fclean;\
	done
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
test: norm all
ifeq ($(wildcard $(TESTS)/test.sh),)
	$(error "Test Script test.sh not found in $(TESTS)")
endif
	@./tests/test.sh --no-memcheck

memtest: norm all
ifeq ($(wildcard $(TESTS)/test.sh),)
	$(error "Test Script test.sh not found in $(TESTS)")
endif
	@./tests/test.sh
