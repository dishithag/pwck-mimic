a.out: client1.o server1.o
	gcc client1.o server1.o
client.o: client1.c interface.h
	gcc-c client1.c 
server.o: server1.c interface.h
	gcc-c server1.c
