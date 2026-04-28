#include <stdio.h>



typedef struct{
    char nome[50];
    int codigo;
    int horas;
    int numeroVagas;
    int numeroParticipante;
}Curso;

typedef struct{
    int numero;
    int ano;
    int horasParticipacao;
    Curso *curso;
}Turma;
typedef struct{
    char nome[50];
    int cpf;
    int idade;
    float nota;
    float media;
    Turma *turma;
}Discente;

int main(){
Curso cursos[3];
Turma turmas[3];
Discente discentes[3];

cursos[0] = (Curso){"Analize e Desenvolvimento de Sistemas", 1001,2800,30,20};
cursos[1] = (Curso){"Licenciatura em Quimica", 1002,3200,30,20};
cursos[2] = (Curso){"Licenciatura em Matematica", 1003,3200,30,20};

turmas[0] = (Turma){101,2026,1300,&cursos[0]};
turmas[1] = (Turma){102,2026,1800,&cursos[1]};
turmas[2] = (Turma){103,2026,1800,&cursos[2]};

discentes[0] = (Discente){"Pedro Henrique",432987,18,10,8,&turmas[0]};
discentes[1] = (Discente){"Maria Pinheiro",124567,21,9,6,&turmas[1]};
discentes[2] = (Discente){"Luis Gonsalves",546723,32,7,9,&turmas[2]};

printf("%s\n",discentes[0].nome);
printf("numero da turma de pedro %d\n", discentes[0].turma->numero);
printf("nome do curso de pedro %s", discentes[0].turma->curso->nome);


return 0;
}

