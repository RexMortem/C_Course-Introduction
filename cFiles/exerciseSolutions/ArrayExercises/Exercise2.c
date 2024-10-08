#include <stdio.h>

int main(){
    float yearAverages[] = {71.4, 69.2, 55.4, 80.1, 76.4, 66.3, 48.0, 57.6, 66.1, 62.3};

    for(int i = 0; i < sizeof(yearAverages)/sizeof(yearAverages[0]); i++){
        if (yearAverages[i] >= 60.0){
            printf("%f\n", yearAverages[i]);
        }
    }
}