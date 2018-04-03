CC=gcc
CFLAGS=-g -Wall -Werror
EXEC=map
LDFLAGS=

map: map.o
	$(CC) -o $@ $^ $(LDLAGS) # $@ désigne le nom de la cible ici map et $^ la liste des dépendances ici map.o

map.o: map.c
	$(CC) -o $@ -c $< $(CFLAGS) # $< désigne la première dépendances ici map.c

all: $(EXEC)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
