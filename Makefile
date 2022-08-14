CC=gcc
CFLAGS=-I -Wall


tcp:
	$(CC) Practical.c ./tcp_v4/TCPEchoClient4.c -o TCPEchoClient4 $(CFLAGS)
	$(CC) Practical.c ./tcp_v4/TCPEchoServer4.c -o TCPEchoServer4 $(CFLAGS)

dns:
	$(CC) Practical.c GetAddrInfo.c -o GetAddrInfo $(CFLAGS)

udp:
	$(CC) Practical.c UDPEchoClient.c -o UDPEchoClient $(CFLAGS)
	$(CC) Practical.c UDPEchoServer.c -o UDPEchoServer $(CFLAGS)

vote:
	$(CC) Practical.c VoteClientTCP.c -o VoteClientTCP $(CFLAGS)
	$(CC) Practical.c VoteServerTCP.c -o VoteServerTCP $(CFLAGS)

sig:
	$(CC) Practical.c SigAction.c -o SigAction $(CFLAGS)

clean:
	rm -f main *.o TCPEchoClient4 TCPEchoServer4 GetAddrInfo UDPEchoClient UDPEchoServer counter select SigAction
