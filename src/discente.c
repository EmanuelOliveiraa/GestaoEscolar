#include <stdio.h>
#include <string.h>
#include <windows.h>
#define MAX 30
typedef struct{
    char nome[50];
    char cpf[12];
    int idade;
}Discente;

Discente discentes[MAX];
totalDiscente = 0;


void gotoxy(int x,int y){
    COORD coordenada;
    coordenada.X = x;
    coordenada.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordenada);
}

void cadastrarDiscente(){
    Discente temp;
    printf("----------CADASTRO----------");
    printf("ESCREVA O NOME:\n");
    fgets(temp.nome,sizeof(temp.nome),stdin);

    printf("ESCREVA O CPF:\n");
    fgets(temp.cpf,sizeof(temp.cpf),stdin);

    printf("ESCREVA A IDADE:\n");
    scanf("%d",&temp.idade);
    getchar();

    discentes[totalDiscente] = temp;
    totalDiscente++;
}

void listarDiscente(){
    system("cls");
    gotoxy(2,1);
    printf("--------------------LISTA DE DISCENTE--------------------");
    for(int i = 0;i < totalDiscente;i++){
        gotoxy(3,5);
    }

}


