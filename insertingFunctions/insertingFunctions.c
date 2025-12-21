#include "insertingFunctions.h"
#include <stdio.h>
#include <string.h>

int insertInt() {
    int pom=0;
    int tym=1;
    while (tym==1) {
        tym=0;
        while (scanf("%d", &pom) != 1) {
            while (getchar() != '\n');
            printf("Podaj jescze raz\n");
        }
        while (getchar()!='\n') {
            tym=1;
        }
        if (tym==1) {
            printf("Podaj jeszcze raz");
        }
    }
    return pom;
}

void insertString(char* text) {
    scanf("%99[^\n]s", text);
}