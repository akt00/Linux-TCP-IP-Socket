CC=gcc
CFLAGS=-I -Wall


tcp4:
	$(CC) Practical.c ./tcp_v4/TCPEchoClient4.c -o TCPEchoClient4 $(CFLAGS)
	$(CC) Practical.c ./tcp_v4/TCPEchoServer4.c -o TCPEchoServer4 $(CFLAGS)

tcp_all:
	$(CC) Practical.c ./tcp_dual_stack/TCPEchoClient.c -o TCPEchoClient $(CFLAGS)
	$(CC) Practical.c ./tcp_dual_stack/TCPEchoServer.c -o TCPEchoServer $(CFLAGS)

dns:
	$(CC) Practical.c GetAddrInfo.c -o GetAddrInfo $(CFLAGS)

udp:
	$(CC) Practical.c ./udp_dual_stack/UDPEchoClient.c -o UDPEchoClient $(CFLAGS)
	$(CC) Practical.c ./udp_dual_stack/UDPEchoServer.c -o UDPEchoServer $(CFLAGS)

vote:
	$(CC) Practical.c VoteClientTCP.c -o VoteClientTCP $(CFLAGS)
	$(CC) Practical.c VoteServerTCP.c -o VoteServerTCP $(CFLAGS)

sig:
	$(CC) Practical.c SigAction.c -o SigAction $(CFLAGS)

clean:
	rm -f main *.o TCPEchoClient4 TCPEchoServer4 TCPEchoClient TCPEchoServer GetAddrInfo UDPEchoClient UDPEchoServer counter select SigAction sigio
