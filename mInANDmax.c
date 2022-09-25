#include <stdio.h>
#include <stdlib.h>

int main(){
    int T[5], i, j, temp, Min=0, Max=0;

	for(i=0; i<5; i++){
		printf("\nNumber %d: ", i+1);
		scanf(" %d", &T[i]);
	}
	for(i=0; i<5; i++){
		for(j=i+1; j<5; j++){
			if(T[i]>T[j]) {
				temp = T[i];
				T[i] = T[j];
				T[j] = temp;
			}
        }
    }
	for(i=0; i<=3; i++){
		Min = Min + T[i];

		Max = Max + T[i+1];

	}
	printf("\nMin: %d", Min);
	printf("\nMax: %d", Max);

	return 0;
}
