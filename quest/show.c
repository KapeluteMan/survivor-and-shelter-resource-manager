#include "show.h"
#include "quest_struct.h"
#include <stdio.h>
#include <string.h>

void print_quest(struct Quest* head) {


    if (head == NULL) {
        printf("There is no quest here.\n");
        return;
    }

    struct Quest*n = head;


    printf("--- List Quests ---\n");

    while (n != NULL) {
        printf(" Quest length = %d, Succession rate = %d%%\n",
            n->quest_length,n->succession_rate);

        n = n->next;

    }
    printf("-------------------\n");
}



