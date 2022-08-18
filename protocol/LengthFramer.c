#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>
#include "Framer.h"
#include "../Practical.h"


/* Read 2-byte length and place in big-endian order.
 * Then read the indicated number of bytes.
 * If the input buffer is too small for the data, truncate to fit and
 * return the negation of the *indicated* length.  Thus a negative return
 * other than -1 indicates that the message was truncated.
 * (Ambiguity is possible only if the caller passes an empty buffer.)
 * Input stream is always left empty.
 */
int GetNextMsg(FILE *in, uint8_t *buf, size_t bufSize) {

    uint16_t mSize = 0;
    uint16_t extra = 0;
    // read the stream size to mSize
    if(fread(&mSize, sizeof(uint16_t), 1, in) != 1) return -1;
    // convert network byte order to host byte order
    mSize = ntohs(mSize);

    // if stream size is bigger than buff size
    if(mSize > bufSize) {
        extra = mSize - bufSize;
        mSize = bufSize; // Truncate
    }

    // read to buf with the size of mSize * uint8
    if(fread(buf, sizeof(uint8_t), mSize, in) != mSize) {
        fprintf(stderr, "Framing error: expected %d, read less\n", mSize);
        return -1;
    }
    // return the size or the the negative size indicating trucation
    if(extra > 0) { // message was truncated
        uint8_t waste[BUFSIZE];
        fread(waste, sizeof(uint8_t), extra, in); // Try to flush the channel
        return -(mSize + extra); // Negation of indicated size
    } else {
        return mSize;
    }
}

/* Write the given message to the output stream, followed by
 * the delimiter.  Precondition: buf[] is at least msgSize.
 * Returns -1 on any error.
 */
int PutMsg(uint8_t buf[], size_t msgSize, FILE *out) {

    if(msgSize > UINT16_MAX) return -1;
    // host byte order to network byte order
    uint16_t payloadSize = htons(msgSize);
    
    if((fwrite(&payloadSize, sizeof(uint16_t), 1, out) != 1) || (fwrite(buf, sizeof(uint8_t), msgSize, out) != msgSize)) {
        return -1;
    }
    fflush(out);
    return msgSize;
}
