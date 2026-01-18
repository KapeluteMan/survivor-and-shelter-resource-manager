#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "survivor_struct.h"
#include "list_operations.h"

#include "file_operations.h"


struct Survivor* add_survivors_from_file(){
    FILE *f = fopen("../files/survivors.txt","r");
    if (!f) {
        return NULL;
    }

    int skill=0;
    int health=0;
    int threat=0;
    int rations=0;
    char name[100];
    struct Survivor* head = NULL;
    while (fscanf(f,"%s %d %d %d %d", name, &skill,&health,&threat,&rations)==5) {
        struct Survivor* pom = calloc(1, sizeof(struct Survivor));
        strcpy(pom->name,name);
        pom->health = health;
        pom->skill = skill;
        pom->threat_level = threat;
        pom->rations=rations;
        pom->next = NULL;
        head = add_last(head,pom);
    }
    fclose(f);
    return head;
}

void add_all_to_file(Survivor *head) {
    FILE *f = fopen("../files/graveyard.txt", "a");
    if (!f) {
        perror("Error opening survivor.txt");
        return;
    }

    Survivor *n = head;
    while (n != NULL) {
        fprintf(f, "%s %d %d %d %d %d %d\n", n->name, n->skill, n->rations, n->health,
                n->state_of_health, n->threat_level, n->status_of_survivor);
        n = n->next;
    }

    fclose(f);
}

void add_one_to_file(Survivor *to_add) {
    FILE *f = fopen("../files/graveyard.txt", "a");
    if (!f) {
        perror("Error opening graveyard.txt");
        return;
    }

    fprintf(f, "%s %d %d %d %d %d %d\n", to_add->name, to_add->skill, to_add->rations,
            to_add->health,
            to_add->state_of_health, to_add->threat_level, to_add->status_of_survivor);

    fclose(f);
}