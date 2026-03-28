#ifndef DISCENTE_H
#define DISCENTE_H
#define MAX 30

typedef struct{
    char nome[50];
    char cpf[12];
    int idade;
}Discente;

Discente discentes[MAX];

void cadastrarDiscente();
void listarDiscente();
int buscarDiscenteNome();
void editarDiscentes();
void excluirDiscente();
int opcao();

#endif // DISCENTE_H
