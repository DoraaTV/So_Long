# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thrio <thrio@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 11:59:39 by thrio             #+#    #+#              #
#    Updated: 2023/01/14 19:59:43 by thrio            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#LIBFT            =    libft/

#LIBFTA             =    $(LIBFT)libft.a

SRCS            =   src/main.c src/map_init.c src/swapers.c src/moves.c src/get_next_line.c src/get_next_line_utils.c src/ft_utils.c src/ft_printf.c

OBJS            =    $(SRCS:.c=.o)

CC              =    cc
RM              =    rm -f
CFLAGS          =    -Wall -Wextra -Werror

NAME            =    so_long

all:            $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Iminilibx-linux -Imlx_linux -O3 -c $< -o $@

$(NAME):        $(OBJS)
				cd minilibx-linux;make;cd ..
				$(CC) $(CFLAGS) $(OBJS) -Lminilibx-linux -lmlx_Linux -Lminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
				cd minilibx-linux;make clean;cd ..
				$(RM) $(OBJS) 

fclean:         clean
				$(RM) $(NAME)

re:             fclean $(NAME)

.PHONY:         all clean fclean re bonus