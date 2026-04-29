#include <stdio.h>
#include <string.h>
#define MAX 30
#include "menu.h"
#include "curso.h"


Curso cursos[MAX];
int totalCurso = 0;

void cadastrarCurso(){
    limparTela();
    Curso temp;
    printf(" ------------------------CADASTRO CURSO------------------------\n");
    printf("ESCREVA O NOME: ");
    fgets(temp.nome,sizeof(temp.nome),stdin);
    temp.nome[strcspn(temp.nome, "\n")] = '\0';

    printf("ESCREVA O CODIGO: ");
    scanf("%d",&temp.codigo);
    getchar();

    printf("ESCREVA A HORAS: ");
    scanf("%d",&temp.horas);
    getchar();

    printf("ESCREVA NUMERO DE VAGAS: ");
    scanf("%d",&temp.numerosVagas);
    getchar();

    printf("ESCREVA O NUMERO DE PARTICIPANTES: ");
    scanf("%d",&temp.numerosParticipante);
    getchar();

    cursos[totalCurso] = temp;
    totalCurso++;

    printf("\nCURSO CADASTRADO!\n");
    getchar();
    limparTela();
}

void listarCursos(){
    int id = 0;
    limparTela();
    gotoxy(1,1);
    printf("---------------------------------------------------------");
    gotoxy(20,2);
    printf("LISTA DE CURSOS");
    gotoxy(1,3);
    printf("---------------------------------------------------------");
    gotoxy(1,4);
    printf("ID");
    gotoxy(5,4);
    printf("NOME");
    gotoxy(15,4);
    printf("CODIGO");
    gotoxy(30,4);
    printf("HORAS");
    gotoxy(40,4);
    printf("NUMERO VAGAS");
    gotoxy(55,4);
    printf("NUMERO PARTICIPANTE");
    for(int i = 0;i < totalCurso;i++){
        gotoxy(1,5 + i);
        printf("%d:  %s", id + i ,cursos[i].nome);
        gotoxy(15,5 + i);
        printf("%d",cursos[i].codigo);
        gotoxy(30,5 + i);
        printf("%d",cursos[i].horas);
        gotoxy(40,5 + i);
        printf("%d",cursos[i].numerosVagas);
        gotoxy(55,5 + i);
        printf("%d",cursos[i].numerosParticipante);
    }
}

int buscarCursoCodigo(){
    int codigo;
    scanf("%d",&codigo);
    getchar();

    for(int i = 0;i < totalCurso;i++){
        if(codigo == cursos[i].codigo){
            return i;
        }
    }
    return -1;
}

void editarCurso(){
    Curso temp;

    limparTela();
    listarCursos();
    printf("\nESCREVA O CODIGO DO CURSO PARA EDITAR\n");
    int posicao = buscarCursoCodigo();
    printf("APERTE ENTER PARA EDITAR");
    getchar();
    limparTela();
    if(posicao == -1){
        printf("\nCODIGO NAO ENCONTRADO OU INCORRETO\n");
        printf("APERTE ENTER PARA VOLTAR A TELA SECUNDARIA");
        getchar();
        return;
    }
    printf("--------------------------EDITAR--------------------------\n");
    printf("NOME: ");
    fgets(temp.nome,sizeof(temp.nome),stdin);
    temp.nome[strcspn(temp.nome, "\n")] = '\0';

    printf("HORAS: ");
    scanf("%d",&temp.horas);
    getchar();

    printf("NUMERO VAGAS: ");
    scanf("%d",&temp.numerosVagas);
    getchar();

    printf("NUMERO PARTICIPANTE: ");
    scanf("%d",&temp.numerosParticipante);
    getchar();
    temp.codigo = cursos[posicao].codigo;
    cursos[posicao] = temp;

    printf("\nEDICAO CONCLUIDA!\n");
    printf("APERTE ENTER PARA CONTINUAR");
    getchar();
    limparTela();
}

void excluirCurso(){
    printf("------------------------EXCLUIR------------------------\n");
    listarCursos();
    printf("\nESCREVA CODIGO DO CURSO PARA EXCLUIR\n");
    int posicao = buscarCursoCodigo();
    if(posicao == -1){
        printf("\nCODIGO NAO ENCONTRADO OU INCORRETO\n");
        printf("APERTE ENTER PARA VOLTAR A TELA SECUNDARIA");
        getchar();
        return;
    }
    for(int i = posicao;i < totalCurso;i++){
        cursos[i] = cursos[i + 1];
    }
    totalCurso--;
    listarCursos();
    printf("\nOPERACAO CONCLUIDA\n");
    printf("APERTE ENTER PARA CONTINUAR\n");
    getchar();
}
void arquivoSalvarCurso(){
    FILE *file = fopen("C:\\Users\\Aluno\\Documents\\escola\\curso.txt", "w");

    if(file == NULL){
        printf("\nERRO AO ABRIR ARQUIVO!\n");
        printf("APERTE ENTER PARA VOLTAR\n");
        getchar();
        return;
    }
    for(int i = 0;i < totalCurso;i++){
        fprintf(file,"%s;%d;%d;%d;%d\n",cursos[i].nome,cursos[i].codigo,cursos[i].horas,cursos[i].numerosVagas,cursos[i].numerosParticipante);
    }
    fclose(file);
}

void arquivoPuxarCurso(){
    FILE *file = fopen("C:\\Users\\Aluno\\Documents\\escola\\curso.txt","r");
    Curso temp;
    totalCurso = 0;
    if(file == NULL){
        printf("\nERRO AO ABRIR ARQUIVO!\n");
        printf("APERTE ENTER PARA VOLTAR\n");
        getchar();
        return;
    }

    while(fscanf(file,"%[^;];%d;%d;%d;%d",temp.nome,&temp.codigo,&temp.horas,&temp.numerosVagas,&temp.numerosParticipante) == 5){
        cursos[totalCurso] = temp;
        totalCurso++;
    }
    fclose(file);
}
