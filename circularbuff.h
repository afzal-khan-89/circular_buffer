#ifndef  _circular_buf_h_
#define  _circular_buf_h_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct {
	int front;
	int back ;
	int size ;
	uint8_t ** buffer;
	int (*push)(uint8_t *, void *);
	int (*pop)(uint8_t **, void *);
} circular_buffer  ;

extern int initialize_circular_buffer(int size, circular_buffer * c_buff);



#endif 
