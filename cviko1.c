
#include <stdio.h>

int main() {
    const char *ODD_FORMAT = "%d\n";
    const char *EVEN_FORMAT = "%ds\n";

    for (int i = 1; i < 11; i++) {
        printf(
            i % 2 ? ODD_FORMAT : EVEN_FORMAT,
            i
        );
    }

    return 0;
}