#include <stdio.h>

main(){
    int mana = 70; // mana points
    int lastCast = 1500; // milliseconds
    int distance = 3; // cells/blocks 

    if((mana >= 35) && (lastCast >= 2000) && (distance <= 3)){
        printf("Cast spell!");
    }else{
        printf("Cannot cast spell!");
    }
}