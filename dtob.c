#include <stdio.h>

// log_2 연산으로 이 수가 몇 비트를 사용할 지 계산 가능

void printZinsu(long long int x, int zinsu);

int main(){
    long long int x;
    int iter;
    scanf("%d", &iter);
    while(iter--){
        scanf("%lld", &x);
        printZinsu(x, 2);
        printZinsu(x, 16);
    }
    return 0;
}

void printZinsu(long long int x, int zinsu){
    long long int result[100], quotient = x;
    int remainder, index = 0;

    while(quotient != 0){
        remainder = quotient % (long long int)zinsu;
        quotient = quotient / (long long int)zinsu;
        result[index] = remainder;
        index++;
    }
    printf("%lld = ", x);
    if(zinsu == 2){
        printf("0b");
        for(int i = index - 1; i >= 0; i--)
            printf("%lld", result[i]);
    }

    else if(zinsu == 16){
        printf("0x");
        for(int i = index - 1; i >= 0; i--)
            printf("%x", result[i]);
    }
    
    else if(zinsu == 8){
        printf("0o");
        for(int i = index - 1; i >= 0; i--)
            printf("%x", result[i]);
    }
    printf("\n");
}