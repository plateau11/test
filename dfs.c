#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 7

struct stack{
    int data[MAXSIZE];
    int top;
};

// void adjmat(int A[MAXSIZE][MAXSIZE], int v);
// void push(struct stack* stack, int data);
// int pop(struct stack* stack);
// void dfs(int A[MAXSIZE][MAXSIZE], int g, int v, struct stack* stack);


void push(struct stack* stack, int data);
int pop(struct stack* stack);

void dfs(int A[MAXSIZE][MAXSIZE], int g, int v, struct stack* stack);

void adjmat(int A[MAXSIZE][MAXSIZE], int v);



int main(){
    int A[MAXSIZE][MAXSIZE];
    int v;
    int g;

    struct stack stack;


    printf("\nEnter the number of vertices in the graph");
    scanf("%d", &v);

    adjmat(A,v);
    stack.top=-1;
    printf("\nEnter the starting vertex");
    scanf("%d", &g);

    dfs(A,g,v,&stack);

    return 0;

}




void dfs(int A[MAXSIZE][MAXSIZE], int g, int v, struct stack* stack){

    //printf("\nhello");

    int visited[v];

    for(int k=0;k<v;k++){
        visited[k] = 0;
    }

    int h=g;

    //printf("hllo3");

    visited[h] = 1;

    while(1){
        //printf("hllo4");
        printf("\nItems visited in the stack: ->");

        printf("%d",h);
        //printf("hi2");
        for(int i=0;i<v;i++){
            //printf("hi");
            if(A[h][i]==1 && visited[i]==0){
                push(stack,i);
                visited[i] = 1;
            }

        }

        if(stack-> top == -1){
            return;
        }

        h = pop(stack);

    }

}

void push(struct stack* stack, int data){

    if(stack->top == MAXSIZE-1){
        return;
    }
    stack->top++;
    stack->data[stack->top] = data;
    

}

int pop(struct stack* stack){
    if(stack->top == -1){
        return -1;
    }
    int item = stack->data[stack->top];
    stack->top--;
    return item;
}



void adjmat(int A[MAXSIZE][MAXSIZE], int v){
    
    printf("Enter the adjacency matrix\n");
    
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            scanf("%d", &A[i][j]);
        }

    }
}


