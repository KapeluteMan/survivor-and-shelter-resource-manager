#include "show.h"
#include "quest_struct.h"
#include <stdio.h>
#include <string.h>

void print_single_quest(Quest *q) {
    if (q == NULL) {
        return;
    }

    printf(" | Quest Length: %3d | Succession Rate: %3d%%\n",q->quest_length,q->succession_rate);
}


void print_all_quests(Quest *head) {
    Quest *n = head;

    printf("--- List Quests ---\n");

    while (n != NULL) {
        print_single_quest(n);
        n = n->next;
    }

    printf("---------------------\n");

}



