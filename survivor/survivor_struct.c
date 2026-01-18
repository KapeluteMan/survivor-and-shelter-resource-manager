#include <string.h>
#include <stdio.h>

#include "survivor_struct.h"


void copy_survivor(const struct Survivor* from, struct Survivor* to) {
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

enum specialist_skill form_int_to_enum_skill(int a) {
    switch (a) {
        case 0: return MEDIC;
        case 1: return ENGINEER;
        case 2: return HUNTER;
        default: return ORDINARY;
    }
}

enum state_of_health form_int_to_enum_state_health(int a) {
    switch (a) {
        case 0: return HEALTHY;
        case 1: return WEAKEN;
        case 2: return SICK;
        default: return DYING;
    }
}
