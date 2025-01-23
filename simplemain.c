

#include "stack.h"
#include <stdio.h>


void single_stack_simple_test()
{

        void *stack1 = NULL;

        create_stack(&stack1, sizeof(uint16_t),0);
        printf("%u\n",check_stack_is_empty(stack1));


        uint16_t data_test = 3;
        stack_push(stack1,(void*) &data_test);

        data_test = 20;
        stack_push(stack1,(void*) &data_test);
        
        data_test = 30;
        stack_push(stack1,(void*) &data_test);
        

        printf("%u\n", *((uint16_t*)check_stack_top(stack1)));
        stack_pop(stack1);

        printf("%u\n", *((uint16_t*)check_stack_top(stack1)));
        stack_pop(stack1);

        printf("%u\n", *((uint16_t*)check_stack_top(stack1)));


        printf("%lu\n",check_stack_size(stack1));

        free_stack(stack1);

        return ;
}


void single_stack_simple_test_2()
{

        void *stack1 = NULL;

        create_stack(&stack1, sizeof(uint16_t),0);


        uint16_t data_test = 3;
        stack_push(stack1,(void*) &data_test);

        free_stack(stack1);

        return ;
}






void two_stacks_simple_test()
{

        void *stack1 = NULL;
        void *stack2 = NULL;


        create_stack(&stack1, sizeof(uint16_t),0);
        create_stack(&stack2, sizeof(uint16_t),0);


        printf("%u\n",check_stack_is_empty(stack1));


        uint16_t data_test = 3;
        stack_push(stack1,(void*) &data_test);

        data_test = 20;
        stack_push(stack1,(void*) &data_test);
        
        data_test = 30;
        stack_push(stack2,(void*) &data_test);
        

        printf("%u\n", *((uint16_t*)check_stack_top(stack1)));
        stack_pop(stack1);

        printf("%u\n", *((uint16_t*)check_stack_top(stack1)));
        stack_pop(stack1);

        printf("%u\n", *((uint16_t*)check_stack_top(stack2)));


        printf("%lu\n",check_stack_size(stack1));

        free_stack(stack1);

        free_stack(stack2);

        return;
}



int main()
{
        single_stack_simple_test();
        
        //single_stack_simple_test_2();

        return 0;  
}