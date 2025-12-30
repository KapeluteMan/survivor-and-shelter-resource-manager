#include "survivorStruct.h"

#include <stdio.h>
#include <string.h>

void copySurvivor(struct Survivor* from, struct Survivor* to) {
    to->id = from ->id;
    strcpy(to->name,from->name);
    to->skill = from ->skill;
    to->rations = from ->rations;
    to->health = from ->health;
    to->stateOfHealth = from ->stateOfHealth;
    to->threatLevel = from -> stateOfHealth;
    to-> statusOfSurvivor = from ->statusOfSurvivor;
    to->next=NULL;
}
