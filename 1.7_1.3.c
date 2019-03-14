/*
Desenvolver algoritmo não recursivo para o cálculo do fatorial
do inteiro n >= 0, de tal forma que prescinda de armazenamento
de qualquer vetor.
*/


#include <stdio.h>

int fat(int n){
    int res = 1;
    
    for(int i = 1; i <= n; i ++){
        res *= i;
    }
    return res;
}

int main (int argc, char *argv[]){
    int n = 5;

    printf("\n\n\nEste programa calcula o fatorial de um numero\n\n\n"
            "Entre um numero para calcular o fatorial: \n");
    
    scanf("%d", &n);
    printf("O fatorial eh: %d\n",fat(n));

    return 0;
}

