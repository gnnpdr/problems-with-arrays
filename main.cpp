#include <stdio.h>
#include <assert.h>

void move_elements (int array[], size_t size);

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    const size_t size = sizeof(array)/sizeof(array[0]); 

    move_elements (array, size);

    return 0;  
}

void move_elements (int array[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        assert (i   < size);
        assert (i+1 < size);  //brings asser to the final element of array

        array[i] = array[i+1];
        printf("%d\n", array[i]);
    }
}