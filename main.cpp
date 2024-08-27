#include <stdio.h>

int printmas (int* intmas, size_t amount_of_str, size_t amount_of_elements_in_str); 

int main ()
{
	int ar[][3] = 
        {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
        };

    const size_t amount_of_str = (sizeof(ar)/sizeof(ar[0]));
    const size_t amount_of_eliments_in_str  = sizeof(ar[0])/sizeof(ar[0][0]); 

    printmas(*ar, amount_of_str, amount_of_eliments_in_str);      
}

int printmas (int* intmas, size_t amount_of_str, size_t amount_of_elements_in_str) 
{
   for(size_t str = 0; str < amount_of_str; str++)  
   {
        for(size_t el = 0; el < amount_of_elements_in_str; el++) 
        {
            if (el < str)
            {
                printf("%d ", *(intmas + str*amount_of_elements_in_str + el));
            }
        }
        printf("\n");
   } 
}