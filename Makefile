# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asanz-ra <asanz-ra@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 20:14:43 by asanz-ra          #+#    #+#              #
#    Updated: 2025/06/30 16:15:16 by asanz-ra         ###   ########.fr        #
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

# Library name
NAME = lib_extended.a

# Source file wrapping folder
SRC_ROOT = ./src

# Source file sub-dirs, can be expanded
SRC_DIRS = $(SRC_ROOT)/libft \
           $(SRC_ROOT)/printf \
		   $(SRC_ROOT)/gnl

# Include directories (add more as needed)
INCLUDE_ROOT = ./inner_include
INCLUDE_DIRS =  . \
				$(INCLUDE_ROOT)
#               $(INCLUDE_DIRS)/another


# Source files
SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))

# Object files
OBJSDIR = ./obj
OBJS = $(patsubst $(SRC_ROOT)/%.c,$(OBJSDIR)/%.o,$(SRCS))

# Include flags
INCLUDES = $(addprefix -I,$(INCLUDE_DIRS))


# Default target. Generate the library.
all: $(NAME)

#-------------------------------Make library-------------------------------

# Link object files into the library.
# $@ means the target(NAME). $^ means all prerequisites (OBJS)
# Create library from objects
$(NAME): $(OBJS)
	@$(LIBA) $@ $^
	@echo "Library compiled $(LIGHT_GREEN)correctly$(REMOVE_COLOUR)"


#-------------------------------Make object files-------------------------------
# Compile a .c file into a needed .o object file.
# This is called when any .o file is needed. That is the meaning of %,
# which is called a wildcard, it could be anything, compiling %.c into %.o.
# $< means the first prerequisite (.../%.c)
# @D is the directory of the target. That mkdir tthen creates subfolders,
#    e.g. obj/libft or obj/printf
$(OBJSDIR)/%.o: $(SRC_ROOT)/%.c | $(OBJSDIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiled $(LIGHT_GREEN)$<$(REMOVE_COLOUR)"


#---------------------------------Make folders---------------------------------
#Make folders to host files when needed
$(OBJSDIR):
	@mkdir -p $@


#-------------------------------------Utils-------------------------------------
# A function isn't run if a file with the name exists in the current directory.
# This is UNLESS we made changes to its prerequisites(recursively). I.e. if
# NAME exists, we NORMALLY don't recompile it again. Every command included as
# a prerequisite in .PHONY will run even if a file with that name exists.

# Clean up generated intermediate files
clean:
	@rm -rf $(OBJSDIR)
	@echo "$(LIGHT_RED)Removed extended lib object files$(REMOVE_COLOUR)"

# Clean up all files generated.
fclean: clean
	@rm -rf $(NAME)
	@echo "$(LIGHT_RED)Removed extended lib compiled .a file$(REMOVE_COLOUR)"

# Recompile. Clean up all files and recompile library.
re: fclean all

.PHONY: all clean fclean re