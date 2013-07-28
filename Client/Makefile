##
## Makefile for spacewar(convert) in /home/antoine/Desktop/spacewar
## 
## Made by antoine paquet
## Login   <paquet_a@epitech.net>
## 
## Started on  Sun Jul 28 05:35:31 2013 antoine paquet
## Last update Sun Jul 28 05:43:19 2013 antoine paquet
##

NAME=		client

SRC=		main.cpp \
		Except.cpp \
		SpaceWar.cpp \
		Network.cpp \
		Position.cpp \
		AObject.cpp \
		Ship.cpp \
		Sun.cpp \
		Shoot.cpp

OBJ=		$(SRC:.cpp=.o)

LDFLAGS=	-lsfml-graphics \
		-lsfml-window \
		-lsfml-system \
		-lsfml-network

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
