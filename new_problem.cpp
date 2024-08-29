#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void enter_amount_of_rows(int* rows);
void creating_arrays_using_rows(int** amount_of_elements_in_row, int*** addresses, bool *const right_enter, int rows);

void filling_array_of_amount_of_element_and_finding_capacity(int* amount_of_elements_in_row, int rows, int* capacity);
void creating_of_main_array(int** result, int capacity, bool *const right_enter);
void filling_array_of_addresses(int capacity, int* amount_of_elements_in_row, int* result, int** addresses);

void filling_all_cells (int capacity, int* result);
void print_all_cells (int capacity, int* result, int** addresses);

int* find_address_of_element(int** addresses);
void change_one_element (int** addresses);
void print_one_element (int** addresses);

void free_place (int* amount_of_elements_in_row, int* result, int** addresses);


int main ()
{
    int rows = 0;
    int capacity = 0;

    int* result = {};
    int* amount_of_elements_in_row = {};
    int** addresses = {};

    bool right_enter = true;

    enter_amount_of_rows(&rows);

    creating_arrays_using_rows(&amount_of_elements_in_row, &addresses, &right_enter, rows);
    if (right_enter == false)
        printf("there is problem with capacity\n");

    filling_array_of_amount_of_element_and_finding_capacity(amount_of_elements_in_row, rows, &capacity);

    creating_of_main_array(&result, capacity, &right_enter);
    if (right_enter == false)
        printf("there is problem with capacity\n");


    filling_array_of_addresses(capacity, amount_of_elements_in_row, result, addresses);

    filling_all_cells (capacity, result);

    print_all_cells (capacity, result, addresses);

    change_one_element (addresses);
    print_all_cells (capacity, result, addresses);
    print_one_element (addresses);

    free_place (amount_of_elements_in_row, result, addresses);

    return 0;
}



void enter_amount_of_rows(int* rows)
{
    printf("how much rows do you want to have\n");
    scanf("%d", rows);                           
}
    
void creating_arrays_using_rows(int** amount_of_elements_in_row, int*** addresses, bool *const right_enter, int rows)
{
    *amount_of_elements_in_row = (int*)calloc(rows, sizeof(int));
    if (*amount_of_elements_in_row == nullptr)
        *right_enter = false;

    *addresses = (int**)calloc(rows, sizeof(int*));
    if (*addresses == nullptr)
        *right_enter = false;

    printf("start of am_of_el %p, start of addresses %p\n", amount_of_elements_in_row, addresses);
}


void filling_array_of_amount_of_element_and_finding_capacity(int* amount_of_elements_in_row, int rows, int* capacity)
{
    //printf("start of am_of_el %p\n", &amount_of_elements_in_row);

    for (int i = 1; i <= rows; i++)                    //calculation starts at 1 for users convenience
    {
        printf("how much cells do you want to have in the %d row?\n", i);

        int capacity_delta = 0;

        scanf("%d", &capacity_delta);

        amount_of_elements_in_row[i-1] = capacity_delta;

        *capacity += capacity_delta;            
    }
}

void creating_of_main_array(int** result, int capacity, bool *const right_enter) 
{
    printf("here\n");
    *result = (int*)calloc(capacity, sizeof(int));

    if (*result == nullptr)
    {
        *right_enter = false;
    }
}


void filling_array_of_addresses(int capacity, int* amount_of_elements_in_row, int* result, int** addresses)
{
    int address_index = 0;
    int cnt_of_elements = 1;       //calculation starts with 1 for convenience
    int elements_index = 0;          

    for (int result_index = 0; result_index < capacity; result_index++)
    {
        if (cnt_of_elements == amount_of_elements_in_row[elements_index])
        {
            addresses[address_index] = &(result[result_index - cnt_of_elements + 1]);

            cnt_of_elements = 1;
            elements_index++;
            address_index++;
        } 
        else
            cnt_of_elements++;
    }
}


void filling_all_cells (int capacity, int* result)
{
    printf("print values in cells one by one\n");
    for (int i = 0; i < capacity; i++)
    {
        int* cell_address = result + i;

        scanf("%d", cell_address);     //address addition
    }
}

void print_all_cells (int capacity, int* result, int** addresses)
{
    int addresses_index = 0;

    printf("you have printed this:\n");

    for (int i = 0; i < capacity; i++)
    {   
        int* cell_address = result + i; 

        if (cell_address == addresses[addresses_index])
        {
            printf("\n");
            addresses_index++;
        }
        printf("%d ", *cell_address);
    }
    printf("\n");
}

int* find_address_of_element(int** addresses)
{
    int row = 0, col = 0;

    scanf("%d", &row);
    scanf("%d", &col);
    return *(addresses + row - 1)+ col - 1;

}

void print_one_element (int** addresses)
{
    printf("print row and col of cell you want to know?\n");

    int* cell_address = find_address_of_element(addresses);

    printf("%d\n", *(cell_address));   
}

void change_one_element (int** addresses)
{
    printf("what element do you want to change? first enter row and after it - col\n");

    int* cell_address = find_address_of_element(addresses);

    printf("print its value\n");

    scanf("%d", cell_address); 
}

void free_place (int* amount_of_elements_in_row, int* result, int** addresses)
{
    
    free(amount_of_elements_in_row);
    free(result);
    free(addresses);
    printf("place is free\n");
}

