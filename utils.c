#include <stdio.h>
#include <string.h>
#include "utils.h"

void lerString(char *str, int tamanho) {
    fgets(str, tamanho, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void limparTela(){

}

void pausar (){
    
}