#include <stdio.h>
#include <stdlib.h>

#define T int
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

//task 1

#define SIZE 6
const int n = SIZE;
int matrix[SIZE][SIZE] = {
    {0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0},
};
int visited[SIZE]={0};
void resetArr(int *arr){
    for (int i = 0; i<n; i++){
        arr[i]=0;
    }
}
void depthTravers(int st){
    int r;
    printf("%d ", st);
    visited[st] = 1;
    for (r=0;r<n;r++){
        if (matrix[st][r] == 1 && !visited[r])
            depthTravers(r);
    }
}

//stack on array
int cursor = -1;
T Stack[SIZE];
boolean push(T data) {
    if (cursor < SIZE){
        Stack[++cursor] = data;
        return true;
    }
    else {
        printf("Stack overflow\n");
        return false;
    }
}

T pop(){
    if (cursor != -1)
        return Stack[cursor--];
    else {
        printf("Stack is empty\n");
        return -1;
    }
}
//depth traversal function using stack
void stackDepthTravers(int st){
    //st - number of current node
    //r - number of node with link from current node
    //int r;
    printf("%d ", st);
    visited[st] = 1;
    push(st);
    while (cursor != -1){ //the loop runs as long as there is a node on the stack (the top node on the stack is the current one)
        st = Stack[cursor];
        for (int r = 0; r < SIZE; r++){
            if (matrix[st][r] == 1 && !visited[r]){ //if a new unvisited node is found from the current node
                st = r; //new unvisited node becomes current
                visited[st] = 1; //new unvisited node is marked visited
                push(st); // new node is pushed into the stack
                printf("%d ", st);
                break;//if new unvisited node is found abort search in current node
            }
            else if (r == SIZE - 1) //if all connections are checked and an unvisited node is not found
                pop(); // remove the current node from the stack if no more links are found from it
        }
    }
}

//task 2
int matrix2[SIZE][SIZE] = {
    {0, 1, 1, 0, 1, 0},
    {0, 0, 1, 1, 1, 0},
    {0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0},
};
int indegree[SIZE] = {0}; //indegree array, array element number = node number
//
void depthTravers2(int st){ //task 2-1 "recursive function"
    int r;
    //printf("%d ", st);
    visited[st] = 1;
    for (r=0;r<n;r++){ // counting only vertices adjacent to the starting point/node777
        if (matrix2[st][r] == 1){
            indegree[r]++;
        }
    }
    for (r=0;r<n;r++){
        if (matrix2[st][r] == 1 && !visited[r]){
            depthTravers2(r);
        }
    }
}
void matrixTravers (){ //task 2-2 "graph traversal by adjacency matrix"
    for (int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if (matrix2[i][j] == 1)
                indegree[j]++;
        }
    }
}
void printIndegree (){
    int printed[SIZE] = {0};
    int max = 0;
    int point = 0;
    for (int i = SIZE; i > 0; i--){
        for (int j = 0; j < SIZE; j++){
            if (indegree[j] >= max && printed[j] != 1){
                max = indegree[j];
                point = j;
                }
        }
        printf("Node #%d (%d indegree)\n",point,max);
        printed[point] = 1;
        max = 0;
        point = 0;
    }
}

int main()
{
    //task 1
    depthTravers(0);
    resetArr(visited);
    printf("\n");
    stackDepthTravers(0);
    resetArr(visited);
    printf("\n");

    //task 2-1
    depthTravers2(0);
    resetArr(visited);
    printf("\n");
    printIndegree();
    resetArr(indegree);

     //task 2-2
    matrixTravers ();
    printf("\n");
    printIndegree();
    resetArr(indegree);
    return 0;
}
