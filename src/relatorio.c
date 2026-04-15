#include <string.h>
#include <stdio.h>
#include "discente.h"
#include "curso.h"
#include "menu.h"
#include "relatorio.h"


void lsDataDiscente(){
    listarDiscente();
    printf("\nAPERTE ENTER PARA CONTINUAR");
    getchar();
}

void lsDataCurso(){
    listarCursos();
    printf("\nAPERTE ENTER PARA CONTINUAR");
    getchar();
}

void lsDiscentePorNome(){
    discentePorNome();
}
