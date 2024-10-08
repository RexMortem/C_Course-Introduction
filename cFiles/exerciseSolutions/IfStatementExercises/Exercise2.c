#include <stdio.h>

int main(){
    int mana = 70; // mana points
    int lastCast = 1500; // milliseconds
    int distance = 3; // cells/blocks 

    if(mana < 35){
        printf("Cannot cast spell: Not enough mana (%d/35)!", mana);
    } else if(lastCast < 2000){
        printf("Cannot cast spell: You're still on cooldown (%d milliseconds left)!", 2000 - lastCast);
    } else if (distance > 3){
        printf("Cannot cast spell: Not within range!");
    }else{
        printf("Cast spell!");
    }
}