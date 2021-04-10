#include<limits.h>


typedef struct stack{
    int *a;
    int size;
    int top;
}stack;

void inits(stack *s, int len);
void push(stack *s, int d);
int isFulls(stack s) ;
int isemptys(stack s);
int pop(stack *s);
int peek(stack *s);


