//
// Created by wojte on 21.12.2025.
//
#include "addFromFile.h"
#include "questStruct.h"
#include "listOperations.h"
#include <stdio.h>
#include <stdlib.h>

struct Quest* addQuestFromFile(struct Quest* head) {
    FILE *f = fopen("quests.txt", "r");
    if (!f) {
        printf("Error opening file - quests.txt");
        return head;
    }

    int length =0;
    int success = 0;
    while (fscanf(f ,"%d %d", &length, &success)==2) {
        struct Quest* quest = malloc(sizeof(struct Quest));
        quest->next = NULL;
        quest->questLength = length;
        quest->successionRate = success;

        head = addQuest(head, quest);
    }


}
