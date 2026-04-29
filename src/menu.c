#include "menu.h"
#include <stdio.h>
//#include <windows.h>



void gotoxy(int y,int x){ // so trocar a posi do x e y
    /*COORD coordenada;
    coordenada.X = x;
    coordenada.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordenada);
    */
    printf("\033[%d;%dH", x, y);
}
void telaPrincipal(){
    printf("-----------------------TELA INICIAL-----------------------\n");
    printf("1: DISCENTES\n");
    printf("2: CURSOS\n");
    printf("3: TURMAS\n");
    printf("4: RELATORIOS\n");
    printf("5: SAIR\n");
}
void telaSecundaria(){
    limparTela();
    printf("----------------------TELA SECUNDARIA---------------------\n");
    printf("1: CADASTRO\n");
    printf("2: EDICAO\n");
    printf("3: LISTAR\n");
    printf("4: EXCLUIR\n");
    printf("5: SAIR\n");
}
void telaRelatorio(){
    limparTela();
    printf("----------------------TELA RELATORIO---------------------\n");
    printf("1: LISTAR TODOS OS DISCENTES\n");
    printf("2: LISTAR TODOS OS CURSOS\n");
    printf("3: LISTAR DISCENTE POR NOME\n");
    printf("4: SAIR\n");
}
void limparTela(){
    printf("\033[H\033[J");
}
int opcao(){
    int op;
    scanf("%d",&op);
    getchar();
    if(op > 0 && op < 6){
        return op;
    }else{
        printf("OPCAO INVALIDA");
        printf("APERTE ENTER PARA CONTINUAR");
        getchar();

        return -1;
    }
}
