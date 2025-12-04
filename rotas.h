#ifndef ROTAS_H
#define ROTAS_H

typedef struct rota{
    char codigo[20];         
    char dataHora[20];        
    char origem[50];       
    char destino[50];       
    float tempoVoo;         
    float combustivel;        
    int passageiros;          
    float carga;             
    char tripulacao[100];     
    char aeronaveAlocada[20];  
    struct rota *prox;
}Rota;

void cadastrarRota(Rota **lista);
void listarRotas(Rota *lista);
void salvarRotas(Rota *lista);
void carregarRotas(Rota **lista);

#endif
