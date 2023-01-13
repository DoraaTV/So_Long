# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thrio <thrio@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 11:59:39 by thrio             #+#    #+#              #
#    Updated: 2023/01/13 12:14:09 by thrio            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#LIBFT            =    libft/

#LIBFTA             =    $(LIBFT)libft.a

SRCS            =   main.c get_next_line.c get_next_line_utils.c

OBJS            =    $(SRCS:.c=.o)

CC              =    cc
RM              =    rm -f
CFLAGS          =    -Wall -Wextra -Werror

NAME            =    so_long

all:            $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Iminilibx-linux -Imlx_linux -O3 -c $< -o $@

$(NAME):        $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -Lminilibx-linux -lmlx_Linux -Lminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
				$(RM) $(OBJS) 

fclean:         clean
				$(RM) $(NAME)

re:             fclean $(NAME)

.PHONY:         all clean fclean re bonus