#ifndef UNTITLED5_QUESTSTRUCT_H
#define UNTITLED5_QUESTSTRUCT_H

typedef struct Quest {
    int quest_length;
    int succession_rate;
    char survivor_name[100];
    struct Quest *next;
}Quest;

#endif //UNTITLED5_QUESTSTRUCT_H