#ifndef PRE_PROCESSAMENTO_H
#define PRE_PROCESSAMENTO_H

#include <stdio.h>
#include <stdlib.h>

void limpar_console()
{
#ifdef _WIN32
    // Comando para Windows (cls)
    system("cls");
#else
    // Comando para Linux/macOS e outros sistemas POSIX (clear)
    system("clear");
#endif
}

#endif