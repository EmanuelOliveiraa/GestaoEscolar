#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "discente.h"







void cadastrarDiscente(Discente discentes[],int *totalDiscente){
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

    discentes[*totalDiscente] = temp;
    (*totalDiscente)++;

    printf("\nDISCENTE CADASTRADO!\n");
    getchar();
    limparTela();
    return;
}

void listarDiscente(Discente discentes[],int *totalDiscente){
    int cont = 0;
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
    for(int i = 0;i < *totalDiscente;i++){
        gotoxy(2,5 + cont);
        printf("%d: %s", i ,discentes[i].nome);
        gotoxy(27,5 + cont);
        printf("%s",discentes[i].cpf);
        gotoxy(47,5 + cont);
        printf("%d",discentes[i].idade);
        cont++;
    }
}

int buscarDiscenteNome(Discente discentes[],int *totalDiscente){
    char tempNome[50];
    fgets(tempNome,sizeof(tempNome),stdin);
    tempNome[strcspn(tempNome, "\n")] = '\0';

    for(int i = 0;i < *totalDiscente;i++){
        if(strcmp(tempNome,discentes[i].nome) == 0){
            printf("NOME ENCONTRADO!\n");
            return i;
        }
    }
    return -1;
}

void editarDiscentes(Discente discentes[],int *totalDiscente){
    Discente temp;

    limparTela();
    listarDiscente(discentes,totalDiscente);
    printf("\nESCREVA O NOME DO DISCENTE PARA EDITAR\n");
    int posicao = buscarDiscenteNome(discentes,totalDiscente);
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

void excluirDiscente(Discente discentes[],int *totalDiscente){
    int id;
    printf("------------------------EXCLUIR------------------------\n");
    listarDiscente(discentes,totalDiscente);
    printf("\nESCREVA O ID DO DISCENTE PARA EXCLUIR\n");
    scanf("%d",&id);
    getchar();
    if(id < 0 || id >= *totalDiscente){
        printf("ID INVALIDO\n");
        printf("APERTE ENTER PARA CONTINUAR");
        getchar();
        return;
    }
    for(int i = id;i < *totalDiscente;i++){
        discentes[i] = discentes[i + 1];
    }
    (*totalDiscente)--;
    listarDiscente(discentes,totalDiscente);
    printf("OPERACAO CONCLUIDA\n");
    printf("APERTE ENTER PARA CONTINUAR");
    getchar();
}

void arquivoSalvarDiscente(Discente discentes[],int *totalDiscente){
    FILE *file = fopen("C:\\Users\\Aluno\\Documents\\escola\\discente.txt.txt", "w");

    if(file == NULL){
        printf("\nERRO AO ABRIR ARQUIVO!\n");
        printf("APERTE ENTER PARA VOLTAR\n");
        getchar();
        return;
    }
    for(int i = 0;i < *totalDiscente;i++){
        fprintf(file,"%s;%s;%d\n",discentes[i].nome,discentes[i].cpf,discentes[i].idade);
    }
    fclose(file);
}

void arquivoPuxarDiscente(Discente discentes[],int *totalDiscente){
    FILE *file = fopen("C:\\Users\\Aluno\\Documents\\escola\\discente.txt.txt", "r");

    Discente temp;
    *totalDiscente = 0;
    if(file == NULL){
        perror("erro");
        printf("\nERRO AO ABRIR ARQUIVO!\n");
        printf("APERTE ENTER PARA VOLTAR\n");
        getchar();
        return;
    }

    while(fscanf(file,"%[^;];%[^;];%d\n",temp.nome,temp.cpf,&temp.idade) == 3){
        discentes[*totalDiscente] = temp;
        (*totalDiscente)++;
    }
    fclose(file);
}


void ordenarDiscente(Discente discentes[],int *totalDiscente){
    int i, k,j;
    Discente temp;
    for(i=0; i < *totalDiscente-1; i++) {
        k = i;
        for(j=i+1; j<*totalDiscente; j++){
            if( strcmp(discentes[k].nome, discentes[j].nome) > 0 ){
                k=j;
            }
        }
        temp = discentes[i];
        discentes[i] = discentes[k];
        discentes[k] = temp;
    }
}

void discentePorNome(Discente discentes[],int *totalDiscente){
    arquivoPuxarDiscente(discentes,totalDiscente);
    limparTela();
    printf("ESCREVA O NOME DO DISCENTE PARA BUSCAR\n");
    char nome[20];
    fgets(nome,sizeof(nome),stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int cont = 0;

    limparTela();
    gotoxy(1,1);
    printf("---------------------------------------------------------");
    gotoxy(20,2);
    printf("LISTA DE DISCENTES POR NOME");
    gotoxy(1,3);
    printf("---------------------------------------------------------");
    gotoxy(5,4);
    printf("NOME");
    gotoxy(27,4);
    printf("CPF");
    gotoxy(47,4);
    printf("IDADE");
    for(int i = 0;i < *totalDiscente;i++){
        if(strstr(discentes[i].nome,nome) != NULL){
            gotoxy(2,5 + cont);
            printf("%s",discentes[i].nome);
            gotoxy(27,5 + cont);
            printf("%s",discentes[i].cpf);
            gotoxy(47,5 + cont);
            printf("%d",discentes[i].idade);
            cont++;
        }
    }
    getchar();

}

