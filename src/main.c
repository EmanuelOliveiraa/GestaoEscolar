#include <stdio.h>
#include "discente.h"
#include "menu.h"

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
                system("cls");
                listarDiscente();
                system("pause");
                break;
            case 4:
                excluirDiscente();
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
