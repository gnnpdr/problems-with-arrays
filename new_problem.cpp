#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct ArrayData
{
    int rows;
    int capacity;

    int* result;
    int* amount_of_elements_in_row;
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

    enter_amount_of_rows(&the_table, &right_enter);  //addresses
    if (right_enter == false)
        printf("there is problem with capacity\n");

    finding_capacity(&the_table, &right_enter);     //result
    if (right_enter == false)
        printf("there is problem with capacity\n");

    filling_all_cells (&the_table);

    print_all_cells (&the_table);

    //change_one_element (&the_table);
    //print_one_element (&the_table);

    free_place (&the_table);

    return 0;
}

void enter_amount_of_rows(ArrayData* the_table, bool *const right_enter)
{
    assert (the_table != nullptr);
    assert (right_enter != nullptr);

    printf("how much rows do you want to have\n");
    scanf("%d", &the_table->rows);

    the_table->amount_of_elements_in_row = (int*)calloc(the_table->rows, sizeof(int));

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
        printf("how much cells do you want to have in the %d row?\n", i);

        scanf("%d", &capacity_delta);
        the_table->amount_of_elements_in_row[i-1] = capacity_delta;

        //printf("it prints %d %d\n", the_table->amount_of_elements_in_row[i-1], capacity_delta);
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
        int* cell_address = the_table->result + i;

        scanf("%d", cell_address);     //address addition
    }
}

void print_all_cells (ArrayData* the_table)
{
    assert(the_table != nullptr);

    int y = 0;
    int cnt = 0;

    printf("you have printed this:\n");

    for (int i = 0; i < the_table->capacity; i++)
    {   
        cnt++;
        int* cell_address = the_table->result + i; 

        if (cnt == the_table->amount_of_elements_in_row[y])
        {
            printf("\n");
            y++;
            cnt = 0;
        }
        
        printf("%d ", *(the_table->result + i));     //address addition
    }
}

/*void print_one_element (ArrayData* the_table)
{
    assert (the_table != nullptr);

    printf("print row and col of cell you want to know");

    size_t row = 0, col = 0;
    scanf("%d", &row);
    scanf("%d", &col);

    printf("here it is\n");
    printf("%d\n", the_table->addresses[row-1][col-1]);   
}

void change_one_element (ArrayData* the_table)
{
    assert (the_table != nullptr);

    printf("what element do you want to change? first enter row and after it - col\n");

    size_t row = 0, col = 0;
    scanf("%d", &row);
    scanf("%d", &col);

    printf("print its value\n");

    scanf("%d", the_table->addresses[row-1]+col-1);   
}*/
void free_place (ArrayData* the_table)
{
    assert(the_table != nullptr);
    
    free(the_table->amount_of_elements_in_row);
    free(the_table->result);
    printf("place is free\n");
}


// int data[2][3] = {};

// data[1][2] = *(data + 1 * sizeof( data[0]) + 2);

// int **data2 = (int **)data;

// data2[1][2] = *(*(data + 1) + 2);

// int *data3 = (int *)data;
// data[1][2] = *(data + length * 1 + 2);