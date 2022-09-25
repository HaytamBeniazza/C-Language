#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
// ************************************************* GLOBAL VARIABLES: *********************************************************
int choice;
int i, j, PDCont=0; // for loops.
int N;             // Number of products.
int n=0;          // Total number of products.

// *** Date Structure ****
typedef struct {
	int day;
	int mon;
	int year;
	int hour;
	int min;
	int sec;
} Date;
// *** Drugs Structure => product info ****
typedef struct {
	char name[40];
	int code;
	float price;
	int quantity;
} drugs;
// *** purchased drugs Structure => purchased drugs info ****
typedef struct {
	int code;
	int quantity;
	float priceTTC;
	Date date;
} purchasedDrugs;

drugs P[1000]; // Table of products stored in the structure drugs
purchasedDrugs PD[1000]; // Table of purchasedDrugs in the structure drugs

//*************************************************** Functions ******************************************************************

void disMenu() {
	printf ("\n\n\t\t\t             ***************** MENU ******************\n\n");
	printf ("\t\t\t             *****************************************\n");
	printf ("\t\t\t             *                                       *\n");
	printf ("\t\t\t             *        1) Add products                *\n");
	printf ("\t\t\t             *                                       *\n");
	printf ("\t\t\t             *        2) List of products            *\n");
	printf ("\t\t\t             *                                       *\n");
	printf ("\t\t\t             *        3) Buy products                *\n");
	printf ("\t\t\t             *                                       *\n");
	printf ("\t\t\t             *        4) searching products          *\n");
	printf ("\t\t\t             *                                       *\n");
	printf ("\t\t\t             *        5) Stock status                *\n");
	printf ("\t\t\t             *                                       *\n");
	printf ("\t\t\t             *        6) Add to the stock            *\n");
	printf ("\t\t\t             *                                       *\n");
	printf ("\t\t\t             *        7) Delete products             *\n");
	printf ("\t\t\t             *                                       *\n");
	printf ("\t\t\t             *        8) Selling statics             *\n");
	printf ("\t\t\t             *                                       *\n");
	printf ("\t\t\t             *        9) EXIT                        *\n");
	printf ("\t\t\t             *                                       *\n");
	printf ("\t\t\t             *****************************************             \n\n");
	printf ("\t\t\t\t                Entrez votre commande:                                                \n");
	printf ("                                                          ");
	scanf("%d", &choice);
	system("cls");
}
void addProduct() {
	printf("\nHow many products you want to add:\n");
	scanf(" %d", &N);
	Sleep(400);
	system("cls");
	for(i=n; i<N+n; i++) {
		printf("\nPRODUCT %d: ", i+1);
		printf("\nName: ");
		fflush(stdin);
		gets(P[i].name);
		printf("\nCode: ");
		scanf(" %d", &P[i].code);
		printf("\nPrice: ");
		scanf(" %f", &P[i].price);
		printf("\nQuantity: ");
		scanf(" %d", &P[i].quantity);
	}
	n = n+N;
}
//*******Displaying function
void sortingDis(){
	float PTTC;
	for(i=0; i<n; i++) {
		printf("\nPRODUCT %d:\n", i+1);
		printf("NAME: %s \nPRICE: %.2f",P[i].name,P[i].price);
		PTTC =  P[i].price * 0.15 + P[i].price;
		printf("\nPriceTTC: %.2f\n", PTTC);
	}
}
void sortingByAlpha (drugs P[],int N) { // Alpha Sorting Function
    drugs s; // Switching sorting alpha values
	for(i=0; i<N; i++) {
		for(j=i; j<N; j++) {
			if(strcmp(P[i].name,P[j].name)>0) {
				s=P[i];
				P[i]=P[j];
				P[j]=s;
			}
		}
	}

	printf("SORT BY NAME (A-Z):\n");
	sortingDis();
}
void sortingByPrice (drugs P[],int N) {// Price Sorting Function
    drugs temp; // Switching sorting price values
	for (i=0; i<N; i++) {
		for (j=i; j<N; j++) {

			if(P[i].price<P[j].price) {
				temp=P[i];
				P[i]=P[j];
				P[j]=temp;
			}
		}
	}
	printf("\nSORT BY PRICE (HIGHEST TO LOWEST.):\n");
	sortingDis();
}
void affTypeOfOrdering() {
    int y=1;
    int sort;

    if(n==0){
        printf("The list is empty!\nPlease add some products first.\n\n");
    }
    else{do{
        printf("\n1-SORT BY NAME\t\t2-SORT BY PRICE:\n");
        scanf(" %d", &sort);
        if(sort == 1) {
            sortingByAlpha(P, n);
            y--;
        } else if(sort == 2) {
            sortingByPrice(P, n);
            y--;
        } else {
            printf("\nPlease enter a valid number.\n");
        }
    }while(y);
    }

}
//*******Buying function
struct tm timeFunc() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
	return tm;
}
void buyingFunc() {
    int y=1, holdValue1, holdValue2;
    float newPrice;
	struct tm now;
	if(n==0){
        printf("The list is empty!\nPlease add some products first.\n\n");
    }
	else{do{
        printf("\nProduct code: ");
        scanf(" %d", &holdValue1);
        for(i=0; i<n; i++) {
            if(P[i].code == holdValue1){
                printf("\nEnter the quantity: ");
                scanf(" %d", &holdValue2);
                --y;
                if(P[i].quantity >= holdValue2){
                    printf("\nThe order is done.\n");
                    P[i].quantity -= holdValue2;
                    printf("\nName: %s", P[i].name);
                    printf("\nItems: %d", holdValue2);
                    newPrice = P[i].price * holdValue2;
                    printf("\nPRICE : %.2f", newPrice);
                    printf("\nPRICE TTC: %.2f", newPrice*0.15 + newPrice);
    				now=timeFunc();
    				printf("\nDate : %d-%02d-%02d | %02d:%02d:%02d\n",now.tm_mday, now.tm_mon + 1,now.tm_year + 1900, now.tm_hour, now.tm_min, now.tm_sec);
					PD[PDCont].code=holdValue1;
					PD[PDCont].quantity=holdValue2;
					PD[PDCont].priceTTC=newPrice*0.15 + newPrice;
					PD[PDCont].date.day=now.tm_mday;
					PD[PDCont].date.mon=now.tm_mon + 1;
					PD[PDCont].date.year=now.tm_year + 1900;
					PD[PDCont].date.hour=now.tm_hour;
					PD[PDCont].date.min=now.tm_min;
					PD[PDCont].date.sec=now.tm_sec;
					PDCont++;
                }else{
                    printf("\nThe product doesn't have this quantity.\n");
                }
            }
        }
	}while(y);
	}
}
void stockStatus(){
	int e = 0;
	if(n==0){
        printf("The list is empty!\nPlease add some products first.\n\n");
    }
	else{printf("Products with a quantity less than 3 items:\n\n");
	    for(i=0; i<n; i++){
		if(P[i].quantity<3){
			printf("\nName: %s", P[i].name);
			printf("\nCode: %d", P[i].code);
			printf("\nQuantity %d\n\n", P[i].quantity);
			e=1;
		}
		}
		if(e==0) {
			printf("\nAll products has more than 3 items in their quantity.\n\n");
		}
	}
}
void addToStock(){
	int addingValue;
	int added;
	if(n==0){
        printf("The list is empty!\nPlease add some products first.\n\n");
    }
	else{printf("Enter the product code: ");
	scanf(" %d", &addingValue);
	for(i=0; i<n; i++){
		if(addingValue == P[i].code){
			printf("\nADD to the stock:\n");
			printf("Name: %s \n", P[i].name);
			printf("\nQuantity: %d", P[i].quantity);
			printf("\nAdd to the quantity: ");
			scanf(" %d", &added);
			printf("\nNew quantity = %d\n\n", P[i].quantity+=added);
		}
	}
	}
}
void deleteFunc(){
	int codeToDelete, index, D, w;
	if(n==0){
        printf("The list is empty!\nPlease add some products first.\n\n");
    }
	else{printf("\n DELETE PRODUCTS:\n");
	printf("\nHow many products you want to delete:\n");
	scanf(" %d", &D);
	Sleep(400);
	system("cls");
	if(D >= n){
        printf("The store doesn't have this number of items.\n\n");
	}
	else{for(w=0; w<D; w++){
        printf("\nEnter Code: ");
        scanf(" %d", &codeToDelete);
	for(i=0;i<n;i++){
		if(codeToDelete == P[i].code){
			index = i;
		}
	}for(j=index;j<n-1;j++){
	    P[j] = P[j+1];
	}

	n--;}
	}}
}
void searchFunc(){
	int searchCode, searchQuantity, k=0, sChoice;
if(n==0){
        printf("The list is empty!\nPlease add some products first.\n\n");
    }else{
more2:
	printf("\n\t\t\t1-Search By Code\t\t\t 2-Search By Quantity\n");
	scanf(" %d", &sChoice);
	if(sChoice == 1) {
rpt:
		printf("\nCode: ");
		scanf(" %d", &searchCode);
		for(i=0; i<n; i++) {
			if(P[i].code == searchCode) {
				printf("\nName: %s", P[i].name);
				printf("\nCode: %d", P[i].code);
				printf("\nQuantity: %d\n", P[i].quantity);
				k=1;
			}
		     if(k==0){
				printf("\nPlease enter a valid code. ");
				goto rpt;
			}
		}

	}else if(sChoice == 2) {
more:
			printf("\nQuantity: ");
			scanf(" %d", &searchQuantity);
			for(i=0; i<n; i++) {
				if(P[i].code == searchQuantity) {
					printf("\nName: %s", P[i].name);
					printf("\nCode: %d", P[i].code);
					printf("\nQuantity: %d\n\n", P[i].quantity);
					break;
				} else {
					printf("\nThere is no item with this Quantity. ");
					goto more;

				}
			}
	}else{
		printf("\nPlease choose 1 or 2\n");
		goto more2;
	}
    }
}
void staticFunc(){
    int z;
    float totalPrice = 0, avrprice=0,max = PD[0].priceTTC, min=PD[0].priceTTC ;
    if(n==0){
        printf("\nThe list is empty!\nPlease add some products first.\n\n");
    }else{
        for(z=0; z<PDCont; z++){
            totalPrice += PD[z].priceTTC;

        }printf("\nThe total price of items purchased in this current day is:  %.2f\n", totalPrice);
        avrprice = totalPrice / PDCont;
        printf("\nThe average price of the sold items in the current day is: %.2f\n", avrprice);
        for(z=0; z<PDCont-1; z++){
            if(PD[z].priceTTC < PD[z+1].priceTTC){
                max = PD[z+1].priceTTC;
            }if(PD[z].priceTTC > PD[z+1].priceTTC){
                min = PD[z+1].priceTTC;
            }
        }printf("\nThe minimum price is: %.2f\n", min);
        printf("\nThe maximum price is: %.2f\n", max);
        printf("\n \nDate : %02d-%02d\n\n", PD[0].date.day, PD[0].date.mon);

    }
}
//***** The main function *******
int main() {
    again:
	disMenu();

	switch(choice) {
		case 1:
			addProduct();
			break;
		case 2:
			affTypeOfOrdering();
			break;
		case 3:
            buyingFunc();
			break;
		case 4:
			searchFunc();
			break;
		case 5:
			stockStatus();
			break;
		case 6:
			addToStock();
			break;
		case 7:
			deleteFunc();
			break;
		case 8:
            staticFunc();
			break;
        case 9:
            exit(0);
			break;
		default:
            printf("Please enter a number between 1 and 8\n\n");
            break;
	}
	system("PAUSE");
	system("cls");
	goto again;
}
