COBJS ?= client.o bmp.o couleur.o cJSON.o cJSON_Utils.o
SOBJS ?= serveur.o  cJSON.o cJSON_Utils.o

.SUFFIXES: .c .o

SERVER = serveur
CLIENT = client

all: $(SERVER) $(CLIENT)

$(SERVER): $(SOBJS)
	gcc -o $(SERVER) $(SOBJS) -lm

$(CLIENT): $(COBJS)
	gcc -o $(CLIENT) $(COBJS)

.c.o: 
	gcc -Wall -Werror -ggdb3 -c $*.c

