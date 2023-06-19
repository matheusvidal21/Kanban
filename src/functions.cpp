#include "../include/functions.h"

void clearTerminal(){
    // Limpa o terminal em diferentes sistemas operacionais
    #ifdef _WIN32  // Para Windows
        system("cls");
    #else  // Para sistemas Unix (Linux, macOS, etc.)
        system("clear");
    #endif
}