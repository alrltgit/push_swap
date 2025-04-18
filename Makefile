# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 13:11:36 by apple             #+#    #+#              #
#    Updated: 2025/03/27 15:24:35 by alraltse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -f

SRC = push_swap.c \
fulfil_list.c \
argv_validation/argv_is_int.c \
argv_validation/do_argv_dupl.c \
argv_validation/argv_is_sorted.c \
argv_validation/helpers.c \
operations/sa_sb_ss.c \
operations/pa_pb.c \
operations/ra_rb.c \
operations/rra_rrb_rrr.c \
sort_cases/case_1.c \
sort_cases/case_2.c \
sort_cases/sort_a.c \
sort_cases/helpers/case_2_helpers.c \
sort_cases/helpers/case_2_utils.c \
sort_cases/helpers/helpers.c \
sort_cases/helpers/sort_a_helpers.c \
sort_cases/helpers/sort_a_utils.c \
sort.c

OBJS = $(SRC:.c=.o)

LIBFT_PATH = libft

LIBFT_NAME = libft.a

NAME = push_swap

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

all: $(NAME)

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re