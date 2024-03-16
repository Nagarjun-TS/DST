#include<stdio.h>
#include<stdlib.h>

/*A structure is a collection of related members but of different data types
named under one name  under a block of memory*/

struct queue{
int front;
int rear;
int size;
int *q;
}a;

typedef struct queue Q;

void create(Q*a){
    printf("enter the size of the queue\n");
    scanf("%d",&a->size);
    a->q=(int*)malloc(a->size * (sizeof(int)));
    if(a->q == NULL){
        printf("allocation failed\n");
        return;
    }
    a->front = 0;
    a->rear = 0;
    printf("created a queue of size %d\n",a->size);
    return;
}

void display(Q*a){
    for(int i=a->front;i<a->rear;i++){
        printf("|%d|\n",a->q[i]);
    }printf("\n");
    return;
}

void insert(Q*a,int val){
if(a->rear > a->size-1){
printf("the queue size is full[OVERFLOW!!]\n");
return;
}
a->q[a->rear++] = val;
printf("%d is added\n",val);
display(a);
}

void dequeue(Q*a){
    if(a->front > a->rear  ||  a->front == a->size){
        printf("queue is empty :(\n");
        return;
    }
    int x = a->q[a->front];
    a->front += 1;
    printf("%d is deleted\n",x);
    display(a);
}

int main(){
    int val,opt,x;
    while(1){
        printf("1]TO CREATE\n2]TO INSERT\n3]TO DELETE\n\n\tENTER AN OPTION\n");
        scanf("%d",&opt);
        switch(opt){
            case 1:create(&a);break;
            case 2:printf("enter the value to insert: ");
            scanf("%d",&val);
            insert(&a,val);
            break;
            case 3:dequeue(&a);
            break;
            default:return 0;
        }
    }return 0;
}