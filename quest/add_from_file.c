#include <stdio.h>
#include <stdlib.h>

#include "quest_struct.h"
#include "list_operations.h"

#include "add_from_file.h"

Quest* add_quest_from_file(Quest* head) {
    FILE *f = fopen("../files/quests.txt","r");
    if (!f) {
        printf("Error opening file - quests.txt");
        return head;
    }

    int length =0;
    int success = 0;
    while (fscanf(f ,"%d %d", &length, &success)==2) {
        Quest* quest = malloc(sizeof(struct Quest));
        quest->next = NULL;
        quest->quest_length = length;
        quest->succession_rate = success;

        head = add_quest(head, quest);
        printf("Odrzytano\n");
    }
    fclose(f);
    return head;
}
