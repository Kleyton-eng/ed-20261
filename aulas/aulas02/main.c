#include <stdio.h>
#include <string.h>
#include "agenda.h"

int main(){

    Agenda agenda = criar_agenda(10);

    Contato contato;
    strcpy(contato.nome, "Jose");
    strcpy(contato.telefone, "1111-2222");

    adicionar_contato(&agenda, contato);

    
    
    //lista_contato(&agenda);
    
    Contato outro;
    strcpy(outro.nome, "Vitor");
    strcpy(outro.telefone, "3333-4444");

    adicionar_contato(&agenda, outro);

    
    
    lista_contato(&agenda);


    return 0;
}