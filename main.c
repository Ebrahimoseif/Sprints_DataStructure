#include <stdio.h>
#include <stdlib.h>

#include"stack.h"
#include"queue.h"
#include"linkedlist.h"

         struct   Node_t * start = NULL;

	unsigned char checkForBalancedParantheses(char* str);
    long long evaluate(char* expression);

int main()
{

    /* stack and queue testing

    ST_stackInfo stack;
    int size = 12;

    createStack(&stack, size );
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    int data1;
    pop(&stack, &data1 );
    printf("%d stack: \n ", data1);

////////////////////////////////////////////////////

    ST_queueInfo queue;
    int queuesize = 12;

   createQueue(&queue, queuesize );
   enqueue(&queue, 1);
   enqueue(&queue, 2);
   enqueue(&queue, 3);
   enqueue(&queue, 4);
   enqueue(&queue, 6);


    int data2;
    dequeue(&queue, &data2 );
    printf("%d queue: \n ", data2);
*/
 /*
    checkForBalancedParantheses("{{{{{5}}}}}");
           evaluate("{6+3+2-2}");

      */

      /* testing the linked list
     struct   Node_t *start = NULL;

      printf("Enter value of element\n");
      scanf("%d", &data);
      insert_at_begin(start,data);

      printf("Enter value of element\n");
      scanf("%d", &data);
      insert_at_end(start, data);

      traverse(start);

      delete_from_begin(start);
      traverse(start);
     */

        // Database requirements
     //struct   Node_t * start = NULL;

    int operation= 0;
    int data= 0;


  for (;;) {
    printf("1. Insert an element at the beginning of linked list.\n");
    printf("2. Insert an element at the end of linked list.\n");
    printf("3. Traverse linked list.\n");
    printf("4. Delete an element from beginning.\n");
    printf("5. Delete an element from end.\n");
    printf("6. Exit\n");

    scanf("%d", &operation);

    if (operation == 1) {
      printf("Enter value of element\n");
      scanf("%d", &data);
      insert_at_begin(&start, data);
    }
    else if (operation == 2) {
      printf("Enter value of element\n");
      scanf("%d", &data);
      insert_at_end(&start, data);
    }
    else if (operation == 3)
      display(&start);
    else if (operation == 4)
      delete_from_begin(&start);
    else if (operation == 5)
      delete_from_end(&start);
    else if (operation == 6)
      break;
    else
      printf("Please enter valid input.\n");
  }


    return 0;
}

	unsigned char checkForBalancedParantheses(char* str){

    int i = 0;
    ST_stackInfo stack;
    int size = 12;
    int  dummy;

    createStack(&stack, size );

    while(str[i] != '\0'){
    if(str[i] == '[' || str[i] == '(' || str[i] == '{'){
            push(&stack, str[i]);
        }
        else if(str[i] == ')'||str[i]=='}'||str[i]==')'){

                if(stack.sptr[stack.top-1] =='(' && str[i]==')')
                pop(&stack, &dummy);
                else if(stack.sptr[stack.top-1]=='{' && str[i] == '}')
                pop(&stack, &dummy);
                else if(stack.sptr[stack.top-1]=='[' && str[i]==']')
                pop(&stack, &dummy);
                else{
                    printf("not balanced");
                    return 0;
                 }
            } // END OF ELSE IF

       i++;
    }

        if( stack.top == 0 ){
               printf("balanced");
                return 1;
        }else{
                printf("not balanced");
                return 0;
        }

}




/*

●Evaluate an expression represented by a String.
●Expression can contain parentheses.
●Assume that the expression contains only integer values.
●For simplicity, you can assume only binary operations allowed are +, -, *, and /.
●Evaluate the operations in order don’t take operator precedence into consideration.
Use the following prototype:
*/

	long long evaluate(char* str){

	      ST_queueInfo queue;
          int queuesize = 12;
          int op1 = 0, op2 = 0 , result = 0 , i = 0 ;
          char operation ;
          int counter = 0 ;

        createQueue(&queue, queuesize );

        if(checkForBalancedParantheses(str)){

            while(str[i] != '\0'){
                if (str[i] >= 48 && str[i] <= 57){
                    enqueue(&queue, (str[i]-'0'));
                  }
            else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
                 {
                     enqueue(&queue, str[i]);
                 }

                  i++;
            } // end of pushing the elements to the queue

           dequeue(&queue, &op1);
           dequeue(&queue, &operation);
           dequeue(&queue, &op2);

       // printf(" number %d operation%c  : %d \n ", op1,operation, op2);

            while (counter < 7){
        switch(operation){

       case '+':
                result = (op1) + (op2 ) ;
                printf(" op1 %d operation%c  : op2 %d \n ", op1,operation, op2);
                break;

       case '-':
                result = (op1- '0') - (op2 - '0');
                break;

       case '*':
                result = (op1- '0') * (op2 - '0');
                break;

       case '/':
                result = (op1- '0') / (op2 - '0');
                break;


           }
           op1 = result ;
           dequeue(&queue, &operation);
           dequeue(&queue, &op2);

            counter++;
         //   printf(" number %d operation : %d \n ", counter, result);

          }  // dequeue(&queue, &op2);
printf("%d", result);
        }
        else {
        printf("bot balanced from the first ");
        return 0 ;}

}
