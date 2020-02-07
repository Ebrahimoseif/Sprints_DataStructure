#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


      typedef struct{
        int front;
        int back;
        int size;
        int *qptr;

    }ST_queueInfo;





	void createQueue(ST_queueInfo* info, int maxSize);
	void enqueue(ST_queueInfo *info, int data);
	void dequeue(ST_queueInfo *info, int* data);

#endif // QUEUE_H_INCLUDED
