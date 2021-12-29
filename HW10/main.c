#include <stdio.h>
#include <stdlib.h>

//task1
#define SZ_ARR 100
#define T char
#define true 1 == 1
#define false 1 != 1

typedef int boolean;
int cursor = -1;
T Stack[SZ_ARR];

boolean push(T data) {
    if (cursor < SZ_ARR){
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

void seqCheck (char *arr){
    printf("%s is ",arr);
    int openBraceCount = 0;
    for(int i = 0; arr[i] != 0; i++){
        if (arr[i] == '[' || arr[i] == '(' || arr[i] == '{'){
            push(arr[i]);
            openBraceCount++;
        }
        else if (arr[i] == ']'){
            if (cursor == -1){
                printf("NOT correct");
                return;
            }
            while (cursor != -1) {
                char tmp = pop();
                if (tmp == '['){
                    openBraceCount--;
                    break;
                }
                else if (tmp == '(' || tmp == '{'){
                    printf("NOT correct");
                    return;
                }
            }
            if (cursor == -1 && openBraceCount > 0){
                printf("NOT correct");
                return;
            }
        }
        else if (arr[i] == ')'){
            if (cursor == -1){
                printf("NOT correct");
                return;
            }
            while (cursor != -1) {
                char tmp = pop();
                if (tmp == '('){
                    openBraceCount--;
                    break;
                }
                else if (tmp == '[' || tmp == '{'){
                    printf("NOT correct");
                    return;
                }
            }
            if (cursor == -1 && openBraceCount > 0){
                printf("NOT correct");
                return;
            }
        }
        else if (arr[i] == '}'){
            if (cursor == -1){
                printf("NOT correct");
                return;
            }
            while (cursor != -1) {
                char tmp = pop();
                if (tmp == '{'){
                    openBraceCount--;
                    break;
                }
                else if (tmp == '[' || tmp == '('){
                    printf("NOT correct");
                    return;
                }
            }
            if (cursor == -1 && openBraceCount > 0){
                printf("NOT correct");
                return;
            }
        }
    }
    if (cursor == -1)
        printf("correct");
    else
       printf("NOT correct");
}


int main()
{
    //task1
    char sequence[] = "(2+(2*2))";
    //char sequence[] = "[[2/{5*(4+7)}]";
    seqCheck(sequence);
    return 0;
}
