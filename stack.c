/*******************************************************************************************************************
* FILE NAME: stack.c
*                                                                                                               
* PURPOSE: This file implements the functions defined in stack.h     
*                                                                                                               
* FILE REFERENCES:                                                                                              
*                                                                                                               
* Name                          I/O                     Description                                             
* ----                          ---                     -----------                                             
* none     
                                                                                                          
* EXTERNAL VARIABLES:                                                                                           
*                                                                                        
*                                                                                                               
* Name          Type            I/O                     Description                                             
* ----          ----            ---                     -----------                                             
* none
*
*                                                                                                             
* EXTERNAL REFERENCES:                                                                                          
* Name                          Description                                                                     
* ----                          -----------
* malloc                        allocates memory space                                                          https://man7.org/linux/man-pages/man3/free.3.html
* realloc                       reallocates memory space                                                        https://man7.org/linux/man-pages/man3/realloc.3p.html
* memcpy                        copies x number of bytes from one memory position to another memory position    https://man7.org/linux/man-pages/man3/memcpy.3.html
* fprintf                       writes formatted data to a stream                                               https://man7.org/linux/man-pages/man3/fprintf.3p.html
*   
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:
*             
*                                                                                                  
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:
*  It is assumed that the stack will never have more than 2^64 elements.                               
*  It is assumed that the user will grab only 1 element size from the memory position returned from check_stack_top 
*                                                                                                               
* NOTES:                                                                                                        
*                                 
*                                       
* REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:                                                            
*
*                                                                                                               
* DEVELOPMENT HISTORY:                                                                                          
*                                                                                                               
* Date          Author                  Change Id       Release         Description Of Change                   
* ----------    ---------------         ---------       -------         ---------------------   
* 14-01-2025    Tiago Rodrigues                               1         File preparation     
* 17-01-2025    Tiago Rodrigues                               1         Initial Implementation of stack, for uint8_t   
* 20-01-2025    Tiago Rodrigues                               1         Changed operations to use memcpy   
* 21-01-2025    Tiago Rodrigues                               1         Changed some operations for edge cases, 
* ----------    ---------------         ---------       -------          and commmented function preambles   
*                                                                                                               
* ALGORITHM (PDL)
*    
*
*                                                                                                           
****************************************************************************************************************/


/* 0 copyright/licensing */
/***************************************************************************************************************/
/*
*       2025 Tiago Filipe Rodrigues tiagorodrigues1590@hotmail.com
*/
/***************************************************************************************************************/


/* 1 includes */
/*****************************************************/

#include "stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*****************************************************/


/* 2 defines */
/*****************************************************/
#define INITIAL_ALLOC 3

/*****************************************************/


/* 3 external declarations */
/*****************************************************/

/*****************************************************/


/* 4 typedefs */
/*****************************************************/

// typedef uint8_t stack_datatype;





/*****************************************************/


/* 5 global variable declarations */
/*****************************************************/
//void *stack = NULL;
//uint64_t stack_size = 0;

// uint64_t stack_size_allocated = 0;                      // num_of_bytes
// uint64_t datatype_size = 0;                             // num_of_bytes

struct stack
{
        uint64_t stack_size;
        uint64_t stack_size_allocated;                  // num_of_elements
        uint64_t datatype_size;                         // num_of_bytes
        void *stack_data;
};


/*****************************************************/


/* 6 function prototypes */
/*****************************************************/



/*****************************************************/



/* 7 function declarations */
/*****************************************************/

/******************************************************************
*
* FUNCTION NAME: create_stack       
*
* PURPOSE: Allocates the needed memory for the stack wanted
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* id_of_stack	        void**	        I/O	pointer to the memory position of the stack to implement
* size_of_datatype      uint64_t        I       byte size of datatype to place in the stack
*
*
* RETURNS: void
*
*
*****************************************************************/
void create_stack(void** id_of_stack, uint64_t size_of_datatype)                 
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(id_of_stack == NULL)
        {
                fprintf(stderr, "Stack pointer location is null\n");
                return ;
        }
                

        // Allocation of a stack struct
        (*id_of_stack) = malloc(1*sizeof(struct stack));                       
        if(*id_of_stack == NULL)
        {
                fprintf(stderr, "Memory allocation failed\n");
        }


        ((struct stack*)(*id_of_stack))->stack_size_allocated = INITIAL_ALLOC;      // assumed that the number of elements to allocate initially is INITIAL_ALLOC (3 by default)
        ((struct stack*)(*id_of_stack))->stack_size = 0;
        ((struct stack*)(*id_of_stack))->datatype_size = size_of_datatype;
        
        // Allocate space in the stack for the array of values
        ((struct stack*)(*id_of_stack))->stack_data = (void*) malloc(((struct stack*)(*id_of_stack))->stack_size_allocated*((struct stack*)(*id_of_stack))->datatype_size);     
        if(((struct stack*)(*id_of_stack))->stack_data == NULL)
        {
                fprintf(stderr, "Memory allocation failed\n");
        }
        

        
        return ;        
}




