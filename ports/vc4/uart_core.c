#include <unistd.h>
#include "py/mpconfig.h"

/*
 * Core UART functions to implement for a port
 */


// Receive single character
int mp_hal_stdin_rx_chr(void) {
    unsigned char c = 0;
    int r = read(0, &c, 1);
    (void)r;
    if (r == 0) {
       c = 4; // EOF, ctrl-D
    } else if (c == '\n') {
       c = '\r';
    }
    return c;
}

// Send string of given length
void mp_hal_stdout_tx_strn(const char *str, mp_uint_t len) {
    int r = write(1, str, len);
    (void)r;
}
