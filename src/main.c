#include <stdio.h>
#include "discente.h"
#include "menu.h"
#include "turma.h"
#include "curso.h"

void loopDiscente(){
    int flag = 0;
    arquivoPuxarDiscente();
    while(flag != 1){
        telaSecundaria();
        int op = opcao();

        switch(op){
            case 1:
                cadastrarDiscente();
                break;
            case 2:
                editarDiscentes();
                break;
            case 3:
                listarDiscente();
                printf("\nAPERTE ENTER PARA CONTINUAR");
                getchar();
                break;
            case 4:
                excluirDiscente();
                break;
            case 5:
                arquivoSalvarDiscente();
                flag = 1;
                break;
            default:
                break;
        }
    }
}
void loopCurso(){
    int flag = 0;
    arquivoPuxarCurso();
    telaSecundaria();
    while(flag != 1){
        int op = opcao();

        switch(op){
            case 1:
                cadastrarCurso();
                break;
            case 2:
                editarCurso();
                break;
            case 3:
                listarCursos();
                printf("\nAPERTE ENTER PARA CONTINUAR\n");
                getchar();
                break;
            case 4:
                excluirCurso();
                break;
            case 5:
                arquivoSalvarCurso();
                flag = 1;
                break;
            default:
                break;
        }
    }
}

void loopTurma(){
    int flag = 0;
    arquivoPuxarTurma();
    telaSecundaria();
    while(flag != 1){
        int op = opcao();

        switch(op){
            case 1:
                cadastrarTurma();
                break;
            case 2:
                editarTurma();
                break;
            case 3:
                listarTurmas();
                printf("\nAPERTE ENTER PARA CONTINUAR\n");
                getchar();
                break;
            case 4:
                excluirTurma();
                break;
            case 5:
                arquivoSalvarTurma();
                flag = 1;
                break;
            default:
                break;
        }
        telaSecundaria();
    }
}

void primeiraTela(){
    int flag = 0;
    telaPrincipal();
    while(flag != 1){
        int op = opcao();

        switch(op){
            case 1:
                loopDiscente();
                break;
            case 2:
                loopCurso();
                break;
            case 3:
                loopTurma();
                break;
            case 4:
                //relatorio
                break;
            case 5:
                flag = 1;
                break;
            default:
                break;
        }
        telaPrincipal();

    }
}
int main(){
    primeiraTela();
return 0;
}
