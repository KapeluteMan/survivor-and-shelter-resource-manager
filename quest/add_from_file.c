//
// Created by wojte on 21.12.2025.
//
#include "add_from_file.h"
#include "quest_struct.h"
#include "list_operations.h"
#include <stdio.h>
#include <stdlib.h>

struct Quest* add_quest_from_file(struct Quest* head) {
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
        quest->quest_length = length;
        quest->succession_rate = success;

        head = add_quest(head, quest);
    }
    fclose(f);
    return head;
}
