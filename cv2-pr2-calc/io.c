
#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

IO_Result IO_get_line(char * const iostr, int * len) {
    if (iostr == NULL
        || len == NULL
        || *len == 0) {

        return IO_ARGS_ERR;
    }

    if (fgets(iostr, *len, stdin) == NULL) {
        return IO_STREAM_ERROR;
    }

    *len = strlen(iostr);
    fflush(stdin);
    return IO_OK;
}


IO_Result IO_get_char(char * const value) {
    if (value == NULL) {
        return IO_ARGS_ERR;
    }

    char string_value[200];
    int len = 200;
    if (IO_get_line(string_value, &len) == IO_OK) {
        *value = string_value[0];
        return IO_OK;
    }

    return IO_STREAM_ERROR;
}


IO_Result IO_get_int(int * const value)
{
    if (value == NULL)
        return IO_ARGS_ERR;
    
    char string_value[200];
    int len = 200;
    if (IO_get_line(string_value, &len) == IO_OK) {
        long converted = strtol(string_value, NULL, 10);
        if (converted == 0 && string_value[0] != '0') {
            return IO_STREAM_ERROR;
        }

        *value = converted;
        return IO_OK;
    }

    return IO_STREAM_ERROR;
}
