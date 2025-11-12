# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tibras <tibras@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/01 00:00:00 by tester            #+#    #+#              #
#    Updated: 2025/11/12 18:10:28 by tibras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft_tester

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -I. -I$(LIBFT_DIR)
LDFLAGS		= -lbsd

# Libft paths (to be set by user)
LIBFT_DIR	= ../../42/Libft/
LIBFT_A		= $(LIBFT_DIR)/libft.a
LIBFT_H		= $(LIBFT_DIR)/libft.h

# Source files
SRCS		= main.c \
			  utils.c \
			  trace.c \
			  menu.c \
			  isolation.c \
			  isolated_tests.c \
			  advice.c \
			  test_char.c \
			  test_string.c \
			  test_string2.c \
			  test_memory.c \
			  test_part2.c \
			  test_part2_extra.c \
			  test_fd.c

OBJS		= $(SRCS:.c=.o)

# Colors
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
BLUE		= \033[0;34m
RESET		= \033[0m

# Rules
all: check_libft $(NAME)

check_libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "$(RED)Error: libft directory not found at $(LIBFT_DIR)$(RESET)"; \
		echo "$(YELLOW)Please set LIBFT_DIR in Makefile or run: make LIBFT_DIR=path/to/libft$(RESET)"; \
		exit 1; \
	fi
	@if [ ! -f "$(LIBFT_H)" ]; then \
		echo "$(RED)Error: libft.h not found at $(LIBFT_H)$(RESET)"; \
		echo "$(YELLOW)Please ensure libft.h exists in your libft directory$(RESET)"; \
		exit 1; \
	fi
	@if [ ! -f "$(LIBFT_A)" ]; then \
		echo "$(YELLOW)⚠ libft.a not found. Compiling libft...$(RESET)"; \
		make -C $(LIBFT_DIR); \
		if [ ! -f "$(LIBFT_A)" ]; then \
			echo "$(RED)Error: Failed to compile libft.a$(RESET)"; \
			exit 1; \
		fi; \
		echo "$(GREEN)✓ libft.a compiled successfully$(RESET)"; \
	fi
	@echo "$(GREEN)✓ Found libft.a and libft.h$(RESET)"

$(NAME): $(OBJS)
	@echo "$(BLUE)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

%.o: %.c tester.h
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@rm -f test_putchar.txt test_putstr.txt test_putendl.txt test_putnbr.txt
	@rm -f .libft_test_traces.log
	@echo "$(GREEN)✓ Clean complete$(RESET)"

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)✓ Full clean complete$(RESET)"

re: fclean all

# Run the tester
run: all
	@echo "$(BLUE)════════════════════════════════════════════════════════════════$(RESET)"
	@echo "$(BLUE)                    Running Libft Tester                        $(RESET)"
	@echo "$(BLUE)════════════════════════════════════════════════════════════════$(RESET)"
	@./$(NAME)

# Help message
help:
	@echo "$(BLUE)╔════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BLUE)║              LIBFT TESTER - USAGE INSTRUCTIONS             ║$(RESET)"
	@echo "$(BLUE)╠════════════════════════════════════════════════════════════╣$(RESET)"
	@echo "$(BLUE)║$(RESET) Available targets:                                        $(BLUE)║$(RESET)"
	@echo "$(BLUE)║$(RESET)   make              - Compile the tester                   $(BLUE)║$(RESET)"
	@echo "$(BLUE)║$(RESET)   make run          - Compile and run (batch mode)         $(BLUE)║$(RESET)"
	@echo "$(BLUE)║$(RESET)   make clean        - Remove object files                  $(BLUE)║$(RESET)"
	@echo "$(BLUE)║$(RESET)   make fclean       - Remove all compiled files            $(BLUE)║$(RESET)"
	@echo "$(BLUE)║$(RESET)   make re           - Recompile everything                 $(BLUE)║$(RESET)"
	@echo "$(BLUE)║$(RESET)                                                              $(BLUE)║$(RESET)"
	@echo "$(BLUE)║$(RESET) Running modes:                                               $(BLUE)║$(RESET)"
	@echo "$(BLUE)║$(RESET)   ./libft_tester         - Run all tests (batch mode)      $(BLUE)║$(RESET)"
	@echo "$(BLUE)║$(RESET)   ./libft_tester -i      - Interactive menu mode           $(BLUE)║$(RESET)"
	@echo "$(BLUE)║$(RESET)   ./libft_tester --interactive                              $(BLUE)║$(RESET)"
	@echo "$(BLUE)║$(RESET)                                                              $(BLUE)║$(RESET)"
	@echo "$(BLUE)║$(RESET) Configuration:                                               $(BLUE)║$(RESET)"
	@echo "$(BLUE)║$(RESET)   Set LIBFT_DIR in Makefile to your libft location         $(BLUE)║$(RESET)"
	@echo "$(BLUE)║$(RESET)   Default: ../../42/Libft/                                  $(BLUE)║$(RESET)"
	@echo "$(BLUE)║$(RESET)                                                              $(BLUE)║$(RESET)"
	@echo "$(BLUE)║$(RESET) Or use: make LIBFT_DIR=path/to/your/libft                  $(BLUE)║$(RESET)"
	@echo "$(BLUE)╚════════════════════════════════════════════════════════════╝$(RESET)"

.PHONY: all clean fclean re run check_libft help
