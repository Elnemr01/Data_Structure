#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define maxstack 100
#define st_entry char

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

bool paired (char l,char r) {

    if( r=='[' && l==']')
        return 1;

    if(r=='{' && l=='}')
        return 1;

    if( r=='(' && l==')')
        return 1;


    return 0;
}

bool balanced (char s[],int len) {
    Stack st;
    create_stack(&st);

    push(s[0],&st);

    for(int i=1;i<len;i++) {

        if(stackempty(&st)) {
            push(s[i],&st);
            continue;
        }

        if(paired(s[i],stackTop(&st))) {
            char ch;
            pop(&ch ,&st);
        }
        else {
              push(s[i],&st);
        }

    }

    return stackempty(&st);

}

int main()
{
    char s[100];
    scanf("%s",&s);
    int l=strlen(s);
    if(balanced(s,l))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
