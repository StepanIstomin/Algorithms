#include <stdio.h>
#include <stdlib.h>

void swapInt(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void printIntArray(int* array, int size, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) {
        printf(format, array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}
void fillIntRandom(int* array, int size, int border) {
    for (int i = 0; i < size; ++i)
        *(array + i) = rand() % border;
}
void sortInserts (int* arr, int len) {
    int temp, pos;
    for (int i = 1; i < len ; i++){
        temp = arr[i];
        pos = i-1;
        while (pos >= 0 && arr[pos] > temp){
           arr[pos + 1] = arr[pos];
        }
        arr[pos + 1] = temp;
    }
}
void quickSort(int* arr, int first, int last) {
    int i = first;
    int j = last;
    int x = arr[(first+last)/2];
    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;
        if (i <= j) {
            swapInt(&arr[i],&arr[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (i < last)
        quickSort(arr, i, last);
    if (first < j)
        quickSort(arr, first, j);
}
void imprQuickSort(int* arr, int first, int last) {
    int i = first;
    int j = last;
    if (last - first >= 10){
        int left = arr[first];
        int right = arr[last];
        int middle = arr[(first+last)/2];
        int x;
        if (left <= middle && left <= right)
            x = (middle <= right)?  middle : right;
        else if (right <= middle && right <= left)
            x = (middle <= left)? middle : left;
        else
            x = (left <= right)? left : right;
        do {
            while (arr[i] < x) i++;
            while (arr[j] > x) j--;
            if (i <= j) {
                swapInt(&arr[i],&arr[j]);
                i++;
                j--;
            }
        } while (i <= j);
        if (i < last)
            quickSort(arr, i, last);
        if (first < j)
            quickSort(arr, first, j);
    }
    else
        sortInserts(arr,last - first + 1);
}
void bucketSort(int* arr, int len){
    const int max = len;
    const int b = 10;
    int buckets[b][max+1];
    for (int i=0;i<b;i++){
        buckets[i][max] = 0;
    }
    for (int digit = 1; digit < 1000000000; digit *=10){
        for (int i=0; i < max; i++){
            int d = (arr[i]/digit)%b;

            //int counter = buckets[d][max];
            //buckets[d][counter] = arr[i];
            //counter++;
            //buckets[d][max] = counter;
            buckets[d][buckets[d][max]++] = arr[i];
        }
        int idx = 0;
        for (int i = 0; i<b; i++){
            for(int j=0;j<buckets[i][max];j++){
                arr[idx++] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }
}
void bucketSortEven(int* arr, int len){
    const int max = len;
    const int b = 10;
    int buckets[b+1][max+1]; // b+1 - additional bucket for array indices
    for (int i=0;i<b+1;i++){
        buckets[i][max] = 0;
    }
    //printf("%d",buckets[b][max]);
    for (int digit = 1; digit < 1000000000; digit *=10){
        for (int i=0; i < max; i++){
            if (arr[i]%2 == 0) { // even check
                int d = (arr[i]/digit)%b;
                buckets[d][buckets[d][max]++] = arr[i];
                buckets[b][buckets[b][max]++] = i; //  write the indices of the even values of the array
            }
        }
        int idx = 0;
        for (int i = 0; i<b; i++){
            for(int j=0;j<buckets[i][max];j++){
                arr[buckets[b][idx++]] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
        buckets[b][max] = 0;
    }
}

int main()
{
    const int arrSize = 30;
    //task1
    printf("Task 1\n");
    int arr[arrSize];
    fillIntRandom(arr, arrSize, 100);
    printIntArray(arr, arrSize, 3);
    imprQuickSort(arr,0, arrSize-1);
    printIntArray(arr, arrSize, 3);
    //task2
    printf("\nTask 2\n");
    int arr2[arrSize];
    fillIntRandom(arr2, arrSize, 100);
    printIntArray(arr2, arrSize, 3);
    bucketSortEven(arr2, arrSize);
    printIntArray(arr2, arrSize, 3);
    return 0;
}
