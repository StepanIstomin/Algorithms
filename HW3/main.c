#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n; // n - checked number
    int a = 1;// a - answer, 1-integer 0-not integer
    printf("Input integer number:");
    scanf("%d", &n);
    if (n > 1) {
        if (n == 2 || n == 3){}
        else {
            int sq = sqrtf(n);
            for (int d = 2;d <= sq;d++){
                if(n % d == 0){
                    a = 0;
                    break;
                }
            }
        }
    }
    else
        a = 0;
    (a == 1)? printf("%d is a PRIME number",n):printf("%d is NOT a prime number",n);
    return 0;
}
