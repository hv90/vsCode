#include <stdio.h>

void hanoi(int n, char A, char B, char C){
    if (n > 0){
        hanoi(n-1, 'A', 'C', 'B');
        printf('move o disco do topo de A para B\n');
        hanoi(n-1, 'A', 'B', 'C');
    }
}

int main (int argc, char* argv[]){
    hanoi(8,'A','B', 'C');
}