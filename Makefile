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
		Serveur/checking.c \
		Serveur/avance.c \
		Serveur/gauche.c \
		Serveur/droite.c \
		Serveur/collide_tir.c \
		Serveur/mort.c \
		Serveur/tir.c \
		Serveur/applique_gravite.c \
		Serveur/gravite.c \
		Serveur/deletenode.c \
		Serveur/move_tir.c \
		Serveur/move_dir.c \
		Serveur/move_dir2.c \
		Serveur/move_dir_tir.c \
		Serveur/move_dir_tir2.c \
		Serveur/graph_avance.c \
		Serveur/graph_gauche.c \
		Serveur/graph_droite.c \
		Serveur/graph_tir.c \
		Serveur/graph_essence.c \
		Serveur/graph_mort.c \
		Serveur/xmalloc.c \

OBJ_CLIENT=	$(SRC_CLIENT:.cpp=.o)

OBJ_SERVER=	$(SRC_SERVER:.c=.o)

LDFLAGS=	-lsfml-system \
		-lsfml-window \
		-lsfml-graphics \
		-lsfml-network

all:		client serveur

client:		$(OBJ_CLIENT)
		g++ -o $(CLIENT) $(OBJ_CLIENT) $(LDFLAGS)

serveur:	$(OBJ_SERVER)
		gcc -o $(SERVER) $(OBJ_SERVER) -lm

clean:		
		rm -f $(OBJ_SERVER)
		rm -f $(OBJ_CLIENT)

fclean:		clean
		rm -f $(SERVER)
		rm -f $(CLIENT)

re:		fclean all
