#include <stdio.h>
#include <string.h>
#define MAX 30
#include "menu.h"
#include "discente.h"


int totalDiscente = 0;


void cadastrarDiscente(){
    system("cls");
    Discente temp;
    printf(" ------------------------CADASTRO------------------------\n");
    printf("ESCREVA O NOME: ");
    fgets(temp.nome,sizeof(temp.nome),stdin);

    printf("ESCREVA O CPF: ");
    fgets(temp.cpf,sizeof(temp.cpf),stdin);

    printf("ESCREVA A IDADE: ");
    scanf("%d",&temp.idade);
    getchar();

    discentes[totalDiscente] = temp;
    totalDiscente++;

    printf("\nDISCENTE CADASTRADO!\n");
    system("pause");
    system("cls");
    return;
}

void listarDiscente(){
    system("cls");
    gotoxy(1,1);
    printf("---------------------------------------------------------");
    gotoxy(20,2);
    printf("LISTA DE DISCENTES");
    gotoxy(1,3);
    printf("---------------------------------------------------------");
    gotoxy(2,4);
    printf("ID");
    gotoxy(5,4);
    printf("NOME");
    gotoxy(27,4);
    printf("CPF");
    gotoxy(47,4);
    printf("IDADE");
    for(int i = 0;i < totalDiscente;i++){
        gotoxy(2,5 + i);
        printf("%d: %s", i + 1 ,discentes[i].nome);
        gotoxy(27,5 + i);
        printf("%s",discentes[i].cpf);
        gotoxy(47,5 + i);
        printf("%d",discentes[i].idade);
    }
    printf("\n");
    system("pause");
}
int buscarDiscenteNome(){
    char tempNome[MAX];
    system("cls");
    listarDiscente();
    printf("\n\n");
    printf("\n\nESCREVA O NOME DO DISCENTE PARA EDITAR\n");
    fgets(tempNome,sizeof(tempNome),stdin);

    for(int i = 0;i < totalDiscente;i++){
        if(strcmp(tempNome,discentes[i].nome) == 0){
            return i;
        }else{
            printf("NOME NAO ENCONTRADO OU INCORRETO");
            return -1;
        }
    }
}
void editarDiscentes(){
    Discente temp;
    int posicao = buscarDiscenteNome();
    system("cls");
    if(posicao == -1){
        return;
    }
    printf("--------------------------EDITAR--------------------------\n");
    printf("NOME: ");
    fgets(temp.nome,sizeof(temp.nome),stdin);
    printf("CPF: ");
    fgets(temp.cpf,sizeof(temp.cpf),stdin);
    printf("IDADE: ");
    scanf("%d",&temp.idade);
    getchar();
    discentes[posicao] = temp;

    printf("\nEDICAO CONCLUIDA!\n");
    system("pause");
    system("cls");
}
void excluirDiscente(){
    int id;
    printf("------------------------EXCLUIR------------------------\n");
    listarDiscente();
    printf("\nESCREVA O ID DO DISCENTE PARA EXCLUIR\n");
    scanf("%d",&id);
    if(id < 0 || id > totalDiscente){
        printf("ID INVALIDO\n");
        system("pause");
        return;
    }
    getchar();
    for(int i = id;i < totalDiscente;i++){
        discentes[i] = discentes[i + 1];
    }
    totalDiscente--;
    listarDiscente();


}

int opcao(){
    int op;
    scanf("%d",&op);
    getchar();
    if(op > 0 && op < 5){
        return op;
    }else{
        printf("OPCAO INVALIDA");
        return -1;
    }
}


