#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "../Practical.h"


void InterruptSingalHandler(int singalType) {
    puts("interrupt Received. Exiting program.\n");
    exit(1);
}


int main(int argc, char *argv[]) {

    struct sigaction handler; 
    handler.sa_handler = InterruptSingalHandler;
    if(sigfillset(&handler.sa_mask) < 0) DieWithSystemMessage("sigfillset() failed");

    handler.sa_flags = 0;

    // upon intteruption, calls handler
    if(sigaction(SIGINT, &handler, 0) < 0) DieWithSystemMessage("sigaction() failed for SIGINT");

    for(;;) pause();

    exit(0);
}
