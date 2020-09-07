/*
 * stack.h
 *
 *  Created on: Sep 4, 2020
 *      Author: sohel
 */

#ifndef STACK_H_
#define STACK_H_

#define _STACKSIZE 10
#define _STACKOVERFLOW -1
#define _STACKUNDERFLOW -2
#define _NOERROR 0

int push(double param);
int pop(double *poppedVal);
int getCurrentStackSize();
const double *getStack(int *stackSize);

#endif /* STACK_H_ */
