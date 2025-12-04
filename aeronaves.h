#ifndef AERONAVES_H
#define AERONAVES_H
#define MAX_AERONAVES 100


typedef struct {
    int id;
    char modelo[50];;
} Aeronave;


void inicializarAernaves();
void cadastrarAeronave();
void listarAeronaves();
void removerAeronave();
void buscarAeronave();
void editarAeronave();

#endif
