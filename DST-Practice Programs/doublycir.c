#include<stdio.h>
#include<stdlib.h>
int count = 0;
struct node{
    int data;
    struct node*right;
    struct node*left;
};

struct list{
    struct node*head;
};

struct node*createnode(int val){
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("allocation failed\n");
        exit(0);
    }
    newnode->data = val;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
};

void display(struct list*list){
    struct node*current = list->head->right;
    if(current == NULL){
        printf("empty list\n");
        exit(0);
    }
    while (current->right != list->head->right)
    {
        printf("%d\t",current->data);
        current = current->right;
    }
    printf("%d->NULL\n",current->data);
}

void insertatbeg(struct list*list,int val){
struct node*newnode = createnode(val);
if(list->head == NULL){
struct node*head = (struct node*)malloc(sizeof(struct node));
list->head=head;
head->data = count;
head->right = newnode;
head->left=NULL;
newnode->left = newnode;
newnode->right = newnode;
display(list);
return;
}
struct node*current = list->head->right;
while (current->right != list->head->right)
{
    current = current->right;
}
current->right = newnode;
newnode->left = current;
newnode->right = list->head->right;
list->head->right = newnode;
count++;
display(list);
return;
}

void insertatrear(struct list*list,int val){
    struct node*newnode = createnode(val);
    if(list->head == NULL){
        insertatbeg(list,val);
        return;
    }
    struct node*current = list->head->right;
    while(current->right != list->head->right){
        current = current->right;
    }
    newnode->right = list->head->right;
    newnode->left = current;
    current->right = newnode;
    count++;
    display(list);
    return;
}

void insertatpos(struct list*list,int pos,int val){
struct node*newnode = createnode(val);
if(pos< 1 || pos>count+2){
    printf("invalid position\n");
    return;
}
if(pos == 1){
    insertatbeg(list,val);
    return;
}
struct node*current = list->head->right;
for(int i = 1;i<pos-1 && current->right != list->head->right;i++){
    current = current->right;
}
newnode->right = current->right;
newnode->left = current;
current->right = newnode;
display(list);
return;
}

void deleteatbeg(struct list* list){
struct node*current = list->head->right;
if(list->head->right == NULL){
    printf("list is empty\n");
    return;
}
struct node*last = current->left;
last->right = current->right;
current->right->left = last;
list->head->right = current->right;
count--;
free(current);
display(list);
}

void deleteatrear(struct list*list){
    if(list->head->right == NULL){
        printf("empty list\n");
        return;
    }
    struct node*current = list->head->right,*prev;
    if(current->right == NULL){
        free(current);
        count--;
        display(list);
        return;
    }
    while(current->right != list->head->right){
        prev = current;
        current = current->right;
    }
    prev->right = list->head->right;
    list->head->right->left = prev;
    free(current);
    count--;
    display(list);
    return;
}

void delbypos(struct list*list,int pos){
    struct node*current = list->head->right,*prev=NULL;
    if(list->head->right == NULL){
        printf("nothing there to delete");
        return;
    }
    if(pos == 1){
        deleteatbeg(list);
        return;
    }
    for(int i=1;i<pos && current->right != list->head->right;i++){
        prev = current;
        current=current->right;
    }
    prev->right = current->right;
    current->right->left = prev;
    free(current);
    display(list);
    count--;
    return;
}

void insertbyorder(struct list*list,int val){
    struct node*current = list->head->right;
    struct node*newnode = createnode(val);
    if(list->head->right == NULL){
        insertatbeg(list,val);
        return;
    }
    int pos = 2;
    while(current->right != list->head->right && current->data<val){
        current = current->right; 
        pos++;
    }
    insertatpos(list,pos,val);
    return;
}

void search(struct list*list,int key){
    struct node*current = list->head->right;
    if(list->head->right == NULL){
        printf("empty list\n");
        return;
    }int i=0;
    while(current->right != list->head->right && current->data != key){
        current = current->right;
        i++;
        if(current->right == list->head->right){
            printf("%d is not found\n",key);
            return;
        }
    }
    printf("%d is found in %dth position\n",key,i);
}

int main(){
    struct list*list=(struct list*)malloc(sizeof(struct list));
    list->head = NULL;
    int pos,val,key,opt;
    while(1){
        printf("enter the option\n");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:printf("enter the value: ");
        scanf("%d",&val);
        insertatbeg(list,val);
        break;
        case 2:printf("enter the value: ");
        scanf("%d",&val);
        insertatrear(list,val);
        break;
        case 3:printf("enter the pos and val: ");
        scanf("%d %d",&pos,&val);
        insertatpos(list,pos,val);
        break;
        case 4:deleteatbeg(list);break;
        case 5:deleteatrear(list);break;
        case 6:printf("pos: ");
        scanf("%d",&pos);
        delbypos(list,pos);break;
        case 7:printf("enter the value: ");
        scanf("%d",&val);
        insertbyorder(list,val);break;
        case 8:printf("enter the key: ");
        scanf("%d",&key);
        search(list,key);break;
        default:return 0;
        }
    }return 0;
}