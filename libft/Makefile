# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 15:25:34 by abiriuk           #+#    #+#              #
#    Updated: 2017/11/29 18:08:31 by abiriuk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =gcc
CFLAGS =-c -Wall -Wextra -Werror 
SOURCES =ft_bzero.c ft_isalnum.c ft_memcpy.c ft_putstr_fd.c ft_striter.c ft_tolower.c ft_isalpha.c ft_memdel.c ft_strcat.c ft_strlen.c ft_toupper.c ft_isascii.c ft_memmove.c ft_strchr.c ft_strncat.c ft_isdigit.c ft_memset.c ft_strclr.c ft_strncmp.c ft_isprint.c ft_putchar.c ft_strcmp.c ft_strncpy.c ft_memalloc.c ft_putchar_fd.c ft_strcpy.c ft_strnew.c ft_memccpy.c ft_putendl.c ft_strdel.c ft_strnstr.c ft_memchr.c ft_putendl_fd.c ft_strdup.c ft_strrchr.c ft_bzero.c ft_memcmp.c ft_putstr.c ft_strequ.c ft_strstr.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_strlcat.c ft_atoi.c ft_isspace.c ft_itoa.c ft_putnbr.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstadd_rev.c ft_replace_elem.c ft_del_cont.c ft_sqrt.c ft_iswhitespace.c
OBJECTS =$(SOURCES:.c=.o)
NAME  =libft.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
