#include <stdio.h>
#include <string.h>

#include "quest_struct.h"

#include "show.h"


void print_quest_list(Quest *head) {
    if (head == NULL) {
        printf("There is no active quest.\n");
        return;
    }

    struct Quest *n = head;


    printf("--- List Active Quests ---\n");

    while (n != NULL) {
        printf(" Quest length left = %d, Succession rate = %d%%, Survivor = %s\n",
        n->quest_length, n->succession_rate,n->survivor_name);

        n = n->next;
    }
    printf("-------------------\n");
}

void print_quest(Quest *to_print) {
    printf(" Quest length = %d, Succession rate = %d%%\n",to_print->quest_length, to_print->succession_rate);
}
