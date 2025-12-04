#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aeronaves.h"

void cadastrarAeronave(Aeronave **lista){
    Aeronave *n = malloc(sizeof(Aeronave));

    printf("ID: "); fgets(n->id,20,stdin); strtok(n->id,"\n");
    printf("Modelo: "); fgets(n->modelo,50,stdin); strtok(n->modelo,"\n");
    printf("Fabricante: "); fgets(n->fabricante,50,stdin); strtok(n->fabricante,"\n");
    printf("Matrícula/Prefixo: "); fgets(n->matricula,20,stdin); strtok(n->matricula,"\n");
    printf("Ano de fabricação: "); scanf("%d",&n->ano); getchar();
    printf("Tipo (carga/passageiro): "); fgets(n->tipo,20,stdin); strtok(n->tipo,"\n");
    printf("Capacidade de passageiros: "); scanf("%d",&n->capacidade); getchar();

    n->prox = *lista;
    *lista = n;
}

void listarAeronaves(Aeronave *l){
    while(l){
        printf("[%s] %s - %s - %s - Ano: %d - Tipo: %s - %d lugares\n",
               l->id, l->modelo, l->fabricante, l->matricula,
               l->ano, l->tipo, l->capacidade);
        l=l->prox;
    }
}

void salvarAeronaves(Aeronave *l){
    FILE *f = fopen("aeronaves.bin","wb");
    if(!f){ printf("Erro ao abrir arquivo.\n"); return; }
    while(l){
        fwrite(l,sizeof(Aeronave),1,f);
        l=l->prox;
    }
    fclose(f);
    printf("Salvo.\n");
}

void carregarAeronaves(Aeronave **lista){
    FILE *f = fopen("aeronaves.bin","rb");
    if(!f){ printf("Erro ao abrir arquivo.\n"); return; }
    *lista=NULL;
    Aeronave temp;
    while(fread(&temp,sizeof(Aeronave),1,f)){
        Aeronave *n = malloc(sizeof(Aeronave));
        *n=temp;
        n->prox=*lista;
        *lista=n;
    }
    fclose(f);
    printf("Carregado.\n");
}
