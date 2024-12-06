# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 18:12:08 by ryagoub           #+#    #+#              #
#    Updated: 2024/02/15 15:40:18 by ryagoub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVERNAME = server
CLIENTNAME = client
BSERVERNAME = bonusserver
BCLIENTNAME = bonusclient
CFILES = client_utils.c client.c
SFILES = server.c server_utils.c
BCFILES = client_utils.c client_bonus.c
BSFILES = server_bonus.c server_utils.c
CFLAGS = -Werror -Wextra -Wall
SOFILES = $(SFILES:.c=.o)
COFILES = $(CFILES:.c=.o)
BSOFILES = $(BSFILES:.c=.o)
BCOFILES = $(BCFILES:.c=.o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: server client
bonus: bonusserver bonusclient


server : $(SFILES)
	$(CC) $(CFLAGS) $(SFILES) -o $(SERVERNAME)

client : $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o $(CLIENTNAME)
bonusserver : $(BSFILES)
	$(CC) $(CFLAGS) $(BSFILES) -o $(BSERVERNAME)
bonusclient : $(BCFILES)
	$(CC) $(CFLAGS) $(BCFILES) -o $(BCLIENTNAME)
clean:
	$(RM) $(COFILES) $(SOFILES) $(BCOFILES) $(BSOFILES)
fclean: clean
	$(RM) $(CLIENTNAME) $(SERVERNAME) $(BCLIENTNAME) $(BSERVERNAME)
re: fclean all bonus

.PHONY: all clean fclean re bonus


























