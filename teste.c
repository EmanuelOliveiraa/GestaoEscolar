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
Curso ads = {"Analize e Desenvolvimento de Sistemas", 2345,2800,30,20};
Turma ano2026_1 = {101,2026,1300,&ads};
Discente pedro = {"Pedro Henrique",432987,18,10,8,&ano2026_1};

printf("%s\n",pedro.nome);
printf("numero da turma de pedro %d", pedro.turma->numero);

return 0;
}

