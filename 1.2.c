/*
Calcula o fatorial de um número recursivamente
*/

#include <stdio.h>

int fatorial(int i){
    int fat = 0;

    if(i <= 1) return 1;
    else {
        fat = i*fatorial(i-1);
    }

    return fat;
}

int main (int argc, char* argv[]){
    int i;

    printf("Entre um numero para calcular o fatorial: \n");
    scanf("%d", &i);
    printf("O fatorial eh: %d\n", fatorial(i));
}