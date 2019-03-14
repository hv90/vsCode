/*
Calcula x elevado a n, recursivamente
*/

#include <stdio.h>
#include <stdlib.h>

int calc_pot(int x, int n){
    if (n == 0){
        return 1;
    }
    return x*calc_pot(x, n-1);
}

int main (int argc, char* argv[]){
    if(argc != 3){
        printf("O programa calcula x elevado a n.\n"
        "Entre o valor de x e de n separados por espaco ao lado\n"
        "do comando de execucao deste programa.\n");

        return 666;
    }
    
    int x = atol(argv[1]);
    int n = atol(argv[2]);

    printf("%d elevado a %d = %d", x, n, calc_pot(x, n));
    
}