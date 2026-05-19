#include <stdio.h>
#include "io.h"
#include "calculator.h"

void print_help();


int main(int, char**){
    print_help();
    printf("Select the option: ");

    char readCh;
    while (IO_get_char(&readCh) == IO_OK && readCh != 'q') {
        switch (readCh)
        {   
            case 'a':
            case 'A':
                Calculator_addFunction();
                break;

            case 's':
            case 'S':
                printf("Odcitani\n");
                break;

            case 'm':
            case 'M':
                printf("Nasobeni\n");
                break;

            case 'd':
            case 'D':
                printf("Deleni\n");
                break;

            case 'h':
            case 'H':print_help();
                break;

            case 'q':
            case 'Q':
                return 0;

            default:
                printf("Nerozpoznana volba!\n");
                break;
        }

        printf("Select the option: ");
    }

    return 0;
}


void print_help()
{
    printf("*************************\n");
    printf(
        "Available options:\n"
        "\ta: addition\n"
        "\ts: substraction\n"
        "\tm: multiplication\n"
        "\td: division\n"
        "\th: print help\n"
        "\tq: quit app\n");
    printf("*************************\n");
}
