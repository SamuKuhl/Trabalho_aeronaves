#include <stdio.h>
#include <stdlib.h>
#include "aeronaves.h"
#include "rotas.h"
#include "utils.h"

void menuAeronaves(Aeronave **lista){
    int op;
    do{
        printf("\n--- MENU AERONAVES ---\n");
        printf("1. Cadastrar aeronave\n");
        printf("2. Listar aeronaves\n");
        printf("3. Salvar binario\n");
        printf("4. Carregar binario\n");
        printf("0. Voltar\n> ");
        scanf("%d",&op); getchar();
        switch(op){
            case 1: cadastrarAeronave(lista); break;
            case 2: listarAeronaves(*lista); break;
            case 3: salvarAeronaves(*lista); break;
            case 4: carregarAeronaves(lista); break;
        }
    }while(op!=0);
}

void menuRotas(Rota **lista){
    int op;
    do{
        printf("\n--- MENU ROTAS ---\n");
        printf("1. Cadastrar rota\n");
        printf("2. Listar rotas\n");
        printf("3. Salvar binario\n");
        printf("4. Carregar binario\n");
        printf("0. Voltar\n> ");
        scanf("%d",&op); getchar();
        switch(op){
            case 1: cadastrarRota(lista); break;
            case 2: listarRotas(*lista); break;
            case 3: salvarRotas(*lista); break;
            case 4: carregarRotas(lista); break;
        }
    }while(op!=0);
}

int main(){
    Aeronave *listaA = NULL;
    Rota *listaR = NULL;
    int op;
    do{
        printf("\n=== SISTEMA FROTA AEREA ===\n");
        printf("1. Aeronaves\n");
        printf("2. Rotas\n");
        printf("0. Sair\n> ");
        scanf("%d",&op); getchar();
        if(op==1) menuAeronaves(&listaA);
        if(op==2) menuRotas(&listaR);
    }while(op!=0);
    return 0;
}
