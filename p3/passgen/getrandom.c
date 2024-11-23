#define _GNU_SOURCE
#include <sys/random.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include <stddef.h>


// Name: Yuet Yue
// netID: yy655
// your code for getrandom goes here

// Function that replaces the system's getrandom() func
// Use "make test" on the CLI in the passgen dir to automatically run this with no LD_PRELOAD and with LD_PRELOAD
ssize_t getrandom(void *buf, size_t buflen, unsigned int flags) {

    // Fill the buffer with non-random password content
    for (size_t i = 0; i < buflen; i++) {
        ((unsigned char *)buf)[i] = 0;
    }

    return buflen;
}

