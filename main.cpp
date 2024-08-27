#include <stdio.h>
#include <stdlib.h>

struct TriangAr
    {
        size_t size;
        int* result;
    };

void enter_size (TriangAr* the_table);

void initial_struct (TriangAr* the_table, int *const capacity);
void find_capacity (const int size, int *const capacity); 

void full_out_el (TriangAr* the_table);
void find_el(const int row, const int col, int *const els);

void print_el (TriangAr* the_table);

void clean (TriangAr* the_table);

void print_ar(TriangAr* the_table, const int capacity);

int main ()
{
    TriangAr the_table = {};

    int capacity = 0;

    enter_size(&the_table);

    initial_struct(&the_table, &capacity); 
}


void enter_size(TriangAr* the_table)
{
    assert (the_table != nullptr);
    scanf("%d", &the_table->size);
}

void initial_struct (TriangAr* the_table, int *const capacity)
{
    assert (the_table != nullptr);
    assert (capacity != nullptr);

    find_capacity(the_table->size, capacity);
 
    the_table->result = (int *)calloc(capacity, sizeof(int));

    if (the_table->result == nullptr)
    {
        printf("bad end\n");
        exit(EXIT_FAILURE);
    }
}

void find_capacity (const int size, int *const capacity)  //ar pr
{
    assert (size != NULL);
    assert (capacity != nullptr);

    for(int i = 0; i <= size; i++)
        *capacity += i;
}

void full_out_el (TriangAr* the_table)
{
    assert (the_table != nullptr);

    size_t row = 0, col = 0;
    scanf("%d", &row);
    scanf("%d", &col);

    int els = 0;
    find_el(row, col, &els);

    scanf("%d", &(the_table->result) + els);
}

void find_el(const int row, const int col, int *const els)
{
    assert (row != NULL);
    assert (col != NULL);
    assert (els != nullptr);

    find_capacity(row-1, els);
    *els += col;
}

void print_el (TriangAr* the_table)
{
    assert (the_table != nullptr);

    size_t row = 0, col = 0;
    scanf("%d", &row);
    scanf("%d", &col);

    int els = 0;
    find_el(row, col, &els);

    printf("%d", &(the_table->result) + els);
}

void clean (TriangAr* the_table)
{
    assert (the_table != nullptr);

    free(the_table->result);
}

void print_ar(TriangAr* the_table, const int capacity)  //here capacity was found
{
    assert (the_table != nullptr);
    assert (capacity != nullptr);

    int k = 0;

    for (int row = 0; row < the_table->size; row++)
    {
        for (int col = 0; col <= row; col++)
        {
            printf("%d", &(the_table->result) + k);
            k++;
        }
    }
}