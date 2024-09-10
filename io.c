#include <unistd.h>
#include <string.h>
#include "io.h"

/* Reads next char from stdin. If no more characters, it returns EOF */
int read_char() {
    char a;
    if (read(0, &a, 1) == 1) {
        return (int) a;
    } else {
        return EOF;
    }
}

/* Writes c to stdout.  If no errors occur, it returns 0, otherwise EOF */
int write_char(char c) {
    if (write(1, &c, 1) != -1) {
        return 0;
    }
    return EOF;
}

/* Writes a null-terminated string to stdout.  If no errors occur, it returns 0, otherwise EOF */
int write_string(char *s) {
    ssize_t result = write(1, s, strlen(s));
    return (result != -1) ? 0 : EOF;
}

/* Writes n to stdout (without any formatting).   
 * If no errors occur, it returns 0, otherwise EOF
 */
int write_int(int n) {
    char buffer[12]; // Enough to hold all numbers up to 32-bit integers
    int length = 0;
    int is_negative = 0;

    if (n == 0) {
        buffer[length++] = '0';
    } else {
        if (n < 0) {
            is_negative = 1;
            n = -n;
        }

        while (n > 0) {
            buffer[length++] = (n % 10) + '0';
            n /= 10;
        }

        if (is_negative) {
            buffer[length++] = '-';
        }

        // Reverse the string
        for (int i = 0; i < length / 2; ++i) {
            char temp = buffer[i];
            buffer[i] = buffer[length - i - 1];
            buffer[length - i - 1] = temp;
        }
    }

    buffer[length] = '\0';
    ssize_t result = write(1, buffer, length);
    return (result != -1) ? 0 : EOF;
}