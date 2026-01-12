#include <stdio.h>
#include <stdlib.h>

#include "quest_struct.h"
#include "list_operations.h"

#include "add_from_file.h"

Quest* add_quest_from_file() {
    FILE *f = fopen("../files/quests.txt","r");
    if (!f) {
        // printf("Error opening file - quests.txt");
        return NULL;
    }

    Quest* head=NULL;
    int length =0;
    int success = 0;
    while (fscanf(f ,"%d %d", &length, &success)==2) {
        Quest* quest = malloc(sizeof(struct Quest));
        quest->next = NULL;
        quest->quest_length = length;
        quest->succession_rate = success;

        head = add_quest(head, quest);
    }
    fclose(f);
    return head;
}
