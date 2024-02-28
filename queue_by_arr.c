#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ele_type int
#define max 100

typedef struct Queue {

    int size,rear,front;
    ele_type entry[max];

} queue;

void create_queue(queue *pq) {
    pq->size=0;
    pq->rear=-1;
    pq->front=0;
}

int size (queue *pq) {
    return pq->size;
}

bool empty (queue *pq) {
   return pq->size==0;

}


bool full (queue *pq) {
   return pq->size==max;
}

void push (ele_type e,queue *pq) {
   pq->rear= pq->rear+1 % max;
   pq->entry[pq->rear]=e;
   pq->size++;
}

void pop (ele_type *e,queue *pq) {
    *e=pq->entry[pq->front];
    pq->front= pq->front+1 % max;
    pq->size--;
}

void clear (queue *pq) {
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}

ele_type front (queue *pq) {
    return pq->entry[pq->front];
}

void traverse (queue *pq , void (*pf) (ele_type) ) {

    for(int pos=pq->front,s=0;s<pq->size;s++) {
        (*pf)(pq->entry[pos]);
        pos=(pos+1)%max;
    }

}

void print (ele_type x) {

    x*=x;

    printf("%d  ",x);

}


int main()
{
    queue q;
    create_queue(&q);
    for(int i=1;i<=20;i++) {
        push(i,&q);
    }

    printf("%d\n",front(&q));

    traverse(&q,&print);

    return 0;
}
