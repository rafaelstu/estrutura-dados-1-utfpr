#include <stdio.h>
#include <string.h>

void copia_string(char *destino,char *origem){

while(*origem!='\0'){
        *destino=*origem;
        destino++;
        origem++;
    }
};

int main() {
    char destino[10];
    char origem[]="boa noite";

    copia_string(destino, origem);

    printf("origem: %s\n", origem);
    printf("destino: %s\n", destino);
    return 0;
}