/******************************************************************
*
* FUNCTION NAME: check_stack_top       
*
* PURPOSE: Returns the memory position of the element that is currently on the top of the stack
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_stack   void*	        I	pointer to the memory position of the stack to check
* 
*
* RETURNS: void* (pointer to the memory position of the top element of the stack)
*
*
*
*****************************************************************/
void* check_stack_top(void* id_of_stack)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(id_of_stack == NULL)
        {
                fprintf(stderr, "Stack pointer location is null\n");
                return NULL;
        }
               

        if(check_stack_is_empty(id_of_stack))                       
                return NULL;

        return (void *) &((uint8_t*)(((struct stack*)id_of_stack)->stack_data))[(((struct stack*)id_of_stack)->stack_size-1)*((struct stack*)id_of_stack)->datatype_size];               //increment the right amount of bytes, then convert back to void
}



/******************************************************************
*
* FUNCTION NAME: stack_pop       
*
* PURPOSE: Removes one position from the top of the stack
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* id_of_stack   void*	        I	pointer to the memory position of the stack to pop from
*
* NOTES: The data is not deleted, therefore it could still be accessed by an adversarial party 
*         (example, check_stack_top and increment the memory position accordingly) 
*
* RETURNS: void
*
*
*
*****************************************************************/
void stack_pop(void* id_of_stack)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(id_of_stack == NULL)
        {
                fprintf(stderr, "Stack pointer location is null\n");
                return ;
        }   
        if(!check_stack_is_empty(id_of_stack))
                ((struct stack*)id_of_stack)->stack_size--;
        return;
}




/******************************************************************
*
* FUNCTION NAME: stack_push        
*
* PURPOSE: Pushes an element to the top of the stack
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* id_of_stack   void*	        I	pointer to the memory position of the stack to push to
* data_to_push  void*	        I	pointer to the memory position of the data to push into the stack
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void stack_push(void* id_of_stack, void* data_to_push)
{
        /* LOCAL VARIABLES:
        *  Variable     Type    Description
        *  --------     ----    -----------
        *  stack_aux    void*   auxiliary pointer for the realloc operation
        */
        if(id_of_stack == NULL)
        {
                fprintf(stderr, "Stack pointer location is null\n");
                return ;
        }
                
        ((struct stack*)id_of_stack)->stack_size++;
        // reallocate memory if num of elements in stack becomes larger than the max num of elements allocated for the stack 
        if(((struct stack*)id_of_stack)->stack_size > ((struct stack*)id_of_stack)->stack_size_allocated)
        {
                // tries to allocate double the size of the current stack;
                void* stack_aux = realloc(((struct stack*)id_of_stack)->stack_data, (((struct stack*)id_of_stack)->stack_size_allocated + ((struct stack*)id_of_stack)->stack_size_allocated)*((struct stack*)id_of_stack)->datatype_size); 
                if(stack_aux == NULL)
                {
                        fprintf(stderr, "Memory allocation failed\n");
                }
                ((struct stack*)id_of_stack)->stack_data = stack_aux;
                ((struct stack*)id_of_stack)->stack_size_allocated <<= 1;
        }

        memcpy((void *) &((uint8_t*)(((struct stack*)id_of_stack)->stack_data))[((((struct stack*)id_of_stack)->stack_size)-1)*(((struct stack*)id_of_stack)->datatype_size)], data_to_push, ((struct stack*)id_of_stack)->datatype_size);

        return ;
}





/******************************************************************
*
* FUNCTION NAME: check_stack_is_empty
*
* PURPOSE: Checks if the stack is empty or not
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* id_of_stack   void*	        I	pointer to the memory position of the stack to check
*
*
* RETURNS: uint8_t (as 0 or 1)
*
*
*
*****************************************************************/
uint8_t check_stack_is_empty(void* id_of_stack)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(id_of_stack == NULL)
        {
                fprintf(stderr, "Stack pointer location is null\n");
                return 0;
        }
                
        if(((struct stack*)id_of_stack)->stack_size == 0)
                return 1;
        else
                return 0;
}


/******************************************************************
*
* FUNCTION NAME: check_stack_size
*
* PURPOSE: Will return the current element count in the stack
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* id_of_stack   void*	        I	pointer to the memory position of the stack to check
*
*
* RETURNS: uint64_t (size of the stack)
*
*
*
*****************************************************************/
uint64_t check_stack_size(void* id_of_stack)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(id_of_stack == NULL)
        {
                fprintf(stderr, "Stack pointer location is null\n");
                return 0;
        }

        return ((struct stack*)id_of_stack)->stack_size;
}


/******************************************************************
*
* FUNCTION NAME: free_stack
*
* PURPOSE: Frees the memory allocated for the stack
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* id_of_stack   void*	        I	pointer to the memory position of the stack to free
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_stack(void* id_of_stack)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(id_of_stack == NULL)
                return;

        if(((struct stack*)id_of_stack)->stack_data != NULL)
                free(((struct stack*)id_of_stack)->stack_data);
        
        free(id_of_stack);
        return ;
}