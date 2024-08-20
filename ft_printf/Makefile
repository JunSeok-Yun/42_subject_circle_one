# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junseyun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 19:14:53 by junseyun          #+#    #+#              #
#    Updated: 2024/04/13 15:16:08 by junseyun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

FILES = ft_itoa.c ft_print_hex.c ft_print_ptr.c ft_print_unsigned.c ft_printf.c \
		ft_put_func.c

OBJS = $(FILES:.c=.o)

all: $(TARGET)

$(TARGET):	$(OBJS)
			$(AR)	$@	$^

clean:
			$(RM)	$(OBJS)

fclean:		clean
			$(RM)	$(TARGET)

re:			fclean	$(TARGET)

.PHONY:		all	clean	fclean	re
