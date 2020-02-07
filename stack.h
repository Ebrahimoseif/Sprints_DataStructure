


#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

    typedef struct{

        int top;
        int size;
        int *sptr;

    }ST_stackInfo;

    void createStack(ST_stackInfo *info, int size);
	void push(ST_stackInfo *info, int data);
	void pop(ST_stackInfo *info, int* data);
	int  stack_isEmpty(ST_stackInfo *info);
	int stack_isFull(ST_stackInfo *info);



#endif // STACK_H_INCLUDED
