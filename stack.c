/*
 * stack.c
 *
 *  Created on: Sep 4, 2020
 *      Author: sohel
 */
#include "stack.h"

static int stackIndex = -1;
static double stack[_STACKSIZE] = {0x00};

int push(double param){
	if(stackIndex < (_STACKSIZE - 1)){
		stack[++stackIndex] = param;
		return _NOERROR;
	}
	else{
		return _STACKOVERFLOW;
	}
}

int pop(double *poppedVal){
	if(stackIndex >= 0){
		double temp = stack[stackIndex];
		stack[stackIndex] = 0x00;
		stackIndex--;
		*poppedVal = temp;
		return _NOERROR;
	}
	else{
		return _STACKUNDERFLOW;
	}
}

const double *getStack(int *stackSize){
	*stackSize = stackIndex + 1;
	return (const double *)stack;
}

int getCurrentStackSize(){
	return (stackIndex + 1);
}
