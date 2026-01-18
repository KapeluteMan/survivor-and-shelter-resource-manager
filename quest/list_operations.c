#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "quest_struct.h"

#include "list_operations.h"


Quest* add_quest(Quest* head, Quest* toAdd) {
    if (head==NULL) {
        return toAdd;
    }

    toAdd->next=head;
    return toAdd;
}

Quest* copy_quest(Quest* from) {
    Quest* to = calloc(1,sizeof(Quest));
    to->quest_length=from->quest_length;
    to->succession_rate=from->succession_rate;
    return to;
}

Quest* random_quest(Quest* head) {
    if (head==NULL) {
        return NULL;
    }

    int pom = rand()%20+1;
    Quest* curr = head;
    for (int i=0;i<pom;i++) {
        curr = curr->next;
    }
    return copy_quest(curr);

}
