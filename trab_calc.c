
/*
Nome: Hugo Machado de Almeida
DRE: 116012155
Descricao do programa:
    Na notacao reversa polonesa, os operadores aparecem 
    na ordem em que devem ser operados: da esquerda para a direita.
    Assim, o programa recebe uma expressao aritmetica e devolve o resultado 
    utilizando o conceito de notação reversa polonesa. 
    Para fazer isso, ele primeiro separa as entradas em pilhas de operadores e operandos.
    Após isso, o programa percorre a pilha de operadores procurando pelo primeiro ')', 
    quando então o programa interrompe o percurso da pilha para resolver os operadores e 
    operandos em um percurso reverso limpando as pilhas a cada iteração.
    Após isto, o programa volta a percorrer a pilha.
    Para casos de surgirem numeros maiores que 9, escolheu-se utilizar uma variável 
    "foiNumero" para saber o momento de avancar uma casa decimal. 
    O conceito é: se o digito anterior foi numero e o atual tambem é, 
    entao uma casa decimal deve ser adicionada.
Exemplo: ((15/(7−(1+1)))*3)−(2+(1+1)) = 15 7 1 1 + − ÷ 3 × 2 1 1 + + −
Pilhas:  |15||7||1||1||3||2||1||1|
        |/||-||+||)||)||)||*||)||-||+||+||)||)|
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int operandosTopo = 0;

int solve(int b, char operador, int a, int result){//resolve uma equacao
     switch(operador){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        default:            
            return result;//nao eh uma expressao
    } 
} 


int main (void){    
    int operandos[1000];
    int operandosTopo = 0;
    char operadores[1000];    
    int operadoresTopo = 0;
    char caractere;
    int pos = 0;
    int foiNumero = 0;//gatilho para subir uma casa decimal
    int result = 0;
    
    while(!feof(stdin)){
        if(scanf("%c", &caractere) == 1){
            switch(caractere){//contanto que a expressao nao ache um ')', 
                            //os demais sao inseridos nas proprias pilhas
                case '(':
                    break;
                case ')'://refaz o percurso da expressao pelo caminho de quem esta voltando              
                    while(operadoresTopo > 0 && operandosTopo > 0){
                        result = solve(operandos[operandosTopo-1], operadores[--operadoresTopo], operandos[operandosTopo-2],result);
                        operandosTopo--;                        
                        operandos[operandosTopo-1] = result;                        
                    }
                case '+':
                    operadores[operadoresTopo++] = caractere;
                    foiNumero = 0;
                    break;
                case '-':
                    operadores[operadoresTopo++] = caractere;
                    foiNumero = 0;
                    break;
                case '*':
                    operadores[operadoresTopo++] = caractere;
                    foiNumero = 0;
                    break;
                case '/':
                    operadores[operadoresTopo++] = caractere;
                    foiNumero = 0;
                    break;
                default:
                    operandos[operandosTopo++] = caractere - '0';//converte char para int
                    if(foiNumero > 0){// conceito: se o digito anterior foi numero,
                                    //entao deve-se subir uma casa decimal
                        operandos[operandosTopo-2] =  operandos[operandosTopo-2]*10 + operandos[--operandosTopo];
                    }                    
                    foiNumero++;
            }
        }
    }    
    printf("%d ", result);                   
}