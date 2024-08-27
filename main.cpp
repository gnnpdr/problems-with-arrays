#include <stdio.h>
#include <stdlib.h>

struct TriangAr
    {
        size_t size;
        int* result;
    };

void enter_size (TriangAr* the_table);

void initial_struct (TriangAr* the_table);
void find_capacity (int size, int* capacity); 

void full_out_el (TriangAr* the_table);
void find_el(int row, int col, int* els);

void print_el (TriangAr* the_table);

void clean (TriangAr* the_table);

//void clean_place()

int main ()
{
    TriangAr the_table = {};

    enter_size(&the_table);

    initial_struct(&the_table);
}


void enter_size(TriangAr* the_table)
{
    scanf("%d", &the_table->size);
}

void initial_struct (TriangAr* the_table)
{
    int capacity = 0;

    find_capacity(the_table->size, &capacity);
 
    the_table->result = (int *)calloc(capacity, sizeof(int));

    if (the_table->result == nullptr)
    {
        printf("bad end\n");
        exit(EXIT_FAILURE);
    }
}

void find_capacity (int size, int* capacity)  //ar pr
{
    for(int i = 0; i <= size; i++)
        *capacity += i;
}

void full_out_el (TriangAr* the_table)
{
    size_t row = 0, col = 0;
    scanf("%d", &row);
    scanf("%d", &col);

    int els = 0;
    find_el(row, col, &els);

    scanf("%d", &(the_table->result) + els);
}

find_el(int row, int col, int* els)
{
    find_capacity(row-1, els);
    *els += col;
}

void print_el (TriangAr* the_table)
{
    size_t row = 0, col = 0;
    scanf("%d", &row);
    scanf("%d", &col);

    int els = 0;
    find_el(row, col, &els);

    printf("%d", &(the_table->result) + els);
}

void clean (TriangAr* the_table)
{
    free(the_table->result);
}