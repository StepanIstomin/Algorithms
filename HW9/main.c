#include <stdio.h>
#include <stdlib.h>


//task1
#define SIZE 10
typedef struct {
    int pr;
    int dat;
} Node;

Node* arr[SIZE];
int items;

void init(){
    for (int i = 0; i < SIZE; i++){
        arr[i] = NULL;
    }
    //head = 0;
    //tail = 0;
    items = 0;
}
void insShift(int pr, int dat) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;

    if (items == 0) {
        arr[items++] = node;
        //items++;
    }
    else if (items == SIZE) {
        printf("Queue is full\n");
        return;
    }
    else {
        int i = 0;
        //int idx = 0;
        Node* tmp1;
        Node* tmp2;
        for (i = 0; i < items; i++) {
            //idx = i %SIZE;
            //idx = i;
            if (arr[i]->pr > pr)
                break;
            //else
                //idx++;
        }
        tmp1 = node;
        while(i < items) {
            tmp2 = arr[i];
            arr[i] = tmp1;
            tmp1 = tmp2;
            i++;
        }
        arr[i] = tmp1;
        items++;
    }
}
Node* remShift(){
    if (items == 0){
        return NULL;
    }
    else {
        Node* tmp = arr[0];
        for (int i = 0; i < items-1; i++) {
            arr[i] = arr[i+1];
        }
        arr[--items] = NULL;
        return tmp;
    }
}
void remPriorShift(int pr){
    if (items == 0){}
    else {
        for (int i = 0; i < items; i++) {
            if (arr[i]->pr == pr){
                for (int j = i; j < items-1; j++) {
                    arr[j] = arr[j+1];
                }
                arr[--items] = NULL;
                i--;
            }
        }
    }
}
void qRemPriorShift(int pr){
    if (items == 0){}
    else {
        printf("remPr=%d\n",pr);
        int holeIdx = NULL;
        int datIdx = 0;
        for (int i = 0; i < items; i++) {
            if (arr[i]->pr == pr){
                if (i && arr[i-1])
                    holeIdx = i;
                arr[i] = NULL;
            }
            else if(i && !arr[i-1])
               datIdx = i;
        }
        if (datIdx > holeIdx){
            int shift = datIdx - holeIdx;
            for (int i = datIdx; i < items; i++){
                arr[holeIdx++] = arr[i];
                arr[i] = NULL;
            }
            items -= shift;
        }
    }
}
void printQueue(){
    printf("[ ");
    for (int i = 0; i < SIZE; i++){
        if (arr[i] == NULL)
            printf("[*, *]");
        else
            printf("[%d, %d]", arr[i]->pr,arr[i]->dat);
    }
    printf(" ]\n");
}
void fillIntRandom(int* array, int size, int border) {
    for (int i = 0; i < size; ++i)
        *(array + i) = rand() % border;
}
void fillQueueRandom(int size, int prLimit, int datLimit) {
    for (int i = 0; i < size; ++i)
        insShift(rand() % prLimit + 1, rand() % datLimit);
}

//task2
#define SZ_ARR 64
#define T int
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
void binTrans (int n){
    if (!n)
        printf("%d",0);
    else {
        while (n > 0){
            if (n % 2 > 0)
                push(1);
            else
                push(0);
            n /= 2;
        }
        while (cursor != -1) {
            printf("%d",pop());
        }
    }
}

int main()
{
    //task1
    init();
    fillQueueRandom (SIZE,5,100); //Queue random fill
    printQueue();
    /*for (int i=0; i < 2; i++){ // i - number of items to remove
        Node* n = remShift();
    }
    printQueue();
    insShift (6,45);
    insShift (6,34);
    printQueue();
    */
    qRemPriorShift(4);
    printQueue();

    //task2
    int n;
    printf("Input positive integer number for binary translation: ");
    scanf("%d", &n);
    printf("%d = ",n);
    binTrans(n);
    return 0;
}
