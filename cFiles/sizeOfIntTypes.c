#include <stdio.h> 
#include <stdint.h>

int main(){
    // common types
    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof(short));
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(long));
    printf("%d\n", sizeof(long long));
    
    // guaranteed sizes
    printf("-----------\n");
    printf("%d\n", sizeof(int8_t));
    printf("%d\n", sizeof(int16_t));
    printf("%d\n", sizeof(int32_t));
    printf("%d\n", sizeof(int64_t));
}