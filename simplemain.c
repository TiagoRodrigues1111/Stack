

#include "stack.h"
#include <stdio.h>


int main()
{
        uint16_t data_test = 3;       
        
        create_stack();
        
        printf("%u\n",check_stack_is_empty());

        stack_push((void*) &data_test);
        data_test = 2000;
        stack_push((void*) &data_test);
        stack_push((void*) &data_test);
        

        printf("%u\n", *((uint16_t*)check_stack_top()));
        stack_pop();
        printf("%u\n", *((uint16_t*)check_stack_top()));
        stack_pop();
        printf("%u\n", *((uint16_t*)check_stack_top()));

        stack_push((void*) &data_test);
        printf("%u\n",check_stack_size());

        free_stack();

        return 0;  
}