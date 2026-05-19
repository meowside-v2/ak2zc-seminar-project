// david-knieradl_ak2zc_seminar.c : Defines the entry point for the application.
//

#include "arrayext.h"
#include "io.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct supported_options_t {
	const char* long_name;
	const char* description;
	char short_name;
} supported_options_t;


void print_help(const supported_options_t* const options, const size_t n);
void print_list(const List* const list);
void handle_add_to_list(List* const list);


int main() {
	const supported_options_t supported_options[] = {
		{ .short_name = 'h', .long_name = "help",	.description = "Print help for operation of the program."},
		{ .short_name = 'a', .long_name = "add",	.description = "Add number to the list."},
		{ .short_name = 'f', .long_name = "finish",	.description = "Finilizes adding numbers to the list." },
		{ .short_name = 'q', .long_name = "quit",	.description = "Quit program."},
        { .short_name = 'p', .long_name = "print",  .description = "Print contents of current list."}
	};

	List list = make_list(16);

    char readCh;
    do {
        printf("Select option (h for help): ");
		const IOResult read_result = io_readchar(&readCh);

		if (read_result != IO_SUCCESS) {
            fprintf(stderr, "Error reading input: %d\n", read_result);
			destroy_list(&list);
			return EXIT_FAILURE;
        }

        readCh = tolower(readCh);
        switch (readCh)
        {
        case 'h':
            print_help(supported_options, sizeof(supported_options) / sizeof(supported_options[0]));
            break;

        case 'p':
            print_list(&list);
			break;

        case 'q':
            destroy_list(&list);
            return EXIT_SUCCESS;

        case 'a':
			handle_add_to_list(&list);
            break;

        default:
            printf("Nerozpoznana volba!\n");
            break;
        }
    } while (readCh != 'f');

	printf("=== reverse_array_in_place ===\n");
	print_list(&list);
	printf("Reversing the list...\n");
    

	destroy_list(&list);
    return EXIT_SUCCESS;
}



void print_help(const supported_options_t* const options, const size_t n) {
	printf("Supported options:\n");
	for (size_t i = 0; i < n; i++) {
		const supported_options_t option = options[i];
		printf("\t%c (%s):\n\t%s\n", option.short_name, option.long_name, option.description);
	}
}

void print_list(const List* const list) {
    printf("List (size: %zu, capacity: %zu):\n", list->size, list->capacity);
    printf("{");
    for (size_t i = 0; i < list->size; i++) {
        printf(i < list->size - 1 ? "%d, " : "%d", list->_data[i]);
    }
    printf("}");
}

void handle_add_to_list(List* const list) {

}