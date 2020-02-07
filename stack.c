

#include<stdlib.h>
#include <stdio.h>
#include"stack.h"



    void createStack(ST_stackInfo *info, int size){

        info->sptr =  malloc(size * sizeof(int));
        info->top = 0 ;
    }

	int  stack_isEmpty(ST_stackInfo *info){

        return info->top == 0 ;
	}

    int stack_isFull(ST_stackInfo *info){

    return info->top == ( info->size - 1 );
    }

	void push(ST_stackInfo *info, int data){
        if (  stack_isFull( info ) == 0)
            info->sptr[ (info->top)++ ] = data;
	}

	void pop(ST_stackInfo *info, int* data){
            if (  stack_isEmpty( info) == 0)
                *data = info->sptr[ --(info->top) ];
	}


