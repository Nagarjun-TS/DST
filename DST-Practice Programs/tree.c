/*A TREE IS A HIERARCHIAL DATA STRUCTURE THAT IS USED TO REPRESENT AND ORGANIZE DATA IN A WAY THAT IS EASY 
TO NAVIGATE AND SEARCH*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int a;
    struct node*left,*right;
};
//BINARY SEARCH TREE ORDERED INSERTION
void insertnode(struct node*root,int val){
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    newnode->a = val;
    newnode->left = NULL;
    newnode->right = NULL; 
    struct node*prev = root;
    while(root != NULL){
        prev = root;
        if(val>=root->a){
        root = root->right;          /*CHECK IF THE VALUE IS GREATER OR SMALLER TO ROOT DATA*/
        }                           //STEP 1:TRAVERSE THE ROOT TILL ITS END NODE CHECKING THE CONDITION TOWARDS 
        else{                      //LEFT OR RIGHT        
            root = root->left;    //STEP 2 :U HAVE NOW REACHED THE LAST NODE NOW DECIDE WETHER U HAVE TO INSERT
        }                        //TOWARDS LEFT OR RIGHT
        }
        if(val >= prev->a){
            prev->right = newnode;
        }
        else{
            prev->left = newnode;
        }
    }
//BINARY SEARCH TREE ORDER PRESERVE THE TREE AND PERFORM DELETION
//delete the value sent by main function
struct node*deletenode(struct node*root,int key){
    struct node*prev = root,*temp = NULL,*r = root;
    //CASE 0:ROOT ITSELF HAS TO BE DELETED
    if(root->a == key){
        //root to be deleted with one sub tree
    if(root->left == NULL || root->right == NULL){
        if(root->right != NULL){
            prev = root->right;
        }
        else{
            prev = root->left;
        }
        free(root);
        return prev;
    }else{
        prev = root->right;
        prev->left = root->left;
    free(root);
    return prev;
    }
    }
    while(root->a != key || root != NULL){
        prev = root;
        if(key > root->a){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }//CASE 1:NODE NOT FOUND
    if(root == NULL){
        printf("invalid key! NO such value found\n\t TRY AGAIN\n");
        return r;
    }
//CASE 2:NODE HAS NO SUBTREE OR ONLY ONE SUBTREE
if(root->left == NULL || root->right == NULL){
    //NODE TO BE DELETED WITH NO OR ONE SUBTREE IS ON RIGHT
    if(key>prev->a){
        if (root->right != NULL){
            prev->right = root->right;
        }
        else{
            prev->right = root->left;
        }
    free(root);      
    }
    else{
        if(root->right != NULL){
            prev->left = root->right;
        }
        else{
            prev->left = root->left;
        }
        free(root);
    }  
}
//CASE 3:NODE HAS 2 SUBTREES 
else{
    if(key>prev->a){
        prev->right = root->left;
        temp = root->left;
        while(temp->right != NULL){
            temp = temp->right;
        }
        temp->right = root->right;
        free(root);
    }
    else{
        prev->left = root->left;
        temp = root->right;
        while(temp->right != NULL){
            temp = temp->right;
        }
        temp->right = root->right;
        free(root);
    }
}
return r;
}
void display(struct node*root){
    if(root ==  NULL){
        return;
    }
    
    if(root->left != NULL){
        display(root->left);
    }
    
    printf("|%d|\n",root->a);
    
    if(root->right != NULL){
        display(root->right);
    }
}


void searchtree(struct node*root,int key){
    if(root==NULL){
        printf("the tree doesnot exit\n");
        return;
    }
    while(root != NULL){
    if(root->a != key){
        printf("%d is found \n",key);
        return;
    }
    if(key > root->a){root = root->right;}
    else{root = root->left;}
    }
    printf("%d is not found\n",key);
    return;
}

//RECURSIVE METHOD TO FREE ALL THE NODES
void freetree(struct node*root){
    if(root == NULL){
        return;
    }
    if(root->left != NULL){
        freetree(root->left);
    }
    if(root->right != NULL){
        freetree(root->right);
    }
    free(root);
}

int main(){
    int x,val,key;
    struct node*root = (struct node*)malloc(sizeof(struct node));
    root->a = 11;
    root->right = NULL;
    root->left = NULL;
    printf("BINARY SEARCH TREE:-\n");
    while(1){
        if(root == NULL){
            printf("the tree is completly burnt down\n");
            return 0;
        }
        printf("1]TO INSERT\n2]TO DELETE\n3]SEARCH\n4]FREE THE TREE NODES\n\tENTER AN OPTION\n");
        scanf("%d",&x);
        switch (x)
        {
        case 1:printf("enter the value: ");
        scanf("%d",&val);
        insertnode(root,val);
        break;
        case 2:printf("ELEMENT TO DELETE:");
        scanf("%d",&key);
        printf("%d is deleted\n",deletenode(root,key));
        break;
        case 3:printf("KEY: ");
        scanf("%d",&key);
        searchtree(root,key);
        break;
        case 4:display(root);
        break;
        default:return 0;
        }
    }
    return 0;
}