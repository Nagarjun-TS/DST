#include<stdio.h>
#include<stdlib.h>

void insertbyorder(int *arr,int *n,int key){
    int i = *n-1;
    while(i>=0 && arr[i]>key){
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = key;
    (*n)++;
}

void deletebypos(int *arr,int pos,int *n){
    if(pos < 1 || pos>*n){
        printf("invalid position\n");
        return;
    }
    for(int i=pos-1;i<*n-1;i++){
        arr[i] = arr[i+1];
    }
    (*n)--;
}

void searchbykey(int *arr,int key,int *n){
    for(int i=0;i<*n;i++){
        if(arr[i] == key){
            printf("%d is found in %dth position\n",key,i+1);
            return;
        }
        printf("%d is not found\n",key);
    }
}

void reverse(int *arr,int *n){
    for(int i=0;i<*n/2;i++){
        int temp = arr[i];
        arr[i] = arr[*n-1-i];
        arr[*n-i-1] = temp;
    }
}

void printarr(int *arr,int*n){
    for(int i=0;i<*n;i++){
        printf("%d\n",arr[i]);
    }
    printf("\n");
}

int main(){
    int *arr,n,c,choice;
    int pos,key;
    printf("enter the array size nd capacity\n");
    scanf("%d %d",&n,&c);
    arr = (int*)malloc(c*sizeof(int));
    printf("enter the array elements in sorted order\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    while (1)
    {
        printf("enter the option\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("enter the key");
        scanf("%d",&key);
        insertbyorder(arr,&n,key);
        break;
        case 2:printf("enter the pos\n");
        scanf("%d",&pos);
        deletebypos(arr,pos,&n);
        break;
        case 3:reverse(arr,&n);
        break;
        case 4:printf("enter the key\n");
        scanf("%d",&key);
        searchbykey(arr,key,&n);
        break;
        case 5:printarr(arr,&n);
        break;
        default:return 0;
        }
    }
    return 0;
}