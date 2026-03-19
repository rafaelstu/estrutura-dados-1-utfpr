#include <stdio.h>
#include <string.h>

void concatena_string(char *sa,char *sb){

    while(*sa!='\0') sa++;

    while(*sb!='\0') {
        *sa=*sb;
        sa++;
        sb++;
    }
};

int main() {
    char sa[30]="bom dia";
    char sb[15]=" boa noite";

    printf("sa: %s\n", sa);

    concatena_string(sa, sb);

    printf("sa: %s\n", sa);
    return 0;
}
