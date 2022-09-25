#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int n, i, j, k;

    printf("Enter the number of lines you want in your pyramid\n");
    scanf(" %d", &n);

    for(j=1; j<=n; j++){
        for(i=j; i<=n; i++){
            printf(" ");
        }for(k=1; k<=j*2-1; k++){
            printf("*");
        }printf("\n");
    }
    return 0;
}
