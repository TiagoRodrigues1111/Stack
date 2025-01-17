

#include "stack.h"
#include <stdio.h>


int main()
{
        uint8_t data_test = 3;       
        
        create_stack(sizeof(uint8_t));
        
        printf("%u\n",check_stack_is_empty());

        stack_push((void*) &data_test);
        data_test = 20;
        stack_push((void*) &data_test);
        stack_push((void*) &data_test);
        

        printf("%u\n", *((uint8_t*)check_stack_top()));
        stack_pop();
        printf("%u\n", *((uint8_t*)check_stack_top()));
        stack_pop();
        printf("%u\n", *((uint8_t*)check_stack_top()));

        stack_push((void*) &data_test);
        printf("%u\n",check_stack_size());

        free_stack();

        return 0;  
}