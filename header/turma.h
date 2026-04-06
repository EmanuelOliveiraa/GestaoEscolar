#ifndef TURMA_H
#define TURMA_H
typedef struct{
    int numero;
    char cpf[12];
    int codigo;
    int ano;
    float nota;
    int horasParticipacao;
}Turma;

void cadastrarTurma();
void listarTurmas();
int buscarNumeroTurma();
void editarTurma();
void excluirTurma();
void arquivoSalvarTurma();
void arquivoPuxarTurma();

#endif // TURMA_H
