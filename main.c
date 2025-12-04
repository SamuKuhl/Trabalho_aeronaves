#include <stdio.h>
#include "aeronaves.h"
#include "rotas.h"
#include "utils.h"

int main() {
    inicializarAeronaves();
    inicializarRotas();

    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Cadastrar aeronave\n");
        printf("2 - Listar aeronaves\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: cadastrarAeronave(); break;
            case 2: listarAeronaves(); break;
        }

    } while (opcao != 0);

    return 0;
}
#include <stdio.h>
#include "aeronaves.h"
#include "rotas.h"
#include "utils.h"

int main() {
    inicializarAeronaves();
    inicializarRotas();

    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Cadastrar aeronave\n");
        printf("2 - Listar aeronaves\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: cadastrarAeronave(); break;
            case 2: listarAeronaves(); break;
        }

    } while (opcao != 0);

    return 0;
}
