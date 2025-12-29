#ifndef UNTITLED5_LISTOPERATIONS_H
#define UNTITLED5_LISTOPERATIONS_H

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
} Survivor;

Survivor* add_survivor(Survivor* head);
int check_health();
int check_state_health(int value);
int threat_check();
Survivor* add_last(Survivor* head, Survivor* n);
int check_skill();
int check_rations();
int check_amount();
Survivor* delete_survivor(Survivor* head, int id);
void print_list(Survivor* head);
void short_print_list(Survivor* head);
void add_to_file(Survivor* head);


#endif //UNTITLED5_LISTOPERATIONS_H