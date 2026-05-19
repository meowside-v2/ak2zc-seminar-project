#include <stdio.h>

void vypis_cislo(int num)
{
    printf("Cislo je: %i\n", num);
}

void vymen(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int *data, int size)
{
    printf("sizeof(data) = %i\n", sizeof(data));
    printf("sizeof(int) = %i\n", sizeof(int));

    for (int i = 0; i < size; i++) {
        printf("data[%i] = %i\n", i, data[i]);
    }
}

int main()
{
    // 1
    vypis_cislo(5);
    int cis = 15;
    vypis_cislo(15);

    printf("\n\n");

    // 2
    int a = 10;
    int b = 20;
    vypis_cislo(a);
    vypis_cislo(b);
    vymen(&a, &b);
    vypis_cislo(a);
    vypis_cislo(b);

    printf("\n\n");

    // 3
    int* temp_a;
    temp_a = &a;
    printf("Hodnota: %i\n", *temp_a);
    printf("Ukazatel temp: %p\n", temp_a);
    printf("Adresa a: %p\n", &a);

    printf("\n\n");

    // 4
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("Pole: %p\n", data);
    printf("Prvni prvek: %p\n", &data[0]);
    for (int i = 0; i < 10; i++) {
        printf("data[%i] = %i\n", i, *(data + i));
    }
    printf("\n");
    for (int* p = data; p < (data + 10); p++) {
        printf("data = %i\n", *p);
    }

    printf("\n\n");

    // 5
    print_array(data, 10);

    printf("\n\n");

    return 0;
}
