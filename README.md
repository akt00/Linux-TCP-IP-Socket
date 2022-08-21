# Linux-TCP-IP-Socket-in-C
Repurposed code for the book, **"TCP/IP Socket in C, Practical Guide for Programmers"**.

# Purpose
Self-study



# Non-blocking IO
## Select system call
  - each file descriptor needs to be rebuild every iteration
  - O(n)
  - best portability
  - level-triggered interrupt
 
## Poll system call
  - No need buuild the fd set each iteration
  - O(n)
  - efficient for calculating large numbered file descriptors
  - level-triggered interrupt

## EPoll system call
  - can dynamically add/remove file descriptors while waiting
  - O(1)
  - linux only implementation
  - level-triggered | edge-triggered

## Edge-triggered interrupts 
One time event interrupt. Fires once only when the state changes.

## Level-triggered interrupts
Keeps interrupting the current work as long as the source of interrpt is asserted.

## [Reference](https://devarea.com/linux-io-multiplexing-select-vs-poll-vs-epoll/)
