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
**sockfd** a socket file descriptor that is returned by socket() API.
**addr** a pointer to the object of either sockaddr_storage for dualstack or sockaddr_in for ipv4.
**addrlen** the size of sockaddr_in for ipv4 or sockaddr_storage for dualstack.
**return** On success, returns the file descriptor. -1 on failure and sets errno to indicate the error.



