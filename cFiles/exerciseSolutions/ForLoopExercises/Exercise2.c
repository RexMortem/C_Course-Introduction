#include <stdio.h>

main(){
    int n = 5;
    int sum = 0;

    for(int i = 2; i <= n; i+=2){
        sum += i*i;
    }

    printf("Sum of square of even integers: %d\n", sum);
}