#include <stdio.h>
#include <stdlib.h>
#include "../headers/pre_processamento.h"

void limpar_console(){
    #ifdef _WIN32
        // Comando para Windows (cls)
        system("cls");
    #else
        // Comando para Linux/macOS e outros sistemas POSIX (clear)
        system("clear");
        system("clear");
    #endif
}
