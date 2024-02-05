#define ALLOC
#include <stdint.h>
#include <stdio.h>
#include "alloc.h"

// heap and heap metadata
// 8-bit word alignment for 64-bit architecture.
#define __word 8

uint8_t heap[__heap_size];
void *__heap_break;

// allocates memory to the heap of size (size)
void *halloc(size_t size) {
	size = scale_and_align(size);
	assert(size < __heap_size);
	void *output = find_block(size);
	if(!output) output = request_block(size);
	
	assert(output && "Free memory not found.");

	if(output -> prev && output -> prev != output)
		output -> prev -> next = output -> next;
	else __freed = NULL;

	return output -> start;
}

// frees memory located at the location (ptr)
void hfree(void* ptr) {
	
}

// collects all garbage upon program exit
void hsweep() {

}

// returns metadata for a block of memory on the heap of size (size)
// [ (used), (size), (next), (ALLOCED...) ]
memblock *find_block(size_t size) {
	uint32_t curblock = 0;
	uint32_t cur_next = heap[curblock];
	bool used 
	size_t nearest = INT_MAX;
	while(curblock && curblock -> next) {
		int free_chunk_size =
		if(free_chunk_size > size && free_chunk_size - size < nearest - size) {
			nearest = free_chunk_size;
			output -> start = curblock -> start + curblock -> size;
			output -> next = curblock -> next;
			output -> prev = curblock;
		}
		curblock = curblock -> next;
	}

	if(!output -> start) return NULL;

	output -> used = true;
	output -> size = size;
	return output;
}

// returns metadata for a new block of memory at the end of the heap of size (size)
void *request_block(size_t size) {
	assert(__heap_break + size < __heap_size && 
					"Heap overflow when attempting to allocate memory.");

	memblock output;
	output -> start = __heap_break;
	output -> prev = __alloc_tail;
	output -> size = size;
	__heap_break += size;
	return return_val;
}

// 8 bit alignment
inline size_t scale_and_align(size_t input) {
	return ((input + __word - 1) & ~(__word - 1)) / 8;
}
