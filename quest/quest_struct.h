#ifndef QUEST_STRUCT_H
#define QUEST_STRUCT_H

typedef struct Quest {
    int quest_length;
    int succession_rate;
    char survivor_name[100];
    struct Quest *next;
}Quest;

#endif //QUEST_STRUCT_H