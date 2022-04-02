# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 17:16:39 by pstengl           #+#    #+#              #
#    Updated: 2022/04/02 15:55:32 by pstengl          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output Name:
NAME:=			libft
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
COMPFLAGS:=		-Wall -Werror -Wextra -g
STDLIBS:=
NONSTDLIBS:=
NORMFLAGS:=

# Source Files:
SRCFILES:=\
	lst/ft_lstadd_back.c\
	lst/ft_lstadd.c\
	lst/ft_lstadd_front.c\
	lst/ft_lstat.c\
	lst/ft_lstclear.c\
	lst/ft_lstdelat.c\
	lst/ft_lstdelone.c\
	lst/ft_lstiter.c\
	lst/ft_lstlast.c\
	lst/ft_lstmap.c\
	lst/ft_lstnew.c\
	lst/ft_lstsize.c\
	lst/ft_lsttoarr.c\
	math/ft_abs.c\
	math/ft_atoi.c\
	math/ft_basetoi.c\
	math/ft_bintoi.c\
	math/ft_hextoi.c\
	math/ft_itoa.c\
	math/ft_itobase.c\
	math/ft_itobin.c\
	math/ft_itohex.c\
	math/ft_itooct.c\
	math/ft_max.c\
	math/ft_min.c\
	math/ft_octtoi.c\
	math/ft_pow.c\
	math/ft_sqrt.c\
	math/ft_uitobase.c\
	mem/ft_bzero.c\
	mem/ft_calloc.c\
	mem/ft_memccpy.c\
	mem/ft_memchr.c\
	mem/ft_memcmp.c\
	mem/ft_memcpy.c\
	mem/ft_memmove.c\
	mem/ft_memset.c\
	print/ft_print.c\
	print/ft_printarr.c\
	print/ft_printc.c\
	print/ft_printint.c\
	print/ft_printintarr.c\
	print/ft_printintbase.c\
	print/ft_printintbin.c\
	print/ft_printinthex.c\
	print/ft_printintoct.c\
	print/ft_println.c\
	print/ft_printlst.c\
	print/ft_printuint.c\
	print/ft_putchar_fd.c\
	print/ft_putendl_fd.c\
	print/ft_putnbr_fd.c\
	print/ft_putstr_fd.c\
	str/ft_isalnum.c\
	str/ft_isalpha.c\
	str/ft_isascii.c\
	str/ft_isdigit.c\
	str/ft_isoneof.c\
	str/ft_isprint.c\
	str/ft_isspace.c\
	str/ft_split.c\
	str/ft_strchr.c\
	str/ft_strcmp.c\
	str/ft_strdup.c\
	str/ft_strext.c\
	str/ft_strjoin.c\
	str/ft_strlcat.c\
	str/ft_strlcpy.c\
	str/ft_strlen.c\
	str/ft_strmapi.c\
	str/ft_strncmp.c\
	str/ft_strnstr.c\
	str/ft_strrchr.c\
	str/ft_strtrim.c\
	str/ft_substr.c\
	str/ft_tolower.c\
	str/ft_toupper.c\
	arr/ft_arrlen.c\
	arr/ft_arrdup.c\
	arr/ft_arrclear.c\
	arr/ft_arrext.c\


# ------------------------------------------
# Do not change anything beyond this point!
# ------------------------------------------

# Process Variables
CC:=		$(COMPILER)
CFLAGS:=\
			$(COMPFLAGS)\
			-I $(INCLUDE)\
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
ifeq ($(NORM),)
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
