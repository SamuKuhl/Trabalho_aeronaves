#ifndef AERONAVES_H
#define AERONAVES_H

typedef struct aeronave{
    char id[20];          
    char modelo[50];     
    char fabricante[50];  
    char matricula[20];   
    int ano;              
    char tipo[20];       
    int capacidade;       
    struct aeronave *prox;
}Aeronave;

void cadastrarAeronave(Aeronave **lista);
void listarAeronaves(Aeronave *lista);
void salvarAeronaves(Aeronave *lista);
void carregarAeronaves(Aeronave **lista);

#endif
