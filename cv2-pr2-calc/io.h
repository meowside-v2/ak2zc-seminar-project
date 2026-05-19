
#ifndef __IO_H_
#define __IO_H_


typedef enum IO_ResultEnum {
    IO_OK,
    IO_ARGS_ERR,
    IO_STREAM_ERROR,
} IO_Result;

IO_Result IO_get_line(char * const in_out_str, int * const len);
IO_Result IO_get_char(char * const value);
IO_Result IO_get_int(int * const value);

#endif