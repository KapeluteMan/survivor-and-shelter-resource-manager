#include "list_operations.h"
#include "quest_struct.h"
#include <stdio.h>

struct Quest* add_quest(struct Quest* head, struct Quest* toAdd) {
    if (head==NULL) {
        return toAdd;
    }

    toAdd->next=head;
    return toAdd;
}