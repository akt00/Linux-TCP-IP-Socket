CC=gcc
CFLAGS=-I -Wall


tcp4:
	$(CC) Practical.c ./tcp_v4/TCPEchoClient4.c -o TCPEchoClient4 $(CFLAGS)
	$(CC) Practical.c ./tcp_v4/TCPEchoServer4.c -o TCPEchoServer4 $(CFLAGS)

tcp_all:
	$(CC) Practical.c ./tcp_dual_stack/TCPEchoClient.c -o TCPEchoClient $(CFLAGS)
	$(CC) Practical.c ./tcp_dual_stack/TCPEchoServer.c -o TCPEchoServer $(CFLAGS)

udp:
	$(CC) Practical.c ./udp_dual_stack/UDPEchoClient.c -o UDPEchoClient $(CFLAGS)
	$(CC) Practical.c ./udp_dual_stack/UDPEchoServer.c -o UDPEchoServer $(CFLAGS)

brute:
	$(CC) Practical.c ./protocol/BruteForceCoding.c -o BruteForceCoding $(CFLAGS)

vote_text_delim:
	$(CC) Practical.c ./protocol/DelimFramer.c ./protocol/VoteEncodingText.c ./protocol/VoteClientTCP.c -o VoteClientTxtDel $(CFLAGS)
	$(CC) Practical.c ./protocol/DelimFramer.c ./protocol/VoteEncodingText.c ./protocol/VoteServerTCP.c -o VoteServerTxtDel $(CFLAGS)

vote_text_len:
	$(CC) Practical.c ./protocol/LengthFramer.c ./protocol/VoteEncodingText.c ./protocol/VoteClientTCP.c -o VoteClientTxtLen $(CFLAGS)
	$(CC) Practical.c ./protocol/LengthFramer.c ./protocol/VoteEncodingText.c ./protocol/VoteServerTCP.c -o VoteServerTxtLen $(CFLAGS)

vote_bin_delim:
	$(CC) Practical.c ./protocol/DelimFramer.c ./protocol/VoteEncodingBin.c ./protocol/VoteClientTCP.c -o VoteClientBinDel $(CFLAGS)
	$(CC) Practical.c ./protocol/DelimFramer.c ./protocol/VoteEncodingBin.c ./protocol/VoteServerTCP.c -o VoteServerBinDel $(CFLAGS)

vote_bin_len:
	$(CC) Practical.c ./protocol/LengthFramer.c ./protocol/VoteEncodingBin.c ./protocol/VoteClientTCP.c -o VoteClientBinLen $(CFLAGS)
	$(CC) Practical.c ./protocol/LengthFramer.c ./protocol/VoteEncodingBin.c ./protocol/VoteServerTCP.c -o VoteServerBinLen $(CFLAGS)

clean:
	rm -f main *.o TCPEchoClient4 TCPEchoServer4 TCPEchoClient TCPEchoServer\
	UDPEchoClient UDPEchoServer BruteForceCoding VoteClientTxtDel VoteServerTxtDel \
	VoteClientTxtLen VoteServerTxtLen VoteClientBinDel VoteServerBinDel VoteClientBinLen VoteServerBinLen\
