#include <stdio.h>
#include <stdlib.h>

int hashString (char *str) {
    int sum = 0;
    int i = 0;
    while (str[i]){
        sum += str[i++];
        //printf("Sum: %d\n", sum);
    }
    return sum;
}

void coinsSum (int sum, int *coins, int lenght){
    int coinsCount = 0;
    printf ("Coins: ");
    int i = 0;
    while (coins[i]){
        printf("%d ",coins[i++]);
    }
    printf("\n");
    for (int j = 0; j < lenght; j++){
        if (!coins[j] || !sum)
            break;
        if (sum / coins[j]){
            printf("Coin %d x %d\n",coins[j],sum / coins[j]);
            coinsCount += sum / coins[j];
        }
        sum = sum % coins[j];
        //printf ("Sum: %d\n", sum);
    }
    if (!coinsCount)
        printf("The number of coins cannot be found");
    else
        printf("Total number of coins: %d", coinsCount);
}

int main()
{
    //task 1
    const int strLenght = 50;
    char inputStr[strLenght];
    printf("Input string (less than %d characters): ", strLenght);
    gets(inputStr);
    printf("Hash: %d\n\n", hashString(inputStr));


    //task 2
    int sum;
    int coins[10] = {0};
    coins[0] = 50;
    coins[1] = 10;
    coins[2] = 5;
    coins[3] = 2;
    coins[4] = 1;
    printf("Input total sum: ");
    scanf("%d", &sum);
    int lenght = sizeof(coins)/sizeof(int); // lenght of coins array
    coinsSum(sum, coins, lenght);
    return 0;
}
