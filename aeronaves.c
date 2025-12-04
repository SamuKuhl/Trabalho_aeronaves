#include <stdio.h>
#include <string.h>
#include "aeronaves.h"
#include "utils.h"

static Aeronave frota[MAX_AERONAVES];
static int totalAeronaves = 0;

void inicializarAeronaves() {
    totalAeronaves = 0;
}

void cadastrarAeronave() {
    if (totalAeronaves >= MAX_AERONAVES) {
        printf("Limite máximo atingido \n");
        return;
    }

Aeronave a;
a.id = totalAeronaves + 1;

printf("Modelo da aeronave: ");
lerString(a.modelo, 50);

}