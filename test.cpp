#include <stdio.h>

int main()
{
    int data[] = {1, 2, 3};

    printf( "%p\n%p\n%p\n", &data, data, &data[0]);
}