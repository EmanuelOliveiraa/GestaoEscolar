#include <stdio.h>
#include "discente.h"
#include "menu.h"
#include "turma.h"
#include "curso.h"
#include "relatorio.h"
#define MAX 30
Discente discentes[MAX];
    int totalDiscente = 0;

void loopDiscente(){
    int flag = 0;
    arquivoPuxarDiscente(discentes,&totalDiscente);
    while(flag != 1){
        telaSecundaria();
        int op = opcao();

        switch(op){
            case 1:
                cadastrarDiscente(discentes,&totalDiscente);
                ordenarDiscente(discentes,&totalDiscente);
                break;
            case 2:
                editarDiscentes(discentes,&totalDiscente);
                break;
            case 3:
                listarDiscente(discentes,&totalDiscente);
                printf("\nAPERTE ENTER PARA CONTINUAR");
                getchar();
                break;
            case 4:
                excluirDiscente(discentes,&totalDiscente);
                break;
            case 5:
                arquivoSalvarDiscente(discentes,&totalDiscente);
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
    while(flag != 1){
        telaSecundaria();
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
    while(flag != 1){
        telaSecundaria();
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
    }
}

void primeiraTela(){
    int flag = 0;
    while(flag != 1){
        limparTela();
        telaPrincipal();
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
                lsDiscentePorNome();
                break;
            case 5:
                printf("\nPROGRAMA ENCERRADO");
                flag = 1;
                break;
            default:
                break;
        }
    }
}

int main(){

    primeiraTela();
    return 0;
}


