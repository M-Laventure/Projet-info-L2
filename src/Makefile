CC=gcc
CFLAGS=-g -Wall -Werror
EXEC=jeu
LDFLAGS=

jeu: jeu.o
	$(CC) -o $@ $^ $(LDLAGS) # $@ désigne le nom de la cible ici jeu et $^ la liste des dépendances ici jeu.o

jeu.o: jeu.c
	$(CC) -o $@ -c $< $(CFLAGS) # $< désigne la première dépendances ici jeu.c

all: $(EXEC)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

