#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define maxstack 100
#define st_entry int

typedef struct stack {
    int top;
    st_entry arr[maxstack];

}Stack;

void  create_stack( Stack *ps){
  ps->top=0;
}

void  push( st_entry e,Stack *ps){
    ps->arr[ps->top++]=e;
}

bool stackfull (Stack *ps) {
   return ps->top==maxstack;
}

bool stackempty (Stack *ps) {
    return ps->top==0;   // return !ps->top;
}

void pop (st_entry *pe,Stack *ps) {
    ps->top--;
    *pe=ps->arr[ps->top];

}

st_entry stackTop (Stack *ps) {

    return ps->arr[ps->top-1];
}

int stackSize (Stack *ps) {

    return ps->top;
}

void clearstack (Stack *ps) {

    ps->top=0;
}
 //traverse on the elements of stack first type
void traverseStack (Stack s) {
    st_entry x;
    while(!stackempty(&s)) {
        printf("%d ",stackTop(&s));
        pop(&x,&s);
    }
}

//traverse on the elements of stack second type
// the second parameter is the operation will be done on every element of stack
/*void traverseStack (Stack *ps ,void (*pf) (st_entry)) {

    for(int i=ps->top;i>0;i--) {
        (*pf)(ps->arr[i-1]);
    }

}*/

int main() {

    Stack st;
    create_stack(&st);

    for(int i=1;i<=10;i++) {
        push(i,&st);
    }

    traverseStack(st);






    return 0;

}
