#include <stdio.h>
#include <string.h>
#include <windows.h>
#define MAX 30
typedef struct{
    char nome[50];
    char cpf[12];
    int idade;
}Discente;

Discente discentes[MAX];
int totalDiscente = 0;


void gotoxy(int x,int y){
    COORD coordenada;
    coordenada.X = x;
    coordenada.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordenada);
}

void cadastrarDiscente(){
    system("cls");
    Discente temp;
    printf(" ------------------------CADASTRO------------------------\n");
    printf("ESCREVA O NOME: ");
    fgets(temp.nome,sizeof(temp.nome),stdin);

    printf("ESCREVA O CPF: ");
    fgets(temp.cpf,sizeof(temp.cpf),stdin);

    printf("ESCREVA A IDADE: ");
    scanf("%d",&temp.idade);
    getchar();

    discentes[totalDiscente] = temp;
    totalDiscente++;

    printf("\nDISCENTE CADASTRADO!\n");
    system("pause");
    system("cls");
    return;
}

void listarDiscente(){
    system("cls");
    gotoxy(1,1);
    printf("---------------------------------------------------------");
    gotoxy(20,2);
    printf("LISTA DE DISCENTES");
    gotoxy(1,3);
    printf("---------------------------------------------------------");
    gotoxy(5,4);
    printf("NOME");
    gotoxy(27,4);
    printf("CPF");
    gotoxy(47,4);
    printf("IDADE");
    for(int i = 0;i < totalDiscente;i++){
        gotoxy(5,5 + i);
        printf("%s",discentes[i].nome);
        gotoxy(27,5 + i);
        printf("%s",discentes[i].cpf);
        gotoxy(47,5 + i);
        printf("%d",discentes[i].idade);
    }
    printf("\n");
    system("pause");
}
int buscarDiscenteNome(){
    char tempNome[MAX];
    system("cls");
    listarDiscente();
    printf("\n\n");
    printf("\n\nESCREVA O NOME DO DISCENTE PARA EDITAR\n");
    fgets(tempNome,sizeof(tempNome),stdin);

    for(int i = 0;i < totalDiscente;i++){
        if(strcmp(tempNome,discentes[i].nome) == 0){
            return i;
        }else{
            printf("NOME NAO ENCONTRADO OU INCORRETO");
            return -1;
        }
    }
}
void editarDiscentes(){
    Discente temp;
    int posicao = buscarDiscenteNome();
    system("cls");
    if(posicao == -1){
        return;
    }
    printf("--------------------------EDITAR--------------------------\n");
    printf("NOME: ");
    fgets(temp.nome,sizeof(temp.nome),stdin);
    printf("CPF: ");
    fgets(temp.cpf,sizeof(temp.cpf),stdin);
    printf("IDADE: ");
    scanf("%d",&temp.idade);
    getchar();
    discentes[posicao] = temp;

    printf("\nEDICAO CONCLUIDA!\n");
    system("pause");
    system("cls");
}
void telaPrincipal(){
    printf("-----------------------TELA INICIAL-----------------------\n");
    printf("1: DISCENTES\n");
    printf("2: CURSOS\n");
    printf("3: TURMAS\n");
    printf("4: RELATORIOS\n");
    printf("5: SAIR\n");
}
void telaSecundaria(){
    system("cls");
    printf("----------------------TELA SECUNDARIA---------------------\n");
    printf("1: CADASTRO\n");
    printf("2: EDICAO\n");
    printf("3: LISTAR\n");
    printf("4: PESQUISA\n");
    printf("5: SAIR\n");
}
int opcao(){
    int op;
    scanf("%d",&op);
    getchar();
    if(op > 0 && op < 5){
        return op;
    }else{
        printf("OPCAO INVALIDA");
        return -1;
    }
}
void loop(){
    int cont = 1;
    telaSecundaria();
    while(cont){
        int op = opcao();
        switch(op){
            case 1:
                cadastrarDiscente();
                break;
            case 2:
                editarDiscentes();
                break;
            case 3:
                listarDiscente();
                break;
            case 4:
                //pesquisarDiscente();
                break;
            default:
                break;
        }
        telaSecundaria();
    }
}
int main(){
    loop();
return 0;
}


