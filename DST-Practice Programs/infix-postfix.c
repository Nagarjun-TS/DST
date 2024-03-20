#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct stack{
    int size;
    int top;
    int*q;
};

void create(struct stack *st,int size){
    st->q = (int*)malloc(size*sizeof(int));
    st->top = -1;
    st->size = size;
}

int prec(char c){
    if(c=='+' || c=='-'){
        return 1;
    }
    else if(c == '*' || c== '/'){
        return 2;
    }
    else if(c == '^'){
        return 3;
    }
}

char associativity(char c){
    if(c == '^')
    return 'r';
    return 'l';
}

void conversion(char s[],struct stack*st){
    char postfix[100];
    int index=0;
    for(int i=0;i<strlen(s);i++){
        char c=s[i];
    if(isalnum(c)){
        postfix[index++]=c;
    }
    else if(c == '('){
        st->q[++st->top] = c; 
    }
    else if(c==')'){
        while(st->top>=0 && st->q[st->top!='(']){
            postfix[index++] = st->q[st->top--];
        }st->top--;
    }
    else{
        while(st->top>=0 && prec(st->q[st->top])>=prec(s[i]) && associativity(s[i])=='l'){
            postfix[index++] = st->q[st->top--];
        }st->q[++st->top]=c;
    }
    }
    while(st->top>=0){
        postfix[index++] = st->q[st->top--];
    }
    postfix[index++] = '\0';
    printf("%s is the postfix expression\n",postfix);
}

int main(){
    char s[100];
    struct stack*st = (struct stack*)malloc(sizeof(struct stack));
    printf("enter the infix expression\n");
    scanf("%s",s);
    create(st,strlen(s));
    conversion(s,st);
    return 0;
}