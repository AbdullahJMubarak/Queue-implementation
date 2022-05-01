#include <stdio.h>
#include <stdlib.h>
typedef struct{
int tail,front,capcity,size;
int*items;
} Queue;




Queue* intialize(int n){
Queue *q=malloc(sizeof(Queue));
q->front=q->tail=0;
q->capcity=n;
q->size=0;
q->items=malloc(n*sizeof(int));
return q;
}
void deleteFirst(Queue*q)
{
    if(q->head)
    {
        Node*temp=q->head;
        q->head=q->next;
        free(temp);
        if(q->head==NULL)
            q->tail=NULL;
    }
}

void enqueue(Queue*q,int val){
q->items[q->tail++]=val;
q->size++;
q->tail%=q->capcity;
}
int dequeue(Queue *q){
int val=q->items[q->front++];
q->size--;
q->front%=q->capcity;
return val;
}
int isFull(Queue*q){
return q->capcity==q->size;
}
int isEmpty(Queue *q){
return q->size==0;
}
int main()
{int i=1;
    Queue *q=intialize(10);
    while(!isFull(q)){
        enqueue(q,i);
        i++;

    }
    while(!isEmpty(q)){

        printf("%d ",dequeue(q));
    }

    return 0;
}
