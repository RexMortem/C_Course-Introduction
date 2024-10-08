#include <stdio.h> 

int main(){
    unsigned char beyondTypicalRange = 254;
    printf("%d\n", beyondTypicalRange);

    beyondTypicalRange += 3; // Demonstrating overflow 
    printf("%d\n", beyondTypicalRange); // 1
}