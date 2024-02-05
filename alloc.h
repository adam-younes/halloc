#ifndef ALLOC_H
#define ALLOC_H

#define __word 8
#define __heap_size 2e20

uint8_t heap[__heap_size];
void *__heap_break;

typedef struct memblock {
	memblock *next;
	memblock *prev;
	size_t size;
	bool used;
	void *start;
} memblock;

void *halloc(size_t size);

int hfree(void *ptr);

// initializes heap metadata.
void __initialize_heap() {
	__heap_break = heap;
}

#endif

