#include "stack.h"

void push( stackPtr *top, TArbre x, int isLeft )
{
    stackPtr nodePtr;

    //allocating memory
    nodePtr = malloc(sizeof(Stack));

    //pushing value at the top of stack only if there is space
    if(nodePtr != NULL)
    {
        nodePtr->isLeft = isLeft;
        nodePtr -> data = x;
        nodePtr -> ptr = *top;
        *top = nodePtr;
    }

    else
       printf("\nERROR !!! (Not enough space)");
   }

TArbre pop(stackPtr *top)
{
   TArbre pValue; //variable for value at the top
   stackPtr tempPtr; //temporary pointer

   tempPtr = *top;
   pValue = (*top) -> data;
   *top = (*top) -> ptr;
   free(tempPtr); //free temporary pointer value
   return pValue;
}

int checkEmpty(stackPtr top)
{
   return top == NULL;
}