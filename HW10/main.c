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

//task2
typedef struct Node {
    int dat;
    struct Node *next;
} Node;
typedef struct {
    Node *head;
    int size;
} List;
void init(List* lst){
    lst->head = NULL;
    lst->size = 0;
}
void ins (List *lst, int data){
    Node *new = (Node*) malloc(sizeof(Node));
    new->dat = data;
    new->next = NULL;

    Node *current = lst->head;
    if (current == NULL) {
        lst->head = new;
        lst->size++;
    }
    else {
        while (current->next != NULL){
            current = current->next;
        }
        current->next = new;
        lst->size++;
    }
}
Node* rm(List *lst, int data){
    Node *current = lst->head;
    Node *parent = NULL;
    if (current == NULL)
        return NULL;
    while (current->next != NULL && current->dat != data){
        parent = current;
        current = current->next;
    }
    if (current->dat != data)
        return NULL;
    if (current == lst->head){
        lst->head = current->next;
        lst->size--;
        return current;
    }
    parent->next = current->next;
    lst->size--;
    return current;
}
void printNode(Node *n){
    if (n == NULL){
        printf("[]");
        return;
    }
    printf("[%d] ",n->dat);
}
void printList(List *lst){
    Node *current = lst->head;
    if (current == NULL){
        printNode(current);
    }
    else {
        do {
            printNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d\n", lst->size);
}
void copyList(List *lst, List *lstCopy){
    Node *current = lst->head;
    if (current == NULL){
        return;
    }
    else {
        do {
            ins(lstCopy,current->dat);
            current = current->next;
        } while (current != NULL);
    }
}
//task 3
void sortCheck (List *lst) {
    Node *current = lst->head;
    if (current == NULL){
        printf("List is empty\n");
        return;
    }
    else if (current->next == NULL) {
        printf("List contains one value \n");
        return;
    }
    else {
        Node *next = current->next;
        if (next->dat >= current->dat) {
            do {
                if (next->dat < current->dat){
                    printf("List is not sorted \n");
                    return;
                }
                current = current->next;
                next = current->next;
            } while (next != NULL);
            printf("List is sorted in ascending order \n");
            return;
        }
        if (next->dat <= current->dat) {
            do {
                if (next->dat > current->dat){
                    printf("List is not sorted \n");
                    return;
                }
                current = current->next;
                next = current->next;
            } while (next != NULL);
            printf("List is sorted in descending order \n");
            return;
        }
    }
}

int main()
{
    //task1
    char sequence[] = "(2+(2*2))";
    //char sequence[] = "[[2/{5*(4+7)}]";
    seqCheck(sequence);
    //task2
    printf("\n");
    List *lst = (List*) malloc(sizeof(List));
    init(lst);
    for (int i=0;i<10;i++){
       ins(lst,rand() % 100);
    }
    printList(lst);
    List *lstCopy = (List*) malloc(sizeof(List));
    init(lstCopy);
    copyList(lst,lstCopy);
    printList(lstCopy);
    rm(lst,62);
    printList(lst);
    printList(lstCopy);
    //task3
    sortCheck(lstCopy);
    List *lst31 = (List*) malloc(sizeof(List));
    init(lst31);
    for (int i=0;i<10;i++){
       ins(lst31,i);
    }
    List *lst32 = (List*) malloc(sizeof(List));
    init(lst32);
    for (int i=10;i>0;i--){
       ins(lst32,i);
    }
    List *lst33 = (List*) malloc(sizeof(List));
    init(lst33);
    List *lst34 = (List*) malloc(sizeof(List));
    init(lst34);
    ins(lst34,5);
    printList(lst31);
    sortCheck(lst31);
    printList(lst32);
    sortCheck(lst32);
    printList(lst33);
    sortCheck(lst33);
    printList(lst34);
    sortCheck(lst34);

    return 0;
}
