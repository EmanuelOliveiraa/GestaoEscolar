#include <stdio.h>








void mostrarDiscente(Discente *discente){
    printf("Nome do discente: %s\n",discente->nome);
    printf("");
}

int main(){

    Discente aluno1;

    cadastrarDiscente(&aluno1);
    arquivoDiscente(&aluno1);
    arquivoMostrarDiscente();

    return 0;
}