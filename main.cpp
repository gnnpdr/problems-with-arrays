#include <stdio.h>

void sum_arrays (int* ar1, int* ar2, size_t amount_of_str, size_t amount_of_el);

int main()
{
    int ar1[][3] = {
        {1, 2, 3},
        {4, 5, 6}
        };

    const size_t amount_of_str = sizeof(ar1)/sizeof(ar1[0]);     // we think amount of els and strings same in a1 and a2
    const size_t amount_of_el = sizeof(ar1[0])/sizeof(ar1[0][0]);

    int ar2[][3] = {
        {2, 3, 5}, 
        {6, 7, 8}, 
        };

    sum_arrays(*ar1, *ar2, amount_of_str, amount_of_el);
}

void sum_arrays (int* ar1, int* ar2, size_t amount_of_str, size_t amount_of_el)
{
    for (size_t str = 0; str < amount_of_str; str++)
    {
        for (size_t el = 0; el < amount_of_el; el++)
        {
            printf("ar[%d][%d] = %d ", str, el, *((int*)ar1 + str*amount_of_el + el) + *((int*)ar2 + str*amount_of_el + el));
        }
        printf("\n");
    }
}