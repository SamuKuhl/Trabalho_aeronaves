#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rotas.h"

void cadastrarRota(Rota **lista){
    Rota *n = malloc(sizeof(Rota));

    printf("Código da rota: "); fgets(n->codigo,20,stdin); strtok(n->codigo,"\n");
    printf("Data e hora (DD/MM/AAAA HH:MM): "); fgets(n->dataHora,20,stdin); strtok(n->dataHora,"\n");
    printf("Origem: "); fgets(n->origem,50,stdin); strtok(n->origem,"\n");
    printf("Destino: "); fgets(n->destino,50,stdin); strtok(n->destino,"\n");
    printf("Tempo estimado de voo (horas): "); scanf("%f",&n->tempoVoo); getchar();
    printf("Combustível necessário (litros): "); scanf("%f",&n->combustivel); getchar();
    printf("Quantidade de passageiros: "); scanf("%d",&n->passageiros); getchar();
    printf("Quantidade de carga útil (kg): "); scanf("%f",&n->carga); getchar();
    printf("Nome dos membros da tripulação: "); fgets(n->tripulacao,100,stdin); strtok(n->tripulacao,"\n");
    printf("Aeronave alocada (código): "); fgets(n->aeronaveAlocada,20,stdin); strtok(n->aeronaveAlocada,"\n");

    n->prox = *lista;
    *lista = n;
}

void listarRotas(Rota *l){
    while(l){
        printf("[%s] %s - %s -> %s - Tempo: %.2f h - Combustível: %.1f L\n",
               l->codigo, l->dataHora, l->origem, l->destino, l->tempoVoo, l->combustivel);
        printf("Passageiros: %d - Carga: %.1f kg\n", l->passageiros, l->carga);
        printf("Tripulação: %s - Aeronave: %s\n\n", l->tripulacao, l->aeronaveAlocada);
        l = l->prox;
    }
}

void salvarRotas(Rota *l){
    FILE *f = fopen("rotas.bin","wb");
    if(!f){ printf("Erro ao abrir arquivo.\n"); return; }
    while(l){
        fwrite(l,sizeof(Rota),1,f);
        l=l->prox;
    }
    fclose(f);
    printf("Salvo.\n");
}

void carregarRotas(Rota **lista){
    FILE *f = fopen("rotas.bin","rb");
    if(!f){ printf("Erro ao abrir arquivo.\n"); return; }
    *lista = NULL;
    Rota temp;
    while(fread(&temp,sizeof(Rota),1,f)){
        Rota *n = malloc(sizeof(Rota));
        *n = temp;
        n->prox = *lista;
        *lista = n;
    }
    fclose(f);
    printf("Carregado.\n");
}
