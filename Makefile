##
## Makefile for my_ftp in /home/helain_f/Semestre_3/Systeme_Unix/my_Ftp/dev-my_ftp
## 
## Made by florian helaine
## Login   <helain_f@epitech.net>
## 
## Started on  Mon Apr  8 12:24:41 2013 florian helaine
## Last update Tue Jul 23 13:14:41 2013 Florian Helaine
##

CLIENT=		client

SERVER=		serveur

SRC_CLIENT=	Client/main.cpp

SRC_SERVER=	Serveur/add_client.c \
		Serveur/client_read.c \
		Serveur/error.c \
		Serveur/main.c \
		Serveur/run.c \
		Serveur/serveur.c \
		Serveur/serveur_read.c \
		Serveur/set_type.c \
		Serveur/xaccept.c \
		Serveur/xbind.c \
		Serveur/xlisten.c \
		Serveur/xsocket.c \

OBJ_CLIENT=	$(SRC_CLIENT:.cpp=.o)

OBJ_SERVER=	$(SRC_SERVER:.c=.o)

all:		client serveur

client:		$(OBJ_CLIENT)
		gcc -o $(CLIENT) $(OBJ_CLIENT)

serveur:	$(OBJ_SERVER)
		gcc -o $(SERVER) $(OBJ_SERVER)

clean:		
		rm -f $(OBJ_SERVER)
		rm -f $(OBJ_CLIENT)

fclean:		clean
		rm -f $(SERVER)
		rm -f $(CLIENT)

re:		fclean all
