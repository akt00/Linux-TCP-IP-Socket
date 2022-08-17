#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "../Practical.h"


const uint8_t val8 = 101;
const uint16_t val16 = 1001;
const uint32_t val32 = 100000001; // 1M and 1
const uint64_t val64 = 1000000000001L; // 1T and 1
const int MESSAGELENGTH = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(uint32_t) + sizeof(uint64_t);

static char stringBuf[BUFSIZE]; // 512

// converts the values in byteArray to string in decimal
char *BytesToDecString(uint8_t *byteArray, int arrayLength) {
    char *cp = stringBuf; // shallow copy
    size_t bufSpaceLeft = BUFSIZE;
    for(int i=0; i < arrayLength && bufSpaceLeft > 0; i++) {
        // on success return total number of chars
        // copy to the format to cp
        int strl = snprintf(cp, bufSpaceLeft, "%u ", byteArray[i]);
        bufSpaceLeft -= strl; // reduct the len
        cp += strl; // increment the pointer
    }
    return stringBuf;
}

// Warning: Untested preconditions (e.g., 0 <= size <= 8)
int EncodeIntBigEndian(uint8_t dst[], uint64_t val, int offset, int size) {

    for(int i=0; i<size; i++) {
        dst[offset++] = (uint8_t) (val >> ((size - 1) - i) * CHAR_BIT);
    }
    return offset;
}

// Warning: Untested preconditions (e.g., 0 <= size <= 8)
int DecodeIntBigEndian(uint8_t val[], int offset, int size) {
    uint64_t rtn = 0;
    for(int i=0;i<size;i++) {
        rtn = (rtn << CHAR_BIT) | val[offset + i];
    }
    return rtn;
}

int main(int argc, char *argv[]) {

    uint8_t message[MESSAGELENGTH]; // Big enough to hold all four values
    // Encode the integers in sequence in the message buffer
    int offset = 0;
    offset = EncodeIntBigEndian(message, val8, offset, sizeof(uint8_t));
    offset = EncodeIntBigEndian(message, val16, offset, sizeof(uint16_t));
    offset = EncodeIntBigEndian(message, val32, offset, sizeof(uint32_t));
    offset = EncodeIntBigEndian(message, val64, offset, sizeof(uint64_t));
    printf("Encoded message: \n%s\n", BytesToDecString(message, MESSAGELENGTH));

    uint64_t value = DecodeIntBigEndian(message, sizeof(uint8_t), sizeof(uint16_t));
    printf("Decoded 2-byte integer = %u\n", (unsigned int) value);
    value = DecodeIntBigEndian(message, sizeof(uint8_t) + sizeof(uint16_t) + sizeof(uint32_t), sizeof(uint64_t));
    printf("Decoded 8-byte integer = %llu\n", value);

    // Show signedness
    offset = 4;
    int iSize = sizeof(int32_t);
    value = DecodeIntBigEndian(message, offset, iSize);
    printf("Decoded value(offset %d, size %d) = %lld", offset, iSize, value);
    int signedVal = DecodeIntBigEndian(message, offset , iSize);
    printf("...same as signed value %d\n", signedVal);
}
