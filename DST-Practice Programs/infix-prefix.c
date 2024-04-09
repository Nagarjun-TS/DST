#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

struct stack{
    int top;
    int a[100];
};
void create(struct stack*st){
st->top = -1;
}
void push(struct stack*st,int val){
    st->a[++(st->top)] = val;
}

int pop(struct stack*st){
    int x = st->a[st->top];
    st->top--;
    return x;
}

int cal(int op1,int op2,char op){
    int r;
    switch(op){
        case '+':r=op1+op2;
        break;
        case '-':r= op1-op2;
        break;
        case '*':r = op1*op2;
        break;
        case '/':r=op1/op2;
        break;
        default:return -1; 
    }
    return r;
}
int evaluate(struct stack*st,char prefix[]){
    char c;
    int x;
    for(int i=strlen(prefix)-1;i>=0;i--){
        char c = prefix[i];
        if(isdigit(c)){
            push(st,c-'0');
        }
        else{
            int op1 = pop(st);
            int op2 = pop(st);
            x = cal(op1,op2,c);
            push(st,x);
        }
    }
    return st->a[st->top--];
}
int prec(char c){
    if(c == '+' || c == '-'){
        return 1;
    }
    else if(c =='*' || c=='/'){
        return 2;
    }
    else if(c == '^'){
        return 3;
    }
    else return -1;
}
void convert(char infix[]){
    char c,result[100],stack[100];
    int index = 0;
    int top = -1;
for(int i=strlen(infix);i>=0;i--){
    c = infix[i];
    if(isalnum(c)){
        result[index++] = c;
    }
    else if(c == ')'){
        stack[++top] = c;
    }
    else if(c == '('){
        while(top>=0 && stack[top] != '('){
            result[index++] = stack[top--];
        }top--;
    }
    else{
        while(top>=0 && prec(c)<=prec(stack[top])){
            result[index++] = stack[top--];
        }
        stack[++top] = c;
    }
}
while(top>=0){
    result[index++] = stack[top--];
}
for(int i = strlen(result)-1;i>=0;i--){
    printf("%c",result[i]);
}
printf("\n");
}
int main(){
    struct stack*st = (struct stack*)malloc(sizeof(struct stack));
    create(st);
    char prefix[100],infix[100];
    int opt;
    while(1){
        printf("\nenter the option\n");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:printf("enter the prefix expression");
        scanf("%s",&prefix);
        printf("%d is the result\n",evaluate(st,prefix));
        break;
        case 2:printf("enter the infix expression\n");
        scanf("%s",&infix);
        convert(infix);
        break;        
        default:return 0;
        }
    }
    return 0;
}
