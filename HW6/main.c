#include <stdio.h>
#include <stdlib.h>

void task1(int*arr, int n, int i) {
    if (n > 0) {
        if (n % 2 > 0)
            arr[i++] = 1;
        else
            arr[i++] = 0;
        task1(arr,n/2,i);
    }
    else {
        for (int j = i-1; j >=0; j--){
            printf("%d", arr[j]);
        }
    }
}
int task21 (int a, int b){
    if (b == 0)
        return 1;
    else if (b == 1)
        return a;
    else
        return a * task21(a, b-1);
}
int task22 (int a, int b) {
    if (b == 0)
    return 1;
    else if (b == 1)
        return a;
    else {
        if(b%2)
            return a * task22(a, b-1);
        else
            return task22(a*a, b/2);
    }
}
#define SIZE_X 8
#define SIZE_Y 8
int task3 (int field[SIZE_X][SIZE_Y], int x, int y){
    if (x == 0 && y == 0 || field[x][y] == 1)
        return 0;
    else if (x == 0) {
        if (task3(field,x,y-1) == 0 && y != 1)
            return 0;
        else
            return 1;
    }
    else if (y == 0) {
         if (task3(field,x-1,y) == 0 && x != 1)
            return 0;
        else
            return 1;
    }
    else
        return task3(field,x,y-1) + task3(field,x-1,y);
}
int main()
{
    //task 1
    int n;
    printf("Input integer number for binary translation: ");
    scanf("%d", &n);
    int arr[256];
    printf("%d = ",n);
    task1(arr,n,0);
    //task 2-1 & 2-2
    int a,b;
    printf("\nInput integer number a: ");
    scanf("%d", &a);
    do {
        printf("Input positive integer number b: ");
        scanf("%d", &b);
    }
    while (b < 0);
    printf("%d^%d = %d",a,b,task21(a,b));
    printf("\n%d^%d = %d\n",a,b,task22(a,b));
    //task 3
    int field[SIZE_X][SIZE_Y] = {0};
    field[4][0] = 1;
    field[3][2] = 1;
    field[6][6] = 1;
    for (int y = 0; y < SIZE_Y; y++){
        for(int x = 0; x < SIZE_X; x++){
            printf("%5d", task3(field,x,y));
        }
        printf("\n");
    }
    return 0;
}
