
#include "calculator.h"
#include "io.h"
#include <stdio.h>


void readNumbers(int *a, int *b) {

}

void Calculator_addFunction() {
    int a;
    int b;

    if(IO_get_int(&a) != IO_OK || IO_get_int(&b) != IO_OK) {
        return;
    }

    int res = a + b;
    printf("%i + %i = %i", a, b, res);
}