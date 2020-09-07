/*
 * menuIfElse.c
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

static void readInput(char *command);
static void displayStack();
static void add();
static void subtract();
static void multiply();
static void divide();
static void pushToStack(double val);

int menuIfElse(){
	char command[51] = {0x00};
	char *ptr;
	double val;

	while(true){

		readInput(command);

		if(!strcmp(command,"e")  || !strcmp(command,"E")){
			break;
		}
		else if(!strcmp(command,"p")  || !strcmp(command,"P")){
			displayStack();
		}
		else if(!strcmp(command,"+")){
			add();
		}
		else if(!strcmp(command,"-")){
			subtract();
		}
		else if(!strcmp(command,"*")){
			multiply();
		}
		else if(!strcmp(command,"/")){
			divide();
		}
		else if((val = strtod(command, &ptr)) != 0){
			pushToStack(val);
		}
		else{
			printf("Command not supported.\n");
		}
	}

	printf("Goodbye!\n");

	return 0;
}

void readInput(char *command){
	printf("\nEnter a number or an operator (or e to end): ");
	command[0] = 0x00;
	scanf("%[^\n]", command);
	scanf("%*c");
}

void displayStack(){
	int size;
	const double *temp = getStack(&size);
	for(int ndx = 0; ndx < size; ndx++){
		printf("\nThe stack value at ndx = %d is %.2f",ndx, temp[ndx]);
	}

}

void add(){
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

void subtract(){
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

void multiply(){
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

void divide(){
	if((getCurrentStackSize() >= MIN_NUM_OF_OPERANDS) /*&& (stack[stackNdx] != 0)*/){
		double op1, op2, result;
		pop(&op2);
		pop(&op1);

		result = op1 / op2;
		push(result);
	}
	else{
		printf("Not enough operands available\n");
	}

}

void pushToStack(double val){
	if(push(val) == _NOERROR){
		printf("value = %f",val);
	}
	else{
		printf("Stack size overflow!");
	}
}
