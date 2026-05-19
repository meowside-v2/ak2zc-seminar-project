
#ifndef __IO_H__
#define	__IO_H__

#include <stdio.h>


typedef enum IOResult {
	IO_SUCCESS = 0,
	IO_ARGUMENT_ERROR,
	IO_STREAM_ERROR,
	IO_OUT_OF_RANGE_ERROR,
	IO_INVALID_FORMAT_ERROR,
} IOResult;


IOResult io_readline(char* const buffer, size_t* const size);
IOResult io_freadline(char* const buffer, size_t* const size, FILE* const stream);

IOResult io_readchar(char* const value);
IOResult io_freadchar(char* const value, FILE* const stream);

IOResult io_readint(int* const value);
IOResult io_freadint(int* const value, FILE* const stream);

#endif // !__IO_H__
