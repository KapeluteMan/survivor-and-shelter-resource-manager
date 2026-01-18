#ifndef SURVIVOR_STRUCT_H
#define SURVIVOR_STRUCT_H

enum specialist_skill {
    MEDIC,
    ENGINEER,
    HUNTER,
    ORDINARY
};

enum state_of_health {
    HEALTHY, //100-80
    WEAKEN, //79-50
    SICK, //49-20
    DYING //19-0
};

enum status_of_survivor {
    WAITING,
    WOUNDED,
    ON_MISSION,
    MISSING,
    DEAD
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
    struct Survivor *next;
} Survivor;

void copy_survivor(const Survivor *from, Survivor *to);
enum specialist_skill form_int_to_enum_skill(int a);
enum state_of_health form_int_to_enum_state_health(int a);


#endif //SURVIVOR_STRUCT_H
