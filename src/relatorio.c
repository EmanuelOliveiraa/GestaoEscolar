#include <string.h>
#include <stdio.h>
#include "discente.h"
#include "curso.h"
#include "menu.h"
#include "relatorio.h"


void lsDataDiscente(Discente discentes[], int *totalDiscente){
    arquivoPuxarDiscente(discentes, totalDiscente);
    listarDiscente(discentes, totalDiscente);
    printf("\nAPERTE ENTER PARA CONTINUAR");
    getchar();
}

void lsDataCurso(){
    arquivoPuxarCurso();
    listarCursos();
    printf("\nAPERTE ENTER PARA CONTINUAR");
    getchar();
}

void lsDiscentePorNome(Discente discentes[], int *totalDiscente){
    arquivoPuxarDiscente(discentes, totalDiscente);
    discentePorNome(discentes, totalDiscente);
}
