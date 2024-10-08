#include <stdio.h> 

int main(){
    int a = 3;
    int b = 4;

    for(int i = 1; i <= a; i++){
        for (int j = i; j <= b; j++){ // notice the change from ex3: j starts at i! 
            printf("%d + %d = %d\n", i, j, i+j);
        }
    }
}