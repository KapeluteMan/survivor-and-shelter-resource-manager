//
// Created by wojte on 27.12.2025.
//

#ifndef UNTITLED5_QUESTSTRUCT_H
#define UNTITLED5_QUESTSTRUCT_H

typedef struct Quest {
    int questLength;
    int successionRate;
    char survivorName[100];
    struct Quest *next;
};

#endif //UNTITLED5_QUESTSTRUCT_H