#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct ArrayData
{
    int rows;
    int capacity;

    int* result;
    int* amount_of_elements_in_row;
    int** addresses;
};

void enter_amount_of_rows(ArrayData* the_table, bool *const right_enter);

void finding_capacity(ArrayData* the_table, bool *const right_enter);

void filling_all_cells (ArrayData* the_table);
void print_all_cells (ArrayData* the_table);

void print_one_element (ArrayData* the_table);
void change_one_element (ArrayData* the_table);

void free_place (ArrayData* the_table);

//int* finding_address_of_the_cell (ArrayData* the_table) ;

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
    print_all_cells (&the_table);
    print_one_element (&the_table);

    free_place (&the_table);

    return 0;
}

void enter_amount_of_rows(ArrayData* the_table, bool *const right_enter)
{
    assert (the_table != nullptr);
    assert (right_enter != nullptr);

    printf("how much rows do you want to have\n");
    scanf("%d", &the_table->rows);                                    //first make variate and then fill the struct

    the_table->amount_of_elements_in_row = (int*)calloc(the_table->rows, sizeof(int));
    if (&the_table->amount_of_elements_in_row == nullptr)
        *right_enter = false;

    the_table->addresses = (int**)calloc(the_table->rows, sizeof(int*));
    if (&the_table->addresses == nullptr)
        *right_enter = false;
}

void finding_capacity(ArrayData* the_table, bool *const right_enter)
{
    assert(the_table != nullptr);
    
    for (int i = 1; i <= the_table->rows; i++)                    //calculation starts at 1 for users convenience
    {
        printf("how much cells do you want to have in the %d row?\n", i);

        int capacity_delta = 0;

        scanf("%d", &capacity_delta);

        the_table->amount_of_elements_in_row[i-1] = capacity_delta;

        //printf("elements in row %d %d\n", i-1, the_table->amount_of_elements_in_row[i-1]);

        the_table->capacity += capacity_delta;                   //data about amount of cells
    }

    //printf ("capacity %d", the_table->capacity);

    the_table->result = (int*)calloc(the_table->capacity, sizeof(int));
    if (&the_table->result == nullptr)
    {
        *right_enter = false;
    }

    int address_ind = 0;
    int cnt_of_elements = 1;       //calculation starts with 1 for convenience
    int elements_ind = 0;          

    for (int result_ind = 0; result_ind < the_table->capacity; result_ind++)
    {
        //printf("address of element of result %p\n", &(the_table->result[result_ind]));

        //printf ("cnt of elements %d, amount_of_el_in_row %d\n", cnt_of_elements, the_table->amount_of_elements_in_row[elements_ind]);
        if (cnt_of_elements == the_table->amount_of_elements_in_row[elements_ind])
        {
            the_table->addresses[address_ind] = &(the_table->result[result_ind - cnt_of_elements + 1]);

            //printf("element of address %p\n", the_table->addresses[address_ind]);

            cnt_of_elements = 1;
            elements_ind++;
            address_ind++;
        } 
        else
            cnt_of_elements++;
    }
}

void filling_all_cells (ArrayData* the_table)
{
    assert(the_table != nullptr);

    printf("print values in cells one by one\n");
    for (int i = 0; i < the_table->capacity; i++)
    {
        int* cell_address = the_table->result + i;

        scanf("%d", cell_address);     //address addition
    }
}

void print_all_cells (ArrayData* the_table)
{
    assert(the_table != nullptr);

    int y = 0;

    printf("you have printed this:\n");

    for (int i = 0; i < the_table->capacity; i++)
    {   
        int* cell_address = the_table->result + i; 

        if (cell_address == the_table->addresses[y])
        {
            printf("\n");
            y++;
        }
        printf("%d ", *cell_address);
    }
    printf("\n");
}

void print_one_element (ArrayData* the_table)
{
    assert (the_table != nullptr);

    printf("print row and col of cell you want to know?\n");

    size_t row = 0, col = 0;

    printf("here\n");
    scanf("%d", &row);
    scanf("%d", &col);

    printf("row %d, col %d\n", row, col);

    printf("here it is\n");

    printf("%d\n", *(*(the_table->addresses + row - 1)+ col - 1));   
}

void change_one_element (ArrayData* the_table)
{
    assert (the_table != nullptr);
    
    printf("here\n");

    printf("what element do you want to change? first enter row and after it - col\n");

    int row = 0, col = 0;
    scanf("%d", &row);
    scanf("%d", &col);
    printf("row %d, col %d\n", row, col);
    

    printf("print its value\n");
    scanf("%d", *(the_table->addresses + row - 1)+ col - 1); 
}

void free_place (ArrayData* the_table)
{
    assert(the_table != nullptr);
    
    free(the_table->amount_of_elements_in_row);
    free(the_table->result);
    free(the_table->addresses);
    printf("place is free\n");
}

