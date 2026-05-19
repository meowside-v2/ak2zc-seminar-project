
#include <stdlib.h>
#include "io.h"


IOResult io_readline(char* const buffer, size_t* size) {
	return io_freadline(buffer, size, stdin);
}

IOResult io_freadline(char* const buffer, size_t* size, FILE* stream) {
	if (buffer == NULL || stream == NULL || *size == 0) {
		fprintf(stderr, "Error: Null pointer passed to io_freadline.\n");
		return IO_ARGUMENT_ERROR;
	}

	if (fgets(buffer, (int)(*size), stream) == NULL) {
		return IO_STREAM_ERROR;
	}

	*size = strlen(buffer);
	fflush(stream);
	return IO_SUCCESS;
}


IOResult io_readint(int* const value) {
	return io_freadint(value, stdin);
}

IOResult io_freadint(int* const value, FILE* stream) {
	if (value == NULL || stream == NULL) {
		fprintf(stderr, "Error: Null pointer passed to io_freadint.\n");
		return IO_ARGUMENT_ERROR;
	}

	char buffer[64];
	size_t size = sizeof(buffer) / sizeof(char);

	const IOResult readline_result = io_readline(buffer, &size);
	if (readline_result != IO_SUCCESS) {
		return readline_result;
	}
	
	const long parsed_value = strtol(buffer, NULL, 10);
	if (parsed_value < INT_MIN || parsed_value > INT_MAX) {
		fprintf(stderr, "Error: Parsed integer out of range in io_freadint.\n");
		return IO_OUT_OF_RANGE_ERROR;
	}

	if (parsed_value == 0 && buffer[0] != '0') {
		fprintf(stderr, "Error: Invalid integer format in io_freadint.\n");
		return IO_INVALID_FORMAT_ERROR;
	}

	return IO_SUCCESS;
}