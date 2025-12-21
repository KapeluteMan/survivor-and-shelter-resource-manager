//
// Created by wojte on 17.12.2025.
//
#include <stdio.h>
#include <string.h>

#include "startPage/startPage.h"
#include "insertingFunctions/insertingFunctions.h"

int main() {
    printf("Hello World!\n");
    showStartPage();
    char a[100];
    insertString(a);
    printf("%s\n", a);
}