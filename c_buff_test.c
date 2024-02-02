#include <stdio.h>
#include "afk_c_buff.h"

uint8_t arr1[]="the quick brown fox jumps over the lazy dog" ;
uint8_t arr2[9][25] = { "hello ","dear " ,"Bangladesh" ,"how can I help" ,"furious the monkey boy" ,"waiting for tonight" ,"lets get it don" ,"hello world" ,"i don't know" } ;
uint8_t * read_ptr = NULL ;
void main()
{
	circular_buffer mBuffer ;
	initialize_circular_buffer(500, &mBuffer) ;
	for(int i=0; i<9; i++)
	{
		if(mBuffer.push(arr2[i], &mBuffer) > 0)
		{
			printf("%s", "write ok\n");
		}
	}
	for(int i=0; i<503; i++)
	{
		mBuffer.pop(&read_ptr, &mBuffer);
    	read_ptr == NULL ? (printf("at %d : %s\n",i ,"ptr null")) : printf("at %d %s\n", i, read_ptr) ;
	}
}