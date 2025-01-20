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
void *stack = NULL;
uint64_t stack_size = 0;

uint64_t stack_size_allocated = 0;                      // num_of_bytes
uint64_t datatype_size = 0;                             // num_of_bytes


/*****************************************************/


/* 6 function prototypes */
/*****************************************************/

// void datatype_definition(uint64_t bytes);


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
void create_stack(uint64_t size_of_datatype)           // send the size of values;
{
        stack_size_allocated = 10;                      //allocate 10 elements
        stack = (void*) malloc(10*size_of_datatype);
        stack_size = 0;
        datatype_size = size_of_datatype;
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
void* check_stack_top()
{
        if(stack_size == 0)                       
                return NULL;

        return (void *) &((uint8_t*)stack)[(stack_size-1)*datatype_size];               //increment the right amount of bytes, then convert back to void
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
void stack_pop()
{
                        // delete the data? for security?
        if(stack_size > 0)
                stack_size--;
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
void stack_push(void* data_to_push)
{

        stack_size++;

        if(stack_size >= (stack_size_allocated / datatype_size))
        {
                void* stack_aux = realloc(stack,stack_size_allocated + stack_size_allocated);            // increments by 10;
                stack_size_allocated <<= 1; 
                if(stack_aux == NULL)
                {
                        fprintf(stderr, "Memory allocation failed\n");
                }
                stack = stack_aux;
        }

        memcpy((void *) &((uint8_t*)stack)[(stack_size-1)*datatype_size], data_to_push, datatype_size);

        return;
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
uint8_t check_stack_is_empty()
{
        if(stack_size == 0)
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
uint64_t check_stack_size()
{
        return stack_size;
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
void free_stack()
{
        free(stack);
        return ;
}