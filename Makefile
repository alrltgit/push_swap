# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apple <apple@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 13:11:36 by apple             #+#    #+#              #
#    Updated: 2025/03/21 17:00:57 by apple            ###   ########.fr        #
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
operations/sa_sb_ss.c \
operations/pa_pb.c \
operations/ra_rb.c \
operations/rra_rrb_rrr.c \
operations/helpers/helpers.c \
sort_cases/case_1.c \
sort_cases/case_2.c \
sort_cases/case_3.c \
sort_cases/helpers/case_3_helpers.c \
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