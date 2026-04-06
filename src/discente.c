#include <stdio.h>
#include <string.h>
#define MAX 30
#include "menu.h"
#include "discente.h"

Discente discentes[MAX];
int totalDiscente = 0;


void cadastrarDiscente(){
    limparTela();
    Discente temp;
    printf(" ------------------------CADASTRO DISCENTE------------------------\n");
    printf("ESCREVA O NOME: ");
    fgets(temp.nome,sizeof(temp.nome),stdin);
    temp.nome[strcspn(temp.nome, "\n")] = '\0';

    printf("ESCREVA O CPF: ");
    fgets(temp.cpf,sizeof(temp.cpf),stdin);
    temp.cpf[strcspn(temp.cpf, "\n")] = '\0';

    printf("ESCREVA A IDADE: ");
    scanf("%d",&temp.idade);
    getchar();

    discentes[totalDiscente] = temp;
    totalDiscente++;

    printf("\nDISCENTE CADASTRADO!\n");
    getchar();
    limparTela();
    return;
}

void listarDiscente(){
    int i = 0;
    limparTela();
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
    for(i;i < totalDiscente;i++){
        gotoxy(2,5 + i);
        printf("%d: %s", i ,discentes[i].nome);
        gotoxy(27,5 + i);
        printf("%s",discentes[i].cpf);
        gotoxy(47,5 + i);
        printf("%d",discentes[i].idade);
    }
}

int buscarDiscenteNome(){
    char tempNome[50];
    fgets(tempNome,sizeof(tempNome),stdin);
    tempNome[strcspn(tempNome, "\n")] = '\0';

    for(int i = 0;i < totalDiscente;i++){
        if(strcmp(tempNome,discentes[i].nome) == 0){
            printf("NOME ENCONTRADO!\n");
            return i;
        }
    }
    return -1;
}

void editarDiscentes(){
    Discente temp;

    limparTela();
    listarDiscente();
    printf("\nESCREVA O NOME DO DISCENTE PARA EDITAR\n");
    int posicao = buscarDiscenteNome();
    printf("APERTE ENTER PARA EDITAR");
    getchar();
    limparTela();
    if(posicao == -1){
        printf("\nNOME NAO ENCONTRADO OU INCORRETO\n");
        printf("APERTE ENTER PARA VOLTAR A TELA SECUNDARIA");
        getchar();
        return;
    }
    printf("--------------------------EDITAR--------------------------\n");
    printf("NOME: ");
    fgets(temp.nome,sizeof(temp.nome),stdin);
    temp.nome[strcspn(temp.nome, "\n")] = '\0';

    printf("CPF: ");
    fgets(temp.cpf,sizeof(temp.cpf),stdin);
    temp.cpf[strcspn(temp.cpf, "\n")] = '\0';

    printf("IDADE: ");
    scanf("%d",&temp.idade);
    getchar();

    discentes[posicao] = temp;

    printf("\nEDICAO CONCLUIDA!\n");
    printf("APERTE ENTER PARA CONTINUAR");
    getchar();
    limparTela();
}

void excluirDiscente(){
    int id;
    printf("------------------------EXCLUIR------------------------\n");
    listarDiscente();
    printf("\nESCREVA O ID DO DISCENTE PARA EXCLUIR\n");
    scanf("%d",&id);
    getchar();
    if(id < 0 || id >= totalDiscente){
        printf("ID INVALIDO\n");
        printf("APERTE ENTER PARA CONTINUAR");
        getchar();
        return;
    }
    for(int i = id;i < totalDiscente;i++){
        discentes[i] = discentes[i + 1];
    }
    totalDiscente--;
    listarDiscente();
    printf("OPERACAO CONCLUIDA\n");
    printf("APERTE ENTER PARA CONTINUAR");
    getchar();
}

void arquivoSalvarDiscente(){
    FILE *file = fopen("discente.txt", "w");

    if(file == NULL){
        printf("\nERRO AO ABRIR ARQUIVO!\n");
        printf("APERTE ENTER PARA VOLTAR\n");
        getchar();
        return;
    }
    for(int i = 0;i < totalDiscente;i++){
        fprintf(file,"%s;%s;%d",discentes[i].nome,discentes[i].cpf,discentes[i].idade);
    }
    fclose(file);
}

void arquivoPuxarDiscente(){
    FILE *file = fopen("discente.txt","r");
    Discente temp;
    totalDiscente = 0;
    if(file == NULL){
        printf("\nERRO AO ABRIR ARQUIVO!\n");
        printf("APERTE ENTER PARA VOLTAR\n");
        getchar();
        return;
    }

    while(fscanf(file,"%[^;];%[^;];%d",temp.nome,temp.cpf,&temp.idade) == 3){
        discentes[totalDiscente] = temp;
        totalDiscente++;
    }
    fclose(file);
}
