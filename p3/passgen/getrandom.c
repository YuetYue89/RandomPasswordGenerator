#define _GNU_SOURCE
#include <sys/random.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include <stddef.h>


// Name: Yuet Yue
// netID: yy655
// your code for getrandom goes here

ssize_t getrandom(void *buf, size_t buflen, unsigned int flags) {

    // Fill the buffer with non-random password content
    for (size_t i = 0; i < buflen; i++) {
        ((unsigned char *)buf)[i] = 0;
    }

    return buflen;
}

