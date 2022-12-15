# Linux-TCP-IP-Socket-in-C
Repurposed code for the book, **"TCP/IP Socket in C, Practical Guide for Programmers"**.

## Purpose
Self-study

## Multiplexing
### Select system call
  - each file descriptor needs to be rebuild every iteration
  - O(n)
  - best portability
  - level-triggered interrupt
 
### Poll system call
  - No need buuild the fd set each iteration
  - O(n)
  - efficient for calculating large numbered file descriptors
  - level-triggered interrupt

### EPoll system call
  - can dynamically add/remove file descriptors while waiting
  - O(1)
  - linux only implementation
  - level-triggered | edge-triggered

### Edge-triggered interrupts (non-blocking)
One time event interrupt. Fires once only when the state changes.

### Level-triggered interrupts (blocking)
Keeps interrupting the current work as long as the source of interrpt is asserted.

### [Reference](https://devarea.com/linux-io-multiplexing-select-vs-poll-vs-epoll/)


# API References
## sys/socket.h
### int accept(int sockfd, struct sockaddr *restrict addr, socklen_t *restrict addrlen)
This function is for TCP connection
***sockfd*** : a socket file descriptor returned by socket().  
***\*addr*** : a pointer to the object of either sockaddr_storage for dualstack or sockaddr_in for ipv4.  
***addrlen*** : the size of sockaddr_in for ipv4 or sockaddr_storage for dualstack.  
***return*** : On success, returns the file descriptor for the socket for client connection. -1 on failure and sets errno.

### int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
***sockfd*** : a socket file descriptor returned by socket().  
***\*addr*** : sockaddr_in for ipv4 or a list of sockaddr objects stored in addrinfo. addrinfo can be obtained by getaddrinfo().  
***addrlen*** : the size of sockaddr_in for ivp4 or the socklen_t in addrinfo from getaddrinfo().  
***return*** : 0 on success. -1 on failure. sets errno.

### int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen_t addrlen)
***sockfd*** : a socket file descriptor returned by socket().  
***addr*** : sockaddr_in for ipv4 or a list of sockaddr objects stored in addrinfo.  
***addrlen*** : the size of a sockaddr_in object or ai_addrlen in addrinfo.  
***return*** 0 on success. -1 on failure. sets errno.

### int listen(int sockfd, int backlog)
***sockfd*** : a socket file descriptor returned by socket().  
***backlog*** : the maximum number of connection request allowed in the queue.  
***return*** : 0 on success. -1 on failure. sets errno.  

### int socket(int domain, int type, int protocol)
***domain*** : address family defined as enum.  
***type*** : L4 socket protocol type as enum.  
***protocol*** : usually IPPROTO_TCP or IPPROTO_UDP.  
***return*** : 0 on success. -1 on failure. sets errno.


### ssize_t recv(int sockfd, void *buf, size_t len, int flags)
This function copies a TCP message to buf.  
***sockfd*** : a file descriptor returned by accept()  
***\*buf*** : a pointer to a byte buffer array. the optimal buffer size depends on the application protocol. This should be large enough to hold the maximums size of the TCP protocol message.  
***len*** : the size of the buf array.  
***flags*** : flag options. set to 0 for no options.  
***return*** : returns the size of the message receieved and set ssize_t value to 0 if no more TCP message. 

### ssize_t send(int sockfd, const void *buf, size_t len, int flags)
This function sends a TCP packet to a client.  
***sockfd*** : a file descriptor returned by accept()  
***\*buf*** : a pointer to a byte array buffer that holds the message to send.  
***len*** : the size of buf.  
***flags*** : flag options. set to 0 if no flag options.  

## sys/types.h
## netdb.h
## unistd.h
## sys/time.h
## fcntl.h


