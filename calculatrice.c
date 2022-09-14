#include <stdio.h.>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(){

    float a;
    float b;
    float result;
    int type;


    again:
    printf("\n\t\t\t\t1:sum\t2:substraction\t3:division\t4:product");
    printf("\n\n\t\t\t\t5:cos\t6:sin\t\t7:tan\t\t8:ln");
    printf("\n\n\t\t\t\t9:exp\t10:racine\t11:power\t11:EMJ\n\n");
    printf("\t\t\t\tChoose a number: ");
    scanf("%d", &type);

    switch(type){
        case 1:
            printf("\n\n\n\n\t\t\t\tEnter the first number: ");
            scanf("%f", &a);
            printf("\n\t\t\t\tEnter the second number: ");
            scanf("%f", &b);
            result = a + b;
            printf("\n\t\t\t\tresult = %.4f\n\n\n\n\n", result);
            break;
        case 2:
            printf("\n\n\n\n\t\t\t\tEnter the first number: ");
            scanf("%f", &a);
            printf("\n\t\t\t\tEnter the second number: ");
            scanf("%f", &b);
            result = a - b;
            printf("\n\t\t\t\tresult = %.4f\n\n\n\n\n", result);
            break;
        case 3:
            printf("\n\n\n\n\t\t\t\tEnter the first number: ");
            scanf("%f", &a);
            printf("\n\t\t\t\tEnter the second number: ");
            scanf("%f", &b);
            if(b==0){
            printf("\n\t\t\t\tErreur!, can't divide by 0.\n\n\n");
            break;
            }else{
            result = a / b;
            printf("\n\t\t\t\tresult = %.4f\n\n\n\n\n", result);}
            break;
        case 4:
            printf("\n\n\n\n\t\t\t\tEnter the first number: ");
            scanf("%f", &a);
            printf("\n\t\t\t\tEnter the second number: ");
            scanf("%f", &b);
            result = a * b;
            printf("\n\t\t\t\tresult = %.4f\n\n\n\n\n", result);
            break;
		case 5:
            printf("\n\n\n\n\t\t\t\tCos");
            scanf("%f", &a);
            result = cos(a);
            printf("\n\t\t\t\tresult = %.4f\n\n\n\n\n", result);
            break;
        case 6:
            printf("\n\n\n\n\t\t\t\tSin");
            scanf("%f", &a);
            result = sin(a);
            printf("\n\t\t\t\tresult = %.4f\n\n\n\n\n", result);
            break;
        case 7:
            printf("\n\n\n\n\t\t\t\tTan");
            scanf("%f", &a);
            result = tan(a);
            printf("\n\t\t\t\tresult = %.4f\n\n\n\n\n", result);
            break;
        case 8:
            printf("\n\n\n\n\t\t\t\tLn");
            scanf("%f", &a);
            if(a<=0){
                printf("\n\n\t\t\t\tErreur!, must be bigger than 0.\n\n\n");
            }else{
            result = log(a);
            printf("\n\t\t\t\tresult = %.4f\n\n\n\n\n", result);}
            break;
        case 9:
            printf("\n\n\n\n\t\t\t\texp");
            scanf("%f", &a);
            result = exp(a);
            printf("\n\t\t\t\tresult = %.4f\n\n\n\n\n", result);
            break;
        case 10:
            printf("\n\n\n\n\t\t\t\tracine");
            scanf("%f", &a);
            if(a<0){
                printf("\n\n\t\t\t\tErreur!, must be bigger or equal to 0.\n\n\n");
            }else{
            result = sqrt(a);
            printf("\n\t\t\t\tresult = %.4f\n\n\n\n\n", result);}
            break;
        case 11:
            printf("\n\n\n\n\t\t\t\tEnter the base: ");
            scanf("%f", &a);
            printf("\n\t\t\t\tEnter the exponent: ");
            scanf("%f", &b);
            result = pow(a, b);
            printf("\n\t\t\t\tresult = %.4f\n\n\n\n\n", result);
            break;
            
        default:printf("\n\n\t\t\t\tplease choose a number between 1 to 12.\n\n\n\n\n");break;

    }goto again;
    return 0;
}
