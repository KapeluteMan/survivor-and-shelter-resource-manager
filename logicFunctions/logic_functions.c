#include <stdio.h>
#include "logic_functions.h"

int insert_int() {
    int pom=0;
    int tym=1;
    while (tym==1) {
        tym=0;
        while (scanf("%d", &pom) != 1) {
            while (getchar() != '\n') {}
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

void insert_string(char* text) {
    scanf("%99[^\n]s", text);
}

int check_interval(int a, int b) {
    int tmp;
    do {
        tmp = insert_int();
        if (tmp < a || tmp > b) {
            printf("!Value is out of range <%d-%d>!\n", a, b);
        }
    } while (tmp < a || tmp > b);

    return tmp;
}