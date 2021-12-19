#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
void printDblArray(double * array, int size, int crop) {
    char format[7];
    sprintf(format, crop ? "%%.%dlf" : "%%lf", crop);
    for (int i = 0; i < size; ++i) {
        printf(format, array[i]);
        if (i != size - 1)
            printf(", ");
    }
    printf("\n");
}
int get2dInt(int** array, const int row, const int col) {
    return *((*(array + row)) + col);

}
void set2dInt(int** array, const int row, const int col, int value) {
    *((*(array + row)) + col) = value;
}
int** init2dIntArray(int** array, const int row, const int col) {

    int * line = (int*) calloc(sizeof(int), row*col);
    array = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = &line[i*col];
    }

    return array;

}
void fill2dIntArray(int** array, const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            //int value = ((i + 1) * (j + 1));
            int value = rand() % 100;
            set2dInt(array, i, j, value);
        }
    }
}
void print2dIntArray(int** array, const int row, const int col, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf(format, get2dInt(array, i, j));
        }
        printf("\n");
    }
}
//task 1
void swapInt2dArray (int** array, const int row1, const int col1, const int row2, const int col2){
    int t = get2dInt(array, row1, col1);
    set2dInt(array, row1, col1, get2dInt(array, row2, col2));
    set2dInt(array, row2, col2, t);
}
int nextValue2dArray (int** array, const int size_col, const int row, const int col){
    if (col < size_col-1)
        return get2dInt(array,row, col+1);
    else
        return get2dInt(array,row+1, 0);
}
void arrBubbleSort (int** array, const int row, const int col){
    int limitRow = row;//=5
    int limitCol = col-1;//=4
    int jLimit;
    while (!(limitRow == 1 && limitCol == 1)){
        for (int i = 0; i < limitRow; i++) { //проверка от 0 до строки меньшей чем лимит
            if (i == limitRow - 1) // если строка последн€€ перед лимитом
                jLimit = limitCol; // лимит столбца ограничиваем limitCol
            else
                jLimit = col; // если строка не последн€€ перед лимитом то перебираем все столбцы
            for (int j = 0; j < jLimit; j++) { // проверка от 0 до 4 или 5
                if (get2dInt(array,i,j) > nextValue2dArray(array,col,i,j)){
                    if (j<col-1) // если столбец не последний то мен€ем соседние в строке
                        swapInt2dArray (array, i, j, i, j+1);
                    else // если столбец последний то мен€ем с 1-м столбцом следующей строки
                        swapInt2dArray (array, i, j, i+1, 0);
                }
            }
        }
        if (limitCol-1 > 0) // ≈сли лева€ €чейка не ноль, то уменьшаем лимит столбца
            limitCol--;
        else { // ≈сли лимит достиг самого левого столбца, уменьшаем лимит строки, лимит столбца сбрасываем на col
            limitRow--;
            limitCol = col;
        }
    }
}
//task 3
void tbp(){
    const int size = 11;
    double tbpArr[size];
    for (int i = 0;i < size; i++){
        double number;
        printf("Input number %d: ",i+1);
        scanf("\n%lf", &number);
        tbpArr[size-1-i] = number;
    }
    printf("\nSequence of elements: ");
    printDblArray(tbpArr,size,2);
    printf("\nCalculation formula: sqrt(fabs(X)) + 5 * pow(X, 3)");
    for (int i = 0;i < size; i++){
        if (sqrt(fabs(tbpArr[i]))+ pow(tbpArr[i],3)*5 > 400)
            printf("\nWarning! calculation result for element [%d]> 400!",i+1);
    }
}
int main()
{
    //task 1
    const int  sizeX = 10;
    const int  sizeY = 10;
    int** arr = init2dIntArray(arr,sizeX,sizeY);
    fill2dIntArray(arr,sizeX,sizeY);
    print2dIntArray(arr,sizeX,sizeY,4);
    printf("\n");
    arrBubbleSort (arr,sizeX,sizeY);
    print2dIntArray(arr,sizeX,sizeY,4);

    //task 3
    tbp();
    return 0;
}
