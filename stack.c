/*******************************************************************************************************************
* FILE NAME: stack.c
*                                                                                                               
* PURPOSE: 
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
*   
* 
*    
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:                                                  
*             
*                                                                                                  
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:                                                                       
*                                
* 
* 
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
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* 
*
* RETURNS: void
*
*
*
*****************************************************************/
void create_stack(void** id_of_stack, uint64_t size_of_datatype)                 
{

        (*id_of_stack) = malloc(1*sizeof(struct stack));
        if(*id_of_stack == NULL)
        {
                fprintf(stderr, "Memory allocation failed\n");
        }


        ((struct stack*)(*id_of_stack))->stack_size_allocated = 3;
        ((struct stack*)(*id_of_stack))->stack_size = 0;
        ((struct stack*)(*id_of_stack))->datatype_size = size_of_datatype;
        
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
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* 
*
* RETURNS: void*
*
*
*
*****************************************************************/
void* check_stack_top(void* id_of_stack)
{

        if(((struct stack*)id_of_stack)->stack_size == 0)                       
                return NULL;

        return (void *) &((uint8_t*)(((struct stack*)id_of_stack)->stack_data))[(((struct stack*)id_of_stack)->stack_size-1)*((struct stack*)id_of_stack)->datatype_size];               //increment the right amount of bytes, then convert back to void
}



/******************************************************************
*
* FUNCTION NAME: stack_pop       
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* 
*
* RETURNS: void
*
*
*
*****************************************************************/
void stack_pop(void* id_of_stack)
{
        if(((struct stack*)id_of_stack)->stack_size > 0)
                ((struct stack*)id_of_stack)->stack_size--;
        return;
}




/******************************************************************
*
* FUNCTION NAME: stack_push        
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* 
*
* RETURNS: void
*
*
*
*****************************************************************/
void stack_push(void* id_of_stack, void* data_to_push)
{

        ((struct stack*)id_of_stack)->stack_size++;

        if(((struct stack*)id_of_stack)->stack_size > ((struct stack*)id_of_stack)->stack_size_allocated)
        {
                printf("hello! \n");
                void* stack_aux = realloc(((struct stack*)id_of_stack)->stack_data, (((struct stack*)id_of_stack)->stack_size_allocated + ((struct stack*)id_of_stack)->stack_size_allocated)*((struct stack*)id_of_stack)->datatype_size);            // increments by 10;
                ((struct stack*)id_of_stack)->stack_size_allocated <<= 1; 
                if(stack_aux == NULL)
                {
                        fprintf(stderr, "Memory allocation failed\n");
                }
                ((struct stack*)id_of_stack)->stack_data = stack_aux;
        }

        memcpy((void *) &((uint8_t*)(((struct stack*)id_of_stack)->stack_data))[((((struct stack*)id_of_stack)->stack_size)-1)*(((struct stack*)id_of_stack)->datatype_size)], data_to_push, ((struct stack*)id_of_stack)->datatype_size);

        return ;
}





/******************************************************************
*
* FUNCTION NAME: check_stack_is_empty
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* 
*
* RETURNS: uint8_t, as 0 or 1 
*
*
*
*****************************************************************/
uint8_t check_stack_is_empty(void* id_of_stack)
{

        if(((struct stack*)id_of_stack)->stack_size == 0)
                return 1;
        else
                return 0;
}


/******************************************************************
*
* FUNCTION NAME: check_stack_size
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* 
*
* RETURNS: uint64_t, size of the stack
*
*
*
*****************************************************************/
uint64_t check_stack_size(void* id_of_stack)
{
        return ((struct stack*)id_of_stack)->stack_size;
}


/******************************************************************
*
* FUNCTION NAME: free_stack
*
*
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* 
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_stack(void* id_of_stack)
{
        free(((struct stack*)id_of_stack)->stack_data);
        free(id_of_stack);
        return ;
}