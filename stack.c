#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
void inits(stack *s, int len){
    s->a = (int*)malloc(sizeof(int)*len);
    s->size = len;
    s->top = -1;
}
int isFulls(stack s) {
    if(s.top == s.size-1)
        return 1;
    else
        return 0;
}

int isemptys(stack s) {
    if(s.top == -1)
        return 1;
    else
        return 0;
}
void push(stack *s, int d){
    if(isFulls(*s))
        return ;
    else {
        s->top++;
        s->a[s->top] = d;
        return;
    }
}
int pop(stack *s) {
    if(isemptys(*s))
        return INT_MIN;
    int k = s->a[s->top--];
    return k;
}
int peek(stack *s){
      if(isemptys(*s))
        return INT_MIN;
      return s->a[s->top];
}
