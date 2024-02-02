#include "afk_c_buff.h"
#include <stdlib.h>
#include <stdio.h>

uint8_t adsfda[]= "hello ";

static int push(uint8_t * buff, void * buff_struct)
{
	circular_buffer* c_buff = (circular_buffer*)buff_struct ;
	uint8_t write = 0 ;
	if(c_buff->front > c_buff->size)
	{
		if(c_buff->back > 0)
		{
			write = 1;
		}
	}
	else if(c_buff->front < c_buff->back)
	{
		if((c_buff->back - c_buff->front) > 1)
		{
			write = 1 ;
		}
	}
	else if(c_buff->front >= c_buff->back)
	{
		write = 1;
	}
	if(write == 1)
	{
		c_buff->buffer[c_buff->front] = buff ;
//		printf("write :: %s\n", c_buff->buffer[c_buff->front]);
		c_buff->front++ ;
		return 0 ;
	}	
	return -1 ;
}
static int pop(uint8_t ** buff, void * buff_struct)
{
	int res = 0 ;
	circular_buffer* c_buff = (circular_buffer*)buff_struct ;
	if(c_buff->front == c_buff->back)
	{
		 *buff =  NULL ;
		 res = -1 ;
	}
	else
	{   
		*buff = c_buff->buffer[c_buff->back]; 
		c_buff->back++ ;
		if(c_buff->back >= c_buff->size)
		{
			c_buff->back = 0 ;
		}
	}
	return res ;
}

int initialize_circular_buffer(int bsize, circular_buffer * c_buff)
{
	c_buff->size = bsize;
	c_buff->buffer = (uint8_t **)malloc(bsize * sizeof(uint8_t *));
	c_buff->push = push;
	c_buff->pop = pop ;
	c_buff->front = 0 ;
	c_buff->back = 0 ;
	for(int i=0; i<bsize; i++) c_buff->buffer[i] = NULL ;
}