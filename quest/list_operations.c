#include <stdio.h>
#include <stdlib.h>

#include "quest_struct.h"
#include "../survivor/survivor_struct.h"

#include "list_operations.h"

#include "../survivor/find.h"


Quest *add_quest(Quest *head, Quest *toAdd) {
    if (head == NULL) {
        return toAdd;
    }

    toAdd->next = head;
    return toAdd;
}

Quest *copy_quest(Quest *from) {
    Quest *to = calloc(1, sizeof(Quest));
    to->quest_length = from->quest_length;
    to->succession_rate = from->succession_rate;
    return to;
}

Quest *random_quest(Quest *head) {
    if (head == NULL) {
        return NULL;
    }

    int pom = rand() % 20 + 1;
    Quest *curr = head;
    for (int i = 0; i < pom; i++) {
        curr = curr->next;
    }
    return copy_quest(curr);
}

void result_of_quest(struct Quest *finished_quest, struct Survivor *head, int *rations) {
    if (rand() % 10 == 0) {
        printf("Survivor %s did not return to shelter",finished_quest->survivor_name);
        find_by_name(head, finished_quest->survivor_name)->status_of_survivor=MISSING;
    } else {
        if (/*wzór na sukcess*/1 > finished_quest->succession_rate) { //czy misja się powiodła
            *rations += 5; //okraślana na podstawie trudności????
        }
        struct Survivor *next = head;
        while (next!=NULL) {
            if (next->status_of_survivor==MISSING && rand()%10 == 0) {
                if (rand()%2==0) {
                    printf("Survivor found %s dead",next->name);
                    next->status_of_survivor=DEAD;
                } else {
                    printf("Survivor found %s alive",next->name);
                    next->status_of_survivor=WOUNDED;
                }
            }
            next=next->next;
        }
    }
}

Quest *checked_finished_quest(struct Quest *head, struct Survivor *s_head, int *rations) {
    if (head == NULL) {
        return NULL;
    }

    struct Quest *next = head;
    struct Quest *tym = NULL;
    struct Quest *pre = NULL;

    while (next != NULL) {
        if (next->quest_length == 0) {
            result_of_quest(next, s_head, rations);
            if (pre == NULL) {
                tym = next;
                next = next->next;
                head = next;
                free(tym);
            } else {
                tym = next;
                pre->next = next->next;
                free(tym);
            }
        } else {
            pre = next;
            next = next->next;
        }
    }
    return head;
}
