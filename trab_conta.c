#include <stdio.h>

int main (void){
    
    char string[100];

    while(scanf("%s", &string)==1 && !feof(stdin)){
        printf("%s\n", string);
    }
    printf("%s\n", string);    
}