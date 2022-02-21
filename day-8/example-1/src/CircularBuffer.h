/*
 * CircularBuffer.h
 *
 *  Created on: Feb 15, 2022
 *      Author: sgojkovic
 */

#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_LENGHT 10
#define TYPE int

typedef struct circular_buffer {
	TYPE* buffer;
	TYPE* head;
	TYPE* tail;
	int size;
	int max_len;
}circular_buffer;

void CircularInit(circular_buffer* c_buffer);
int CircularIsFull(circular_buffer* c_buffer);
int CircularIsEmpty(circular_buffer* c_buffer);
void CircularPut(circular_buffer* c_buffer,TYPE data);
TYPE CircularGet(circular_buffer* c_buffer);
void CircularEmptyBuff(circular_buffer* c_buffer);
void CircularDump(circular_buffer* c_buffer);



#endif /* CIRCULARBUFFER_H_ */
