//
// Created by wojte on 27.12.2025.
//

#ifndef UNTITLED5_SURVIVORSTRUCT_H
#define UNTITLED5_SURVIVORSTRUCT_H

enum SpecialistSkill {
    MEDIC,
    ENGINEER,
    ORDINARY
};

enum StateOfHealth {
    HEALTHY,
    WEAKEN
};

enum StatusOfSurvivor {
    WAITING,
    ON_MISSION
};

typedef struct Survivor {
    int id;
    char name[100];
    enum SpecialistSkill skill;
    int rations;
    int health;
    enum StateOfHealth stateOfHealth;
    int threatLevel;
    enum StatusOfSurvivor statusOfSurvivor;
    struct Survivor* next;
}Survivor;

void copySurvivor(struct Survivor* from, struct Survivor* to);

#endif //UNTITLED5_SURVIVORSTRUCT_H