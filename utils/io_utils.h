#ifndef IO_UTILS
#define IO_UTILS

#include <stdio.h>

// FUNCTION DECLARATIONS

int read_line(FILE *stream, char *buffer, size_t size);
int read_int(FILE *stream, int *a);
int read_ints(FILE *stream, int *arr);


// FUNCTION DEFINITIONS

int read_line(FILE *stream, char *buffer, size_t size) {
    int c, idx = 0;

    while ((c = getc(stream)) != '\n' && c != EOF && idx < size - 1) {
        buffer[idx++] = c;
    }
    buffer[idx] = 0;
    return idx;
}


int read_int(FILE *stream, int *a) {
    int ret;
    if ((ret = fscanf(stream, "%d", a)) == EOF) {
        fprintf(stderr, "Error in reading integer.\n");
    }
    return ret;
}

int read_ints(FILE *stream, int *arr) {
    char buffer[1024];
    if (!read_line(stream, buffer, sizeof(buffer))) return 0;

    int i = 0, n;
    char *ptr = buffer;
    while (sscanf(ptr, "%d%n", &arr[i], &n) == 1) {
        i++;
        ptr += n;
    }
    return i;
}


#endif