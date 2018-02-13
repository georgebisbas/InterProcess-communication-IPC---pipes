all: client7941 server7941

client7941: client7941.c
	gcc -o client7941 client7941.c 

server: server7941.c
	gcc -o server7941 server7941.c 

clean:
	rm client7941 server7941
