#include <stdio.h>

int main(){
    int uninitialisedArray[10];

    for(int i = 0; i < 10; i++){
        printf("%d ", uninitialisedArray[i]);
    }

    printf("\n");
}

/*
    8 0 4199705 0 8 0 84 0 791520 0

    This is what my output is for the array; so it prints a bunch of gibberish. 
    This is once again an example of Undefined Behaviour (such as in Exercise1 of the Integer Exercises)

    We haven't initialised the values, so the elements of the array are whatever was in memory before the memory is used by C. 
    Therefore, it's Undefined Behaviour since we can't predict what the elements of the array are going to be! 

    This can be quite confusing to debug in a large complex program, so try to avoid programming Undefined Behaviour at all costs. 
*/