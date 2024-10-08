#include <stdio.h>

int main(){
    char maxVal = 127;
    maxVal++; // integer overflow! 

    printf("%d\n", maxVal); // output: -128

    char minVal = -128; 
    minVal--; // integer underflow! 

    printf("%d\n", minVal); // output: 127
}

