#ifndef CURSO_H
#define CURSO_H
typedef struct{
    char nome[21];
    int codigo;
    int horas;
    int numerosVagas;
    int numerosParticipante;
}Curso;

void cadastrarCurso();
void listarCursos();
int buscarCursoCodigo();
void editarCurso();
void excluirCurso();
void arquivoSalvarCurso();
void arquivoPuxarCurso();


#endif // CURSO_H
