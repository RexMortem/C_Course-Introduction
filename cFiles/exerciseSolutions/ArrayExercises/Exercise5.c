#include <stdio.h>

int main(){
    int arr[] = {1,2};
    int largeNumber = 10000000;

    // Let's cause a segmentation fault! 
    printf("(Probably) a seg fault incoming :D\n");
    
    int d;

    for(int i = 2; i<largeNumber; i++){
        d = arr[i];
    }
}