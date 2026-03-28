#include "menu.h"
#include <windows.h>



void gotoxy(int x,int y){
    COORD coordenada;
    coordenada.X = x;
    coordenada.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordenada);
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
    system("cls");
    printf("----------------------TELA SECUNDARIA---------------------\n");
    printf("1: CADASTRO\n");
    printf("2: EDICAO\n");
    printf("3: LISTAR\n");
    printf("4: EXCLUIR\n");
    printf("5: SAIR\n");
}
