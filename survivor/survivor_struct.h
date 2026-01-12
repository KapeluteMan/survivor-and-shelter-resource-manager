#ifndef SURVIVOR_STRUCT_H
#define SURVIVOR_STRUCT_H

enum specialist_skill {
    MEDIC,
    ENGINEER,
    ORDINARY
};

enum state_of_health {
    HEALTHY,
    WEAKEN
};

enum status_of_survivor {
    WAITING,
    ON_MISSION,
    MISSING
};

typedef struct Survivor {
    int id;
    char name[100];
    enum specialist_skill skill;
    int rations;
    int health;
    enum state_of_health state_of_health;
    int threat_level;
    enum status_of_survivor status_of_survivor;
    struct Survivor* next;
}Survivor;

void copy_survivor(const struct Survivor* from, struct Survivor* to);

#endif //SURVIVOR_STRUCT_H