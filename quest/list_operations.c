#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quest_struct.h"
#include "../survivor/survivor_struct.h"

#include "list_operations.h"
#include "../survivor/list_operations.h"

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

int calc_chance_of_success(struct Survivor* survivor) {
    int ch = rand()%50 + 40;
    switch (survivor->state_of_health) {
        case 0:
            ch *=3;
            break;
        case 1:
            ch*=2;
            break;
        case 2:
            ch*=1;
            break;
        case 3:
            ch/=4;
            break;
    }

    if (survivor->status_of_survivor==WOUNDED) {
        ch=ch*2/3;
    }

    if (survivor->skill!=ORDINARY) {
        ch=ch*2;
    }

    ch = ch / survivor->threat_level;

    return ch;
}

void result_of_quest(struct Quest *finished_quest, struct Survivor *head, int *rations) {
    if (rand() % 10 == 0) {
        printf("Survivor %s did not return to shelter",finished_quest->survivor_name);
        find_by_name(head, finished_quest->survivor_name)->status_of_survivor=MISSING;
    } else {
        find_by_name(head, finished_quest->survivor_name)->status_of_survivor=WAITING;
        if (calc_chance_of_success(find_by_name(head, finished_quest->survivor_name)) > 100-finished_quest->succession_rate) { //czy misja się powiodła
            *rations += 120-finished_quest->succession_rate * 3;
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
        if (rand()%5==0) {
            printf("Survivor %s found another survivor\n",finished_quest->survivor_name);
            head = add_survivor_name(head);
        }
        if (rand()%10==0) {
            printf("Survivor %s found another survivor\n",finished_quest->survivor_name);
            head = add_survivor_name(head);
        }
        if (rand()%20==0) {
            printf("Survivor %s found another survivor\n",finished_quest->survivor_name);
            head = add_survivor_name(head);
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

int check_amount_quest(Quest *head) {
    Quest *n = head;
    int i = 0;

    while (n != NULL) {
        i++;
        n = n->next;
    }
    return i;
}

void survivor_to_quest(Quest *quest, struct Survivor *survivor) {
    if (quest == NULL || survivor == NULL) {
        return;
    }

    strncpy(quest->survivor_name, survivor->name, sizeof(quest->survivor_name) - 1);
    quest->survivor_name[sizeof(quest->survivor_name) - 1] = '\0';

    survivor->status_of_survivor = ON_MISSION;
}




