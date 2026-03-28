/*#include <stdio.h>
typedef struct{
    int numero;
    char cpf[12];
    int codigo;
    int ano;
    float nota;
    int horasParticipacao;
}Turma;

Turma *turmas = NULL;
int totalTurma = 0;

void cadastrarTurma(){
    Turma temp;

    printf("Escreva o numero da turma\n");
    scanf("%d",&temp.nota);
    getchar();
    printf("Escreva o cpf do discente\n");
    fgets(temp.cpf,sizeof(temp.cpf),stdin);

    printf("Escreva o codigo do curso\n");
    scanf("%d",&temp.codigo);

    printf("Escreva o ano do curso\n");
    scanf("%d",&temp.ano);
    getchar();

    printf("Escreva a nota\n\n");
    scanf("%f",&temp.nota);
    getchar();

    printf("Escreva as horas de participacao\n");
    scanf("%d",&temp.horasParticipacao);
    getchar();

    int indexDiscente = buscarDiscenteCPF(temp.cpf);

    if(indexDiscente == -1){
        printf("Discente nao encontrado!\n");
        return;
    }
    int indexCurso = buscarCurso(temp.codigo);

    if(turmas[indexCurso].numerosParticipante >= cursos[indexCurso].numerosVagas) {
        printf("Curso cheio!\n");
        return;
    }

    turmas = realloc(turmas(totalTurma + 1) * sizeof(Turma));
    turmas[totalTurma] = temp;

    totalTurma++;

    cursos[indexCurso].numerosParticipante++;

    printf("Turma cadastrada!\n");
}

int buscarTurma(int numero){
    for(int i = 0;i < totalTurma;i++){
        if(turmas[i].numero == numero){
            return i;
        }

    }
    return -1;
}

Turma listarTurmas(){
    if(totalTurma == 0){
        printf("Nenhuma Turma cadastrada.\n");
        return;
    }

    for(int i = 0;i< totalTurma;i++){
        printf("\nTurma: %d\n",turmas[i].numero);
        printf("CPF discente: %s\n",turmas[i].cpf);
        printf("Codigo do curso: %d\n",turmas[i].codigo);
        printf("Ano:  %d\n",turmas[i].ano);
        printf("Nota: %.2f\n",turmas[i].nota);
        printf("Horas de Participacao %d\n\n",turmas[i].horasParticipacao);
    }
    return turmas[i].ano
}*/

