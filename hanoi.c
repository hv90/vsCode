#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv){
    int destino[argc];

    printf("destino antes: %d\n", sizeof(destino));

    for(int i = 0; i < argc; i++){
        destino[i] = atol(argv[i+1]);
    }
    

    printf("destino depois: %d\n", sizeof(destino));
}