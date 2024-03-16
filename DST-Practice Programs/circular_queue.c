/*AN ORDINARY QUEUE CANNOT BE REUSED THEREFORE DOUBLY ENDED QUEUE || CIRCULAR QUEUE ARE USED*/

#include<stdio.h>
#include<stdlib.h>

// creating a struct of queue members
/*A STRUCTURE IS A COLLECTION OF RELATED MEMBERS BUT OF DIFFERENT DATA TYPES LISTED
UNDER ONE NAME UNDER A BLOCK OF MEMORY VERY SIMILAR TO CLASSES IN OTHER LANGUAGES*/
struct queue{
int front;
int rear;
int size;
int *Q;
}q;// here q is a body representing the queue structure.

typedef struct queue Q;

void create(Q*q){
    printf("enter the size of the queue\n");
    scanf("%d",&q->size);
    if(q->size <= 0){
        printf("invalid size!!\n");
        return;
    }
    q->front = q->rear = -1;
    //IN CIRCULAR QUEUE FRONT AND REAR ARE AT -1 INITIALLY
    //CREATING AN ARRAY DYNAMICALLY
    q->Q = (int*)malloc((q->size)*sizeof(int));
    if(q->Q == NULL){
        printf("allocation failed\n");
        exit(0);
    }
    printf("created\n");
}

void display(Q*q){
    if (q->front == -1 ){
        printf("the queue is empty not yet initiated!!\n");
        return;
    }
    int i = q->front;
    do{
        printf("|%d|->\t",q->Q[i]);
        i=(i+1)%q->size;
    }while(i != (q->rear+1) % q->size);//i should iterate till it is exactly equal to rear
printf("\n");
}

void enqueue(Q*q,int val){
if(q->front == -1){
    q->front = 0;
    q->rear = 0;
    q->Q[q->front] = val;
    display(q);
    return;
}
if((q->rear+1) % q->size == q->front){
    printf("queue overflow\n");
    return;
}
q->rear = (q->rear+1) % q->size;
q->Q[q->rear] = val;
printf("new element added\n");
display(q);
}

void dequeue(Q*q){
    if(q->front == -1){
        printf("queue has zero elements \n");
        return; 
    }
    if(q->front == q->rear){
    int x = q->Q[q->front];
    q->front = q->rear = -1;
    printf("\n %d is deleted\n",x);
    return;
    }
    int y = q->Q[q->front];
    q->front = (q->front+=1)%q->size;
    printf("deleted %d element\n",y);
    display(q);
}

int main(){
    int opt,val,pos;
    while(1){
        printf("1]to create a queue\n 2]to enqueue\n  3]to dequeue\n  4]to display\n\nchose an option\n");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:create(&q);break;
        case 2:printf("enter the value:");
        scanf("%d",&val);
        enqueue(&q,val);
        break;
        case 3:dequeue(&q);break;
        case 4:display(&q);break;
        default:printf("exitting the program\n");
        return 0;
        }
    }return 0;
}
