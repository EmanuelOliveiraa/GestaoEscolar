#include <stdio.h>
#include <string.h>
#define MAX 20
#include "turma.h"
#include "menu.h"

Turma turmas[MAX];
int totalTurma = 0;

void cadastrarTurma(){
    limparTela();
    Turma temp;
    printf(" ------------------------CADASTRO TURMA------------------------\n");
    printf("ESCREVA O NUMERO DA TURMA: ");
    scanf("%d",&temp.numero);
    getchar();

    printf("ESCREVA O CPF DO DISCENTE: ");
    fgets(temp.cpf,sizeof(temp.cpf),stdin);
    temp.cpf[strcspn(temp.cpf, "\n")] = '\0';

    printf("ESCREVA O CODIGO DO CURSO: ");
    scanf("%d",&temp.codigo);
    getchar();

    printf("ESCREVA O ANO: ");
    scanf("%d",&temp.ano);
    getchar();

    printf("ESCREVA A NOTA: ");
    scanf("%f",&temp.nota);
    getchar();

    printf("ESCREVA AS HORAS DE PARTICIPACAO: ");
    scanf("%d",&temp.horasParticipacao);
    getchar();

    turmas[totalTurma] = temp;
    totalTurma++;

    printf("\nTURMA CADASTRADO!\n");
    getchar();
    limparTela();
}

void listarTurmas(){
    limparTela();
    gotoxy(1,1);
    printf("------------------------------------------------------------------------");
    gotoxy(30,2);
    printf("LISTA DE TURMAS");
    gotoxy(1,3);
    printf("------------------------------------------------------------------------");
    gotoxy(1,4);
    printf("NUMERO");
    gotoxy(10,4);
    printf("CPF");
    gotoxy(27,4);
    printf("CODIGO");
    gotoxy(38,4);
    printf("ANO");
    gotoxy(47,4);
    printf("NOTA");
    gotoxy(55,4);
    printf("HORAS PARTICIPACAO");
    for(int i = 0;i < totalTurma;i++){
        gotoxy(1,5 + i);
        printf("%d", turmas[i].numero);
        gotoxy(10,5 + i);
        printf("%s",turmas[i].cpf);
        gotoxy(27,5 + i);
        printf("%d",turmas[i].codigo);
        gotoxy(38,5 + i);
        printf("%d",turmas[i].ano);
        gotoxy(47,5 + i);
        printf("%.2f",turmas[i].nota);
        gotoxy(55,5 + i);
        printf("%d",turmas[i].horasParticipacao);
    }
}

int buscarNumeroTurma(){
    int numero;
    scanf("%d",&numero);
    getchar();
    for(int i = 0;i < totalTurma;i++){
        if(turmas[i].numero == numero){
            return i;
        }
    }
    return -1;
}

void editarTurma(){
    Turma temp;

    limparTela();
    listarTurmas();
    printf("\nESCREVA O NUMERO DA TURMA PARA EDITAR\n");
    int posicao = buscarNumeroTurma();
    printf("APERTE ENTER PARA EDITAR");
    getchar();
    limparTela();
    if(posicao == -1){
        printf("\nNUMERO NAO ENCONTRADO OU INCORRETO\n");
        printf("APERTE ENTER PARA VOLTAR A TELA SECUNDARIA");
        getchar();
        return;
    }

    printf("--------------------------EDITAR--------------------------\n");
    printf("ESCREVA O CPF DO DISCENTE: ");
    fgets(temp.cpf,sizeof(temp.cpf),stdin);
    temp.cpf[strcspn(temp.cpf, "\n")] = '\0';

    printf("ESCREVA O CODIGO DO CURSO: ");
    scanf("%d",&temp.codigo);
    getchar();

    printf("ESCREVA O ANO: ");
    scanf("%d",&temp.ano);
    getchar();

    printf("ESCREVA A NOTA: ");
    scanf("%f",&temp.nota);
    getchar();

    printf("ESCREVA AS HORAS DE PARTICIPACAO: ");
    scanf("%d",&temp.horasParticipacao);
    getchar();

    temp.numero = turmas[posicao].numero;
    turmas[posicao] = temp;
    //totalTurma++;

    printf("\nEDICAO CONCLUIDA!\n");
    printf("APERTE ENTER PARA CONTINUAR");
    getchar();
    limparTela();
}

void excluirTurma(){
    printf("------------------------EXCLUIR------------------------\n");
    listarTurmas();
    printf("\nESCREVA NUMERO DA TURMA PARA EXCLUIR\n");
    int posicao = buscarNumeroTurma();
    if(posicao == -1){
        printf("\nNUMERO NAO ENCONTRADO OU INCORRETO\n");
        printf("APERTE ENTER PARA VOLTAR A TELA SECUNDARIA");
        getchar();
        return;
    }
    for(int i = posicao;i < totalTurma;i++){
        turmas[i] = turmas[i + 1];
    }
    totalTurma--;
    listarTurmas();
    printf("\nOPERACAO CONCLUIDA\n");
    printf("APERTE ENTER PARA CONTINUAR\n");
    getchar();
}

void arquivoSalvarTurma(){
    FILE *file = fopen("C:\\Users\\Aluno\\Documents\\escola\\turmas.txt.txt","w+");

    if(file == NULL){
        printf("\nERRO AO ABRIR ARQUIVO!\n");
        printf("APERTE ENTER PARA VOLTAR\n");
        getchar();
        return;
    }

    for(int i = 0;i < totalTurma;i++){
        fprintf(file,"%d;%s;%d;%d;%f;%d\n",turmas[i].numero,turmas[i].cpf,turmas[i].codigo,turmas[i].ano,turmas[i].nota,turmas[i].horasParticipacao);
    }
    fclose(file);
}

void arquivoPuxarTurma(){
    Turma temp;
    totalTurma = 0;
    FILE *file = fopen("C:\\Users\\Aluno\\Documents\\escola\\turmas.txt.txt","r");

    if(file == NULL){
                    perror("erro");

        printf("\nERRO AO ABRIR ARQUIVO!\n");
        printf("APERTE ENTER PARA VOLTAR\n");
        getchar();
        return;
    }

    while(fscanf(file,"%d;%[^;];%d;%d;%f;%d",&temp.numero,temp.cpf,&temp.codigo,&temp.ano,&temp.nota,&temp.horasParticipacao) == 6){
        turmas[totalTurma] = temp;
        totalTurma++;
    }
    fclose(file);
}



