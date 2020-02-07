

#include<stdlib.h>
#include<stdio.h>
#include "queue.h"



	void createQueue(ST_queueInfo* info, int maxSize){

        info->qptr = (ST_queueInfo *) malloc(maxSize * sizeof(int ));
        info->front = -1 ;
        info->back =-1;

	}
	void enqueue(ST_queueInfo *info, int data){

        info->back++;
        info->qptr[info->back] = data;

	}
	void dequeue(ST_queueInfo *info, int* data){

			if(info->front == info->back){
			*data = info->qptr[info->front];
			info->front = -1;
			info->back = -1;
		}
		else{

			*data = info->qptr[(info->back)--];
		}

	}
