#include <stdio.h>

int main(){
    int a = 3;
    int b = 2;

    float result = a/b; // Without explicit casting
    printf("%f\n", result); // 1.000000

    result = (float) a / (float) b; // With explicit casting
    printf("%f\n", result); // 1.500000
}

