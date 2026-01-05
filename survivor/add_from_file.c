#include "add_from_file.h"
#include "survivor_struct.h"
#include "list_operations.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Survivor* add_survivors_from_file(){
    FILE *f = fopen("../files/survivors.txt","r");
    if (!f) {
        perror("Error opening survivor.txt");
        return NULL;
    }

    int skill=0;
    int health=0;
    int threat=0;
    char name[100];
    struct Survivor* head = NULL;
    while (fscanf(f,"%s %d %d %d", name, &skill,&health,&threat)==4) {
        struct Survivor* pom = calloc(1, sizeof(struct Survivor));
        strcpy(pom->name,name);
        pom->health = health;
        pom->skill = skill;
        pom->threat_level = threat;
        if (health>50) {
            pom->state_of_health=HEALTHY;
        } else {
            pom->state_of_health=WEAKEN;
        }
        pom->next = NULL;
        add_last(head,pom);
    }
    fclose(f);
    return head;
}
