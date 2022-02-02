#ifndef STACK_H_
#define STACK_H_
#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
struct stack
{
   TArbre data;
   int isLeft;
   struct stack *ptr;
};

typedef struct stack Stack;
typedef Stack *stackPtr;

void push(stackPtr *top, TArbre c, int isLeft); //for pushing value in stack
TArbre pop(stackPtr *top); //for popping value out of stack
int checkEmpty(stackPtr top); //checking whether stack is empty
#endif