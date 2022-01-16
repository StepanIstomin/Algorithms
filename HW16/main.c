#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 100

//task 1
void caesarEncr(char *str, char *encrStr, int key) {
    if (key > 94)
        key %= 94;
    int i = 0;
    while (str[i]){
        if (str[i] + key > 126)
            encrStr[i] = str[i] + key - 126 + 32;
        else
            encrStr[i] = str[i] + key;
        i++;
    }
}
void caesarDecr(char *str, char *encrStr, int key) {
    if (key > 94)
        key %= 94;
    int i = 0;
    while (encrStr[i]){
        if (encrStr[i] - key < 32)
            str[i] = 126 - (32 - (encrStr[i] - key ));
        else
            str[i] = encrStr[i] - key;
        i++;
    }
}
//task 2
void permEncr(char *str, char *encrStr, int key){
    int i = 0;
    int strLenght = 0;
    while (str[i++]) {
        strLenght++;
    }
    if (key == 0){
        printf("Error: key is null\n");
        return;
    }
    if (key >= strLenght){
        printf("Error: key is to long\n");
        return;
    }
    i = 0;//encrypted array indexes
    for (int j = 0; j < key; j++){
        int k = j;
        while (str[k]){
            encrStr[i++] = str[k];
            k += key;
        }
    }
}
void permDecr(char *str, char *encrStr, int key){
    if (key == 0){
        printf("Error: key is null\n");
        return;
    }
    int strLenght = 0;
    int i = 0;
    while (encrStr[i++]) {
        strLenght++;
    }
    int columns = strLenght / key; //number of complete columns
    int remainder = strLenght % key; // the number of values in the last incomplete column
    /*
    for example with key = 5:
        THIS IS A SECRET - > TISTHSEI CSAR  E

        TIST
        HSE
        I_C
        SAR
        __E

        three complete columns and one uncomlete column with one char-value
    */
    i = 0;//decrypted array indexes
    for (int j = 0; j < columns + remainder; j++){
        int k = j;
        while(encrStr[k]){
            str[i++] = encrStr[k];
            if (i == strLenght)
                return;
            if(k < (columns+1)*remainder){ //decryption shift check
                k = k + columns + 1;
            }
            else
                k += columns;
            if(k >= strLenght)
                break;
        }
    }
}
int main()
{
    //task 1
    int key = 0;
    char message[STR_SIZE] = {0};
    char encrMessage[STR_SIZE] = {0};
    char decrMessage[STR_SIZE] = {0};
    printf("Input your message: ");
    gets(message);
    printf("Input encryption key: ");
    scanf("%d",&key);
    caesarEncr(message, encrMessage, key);
    printf("Encrypted message: ");
    puts(encrMessage);
    caesarDecr(decrMessage, encrMessage, key);
    printf("Decrypted message: ");
    puts(decrMessage);

    //task 2
    char encrMessPerm[STR_SIZE] = {0};
    char decrMessPerm[STR_SIZE] = {0};
    printf("\n\nInput encryption key (number of columns ): ");
    scanf("%d",&key);
    permEncr(message, encrMessPerm, key);
    printf("Encrypted message: ");
    puts(encrMessPerm);
    permDecr(decrMessPerm, encrMessPerm, key);
    puts(decrMessPerm);
    return 0;
}
