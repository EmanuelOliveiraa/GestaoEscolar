#include <stdio.h>
typedef struct{
    int numero;
    char cpf[11];
    int codigo;
    int ano;
    int nota;
    int horasParticipacao;
}Turma;

void cadastrarTurma(Turma *turma){
    printf("Escreva o numero da turma\n");
    fgets(turma->numero,sizeof(turma->numero),stdin);
    printf("Escreva o cpf da turma\n");
    fgets(turma->cpf,sizeof(turma->cpf),stdin);
    printf("Escreva o codigo da turma\n");
    fgets(turma->codigo,sizeof(turma->codigo),stdin);
    printf("Escreva o ano da turma\n");
    //fgets(turma->ano(sizeof(turma->ano),stdin);
    printf("Escreva a nota da turma");
    fgets(turma->nota,sizeof(turma->nota),stdin);
    printf("Escreva a quantidade de horas de participacao da turma");
    fgets(turma->horasParticipacao,sizeof(turma->horasParticipacao),stdin);

}