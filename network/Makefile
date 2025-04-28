# Makefile
CC = gcc
CFLAGS = -Wall
OBJS = main.o link_layer.o network_layer.o transport_layer.o socket_layer.o

all: net_layers_app

net_layers_app: $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	rm -f *.o net_layers_app
