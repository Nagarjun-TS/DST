#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct stack
{
    int top;
    int size;
    int *q;
};

void create(struct stack*st,int size){
    st->size = size;
    st->q = (int*)malloc(size*sizeof(int));
    st->top = -1;
}

int prec(char c){
    if(c=='+' || c=='-'){
        return 1;
    }
    if(c=='*' || c=='/'){
        return 2;
    }
    if(c=='^'){
        return 3;
    }
}

char associativity(char c){
    if(c=='^')
    return 'r';
    return 'l';
}

void convert(char s[],struct stack*st){
    int index=0;
    char res[100];
    for(int i=strlen(s)-1;i>=0;i--){
        char c = s[i];
        if(isalnum(c)){
            res[index++] = c;
        }
        else if(c==')'){
            st->q[++st->top] = c;
        }
        else if(c == '('){
           while(st->top>=0 && st->q[st->top]!=')'){
                res[index++] = st->q[st->top--];
            }st->top--;
        }
        else{
             while(st->top>=0 && prec(st->q[st->top])>=prec(s[i]) && associativity(c)){
                res[index++] = st->q[st->top--];
             }st->q[++st->top] = c;
        }
    }
    while(st->top>=0){
        res[index++] = st->q[st->top--];
    }
    res[index++] = '\0';
    for(int i=strlen(res)-1;i>=0;i--){
        printf("%c",res[i]);
    }
}
int main(){
    char s[100];
    struct stack*st = (struct stack*)malloc(sizeof(struct stack));
    printf("enter the infix expression\n");
    scanf("%s",s);
    create(st,strlen(s));
    convert(s,st);
    return 0;
}