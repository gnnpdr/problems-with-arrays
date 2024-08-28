#include <stdio.h>


enum ResultOfFindingPlace
{
    ERROR,
    OK,
};

struct ArrayData
{
    int rows;
    int* result;
    int* addresses;
    int capacity;
};

int main ()
{
    ArrayData the_table = {};

    enter_amount_of_rows(&the_table);
}

ResultOfFindingPlace enter_amount_of_rows(ArrayData* the_table)
{
    assert (the_table != nullptr);

    printf("how much rows do you want to have\n");
    scanf("%d", &the_table->rows);

    the_table->addresses = (int*)calloc(*rows, sizeof(int));
    if (&the_table->result == nullptr)
    {
        printf("there is no place\n");
        return ERROR;
    }
}

ResultOfFindingPlace finding_capacity(ArrayData* the_table)
{
    int capacity_delta = 0;

    for (int i = 1; i <= the_table->rows; i++)  //calculation starts at 1 for users convenience
    {
        the_table->addresses = &the_table->result + capacity;     //fills by addresses of new row

        printf("how much cells do you want to have in the %d row?\n", &i);

        scanf("%d", &capacity_delta);
        the_table->capacity += capacity_delta;
    }

    the_table->result = (int*)calloc(*capacity, sizeof(int));
    if (&the_table->result == nullptr)
    {
        printf("there is no place\n");
        return ERROR;
    }
}

void filling_cells (ArrayData* the_table)
{
    printf("print values ​​in cells one by one\n");
    for (int i = 0; i < )
    csanf("%d", )
}