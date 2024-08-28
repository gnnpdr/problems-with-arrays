#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

struct TriangAr
{
    size_t table_lenght;
    int* result;
};

void enter_table_lenght (TriangAr* the_table);

void initial_struct (TriangAr* the_table, int *const capacity);
void arithmetic_progression (const int table_lenght, int *const capacity); 

void fill_element (TriangAr* the_table);
void find_element(const int row, const int col, int *const elements);

void print_element (TriangAr* the_table);

void clean (TriangAr* the_table);

void print_array(TriangAr* the_table, const int capacity);

int main ()
{
    TriangAr the_table = {};

    int capacity = 0;

    enter_table_lenght(&the_table);

    initial_struct(&the_table, &capacity); 
}

void enter_table_lenght(TriangAr* the_table)
{
    assert (the_table != nullptr);

    scanf("%d", &the_table->table_lenght);
}

void initial_struct (TriangAr* the_table, int *const capacity)
{
    assert (the_table != nullptr);
    assert (capacity != nullptr);

    arithmetic_progression(the_table->table_lenght, capacity);
 
    the_table->result = (int*)calloc(*capacity, sizeof(int));

    if (the_table->result == nullptr)
    {
        printf("bad end\n");
        exit(EXIT_FAILURE);
    }
}

void arithmetic_progression (const int table_lenght, int *const capacity)  //arifm pr
{ 
    assert (capacity != nullptr);

    *capacity = (1 + table_lenght) / 2;
}

void fill_element (TriangAr* the_table)
{
    assert (the_table != nullptr);

    size_t row = 0, col = 0;
    scanf("%d", &row);
    scanf("%d", &col);

    int elements = 0;
    find_element(row, col, &elements);

    scanf("%d", &(the_table->result) + elements);
}

void find_element(const int row, const int col, int *const elements)
{
    assert (elements != nullptr);

    arithmetic_progression(row-1, elements);
    *elements += col;
}

void print_element (TriangAr* the_table)
{
    assert (the_table != nullptr);

    size_t row = 0, col = 0;
    scanf("%d", &row);
    scanf("%d", &col);

    int elements = 0;
    find_element(row, col, &elements);

    printf("%d", &(the_table->result) + elements);   
}

void clean (TriangAr* the_table)
{
    assert (the_table != nullptr);

    free(the_table->result);
}

void print_array(TriangAr* the_table, const int capacity) 
{
    assert (the_table != nullptr);

    int k = 0;

    for (int row = 0; row < the_table->table_lenght; row++)
    {
        for (int col = 0; col <= row; col++)
        {
            printf("%d", &(the_table->result) + k);
            k++;
        }
    }
}