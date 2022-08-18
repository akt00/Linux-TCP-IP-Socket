#ifndef VOTE_PROTOCOL
#define VOTE_PROTOCOL
#include <stdbool.h>


struct VoteInfo {
    uint64_t count;
    int candidate;
    bool isInquiry;
    bool isResponse;
};

typedef struct VoteInfo VoteInfo;

enum {
    MAX_CANDIDATE = 1000,
    MAX_WIRE_SIZE = 500,
};


#endif
