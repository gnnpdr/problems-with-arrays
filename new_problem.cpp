#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct ArrayData
{
    int rows;
    int capacity;

    int* result;
    int* addresses;
};

void enter_amount_of_rows(ArrayData* the_table, bool *const right_enter);

void finding_capacity(ArrayData* the_table, bool *const right_enter);

void filling_all_cells (ArrayData* the_table);
void print_all_cells (ArrayData* the_table);

void print_one_element (ArrayData* the_table);
void change_one_element (ArrayData* the_table);

void free_place (ArrayData* the_table);

int main ()
{
    ArrayData the_table = {};

    bool right_enter = true;

    enter_amount_of_rows(&the_table, &right_enter);
    if (right_enter == false)
        printf("there is problem with capacity\n");

    finding_capacity(&the_table, &right_enter);
    if (right_enter == false)
        printf("there is problem with capacity\n");

    filling_all_cells (&the_table);

    print_all_cells (&the_table);

    change_one_element (&the_table);
    print_one_element (&the_table);

    free_place (&the_table);

    return 0;
}

void enter_amount_of_rows(ArrayData* the_table, bool *const right_enter)
{
    assert (the_table != nullptr);
    assert (right_enter != nullptr);

    printf("how much rows do you want to have\n");
    scanf("%d", &the_table->rows);

    the_table->addresses = (int*)calloc(the_table->rows, sizeof(int));

    if (&the_table->result == nullptr)
    {
        *right_enter = false;
    }
}

void finding_capacity(ArrayData* the_table, bool *const right_enter)
{
    assert(the_table != nullptr);
    
    int capacity_delta = 0;

    for (int i = 1; i <= the_table->rows; i++)                    //calculation starts at 1 for users convenience
    {
        the_table->addresses = *(&the_table->result + the_table->capacity);     //fills addresses by addresses of new rows

        printf("how much cells do you want to have in the %d row?\n", i);

        scanf("%d", &capacity_delta);
        the_table->capacity += capacity_delta;                   //data about amount of cells
    }

    the_table->result = (int*)calloc(the_table->capacity, sizeof(int));
    if (&the_table->result == nullptr)
    {
        *right_enter = false;
    }
}

void filling_all_cells (ArrayData* the_table)
{
    assert(the_table != nullptr);

    printf("print values in cells one by one\n");
    for (int i = 0; i < the_table->capacity; i++)
    {
        scanf("%d", &(the_table->result) + i);     //address addition
    }
}

void print_all_cells (ArrayData* the_table)
{
    assert(the_table != nullptr);

    printf("you have printed it:\n");
    for (int i = 0; i < the_table->capacity; i++)
    {
        printf("%d\n", *(&(the_table->result) + i));     //address addition
    }
}

void print_one_element (ArrayData* the_table)
{
    assert (the_table != nullptr);

    printf("print row and col of cell you want to know");

    size_t row = 0, col = 0;
    scanf("%d", &row);
    scanf("%d", &col);

    printf("here it is\n");
    printf("%d\n", (&the_table->addresses)[row][col]);   
}

void change_one_element (ArrayData* the_table)
{
    assert (the_table != nullptr);

    printf("what element do you want to change? first enter row and after it - col\n");

    size_t row = 0, col = 0;
    scanf("%d", &row);
    scanf("%d", &col);

    printf("print its value\n");

    scanf("%d", (&the_table->addresses)[row-1][col-1]);   
}
void free_place (ArrayData* the_table)
{
    assert(the_table != nullptr);
    
    free(the_table->addresses);
    free(the_table->result);
    printf("place is free\n");
}