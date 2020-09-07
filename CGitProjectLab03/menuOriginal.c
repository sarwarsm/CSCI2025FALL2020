/*
 * menuOriginal.c
 *
 *  Created on: Sep 4, 2020
 *      Author: sohel
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

#define MIN_NUM_OF_OPERANDS 2

int menuOriginal(){
	char task[51] = {0x00};
	char *ptr;
	double val;

	while(true){
		printf("\nEnter a number or an operator (or e to end): ");
		task[0] = 0x00;
		scanf("%[^\n]", task);
		scanf("%*c");

		if(!strcmp(task,"e")  || !strcmp(task,"E")){
			break;
		}
		else if(!strcmp(task,"p")  || !strcmp(task,"P")){
			int size;
			const double *temp = getStack(&size);
			for(int ndx = 0; ndx < size; ndx++){
				printf("\nThe stack value at ndx = %d is %.2f",ndx, temp[ndx]);
			}
		}
		else if(!strcmp(task,"+")){
			if((getCurrentStackSize() >= MIN_NUM_OF_OPERANDS) /*&& (stack[stackNdx] != 0)*/){
				double op1, op2, result;
				pop(&op2);
				pop(&op1);

				result = op1 + op2;
				push(result);
			}
			else{
				printf("Not enough operands available\n");
			}
		}
		else if(!strcmp(task,"-")){
			if((getCurrentStackSize() >= MIN_NUM_OF_OPERANDS) /*&& (stack[stackNdx] != 0)*/){
				double op1, op2, result;
				pop(&op2);
				pop(&op1);

				result = op1 - op2;
				push(result);
			}
			else{
				printf("Not enough operands available\n");
			}
		}
		else if(!strcmp(task,"*")){
			if((getCurrentStackSize() >= MIN_NUM_OF_OPERANDS) /*&& (stack[stackNdx] != 0)*/){
				double op1, op2, result;
				pop(&op2);
				pop(&op1);

				result = op1 * op2;
				push(result);
			}
			else{
				printf("Not enough operands available\n");
			}
		}
		else if(!strcmp(task,"/")){
			if((getCurrentStackSize() >= MIN_NUM_OF_OPERANDS) /*&& (stack[stackNdx] != 0)*/){
				double op1, op2, result;
				pop(&op2);
				pop(&op1);

				result = op1 / op2;
				push(result);
			}
		}
		else if((val = strtod(task, &ptr)) != 0){
			if(push(val) == _NOERROR){
				printf("value = %f",val);
			}
			else{
				printf("Stack size overflow!");
			}
		}
		else{
			printf("Command not supported.\n");
		}
	}

	printf("Goodbye!\n");

	return 0;
}

