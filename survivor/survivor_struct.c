#include "survivor_struct.h"

#include <stdio.h>
#include <string.h>

void copy_survivor(struct Survivor* from, struct Survivor* to) {
    to->id = from ->id;
    strcpy(to->name,from->name);
    to->skill = from ->skill;
    to->rations = from ->rations;
    to->health = from ->health;
    to->state_of_health = from ->state_of_health;
    to->threat_level = from -> state_of_health;
    to-> status_of_survivor = from ->status_of_survivor;
    to->next=NULL;
}
