#include <stdio.h>
#include <stdlib.h>

struct car{
	int fuel_car_cap;
	int seating_car_cap;
	float city_miling;};

int main(){
	struct car c[2];
	int i;

	for(i=0;i<2;i++){
		printf("\nDETAILS OF CAR %d", i+1);
		printf("\nFuel car capacity: ");
		scanf(" %d", &c[i].fuel_car_cap);
		printf("\nSeating car capacity: ");
		scanf(" %d", &c[i].seating_car_cap);
		printf("\nCity miling: ");
		scanf(" %f", &c[i].city_miling);
		printf("\n\n");
	}printf("******************************************\n");
	for(i=0; i<2; i++){
		printf("DETAILS OF THE CAR %d\n", i+1);
		printf("FUEL CAPACITY: %d\n", c[i].fuel_car_cap);
		printf("SEATING CAPACITY: %d\n", c[i].seating_car_cap);
		printf("CITY MILING: %2.f\n", c[i].city_miling);
		printf("\n\n");

	}

	return 0;
}
