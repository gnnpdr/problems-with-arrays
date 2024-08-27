#include <stdio.h>

int printmas (int intmas[][4], size_t amount_of_rows, size_t amount_of_elements_in_row);

int main ()
{
    int array [3][4]={
                          {10, 9, 98, 65},
                          {8 ,-9, -4,  6},
                          {15, 6, 78, -8}
                         };

    const size_t amount_of_rows = (sizeof(array)/sizeof(array[0]));
    const size_t amount_of_eliments_in_row  = sizeof(array[0])/sizeof(array[0][0]); 

    printmas(array, amount_of_rows, amount_of_eliments_in_row);
}

int printmas (int intmas[][4], size_t amount_of_rows, size_t amount_of_elements_in_row)
{
   for(size_t row = 0; row < amount_of_rows; row++)  
   {
     for(size_t element_in_row = 0; element_in_row < amount_of_elements_in_row; element_in_row++) 
       {
         printf("%d ", intmas[row][element_in_row]);
       }
     printf("\n"); 
   } 
}