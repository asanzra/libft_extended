# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 20:14:43 by asanz-ra          #+#    #+#              #
#    Updated: 2024/12/12 21:26:41 by asanz-ra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Bash colours
LIGHT_RED = \e[91m
LIGHT_GREEN = \e[92m
REMOVE_COLOUR = \e[0m

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra

# Archive (lib) creator
LIBA = ar rcs

# Source files
LIBFT_SRCSDIR = ./libft_srcs
LIBFT_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	   ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	   ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	   ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	   ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	   ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	   ft_lstmap.c ft_itoa_base.c ft_itoa_base_long.c ft_abs.c
SRCSDIR = ./src
SRCS = conversion_strings.c ft_printf.c utils_output.c \
		parser_letter_fields.c parser_number_fields.c conversion_numbers.c \
		utils_itoa_unsigned.c conversion_ptr.c \
		utils_output_field_width_bonus.c utils_output_precision_bonus.c \
		utils_output_precision_special_bonus.c ft_print_color.c

# Object files
LIBFT_OBJSDIR = ./libft/libft_objs
LIBFT_OBJS = $(LIBFT_SRCS:%.c=$(LIBFT_OBJSDIR)/%.o)
OBJSDIR = ./obj
OBJS = $(SRCS:%.c=$(OBJSDIR)/%.o)

# Executable name
LIBFT_LIB_DIR = ./libft/lib
LIBFT_LIB_NAME = $(LIBFT_LIB_DIR)/libft.a
NAME = lib_extended.a

# Header name
LIBFT_INCLUDE_DIR = ./libft
LIBFT_INCLUDE = $(LIBFT_INCLUDE_DIR)/libft.h
INCLUDE_DIR = ./printf_header
INCLUDE = $(INCLUDE_DIR)/ft_printf.h

# Default target. Generate the executable.
all: $(NAME)

#-------------------------------Make executables-------------------------------

# Link object files into the library.
# $@ means the target(NAME).
$(NAME): libft_bonus $(OBJS)
	@cp $(LIBFT_LIB_NAME) $(NAME)
	@$(LIBA) $@ $(OBJS)
	@echo "Library compiled $(LIGHT_GREEN)correctly$(REMOVE_COLOUR)"
	
libft_bonus: $(LIBFT_LIB_NAME)

$(LIBFT_LIB_NAME): $(LIBFT_OBJS) $(LIBFT_INCLUDE_DIR) | $(LIBFT_LIB_DIR)
	@$(LIBA) $@ $(LIBFT_OBJS)


#-------------------------------Make object files-------------------------------

# Compile a .c file into a needed .o object file.
# This is called when any .o file is needed. That is the meaning of %,
# which is called a wildcard, it could be anything, compiling %.c into %.o.
# $< means the first prerequisite (.../%.c)
$(OBJSDIR)/%.o: $(SRCSDIR)/%.c | $(OBJSDIR)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(LIBFT_OBJSDIR)/%.o: $(LIBFT_SRCSDIR)/%.c | $(LIBFT_OBJSDIR)
	@$(CC) $(CFLAGS) -I$(LIBFT_INCLUDE_DIR) -c $< -o $@



#---------------------------------Make folders---------------------------------
#Make folders to host files when needed
$(OBJSDIR) $(LIBFT_OBJSDIR) $(LIBFT_LIB_DIR):
	@mkdir -p $@



#-------------------------------------Utils-------------------------------------
# A function isn't run if a file with the name exists in the current directory.
# This is UNLESS we made changes to its prerequisites(recursively). I.e. if
# NAME exists, we NORMALLY don't recompile it again. Every command included as
# a prerequisite in .PHONY will run even if a file with that name exists.
.PHONY: clean fclean re

# Clean up generated intermediate files
clean:
	@rm -rf $(LIBFT_OBJSDIR)
	@rm -rf $(OBJSDIR)
	@echo "$(LIGHT_RED)Removed extended lib object files$(REMOVE_COLOUR)"

# Clean up all files generated.
fclean: clean
	@rm -rf $(LIBFT_LIB_DIR)
	@rm -rf $(NAME)
	@echo "$(LIGHT_RED)Removed extended lib compiled .a file$(REMOVE_COLOUR)"

# Recompile. Clean up all files and recompile executable.
re: fclean all