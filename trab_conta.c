//DRE: 116012155
//Data: 24/03/2019
//
//Input: texto sem acentos graficos digitado a partir do teclado
//Output: valor da frequencia de cada palavra. Exibe em ordem pela tabela ASCII
//
//Descricao: Utiliza uma lista encadeada (Linked List) para guardar o texto
//           na proporcao palavras/no.
//           Se houver caractere repetido soma 1 ao campo frequencia.
//           Em seguida, ordena a lista encadeada e exibe na tela.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_TAM 20

typedef struct _LLNODE
{
    int frequencia;
    char palavra[STR_TAM];
    struct _LLNODE *nextPtr;
}LLNODE;

//--------------------------------------------
void LLprint(LLNODE *head){
    LLNODE *current = head;
    
    if(current == NULL) perror("A lista estah vazia.");

    while(current != NULL){
        printf("%s - %d\n", current->palavra, current->frequencia);
        current = current->nextPtr;
    }
}

//--------------------------------------------
LLNODE* findByStr(LLNODE *ptr, char *str){
    LLNODE *current = ptr;

    while(current != NULL){
        if(strcmp(current->palavra, str) == 0){
            return current;
        }
        current = current->nextPtr;
    }
    return NULL;
}
//--------------------------------------------
void LLinsert(LLNODE **head, char* str){
    LLNODE *newPtr = malloc(sizeof(LLNODE));
    LLNODE *ehRepetidoPtr;

    if(newPtr != NULL){
        ehRepetidoPtr = findByStr(*head, str);

        if(ehRepetidoPtr == NULL){
            strcpy(newPtr->palavra, str);
            newPtr->frequencia = 1;
            newPtr->nextPtr = *head;
            *head = newPtr;
        }else{
            ehRepetidoPtr->frequencia++;
            }
    }else{
        perror("Nao foi possivel alocar memoria para inserir.");
        }
}
//--------------------------------------------
LLNODE* achaMenor(LLNODE *head){
    LLNODE *currPtr = head;
    LLNODE *menor = head;
    char *temp;
    int freq;

    while(currPtr != NULL){
        if(strcmp(menor->palavra, currPtr->palavra) > 0){
            temp = malloc(strlen(menor->palavra)*sizeof(char));
            strcpy(temp, menor->palavra);
            freq = menor->frequencia;

            strcpy(menor->palavra, currPtr->palavra);
            menor->frequencia = currPtr->frequencia;

            strcpy(currPtr->palavra, temp);
            currPtr->frequencia = freq;
        }
        currPtr = currPtr->nextPtr;
    }
    return menor;
}

//--------------------------------------------
void LLsort(LLNODE **head){
    LLNODE *currPtr = *head;
    LLNODE *menor = NULL;
    int freq;
    char *temp;

    while(currPtr != NULL){
        menor = achaMenor(currPtr);

        temp = malloc(strlen(menor->palavra)*sizeof(char));
        strcpy(temp, menor->palavra);
        freq = menor->frequencia;

        strcpy(menor->palavra, currPtr->palavra);
        menor->frequencia = currPtr->frequencia;

        strcpy(currPtr->palavra, temp);
        currPtr->frequencia = freq;

        currPtr = currPtr->nextPtr;
    }
    
}


//--------------------------------------------
int main (void){
    
    char string[1000];
    LLNODE *head = NULL;

    while(!feof(stdin)){
        if(scanf("%s", &string) == 1){
            LLinsert(&head, string);
        }        
    }

    LLsort(&head);
  
    LLprint(head);



  return 0;
}





