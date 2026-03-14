#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char nome[21];
    int codigo;
    int horas;
    int numerosVagas;
    int numerosParticipante;
}Curso;

Curso *cursos = NULL;
int totalCurso = 0;

void cadastrarCusrso(){
    Curso temp;
    printf("Escreva o nome do Curso\n");
    fgets(temp.nome,sizeof(temp.nome),stdin);

    int numero = (rand() % (9999 - 1000 + 1)) + 1000;
    temp.codigo = numero;

    printf("Escreva as horas do Curso\n");
    scanf("%d",&temp.horas);
    getchar();

    printf("Escreva o numero de vagas para o Curso\n");
    scanf("%d",&temp. numerosVagas);
    getchar();

    printf("Escreva o numero de participantes para o Curso\n");
    scanf("%d",&temp. numerosParticipante);
    getchar();

    cursos = realloc(cursos,(totalCurso + 1) * sizeof(Curso));
    cursos[totalCurso] = temp;

    totalCurso++;

}

//lista o array chamando a funcao mostrarCurso
void listarCursos(){
    for(int i = 0;i < totalCurso;i++){
        mostrarCurso(cursos[i]);
    }
}

//recebe a struct e print na tela
void mostrarCurso(Curso *cursos){
    printf("Nome do curso: %s       ",cursos->nome);
    printf("Codigo do curso: %d\n",cursos->codigo);
    printf("Quantidade de horas do curso: %d\n",cursos->horas);
    printf("\n\n");
}
//edita dados usando o codigo como referencia
int editarCurso(int codigo){
    Curso temp;
    int posicao = buscarCurso(codigo);

    if(posicao >= 0){
        printf("Rescreva o nome do Curso\n");
        fgets(temp.nome,sizeof(temp.nome),stdin);

        printf("Rescreva as horas do Curso\n");
        scanf("%d",&temp.horas);
        getchar();

        printf("Rescreva o numero de vagas para o Curso\n");
        scanf("%d",&temp. numerosVagas);
        getchar();

        printf("Rescreva o numero de participantes para o Curso\n");
        scanf("%d",&temp. numerosParticipante);
        getchar();
        cursos[posicao] = temp;
        cursos[posicao].codigo = codigo;
        return 1;
    }else{
        printf("Curso nao encontrado\n");
        return 0;
    }
}
//busca curso por codigo
int buscarCurso(int codigo){
    for(int i = 0;i < totalCurso;i++){
        if(cursos[i].codigo == codigo){
            return i;
        }
    }
    return -1;
}
//busca curso por codigo e exclui do array
int excluirCurso(int codigo){
    int posicao = buscarCurso(codigo);
    if(posicao == -1){
        return 0;
    }
    for(int i = posicao;i < totalCurso;i++){
        cursos[i] = cursos[i + 1];
    }
    totalCurso--;
    return 1;

}
//abre arquivo e salva dados
void arquivoSalvarCurso(){
    FILE *file = fopen("cursos.txt","w");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    for(int i = 0; i < totalCurso;i++){
        fprintf(file,"%s;%d;%d;%d;%d\n",cursos[i].nome,cursos[i].codigo,cursos[i].horas,cursos[i].numerosParticipante,cursos[i].numerosVagas);
        printf("esta salvando");
    }
    fclose(file);
    printf("Estruct salva!\n");
}
//abre arquivo e puxa todos os dados
void arquivoBuscarCurso(){
    FILE *file = fopen("cursos.txt", "r");

    if(file == NULL){
        return;
    }
    Curso temp;

    while(fscanf(file,"%[^;];%d;%d;%d;%d\n",temp.nome,temp.codigo,temp.horas,temp.numerosParticipante,temp.numerosVagas) == 3){
        cursos[totalCurso] = temp;
        totalCurso++;
    }
    fclose(file);
}

