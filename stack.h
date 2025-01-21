
/*******************************************************************************************************
* NAME: stack.h                                                                    
*                                                                                                       
* PURPOSE: This file defines the function prototypes for a stack implementation                                                                       
*                                                                                                       
* GLOBAL VARIABLES: None                                                                                
*                                                                                                       
*                                                                                                       
* DEVELOPMENT HISTORY:                                                                                  
*                                                                                                       
* Date          Author          Change Id       Release         Description Of Change                   
* ----------    --------------- ---------       -------         -----------------------------------     
* 14-01-2025    Tiago Rodrigues                       1         File preparation     
* 14-01-2025    Tiago Rodrigues                       1         Added prototype functions  
* 21-01-2025    Tiago Rodrigues                       1         Commmented function preambles 
*                                                                                                       
*******************************************************************************************************/
#ifndef STACK_H
#define STACK_H

/* 0 copyright/licensing */
/*******************************************************************************************************
*
* 2025 Tiago Filipe Rodrigues tiagorodrigues1590@hotmail.com
*
********************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif


/* 1 includes */
/*****************************************************/
#include <stdint.h>

/*****************************************************/

/* 2 defines */
/*****************************************************/

/*****************************************************/

/* 3 external declarations */
/*****************************************************/

/*****************************************************/

/* 4 typedefs */
/*****************************************************/

/*****************************************************/

/* 5 global variable declarations */
/*****************************************************/

/*****************************************************/


/* 6 function prototypes */
/*****************************************************/


/******************************************************************
*
* FUNCTION NAME: create_stack       
*
*
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
*
*****************************************************************/
void create_stack(void** id_of_stack, uint64_t size_of_datatype);           // send the size of values;



/******************************************************************
*
* FUNCTION NAME: check_stack_top       
*
*
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
void* check_stack_top(void* id_of_stack);

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
* id_of_stack   void*	        I	pointer to the memory position of the stack to pop from
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void stack_pop(void* id_of_stack);


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
* id_of_stack   void*	        I	pointer to the memory position of the stack to push to
* data_to_push  void*	        I	pointer to the memory position of the data to push into the stack
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void stack_push(void* id_of_stack, void* data_to_push);


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
* id_of_stack   void*	        I	pointer to the memory position of the stack to check
*
*
* RETURNS: uint8_t
*
*
*
*****************************************************************/
uint8_t check_stack_is_empty(void* id_of_stack);



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
* id_of_stack   void*	        I	pointer to the memory position of the stack to check
*
*
* RETURNS: uint64_t (size of the stack)
*
*
*
*****************************************************************/
uint64_t check_stack_size(void* id_of_stack);



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
* id_of_stack   void*	        I	pointer to the memory position of the stack to free
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_stack(void* id_of_stack);



#ifdef __cplusplus
}
#endif


#endif

