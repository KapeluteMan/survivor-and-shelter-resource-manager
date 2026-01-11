#include <stdio.h>

#include "quest_struct.h"

#include "list_operations.h"

Quest* add_quest(Quest* head, Quest* toAdd) {
    if (head==NULL) {
        return toAdd;
    }

    toAdd->next=head;
    return toAdd;
}
