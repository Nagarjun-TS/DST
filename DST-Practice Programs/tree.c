#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*right,*left;
};

void insert(struct node*root,int val){
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->right = NULL;
    newnode->left = NULL;
    struct node*prev = root;
    while(root!=NULL){
        prev = root;
        if(root->data <= val){
            root = root->right;
        }
        else{
            root=root->left;
        }
    }
    if(prev->data<=val){
        prev->right = newnode;
    }
    else{
        prev->left = newnode;
    }
}

void display(struct node*root){
    if(root == NULL){
        return;
    }
    printf("%d->",root->data);
    display(root->left);
    display(root->right);
}

struct node*delkey(struct node*root,int key){
    if(root == NULL){
        printf("key not found\n");
        return NULL;
    }
    if(root->data > key){
        root->left = delkey(root->left,key);
    }
    else if(root->data<key){
        root->right = delkey(root->right,key);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        else if(root->right == NULL){
            return root->left;
        }
        else if(root->left == NULL){
            return root->right;
        }
        else{
            struct node*temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delkey(root->right,temp->data);
        }

    }
}

void search(struct node*root,int key,struct node*par){
    if(root == NULL){
        printf("key not found\n");
        return;
    }
    if(root->data == key){
        printf("%d is found\n",key);
        if(par == NULL){
            printf("parent not present\n");
        }
        else{
            printf("%d is the parent\n",par->data);
        }
        return;
    }
    par = root;
    if(root->data<key){
        search(root->right,key,par);
    }
    else{
        search(root->left,key,par);
    }
}

int countnode(struct node*root){
    if(root == NULL){
        return 0;
    }
    int left = countnode(root->left);
    int right = countnode(root->right);
    return left+right+1;
}

int max(int a , int b){
    return a>b?a:b;
}

int height(struct node*root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right)+1;
}

void findmax(struct node*root,struct node*par){
    if(root == NULL){
        printf("empty\n");
        return;
    }
    if(root->right == NULL){
        printf("%d is the max value\n",root->data);
        if(par == NULL){
            printf("no parent\n");
        }
        else{
            printf("%d parent\n",par->data);
        }
        return;
        }
    par = root;
    findmax(root->right,par);
    }
int main(){
    struct node*root = (struct node*)malloc(sizeof(struct node));
    root->left = NULL;
    root->right = NULL;
    root->data = 100;
    int val,key,opt;
    while(1){
        printf("enter an option\n");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:printf("enter the value\n");
               scanf("%d",&val);
               insert(root,val);
               break;
        case 2:printf("enter the key\n");
               scanf("%d",&key);
               search(root,key,NULL);
               break;
        case 3:val = countnode(root);
                printf("total number of nodes %d\n",val);
                break;
        case 4:display(root);break;
        case 5:findmax(root,NULL);break;
        case 6:scanf("%d",&key);
       root = delkey(root,key);break;
        default:return 0;
        }
    }return 0;
}