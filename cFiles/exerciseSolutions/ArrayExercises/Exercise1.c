#include <stdio.h>

int main(){
    int numbers[] = {4, 5, 3, 2, 9, 17, 1, 4};
    int sum = 0;

    int nElements = sizeof(numbers)/sizeof(numbers[0]);

    for(int i = 0; i < nElements; i++){
        sum += numbers[i];
    }

    float average = (float) sum / nElements; // casting float to one forces the other to turn into a float as well! 
    printf("Average: %f\n", average);
}