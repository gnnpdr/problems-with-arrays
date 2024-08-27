#include <stdio.h>


void print_every_element (int array[], size_t size);

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    const size_t size = sizeof(array)/sizeof(array[0]); 

    print_every_element (array, size);  //use the pointer to the array and need amount of elements

    return 0;  
}

void print_every_element (int array[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        printf("%d\n", array[i]);
}