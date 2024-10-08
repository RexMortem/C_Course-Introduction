#include <stdio.h> 

main(){
    int a = 3;
    int b = 4;

    for(int i = 1; i <= a; i++){
        for (int j = 1; j <= b; j++){
            printf("%d + %d = %d\n", i, j, i+j);
        }
    }
}