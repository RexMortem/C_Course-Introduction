#include <stdio.h>

main(){
    int n = 5;
    int sum = 0;

    for(int i = 1; i <= n; i++){
        sum += i;
    }

    printf("Sum: %d\n", sum);
}