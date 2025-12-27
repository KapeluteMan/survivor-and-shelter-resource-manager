#include "listOperations.h"
#include "questStruct.h"
#include <stdio.h>

struct Quest* addQuest(struct Quest* head, struct Quest* toAdd) {
    if (head==NULL) {
        return toAdd;
    }

    toAdd->next=head;
    return toAdd;
}