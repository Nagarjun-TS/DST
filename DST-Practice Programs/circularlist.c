# include<stdio.h>
# include<stdlib.h>
int count = 0;
struct node{
    int data;
    struct node*next;
};

struct list{

    struct node*head;
};

struct node*createnode(int val){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    if(new == NULL){
        printf("allocation failed\n");
        exit(0);
    }
    new->data = val;
    new->next = NULL;
    return new;
}
void display(struct list*list){
    struct node*current = list->head->next;
    if(current == NULL){
        printf("empty list\n");
        return;
    }
    while(current->next != list->head->next){
        printf("%d\t",current->data);
        current = current->next;
    }
    printf("%d\n",current->data);
}
void insertatfront(struct list*list,int val){
    struct node*new = createnode(val);
    if(list->head == NULL){
        struct node*head = (struct node*)malloc(sizeof(struct node));
        head->data = count;
        list->head = head;
        head->next = new;
        new->next = new;
        count++;
        display(list);
        return;
    }
    struct node*cur = list->head->next;
    while(cur->next != list->head->next){
        cur = cur->next;
    }
    cur->next = new;
    new->next = list->head->next;
    list->head->next = new;
    count ++;
    display(list);
}
void insertatrear(struct list*list,int val){
    if(list->head == NULL){
        insertatfront(list,val);
        return;
    }
    struct node*cur = list->head->next;
    struct node*new = createnode(val);
    while(cur->next != list->head->next){
        cur = cur->next;
    }
    new->next = cur->next;
    cur->next = new;
    count++;
    display(list);
    return;
}

void insertatpos(struct list*list,int val,int pos){
    if(pos < 1 || pos>count+1){
        printf("invalid position\n");
        return;
    }
    if(pos == 1){
        insertatfront(list,val);
        return;
    }
    struct node*new = createnode(val);
    struct node*current = list->head->next;
    for(int i=1;i<pos-1 && current->next != list->head->next;i++){
        current = current->next;
    }
    new->next = current->next;
    current->next = new;
    count ++;
    display(list);
    return;
}

void deleteatfront(struct list*list){
    if(list->head->next == NULL){
        printf("list not initiated\n");
        return;
    }
    struct node*current = list->head->next;
    struct node*tail = current->next;
    while(tail->next != list->head->next){
        tail = tail->next;
    }
    tail->next = current->next;
    list->head->next = current->next;
    free(current);
    count--;
    display(list);
    return;
}

void deleteatrear(struct list*list){
    if(list->head->next == NULL){
        printf("list is empty\n");
        return;
    }
    struct node*current = list->head->next;
    struct node*prev = NULL;
    while(current->next != list->head->next){
        prev = current;
        current = current->next;
    }
    if(prev == NULL){
        list->head->next = NULL;
        return;
    }
    prev->next = list->head->next;
    free(current);
    count--;
    display(list);
    return;
}

void delbypos(struct list*list,int pos){
    if(pos<1 || pos>count+1){
        printf("invalid position\n");
        return;
    }
    if(pos == 1){
        deleteatfront(list);
        return;
    }
    struct node*current = list->head->next,*temp=NULL;
    for(int i=1;i<pos && current->next != list->head->next;i++){
        temp = current;
        current = current->next;
    }
    temp->next = current->next;
    free(current);
    count--;
    display(list);
    return;
}
void delbykey(struct list*list,int key){
    struct node*current = list->head->next;
    struct node*prev=NULL;
    while(current->next != list->head->next && current->data != key){
        prev = current;
        current = current->next;
    }
    if(current->next == list->head->next){
        printf("key not found\n");
        return;
    }
    prev->next = current->next;
    free(current);
    count--;
    display(list);
    return;
}

void reverse(struct list*list){
    struct node*current=list->head->next;
    struct node*prev=NULL,*next=NULL;
    do{
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }while(current != list->head->next);
    list->head->next = prev;
    display(list);
    return;
}

int main(){
    struct list*list = (struct list*)malloc(sizeof(struct list));
    list->head = NULL;
    int val,pos,opt,key;
    while(1){
        printf("enter the option\n");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:printf("enter the value ");
        scanf("%d",&val);
        insertatfront(list,val);
        break;
        case 2:printf("enter the value ");
        scanf("%d",&val);
        insertatrear(list,val);
        break;
        case 3:printf("enter the value and pos\n");
        scanf("%d",&pos);
        scanf("%d",&val);
        insertatpos(list,val,pos);
        break;
        case 4:deleteatfront(list);break;
        case 5:deleteatrear(list);break;
        case 6:printf("enter the key\n");
        scanf("%d",&key);
        delbykey(list,key);break;
        case 7:reverse(list);break;
        case 8:printf("enter key ");
        scanf("%d",&pos);
        delbypos(list,pos);
        break;
        default:return 0;
        }
    }
    return 0;
}