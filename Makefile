# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eval </var/mail/tmasaki>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/07 15:41:32 by eval              #+#    #+#              #
#    Updated: 2021/11/07 16:00:37 by eval             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = gcc

CFLAG = -Wall -Wextra -Werror

NAME = minitalk

NAME1 = server

SSRC = server.c

NAME2 = client

CSRC = client.c


all :  $(NAME1) $(NAME2)

$(NAME) : all

$(NAME1) :
		 		@$(CC) $(CFLAG) $(SSRC) -I minitalk.h -o $(NAME1)

$(NAME2) :
		 		@$(CC) $(CFLAG) $(CSRC) -I minitalk.h  -o $(NAME2)

clean :
				rm -rf server.o client.o

fclean : clean
				rm -rf $(NAME1) $(NAME2)

re : fclean all


.PHONEY: all clean fclean re
