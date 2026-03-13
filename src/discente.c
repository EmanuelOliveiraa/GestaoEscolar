#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    char cpf[12];
    int idade;
}Discente;

    Discente *discentes = NULL;
    int totalDiscente = 0;

//realiza o cadastro e aumenta o tam do array
void cadastrarDiscente(){
    Discente temp;
    printf("Escreva o nome do discente\n");
    fgets(temp.nome,sizeof(temp.nome),stdin);

    printf("Escreva o cpf do discente\n");
    fgets(temp.cpf,sizeof(temp.cpf),stdin);

    printf("Escreva a idade do discente\n");
    scanf("%d",&temp.idade);
    getchar();

    discentes = realloc(discentes,(totalDiscente + 1) * sizeof(Discente));
    discentes[totalDiscente] = temp;

    totalDiscente++;
}

//edita nome e idade buscando pelo cpf
int editarDiscente(char cpf[]){
    Discente temp;
    int posicao = buscarDiscenteCPF(cpf);

    if(posicao >= 0){
        printf("Escreva o novo nome: ");
        fgets(temp.nome,sizeof(temp.nome),stdin);
        printf("Escreva a nova idade: ");
        fgets(temp.idade,sizeof(temp.idade),stdin);
        discentes[posicao] = temp;
        return 1;
    }else{
        printf("Discente nao encontrado ou nao existe!");
        return 0;
    }

}

//lista o array chamando a funcao mostrarDiscente
void listarDicentes(){
    for(int i = 0;i < totalDiscente;i++){
        mostrarDiscente(discentes[i]);
    }
}

//recebe a struct e print na tela
void mostrarDiscente(Discente *discente){
    printf("Nome do discente: %s\n",discente->nome);
    printf("CPF do discente: %s\n",discente->cpf);
    printf("Idade do discente: %d\n",discente->idade);
    printf("\n\n");
}

//compara a entrada com o array
int buscarDiscenteCPF(char cpf[]){
    for(int i = 0;i<totalDiscente;i++){
        if(strcmp(discentes[i].cpf,cpf) == 0){
            return i;
        }
    }
    return -1;
}


int excluirDiscente(char cpf[]){
    int posicao = buscarDiscenteCPF(cpf);
    if(posicao == -1){
        return 0;
    }
    for(int i = posicao;i < totalDiscente - 1;i++){
        discentes[i] = discentes[i+1];
    }
    totalDiscente--;
    return 1;
}
//salva e sempre sobrescreve a cada modificaçao
void arquivoSalvarDiscente(){
    FILE *file = fopen("discente.txt","w");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    for(int i = 0;i < totalDiscente;i++){
        fprintf(file,"%s;%s;;%d\n",discentes[i].nome,discentes[i].cpf,discentes[i].idade);
    }
    fclose(file);
    printf("Struct salva!\n");
}

void arquivoCarregarDiscente(){
    FILE *file = fopen("discente.txt","r");

    if(file == NULL){
        return;
    }
    Discente temp;

    while(fscanf(file,"%[^;];%[^;];%d\n",temp.nome,temp.cpf,temp.idade) == 3){
        discentes[totalDiscente] = temp;
        totalDiscente++;
    }
    fclose(file);
}



