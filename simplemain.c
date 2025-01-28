

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

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


/* High memory usage test */
void stack_stress_test1()
{
        void *stack1=NULL;
        uint16_t data1 =0; 

        create_stack(&stack1,sizeof(uint16_t),100);

        uint64_t n = 400000000;
        
        while(0 < n)
        {
                
                if(NULL != check_stack_top(stack1))
                {
                        // printf("%lu",*((uint16_t*)check_stack_top(stack1)));
                }

                data1++;
                stack_push(stack1, (void*) &data1);
                n--;



        }
        while(!check_stack_is_empty(stack1))
        {
                stack_pop(stack1);
                // printf("%lu",check_stack_size(stack1));


        }

        free_stack(stack1);

}

/* High CPU usage test */
void stack_stress_test2()
{
        void *stack1=NULL;
        void *stack2=NULL;
        uint16_t data1 =0;
        uint16_t data2 =0; 

        create_stack(&stack1,sizeof(uint16_t),5);
        create_stack(&stack2,sizeof(uint16_t),5);

        uint64_t n = 4000000000;
        
        while(0 < n)
        {
                stack_pop(stack1);
                stack_pop(stack2);
                data1++;
                data2++;
                stack_push(stack1, (void*) &data1);
                stack_push(stack2, (void*) &data2);
                n--;        
        }
        while(!check_stack_is_empty(stack1))
        {
                stack_pop(stack1);
                // printf("%lu",check_stack_size(stack1));
        }

        free_stack(stack1);
        free_stack(stack2);

}

/* Array of stacks test */
void stack_stress_test3()
{
        void **stacks=NULL;
        
        uint64_t num_of_stacks = 20000;
        stacks = (void **) malloc(num_of_stacks* sizeof(void *));
        if(stacks == NULL)
                return ;

        uint16_t data1=20;

        for(uint64_t i=0;i<num_of_stacks;i++)
        {
                create_stack(&(stacks[i]),sizeof(uint16_t),2);
                
                stack_push(stacks[i], (void*) &data1);
                stack_push(stacks[i], (void*) &data1);
        }

        for(uint64_t i=0;i<num_of_stacks;i++)
        {

                while(!check_stack_is_empty(stacks[i]))
                {
                if(NULL != check_stack_top(stacks[i]))
                {
                        printf("%lu ",*((uint16_t*)check_stack_top(stacks[i])));
                }

                stack_pop(stacks[i]);
                
                // printf("%lu",check_stack_size(stack1));
                }
        }

        for(uint64_t i=0;i<num_of_stacks;i++)
        {
                free_stack(stacks[i]);
        }        
        
}




int main()
{
        // single_stack_simple_test();
        
        //single_stack_simple_test_2();

        // stack_stress_test1();
        //stack_stress_test2();

        stack_stress_test3();

        return 0;  
}