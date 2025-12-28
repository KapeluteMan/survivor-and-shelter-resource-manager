#include "addFromFile.h"
#include "survivorStruct.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Survivor* addSurvivorsFromFile(){
    FILE *f = fopen("../files/survivors.txt","r");
    if (!f) {
        printf("Error in opening file - survivors.txt\n");
        return NULL;
    }

    int skill=0;
    int health=0;
    int threat=0;
    char name[100];
    while (fscanf(f,"%s %d %d %d", name, &skill,&health,&threat)==4) {
        struct Survivor* pom = malloc(sizeof(struct Survivor));
        strcpy(pom->name,name);
        pom->health = health;
        pom->skill = skill;
        pom->threatLevel = threat;
        if (health>50) {
            pom->stateOfHealth=HEALTHY;
        } else {
            pom->stateOfHealth=WEAKEN;
        }
        pom->next = NULL;
    }

    fclose(f);
}
