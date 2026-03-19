#include <stdio.h>
#include <string.h>

void contaChar(char *s,int *qtChar){

while(*s!='\0'){
        (*qtChar)++;
        s++;
    }
};

int main() {
    int qtChar=0;
    char s[]="{10,20,30,40}";

    contaChar(s, &qtChar);

    printf("tamanho str: %d", qtChar);
    return 0;
}
